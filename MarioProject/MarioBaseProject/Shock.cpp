#include "Shock.h"
#include <iostream>
#include "constants.h"

Shock::Shock(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	m_texture->LoadFromFile(imagePath);
	isActive = false;
}

void Shock::Render()
{
 	m_texture->Render(m_position, SDL_FLIP_NONE, shockAngle);//(shockAngle/180.0)*3.141592
}

void Shock::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

void Shock::Update(float deltaTime)
{
	if (isActive)
	{
		
		activeTime -= deltaTime;
		if (activeTime <= 0.0)
		{
			isActive = false;
		}
	}
	else
	{
		SetPosition(Vector2D(-100,-100));
	}

	shockAngle += 100.0*deltaTime;
	if (shockAngle >= 360.0)
		shockAngle = 0.0;
}

void Shock::Activate(Vector2D spawnPosition)
{
	isActive = true;
	activeTime = SHOCK_TIME;
	SetPosition(spawnPosition);
}

Shock::~Shock()
{
	m_renderer = nullptr;
	delete m_texture;
	m_texture = nullptr;
}

