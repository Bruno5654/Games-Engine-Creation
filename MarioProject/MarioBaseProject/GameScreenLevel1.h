#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "Character2B.h"
#include "CharacterPod.h"
#include "LevelMap.h"

class Texture2D;
class Character2B;
class CharacterPod;

class GameScreenLevel1 : GameScreen
{
	private:
		Texture2D* m_Background_texture;
		bool SetUpLevel();
		Character2B* my_character;
		CharacterPod* my_character2;
		void SetLevelMap();
		LevelMap* m_level_map;
	
	public:
		GameScreenLevel1(SDL_Renderer* renderer);
		~GameScreenLevel1();

		void Render() override;
		void Update(float deltaTime, SDL_Event e) override;


};

#endif