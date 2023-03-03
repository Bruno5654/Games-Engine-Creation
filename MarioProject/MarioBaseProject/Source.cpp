//Be grateful for humble beginnings, because the next level will always require so much more of you
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include <iostream>

using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
SDL_Texture* g_texture = nullptr;

bool InitSDL();
void CLoseSDL();
bool Update();
void Render();
SDL_Texture* LoadTextureFromFile(string path);
void FreeTexture();

int main(int argc, char* args[])
{
	//Check if SDL was setup correctly.
	if (InitSDL())
	{
		SDL_Delay(5000);
	}
	
	//Flat to check if we quit.
	bool quit = false;

	//Game Loop
	while (!quit)
	{
		Render();
		quit = Update();
	}

	CLoseSDL();

	return 0;
}

bool InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Error check.
	{
		cout << "SDL did not initalise. Error: " << SDL_GetError();
		return false;
	}
	else //Create window
	{
		g_window = SDL_CreateWindow("Games Engine Creation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (g_window == nullptr) //Error check window.
		{
			cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}

		g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_renderer != nullptr)
		{
			//Init PNG loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout << "SDL_Image could not initalise. Error: " << IMG_GetError();
				return false;
			}

			//Load the background texture.
			g_texture = LoadTextureFromFile("Images/test.bmp");
			if (g_texture == nullptr)
			{
				return false;
			}
		}
		else
		{
			cout << "Renderer could not initalise. Error: " << SDL_GetError();
			return false;
		}

	}
}

void CLoseSDL()
{
	//Release the window.
	SDL_DestroyWindow(g_window);
	g_window = nullptr;
	
	//Clear the texture
	FreeTexture();
	//Release the renderer.
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;
	
	//Quit SDL subsytems.
	IMG_Quit();
	SDL_Quit();

}

bool Update()
{
	SDL_Event e;

	//Get events
	SDL_PollEvent(&e);

	switch (e.type)
	{
	//Click x to quit.  	
	case SDL_QUIT:
			return true;
		break;
	}

	return false;
}

void Render()
{
	//Clear the screen.
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	//Set where to render the texture.
	SDL_Rect renderLocation = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//Render to screen.
	SDL_RenderCopyEx(g_renderer, g_texture, NULL, &renderLocation, 0, NULL, SDL_FLIP_NONE);

	//Update the screen.
	SDL_RenderPresent(g_renderer);
}

SDL_Texture* LoadTextureFromFile(string path)
{
	//Remove memory used for a previous texture.
	FreeTexture();
	SDL_Texture* p_texture = nullptr;

	//Load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());
	if (p_surface != nullptr)
	{
		p_texture = SDL_CreateTextureFromSurface(g_renderer, p_surface);
		if (p_texture == nullptr)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError();
		}
		//Remove the loaded surface now that we have a texture.
		SDL_FreeSurface(p_surface);
	
	}
	else
	{
		cout << "Unable to create texture from surface. Error: " << IMG_GetError();
	}
	
	return p_texture;
}

void FreeTexture()
{
	//Check if texture exists before removing it.
	if (g_texture != nullptr)
	{
		SDL_DestroyTexture(g_texture);
		g_texture = nullptr;
	}
}
