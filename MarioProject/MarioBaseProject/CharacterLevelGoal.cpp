#include "CharacterLevelGoal.h"

CharacterLevelGoal::CharacterLevelGoal(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing) : Character(renderer, imagePath, start_position, map)
{
	isFloating = true;

}

void CharacterLevelGoal::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);
}

CharacterLevelGoal::~CharacterLevelGoal()
{
}
