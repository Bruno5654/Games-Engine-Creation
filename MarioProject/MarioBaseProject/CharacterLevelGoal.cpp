#include "CharacterLevelGoal.h"

CharacterLevelGoal::CharacterLevelGoal(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing) : Character(renderer, imagePath, start_position, map)
{
	isFloating = true;
	originPOS = start_position;
	m_movespeed = 10.0f;
}

void CharacterLevelGoal::Update(float deltaTime, SDL_Event e)
{
	m_delay -= deltaTime;
	if (m_delay <= 0.0f)
	{
		m_delay = 0.3f;

		if (m_position.y > originPOS.y)
		{
			m_moving_down = false;
			m_moving_up = true;
		}
		else
		{
			m_moving_up = false;
			m_moving_down = true;
		}

	}

	Character::Update(deltaTime, e);
}

CharacterLevelGoal::~CharacterLevelGoal()
{
}
