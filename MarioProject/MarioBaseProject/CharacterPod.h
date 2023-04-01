#pragma once
#include "Character.h"

class CharacterPod : public Character
{
	public:
		CharacterPod(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
		~CharacterPod();
		void Update(float deltaTime, SDL_Event e);
};

