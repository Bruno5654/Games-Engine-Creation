#include "CharacterStubby.h"

CharacterStubby::CharacterStubby(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed) : Character(renderer, imagePath, start_position, map)
{
	isFloating = true;
	
	m_facing_direction = start_facing;
	m_movement_speed = movement_speed;
	m_position = start_position;
	m_injured = false;

	m_single_sprite_w = m_texture->GetWidth() / 2;
	m_single_sprite_h = m_texture->GetHeight();
}


void CharacterStubby::TakeDamage()
{
	m_injured = true;
	m_injured_time = INJURED_TIME;
}

void CharacterStubby::Jump()
{
	if (!m_jumping)
	{
		m_jump_force = INITIAL_JUMP_FORCE_SMALL;
		m_jumping = true;
		m_can_jump = false;
	}
}

void CharacterStubby::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);
	if (!m_injured)
	{
		//enemy is not injured so move
		if (m_facing_direction == FACING_LEFT)
		{
			m_moving_left = true;
			m_moving_right = false;
		}
		else if (m_facing_direction == FACING_RIGHT)
		{
			m_moving_right = true;
			m_moving_left = false;
		}
	}
	else
	{
		//we should not be moving when injured
		m_moving_right = false;
		m_moving_left = false;

		//count down the injured time
		m_injured_time -= deltaTime;

		if (m_injured_time <= 0.0)
			FlipRightwayUp();
	}
}

void CharacterStubby::Render()
{
	int left = 0.0f;

	if (m_injured)
		left = m_single_sprite_w;

	SDL_Rect portion_of_sprite = { left,0,m_single_sprite_w, m_single_sprite_h };

	SDL_Rect destRect = { (int)(m_position.x), (int)(m_position.y), m_single_sprite_w, m_single_sprite_h };

	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_HORIZONTAL);
	}

}

void CharacterStubby::FlipRightwayUp()
{
	if (m_facing_direction == FACING_LEFT)
	{
		m_facing_direction = FACING_RIGHT;

	}
	else
	{
		m_facing_direction = FACING_LEFT;
	}

	m_injured = false;
	Jump();
}

CharacterStubby::~CharacterStubby()
{

}