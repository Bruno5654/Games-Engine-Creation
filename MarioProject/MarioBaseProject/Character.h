#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <iostream>
#include "SDL.h"
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"

using namespace std;

class Texture2D;

class Character
{
	protected:
		SDL_Renderer* m_renderer;
		Vector2D m_position;
		Texture2D* m_texture;
		FACING m_facing_direction;
		bool m_moving_left;
		bool m_moving_right;
		bool m_moving_up;
		bool m_moving_down;
		bool m_jumping;
		bool m_can_jump;
		bool isFloating;
		bool m_alive;
		float m_jump_force;
		float m_collision_radius;
		float m_movespeed;
		virtual void MoveLeft(float deltaTime);
		virtual void MoveRight(float deltaTime);
		virtual void MoveUp(float deltaTime);
		virtual void MoveDown(float deltaTime);
		virtual void Jump(float jumpForce);
		virtual void AddGravity(float deltaTime);

	private:
		
		LevelMap* m_current_level_map;
		
	public:
		Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
		~Character();

		virtual void Render();
		virtual void Update(float deltaTime,SDL_Event e);
		void SetPosition(Vector2D new_position);
		
		bool IsJumping() { return m_jumping; }
		void CancelJump() { m_jumping = false; }

		Vector2D GetPosition();

		void SetAlive(bool isAlive) { m_alive = isAlive; }
		bool GetAlive() { return m_alive; }
		
		float GetCollisionRadius();
		Rect2D GetCollisionBox() 
		{
			return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight());
		}
};

#endif
