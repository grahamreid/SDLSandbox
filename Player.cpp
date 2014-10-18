#pragma once
#include "Player.h"

Player::Player(int x, int y)
{
	_sx = Player_Assets::TEXTURE_SIZE_X;
	_sy = Player_Assets::TEXTURE_SIZE_Y;
	init(	x, 
			y, 
			GameObject::Player, 
			Player_Assets::TEXTURE_PATH,
			Player_Assets::SPRITE_COUNT,
			Player_Assets::ANIMATION_COUNT
		);
	_sprite->getAnimations()[Player_Assets::ANIMATIONS::NONE].init(Player_Assets::NO_ANIMATION,
															sizeof(Player_Assets::NO_ANIMATION));
}


Player::~Player()
{

}

void update()
{

}

void input()
{

}