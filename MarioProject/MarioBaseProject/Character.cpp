#include "Character.h"
#include "Texture2D.h"
#include "constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
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
	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
	
	if (m_moving_up)
	{
		MoveUp(deltaTime);
	}
	else if (m_moving_down)
	{
		MoveDown(deltaTime);
	}
}

void Character::MoveLeft(float deltaTime)
{
	m_facing_direction = FACING_LEFT;
	m_position.x -= deltaTime * MOVEMENTSPEED;
}

void Character::MoveRight(float deltaTime)
{
	m_facing_direction = FACING_RIGHT;
	m_position.x += deltaTime * MOVEMENTSPEED;
}

void Character::MoveUp(float deltaTime)
{
	m_position.y -= deltaTime * MOVEMENTSPEED;
}

void Character::MoveDown(float deltaTime)
{
	m_position.y += deltaTime * MOVEMENTSPEED;
}

void Character::AddGravity(float deltaTime)
{
	if (m_position.y + 64 <= SCREEN_HEIGHT)
	{
		m_position.y += deltaTime * GRAVITY;
	}
	else
	{
		m_can_jump = true;
	}
}

void Character::Jump()
{
	//Jump.
	m_jump_force = INITAL_JUMP_FORCE;
	m_jumping = true;
	m_can_jump = false;
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D Character::GetPosition()
{
	return m_position;
}

Character::~Character()
{
	m_renderer = nullptr;
}