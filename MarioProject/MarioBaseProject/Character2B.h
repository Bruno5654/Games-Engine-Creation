#pragma once
#include "Character.h"

class Character2B : public Character
{
	public:	
		Character2B(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
		~Character2B();
		void Update(float deltaTime, SDL_Event e);
};


