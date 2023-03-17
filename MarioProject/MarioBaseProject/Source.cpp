//Be grateful for humble beginnings, because the next level will always require so much more of you
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include <iostream>
#include "Texture2D.h"
#include "Commons.h"
#include "GameScreenManager.h"

GameScreenManager* game_screen_manager;
Uint32 g_old_time;

using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
Texture2D* g_texture = nullptr;

bool InitSDL();
void CLoseSDL();
bool Update();
void Render();


int main(int argc, char* args[])
{
	//Check if SDL was setup correctly.
	if (InitSDL())
	{
		game_screen_manager = new GameScreenManager(g_renderer, SCREEN_LEVEL1);
		//Set the time.
		g_old_time = SDL_GetTicks();
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
		}
		else
		{
			cout << "Renderer could not initalise. Error: " << SDL_GetError();
			return false;
		}
	}
	
	//Load the background texture.
	g_texture = new Texture2D(g_renderer);
	if (!g_texture->LoadFromFile("Images/test.bmp"))
	{
		return false;
	}
}

bool Update()
{
	SDL_Event e;
	Uint32 new_time = SDL_GetTicks();
	

	//Get events
	SDL_PollEvent(&e);

	switch (e.type)
	{
	//Click x to quit.  	
	case SDL_QUIT:
			return true;
		break;
	}
	
	game_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, e);
	g_old_time = new_time;
	return false;
}

void Render()
{
	//Clear the screen.
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	g_texture->Render(Vector2D(), SDL_FLIP_NONE);

	//Update the screen.
	SDL_RenderPresent(g_renderer);
}

void CLoseSDL()
{
	//Release the window.
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	//Release the renderer.
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;

	//Destroy the game screen manager.
	delete game_screen_manager;
	game_screen_manager = nullptr;


	//Quit SDL subsytems.
	IMG_Quit();
	SDL_Quit();

}

