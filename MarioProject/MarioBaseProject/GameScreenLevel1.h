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
class PowBlock;

class GameScreenLevel1 : GameScreen
{
	private:
		Texture2D* m_Background_texture;
		bool SetUpLevel();
		Character2B* my_character;
		CharacterPod* my_character2;
		void SetLevelMap();
		LevelMap* m_level_map;
		PowBlock* m_pow_block;
		bool m_screenshake;
		float m_shake_time;
		float m_wobble;
		float m_background_yPos;
		void DoScreenshake();
	
	public:
		GameScreenLevel1(SDL_Renderer* renderer);
		~GameScreenLevel1();

		void Render() override;
		void Update(float deltaTime, SDL_Event e) override;
		void UpdatePowBlock();


};

#endif