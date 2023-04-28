#pragma once
#include "Character.h"

class CharacterLevelGoal : public Character
{
public:
	CharacterLevelGoal(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing);
	~CharacterLevelGoal();
	void Update(float deltaTime, SDL_Event e);
};

