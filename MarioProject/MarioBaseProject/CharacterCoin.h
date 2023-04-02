#pragma once
#include "Character.h"

class CharacterCoin : public Character
{
	private:
		float m_single_sprite_w;
		float m_single_sprite_h;
		float m_frame_delay;
		int m_current_frame;
	public:
		CharacterCoin(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position);
		~CharacterCoin();
		void Update(float deltaTime, SDL_Event e);
		void Render();
};

