#include "CharacterPod.h"


CharacterPod::CharacterPod(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map, Shock* shock) : Character(renderer, imagePath, start_position, map)
{
	isFloating = true;
	m_movespeed = MOVEMENTSPEED;
	m_shock = shock;
}

void CharacterPod::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			m_moving_right = true;
			break;
		case SDLK_LEFT:
			m_moving_left = true;
			break;
		case SDLK_UP:
			m_moving_up = true;
			break;
		case SDLK_DOWN:
			m_moving_down = true;
			break;
		case SDLK_SPACE:
			if (!m_shock->CheckActive())
			{
				if (m_facing_direction == FACING_LEFT)
				{
					m_shock->Activate(Vector2D(m_position.x-16, m_position.y));
				}
				else
				{
					m_shock->Activate(Vector2D(m_position.x + 16, m_position.y));
				}
			}
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			m_moving_right = false;
			break;
		case SDLK_LEFT:
			m_moving_left = false;
			break;
		case SDLK_UP:
			m_moving_up = false;
			break;
		case SDLK_DOWN:
			m_moving_down = false;
			break;
		}
		break;
	}

	Character::Update(deltaTime, e);
}
CharacterPod::~CharacterPod()
{

}