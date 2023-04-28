#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "Character2B.h"
#include "CharacterPod.h"
#include "CharacterStubby.h"
#include "CharacterCoin.h"
#include "CharacterLevelGoal.h"
#include <vector>

class Texture2D;
class Character2B;
class CharacterPod;
class CharacterStubby;
class CharacterCoin;
class CharacterLevelGoal;
class PowBlock;
class Shock;

class GameScreenLevel : GameScreen
{
	private:
		Texture2D* m_Background_texture;
		Texture2D* m_Tile_texture;
		bool SetUpLevel(int id);
		Character2B* my_character;
		CharacterPod* my_character2;
		CharacterLevelGoal* levelEnd;
		void SetLevelMap(string path);
		LevelMap* m_level_map;
		PowBlock* m_pow_block;
		bool m_screenshake;
		float m_shake_time;
		float m_wobble;
		float m_background_yPos;
		void DoScreenshake();
		void UpdateEnemies(float deltaTime, SDL_Event e);
		void CreateStubby(Vector2D position, FACING direction, float speed);
		void CreateCoin(Vector2D position);
		vector<CharacterStubby*> m_enemies;
		vector<CharacterCoin*> m_coins;
		LevelMap* m_current_level_map;
		Shock* m_shock;
		GameScreenManager* m_screenManager;
	
	public:
		GameScreenLevel(SDL_Renderer* renderer, GameScreenManager* screenManager,int levelID);
		~GameScreenLevel();

		void Render() override;
		void Update(float deltaTime, SDL_Event e) override;
		void UpdatePowBlock();


};

#endif