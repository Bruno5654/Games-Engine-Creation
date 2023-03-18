#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <iostream>
#include "SDL.h"
#include "Commons.h"

using namespace std;

class Texture2D;

class Character
{
	protected:
		SDL_Renderer* m_renderer;
		Vector2D m_position;
		Texture2D* m_texture;
		bool m_moving_left;
		bool m_moving_right;
		bool m_moving_up;
		bool m_moving_down;
		bool m_jumping;
		bool m_can_jump;
		float m_jump_force;
		virtual void MoveLeft(float deltaTime);
		virtual void MoveRight(float deltaTime);
		virtual void MoveUp(float deltaTime);
		virtual void MoveDown(float deltaTime);
		virtual void Jump();
		virtual void AddGravity(float deltaTime);

	private:
		FACING m_facing_direction;
	public:
		Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
		~Character();

		virtual void Render();
		virtual void Update(float deltaTime,SDL_Event e);
		void SetPosition(Vector2D new_position);
		Vector2D GetPosition();
};

#endif
