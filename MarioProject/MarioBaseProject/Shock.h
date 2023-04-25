#pragma once
#include "Texture2D.h"

using namespace std;

class Texture2D;

class Shock
{
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	bool isActive;
	float activeTime;
	double shockAngle;
public:
	Shock(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~Shock();

	void Render();
	void Update(float deltaTime);
	void SetPosition(Vector2D new_position);

	void Activate(Vector2D spawnPosition);

	bool CheckActive() { return isActive; }

	float GetCollisionRadius();
	Rect2D GetCollisionBox()
	{
		return Rect2D(m_position.x+16, m_position.y+16, (m_texture->GetWidth())/2, (m_texture->GetHeight())/2);
	}
};

