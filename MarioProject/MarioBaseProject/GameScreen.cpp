#include "GameScreen.h"
#include "LevelMap.h"

GameScreen::GameScreen(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

void GameScreen::Render(){}
void GameScreen::Update(float deltaTime, SDL_Event e){}

GameScreen::~GameScreen() 
{
	m_renderer = nullptr;
}