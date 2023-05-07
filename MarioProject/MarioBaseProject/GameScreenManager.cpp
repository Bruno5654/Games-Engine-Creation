#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;
	m_next_screen = SCREEN_LEVEL1;
	ChangeScreen();
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
		if (m_current_screen != nullptr)
		{
			QueueScreen(m_current_screen_enum);
		}
		break;
	}
	m_current_screen->Update(deltaTime,e);
}

void GameScreenManager::QueueScreen(SCREENS new_screen)
{
	m_next_screen = new_screen;
}

void GameScreenManager::ChangeScreen()
{
	//Clear up the old screen.
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}

	GameScreenLevel* tempScreen;

	

	switch (m_next_screen)
	{
		case SCREEN_LEVEL1:
			tempScreen = new GameScreenLevel(m_renderer,this,1);
			m_current_screen = (GameScreen*)tempScreen;
			m_current_screen_enum = SCREEN_LEVEL1;
			tempScreen = nullptr;
			break;
		case SCREEN_LEVEL2:
			tempScreen = new GameScreenLevel(m_renderer,this,2);
			m_current_screen = (GameScreen*)tempScreen;
			m_current_screen_enum = SCREEN_LEVEL2;
			tempScreen = nullptr;
			break;
		case SCREEN_LEVEL3:
			tempScreen = new GameScreenLevel(m_renderer, this, 3);
			m_current_screen = (GameScreen*)tempScreen;
			m_current_screen_enum = SCREEN_LEVEL3;
			tempScreen = nullptr;
			break;
		default:
			tempScreen = new GameScreenLevel(m_renderer,this,1);
			m_current_screen = (GameScreen*)tempScreen;
			m_current_screen_enum = SCREEN_LEVEL1;
			tempScreen = nullptr;
			break;
	}

	m_next_screen = NONE;
}

GameScreenManager::~GameScreenManager()
{
	m_renderer = nullptr;
	delete m_current_screen;
	m_current_screen = nullptr;
}