#pragma once
#include "SDL_ttf.h"
#include <string>

using namespace std;

class TextRenderer
{
private:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	SDL_Rect m_text_rect;
	TTF_Font* m_font;
public:
	TextRenderer(SDL_Renderer* renderer);
	~TextRenderer();
	void Render(int x, int y);
	bool LoadFont(string path, int size, const string message, SDL_Color color);
};

