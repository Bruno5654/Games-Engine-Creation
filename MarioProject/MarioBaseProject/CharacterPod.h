#pragma once
#include "Character.h"
#include "Shock.h"

class Shock;

class CharacterPod : public Character
{
private:
	Shock* m_shock;
public:
		CharacterPod(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map, Shock* shock);
		~CharacterPod();
		void Update(float deltaTime, SDL_Event e);
};

