#include "Character.h"
#include "constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map)
{
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load character texture!" << std::endl;
	}
	m_facing_direction = FACING_RIGHT; //Same direction as image.
	m_moving_left = false;
	m_moving_right = false;
	m_alive = true;
	m_collision_radius = 15.0f;
	m_current_level_map = map;
}

void Character::Render()
{
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
}

void Character::Update(float deltaTime, SDL_Event e)
{
	//Deal with jumping first.
	if (m_jumping)
	{
		//Adjust Postion.
		m_position.y -= m_jump_force * deltaTime;

		//Reduce jump force.
		m_jump_force -= deltaTime * JUMP_FORCE_DECREMENT;

		//If jump force is 0.
		if (m_jump_force <= 0.0f)
		{
			m_jumping = false;
		}
	}

	int centralX_position = (int)(m_position.x + (m_texture->GetWidth() * 0.5)) / TILE_WIDTH;
	int foot_position = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;
	int head_postion = (int)(m_position.y) / TILE_HEIGHT;

	if (m_moving_left && !(m_position.x < LEFT_BUFFER))
	{
		MoveLeft(deltaTime);
	}
	else if (m_moving_right && !(m_position.x > SCREEN_WIDTH - RIGHT_BUFFER))
	{
		MoveRight(deltaTime);
	}

	if (m_moving_up && !(m_current_level_map->GetTileAt(head_postion, centralX_position) == 4))
	{
		MoveUp(deltaTime);
	}
	else if (m_moving_down && !(m_current_level_map->GetTileAt(foot_position, centralX_position) == 4))
	{
		MoveDown(deltaTime);
	}

	//Deal with gravity
	if (!isFloating && m_current_level_map->GetTileAt(foot_position, centralX_position) != 1 && m_current_level_map->GetTileAt(foot_position, centralX_position) != 4)
	{
		AddGravity(deltaTime);
	}
	else
	{
		m_can_jump = true;
	}

	if (m_current_level_map->GetTileAt(head_postion, centralX_position) == 4)
	{
		CancelJump();
	}
}

void Character::MoveLeft(float deltaTime)
{
	m_facing_direction = FACING_LEFT;
	m_position.x -= deltaTime * m_movespeed;
}

void Character::MoveRight(float deltaTime)
{
	m_facing_direction = FACING_RIGHT;
	m_position.x += deltaTime * m_movespeed;
}

void Character::MoveUp(float deltaTime)
{
	m_position.y -= deltaTime * m_movespeed;
}

void Character::MoveDown(float deltaTime)
{
	m_position.y += deltaTime * m_movespeed;
}

void Character::AddGravity(float deltaTime)
{
	if (m_position.y + 64 <= SCREEN_HEIGHT)
	{
		m_position.y += GRAVITY * deltaTime;
	}
	else
	{
		m_can_jump = true;
	}
}

void Character::Jump(float jumpForce)
{
	//Jump.
	m_can_jump = false;
	m_jump_force = jumpForce;
	m_jumping = true;
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D Character::GetPosition()
{
	return m_position;
}

float Character::GetCollisionRadius()
{
	return m_collision_radius;
}

Character::~Character()
{
	m_renderer = nullptr;
}