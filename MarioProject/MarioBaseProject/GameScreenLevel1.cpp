#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include <iostream>
#include "Collisions.h"

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

bool GameScreenLevel1::SetUpLevel()
{
	//Load texture.
	m_Background_texture = new Texture2D(m_renderer);
	if (!m_Background_texture->LoadFromFile("Images/testMario.png"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}

	//Set up player characters.
	my_character = new Character2B(m_renderer, "Images/Mario.png", Vector2D(64, 355));
	my_character2 = new CharacterPod(m_renderer, "Images/Luigi.png", Vector2D(64, 355));

	return true;
}

void GameScreenLevel1::Render() 
{
	//Draw the background.
	m_Background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	my_character->Render();
	my_character2->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//Update Character.
	my_character->Update(deltaTime, e);
	my_character2->Update(deltaTime, e);

	//Collision
	if (Collisions::Instance()->Circle(my_character, my_character2))
	{
		cout << "Circle Hit!" << endl;
	}
}

GameScreenLevel1::~GameScreenLevel1()
{
	delete m_Background_texture;
	m_Background_texture = nullptr;
	delete my_character;
	my_character = nullptr;
	delete my_character2;
	my_character2 = nullptr;
}

