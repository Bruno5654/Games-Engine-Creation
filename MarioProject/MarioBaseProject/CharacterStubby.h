#pragma once
#include "Character.h"

class CharacterStubby : public Character
{	
	private:
		float m_single_sprite_w;
		float m_single_sprite_h;
		bool m_injured;
		float m_injured_time;
		bool m_isFlyer;
		void FlipRightwayUp();
	public:
		CharacterStubby(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed, bool isFlyer);
		~CharacterStubby();
		void TakeDamage();
		void Update(float deltaTime, SDL_Event e);
		void Render();
		FACING m_facing_direction;
		bool GetInjured() { return m_injured; }
};

