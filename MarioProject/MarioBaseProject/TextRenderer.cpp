#include "TextRenderer.h"

TextRenderer::TextRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

void TextRenderer::Render(int x, int y)
{
	m_text_rect.x = x;
	m_text_rect.y = y;
	SDL_RenderCopy(m_renderer, m_texture, nullptr, &m_text_rect);
}

bool TextRenderer::LoadFont(string path, int size, const string message, SDL_Color color)
{
	m_font = TTF_OpenFont(path.c_str(), size);

	SDL_Surface* text_surface = TTF_RenderText_Solid(m_font, message.c_str(), color);

	m_texture = SDL_CreateTextureFromSurface(m_renderer,text_surface);

	TTF_CloseFont(m_font);

	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}

	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_text_rect.x, &m_text_rect.y);
	return m_texture;
	return false;
}
