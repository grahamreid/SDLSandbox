#pragma once
#include "Scout.h"
#include "Physics.h"

Scout::Scout(int x, int y)
{
	init(	x, 
			y, 
			GameObject::Scout, 
			Scout_Assets::TEXTURE_PATH,
			Scout_Assets::SPRITE_COUNT,
			Scout_Assets::ANIMATION_COUNT,
			Scout_Assets::TEXTURE_SIZE_X,
			Scout_Assets::TEXTURE_SIZE_Y
		);

	_sprite->getAnimations()[Scout_Assets::ANIMATIONS::NONE].init
		(
			Scout_Assets::NO_ANIMATION,
			sizeof(Scout_Assets::NO_ANIMATION)
		);
	_sprite->getAnimations()[Scout_Assets::ANIMATIONS::MOVING].init
		(
			Scout_Assets::MOVING_ANIMATION,
			sizeof(Scout_Assets::MOVING_ANIMATION)
		);

	_nextActionTime = SDL_GetTicks() + _movementCooldown;

	_currentState = State::waiting;

}

Scout::~Scout()
{
}

//update override
void Scout::update()
{
	//log time since last update
	__super::update();

	switch (_currentState)
	{
		case State::waiting :
			if (SDL_GetTicks() >= _nextActionTime)
			{
				Physics::ChooseRandomDirection(&_vx, &_vy);
				_currentDirection = Physics::DetermineDirection(_vx, _vy);
				_nextActionTime += 500;
				_sprite->setCurrentAnimationIndex(Scout_Assets::ANIMATIONS::MOVING);
				_currentState = State::moving;
			}
			break;
		case State::moving :
			if (SDL_GetTicks() >= _nextActionTime)
			{
				_nextActionTime += 1000;
				_currentState = State::waiting;
				_vx = 0;
				_vy = 0;
				_sprite->setCurrentAnimationIndex(Scout_Assets::ANIMATIONS::NONE);
			}
			else
			{
				Physics::moveUnit(&_x, &_y, _vx, _vy, _speed, (float)_clock.getTimeSinceLastUpdate());
			}
			break;
	}
}