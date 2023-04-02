#include "CharacterPod.h"

CharacterPod::CharacterPod(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map) : Character(renderer, imagePath, start_position, map)
{
	isFloating = true;
	m_movement_speed = MOVEMENTSPEED;
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