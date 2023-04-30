#include "Character2B.h"
#include "constants.h"

Character2B::Character2B(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map) : Character(renderer, imagePath, start_position, map)
{
	isFloating = false;
	m_movespeed = MOVEMENTSPEED;
	m_alive = true;
}

void Character2B::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_d:
			m_moving_right = true;
			break;
		case SDLK_a:
			m_moving_left = true;
			break;
		case SDLK_w:
			if (m_can_jump)
			{
				Jump(INITAL_JUMP_FORCE);
			}
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_d:
			m_moving_right = false;
			break;
		case SDLK_a:
			m_moving_left = false;
			break;
		}
		break;
	}
	
	Character::Update(deltaTime,e);
}

Character2B::~Character2B()
{

}