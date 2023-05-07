#include "TextRenderer.h"
#include <iostream>

TextRenderer::TextRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

void TextRenderer::Render(int x, int y)
{
	m_text_rect.x = x;
	m_text_rect.y = y;
	m_text_rect.w = 150;
	m_text_rect.h = 50;
	SDL_RenderCopy(m_renderer, m_texture, nullptr, &m_text_rect);
}

bool TextRenderer::LoadFont(string path, int size, const string message, SDL_Color color)
{
	m_font = TTF_OpenFont(path.c_str(), size);

	if (m_font == nullptr)
	{
		std::cout << "Could not open font. Error: "<< TTF_GetError() << std::endl;
		return false;
	}

	SDL_Surface* text_surface = TTF_RenderText_Solid(m_font, message.c_str(), color);


	m_texture = SDL_CreateTextureFromSurface(m_renderer,text_surface);

	TTF_CloseFont(m_font);

	if (text_surface != nullptr)
	{
		SDL_FreeSurface(text_surface);
	}

	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_text_rect.x, &m_text_rect.y);
	return m_texture;
	return false;
}

TextRenderer::~TextRenderer()
{
	m_renderer = nullptr;
}