#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include <iostream>

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

bool GameScreenLevel1::SetUpLevel()
{
	//Load texture.
	m_Background_texture = new Texture2D(m_renderer);
	if (!m_Background_texture->LoadFromFile("Images/test.bmp"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}

	return true;
}

void GameScreenLevel1::Render() 
{
	//Draw the background.
	m_Background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

}

GameScreenLevel1::~GameScreenLevel1()
{
	delete m_Background_texture;
	m_Background_texture = nullptr;
}

