#include "CharacterCoin.h"

CharacterCoin::CharacterCoin(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position) : Character(renderer, imagePath, start_position, map)
{
	isFloating = true;
	m_position = start_position;

	m_single_sprite_w = m_texture->GetWidth() / 3;
	m_single_sprite_h = m_texture->GetHeight();
}


void CharacterCoin::Update(float deltaTime, SDL_Event e)
{
	m_frame_delay -= deltaTime;
	if (m_frame_delay <= 0.0f)
	{
		//reset frame delay count
		m_frame_delay = ANIMATION_DELAY;

		//move the frame over
		m_current_frame++;

		//loop frame around if it goes beyond the number of frames
		if (m_current_frame > 2)
		{
			m_current_frame = 0;
		}
			
	}
}

void CharacterCoin::Render()
{
	int left = m_current_frame * m_single_sprite_w;

	SDL_Rect portion_of_sprite = { left,0,m_single_sprite_w, m_single_sprite_h };

	SDL_Rect destRect = { (int)(m_position.x), (int)(m_position.y), m_single_sprite_w, m_single_sprite_h };

	m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
}

CharacterCoin::~CharacterCoin()
{

}
