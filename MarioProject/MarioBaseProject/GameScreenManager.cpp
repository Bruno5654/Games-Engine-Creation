#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;

	ChangeScreen(startScreen);
}

void GameScreenManager::Render()
{
	m_current_screen->Render();
}
void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_r:
		ChangeScreen(SCREEN_LEVEL2);
		break;
	}
	m_current_screen->Update(deltaTime,e);
}

void GameScreenManager::ChangeScreen(SCREENS new_screen)
{
	//Clear up the old screen.
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}

	GameScreenLevel* tempScreen;

	switch (new_screen)
	{
		case SCREEN_LEVEL1:
			tempScreen = new GameScreenLevel(m_renderer,this,1);
			m_current_screen = (GameScreen*)tempScreen;
			tempScreen = nullptr;
			break;
		case SCREEN_LEVEL2:
			tempScreen = new GameScreenLevel(m_renderer,this,2);
			m_current_screen = (GameScreen*)tempScreen;
			tempScreen = nullptr;
			break;
		default:
			tempScreen = new GameScreenLevel(m_renderer,this,1);
			m_current_screen = (GameScreen*)tempScreen;
			tempScreen = nullptr;
			break;
	}
}

GameScreenManager::~GameScreenManager()
{
	m_renderer = nullptr;
	delete m_current_screen;
	m_current_screen = nullptr;
}