#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include <iostream>
#include <fstream>
#include "Collisions.h"
#include "PowBlock.h"
#include <string>
GameScreenLevel::GameScreenLevel(SDL_Renderer* renderer, GameScreenManager* screenManager, int levelID) : GameScreen(renderer)
{
	m_level_map = nullptr;
	m_screenManager = screenManager;
	SetUpLevel(levelID);
}

bool GameScreenLevel::SetUpLevel(int ID)
{
	m_Background_texture = new Texture2D(m_renderer);
	if (!m_Background_texture->LoadFromFile("Images/Background.png"))
	{
		std::cout << "Failed to load Background texture!" << std::endl;
		return false;
	}

	m_Tile_texture = new Texture2D(m_renderer);
	if (!m_Tile_texture->LoadFromFile("Images/Platform.png"))
	{
		std::cout << "Failed to load Platform texture!" << std::endl;
		return false;
	}

	m_shock = new Shock(m_renderer,"Images/Shock.png", Vector2D(-100,-100));

	//Set up level.

	string path1 = "Level" + to_string(ID);
	string path2 = ".txt";

	SetLevelMap(path1+path2);

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			//Create Players
			if (m_level_map->GetTileAt(j, i) == 9)
			{
				my_character = new Character2B(m_renderer, "Images/2B.png", Vector2D(i * TILE_SIZE, j * TILE_SIZE), m_level_map); //If this is lower or higher than the small range around 336 2B starts at a like y 1333
				my_character2 = new CharacterPod(m_renderer, "Images/Pod.png", Vector2D((i * TILE_SIZE) - TILE_SIZE, (j * TILE_SIZE) - TILE_SIZE), m_level_map, m_shock);
			}

			//Create Coins
			if (m_level_map->GetTileAt(j, i) == 2)
			{
				CreateCoin(Vector2D(i * TILE_SIZE, j * TILE_SIZE));
			}

			//Create Stubbies
			if (m_level_map->GetTileAt(j, i) == 3)
			{
				if (i < MAP_WIDTH / 2) //Check which side of the map its on.
				{
					CreateStubby(Vector2D(i * TILE_SIZE, j * TILE_SIZE), FACING_RIGHT, STUBBY_SPEED);
				}
				else
				{
					CreateStubby(Vector2D(i * TILE_SIZE, j * TILE_SIZE), FACING_LEFT, STUBBY_SPEED);
				}

			}
		}
	}

	m_pow_block = new PowBlock(m_renderer, m_level_map);

	m_screenshake = false;
	m_background_yPos = 0.0f;


	return true;
}

void GameScreenLevel::SetLevelMap(string path)
{
	ifstream inFile;
	int map[MAP_HEIGHT][MAP_WIDTH];

	inFile.open(path);

	if (!inFile.good())
	{
		cerr << "Can't open level file " << path << endl;
	}
	
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			inFile >> map[i][j];
		}
	}

	inFile.close();
	//clear any old maps
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}

	//set the new one
	m_level_map = new LevelMap(map);
}

void GameScreenLevel::UpdatePowBlock()
{
	if (Collisions::Instance()->Box(my_character->GetCollisionBox(), m_pow_block->GetCollisionBox()))
	{
		if (m_pow_block->IsAvailable())
		{
			//Collided while jumping
			if (my_character->IsJumping())
			{
				DoScreenshake();
				m_pow_block->TakeHit();
				my_character->CancelJump();
			}
		}
	}
}

void GameScreenLevel::UpdateEnemies(float deltaTime, SDL_Event e)
{
	if (!m_enemies.empty())
	{
		int enemyIndexToDelete = -1;
		for (unsigned int i = 0; i < m_enemies.size(); i++)
		{
			//check if the enemy is on the bottom row of tiles
			if (m_enemies[i]->GetPosition().y > 300.0f)
			{
				//is the enemy off screen to the left / right?
				if (m_enemies[i]->GetPosition().x < (float)(-m_enemies[i]->GetCollisionBox().width * 0.5f) || m_enemies[i]->GetPosition().x > SCREEN_WIDTH - (float)(m_enemies[i]->GetCollisionBox().width * 0.55f))
				{
					m_enemies[i]->SetAlive(false);
					//cout << "Dead is " << i << endl;
				}
					
			}
			
			if (m_enemies[i]->GetPosition().x > SCREEN_WIDTH)
			{
				m_enemies[i]->m_facing_direction = FACING_LEFT;
			}

			if (m_enemies[i]->GetPosition().x < 0)
			{
				m_enemies[i]->m_facing_direction = FACING_RIGHT;
			}

			//now do the update
			m_enemies[i]->Update(deltaTime, e);

			if (Collisions::Instance()->Circle(m_enemies[i], my_character))
			{
				if (m_enemies[i]->GetInjured())
				{
					m_enemies[i]->SetAlive(false);
				}
				else
				{
					if (my_character->GetAlive())
					{
						my_character->SetAlive(false);
					}
				}

				//if the enemy is no longer alive then schedule it for deletion
				if (!m_enemies[i]->GetAlive())
				{
					enemyIndexToDelete = i;
				}
			}

			if (Collisions::Instance()->Box(m_enemies[i]->GetCollisionBox(), m_shock->GetCollisionBox()))
			{
				if (!m_enemies[i]->GetInjured())
				{
					m_enemies[i]->TakeDamage();
				}
			}
			//remove dead enemies -1 each update
			if (enemyIndexToDelete != -1)
			{
				m_enemies.erase(m_enemies.begin() + enemyIndexToDelete);
			}
		}
	}
}

void GameScreenLevel::Render()
{
	
	m_Background_texture->Render(Vector2D(0, 0), SDL_FLIP_NONE);

	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->Render();
	}

	for (int i = 0; i < m_coins.size(); i++)
	{
		m_coins[i]->Render();
	}

	for (unsigned int i = 0; i < MAP_WIDTH; i++)
	{
		for (unsigned int j = 0; j < MAP_HEIGHT; j++)
		{
			if (m_level_map->GetTileAt(j, i) == 1)
			{
				m_Tile_texture->Render(Vector2D(i* TILE_SIZE,j* TILE_SIZE), SDL_FLIP_NONE);
			}
		}
	}

	m_shock->Render();
	my_character->Render();
	my_character2->Render();
	m_pow_block->Render();
}

void GameScreenLevel::Update(float deltaTime, SDL_Event e)
{
	//Screenshake
	if (m_screenshake)
	{
		m_shake_time -= deltaTime;
		m_wobble++;
		m_background_yPos = sin(m_wobble);
		m_background_yPos *= 3.0f;

		//end shake after duration
		if (m_shake_time <= 0.0f)
		{
			m_shake_time = false;
			m_background_yPos = 0.0f;
		}
	}

	m_shock->Update(deltaTime);

	//Update Character.
	my_character->Update(deltaTime, e);
	my_character2->Update(deltaTime, e);

	UpdatePowBlock();
	UpdateEnemies(deltaTime, e);

	for (int i = 0; i < m_coins.size(); i++)
	{
		m_coins[i]->Update(deltaTime,e);
		if (Collisions::Instance()->Circle(m_coins[i], my_character))
		{
			m_coins.erase(m_coins.begin() + i);
			//Increase Score
		}
	}
}

void GameScreenLevel::DoScreenshake()
{
	m_screenshake = true;
	m_shake_time = SHAKE_DURATION;
	m_wobble = 0.0f;
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->TakeDamage();
	}
}

void GameScreenLevel::CreateStubby(Vector2D position, FACING direction, float speed) 
{
	m_enemies.push_back(new CharacterStubby(m_renderer, "Images/Stubby.png", m_level_map, position, direction, speed));
}

void GameScreenLevel::CreateCoin(Vector2D position)
{
	m_coins.push_back(new CharacterCoin(m_renderer, "Images/Coin.png", m_level_map, position));
}

GameScreenLevel::~GameScreenLevel()
{
	//delete m_Background_texture;
	//m_Background_texture = nullptr;
	delete m_Tile_texture;
	m_Tile_texture = nullptr;
	delete my_character;
	my_character = nullptr;
	delete my_character2;
	my_character2 = nullptr;
	delete m_pow_block;
	m_pow_block = nullptr;
	for (int i = 0; i < m_enemies.size(); i++)
	{
		delete m_enemies[i];
	}
	m_enemies.clear();
	for (int i = 0; i < m_coins.size(); i++)
	{
		delete m_coins[i];
	}
	m_coins.clear();

}

