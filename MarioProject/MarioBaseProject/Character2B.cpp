#include "Character2B.h"
#include "constants.h"

Character2B::Character2B(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map) : Character(renderer, imagePath, start_position, map)
{
	isFloating = false;
}

void Character2B::Update(float deltaTime, SDL_Event e)
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
				Jump();
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