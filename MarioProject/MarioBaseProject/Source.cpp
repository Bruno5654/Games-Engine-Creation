//Be grateful for humble beginnings, because the next level will always require so much more of you
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include <iostream>

using namespace std;

//Globals
SDL_Window* g_window = nullptr;

bool InitSDL();
void CLoseSDL();

int main(int argc, char* args[])
{
	if (InitSDL())
	{
		SDL_Delay(5000);
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
	}
}

void CLoseSDL()
{
	//Release the window.
	SDL_DestroyWindow(g_window);
	g_window = nullptr;
	//Quit SDL subsytems.
	IMG_Quit();
	SDL_Quit();
}