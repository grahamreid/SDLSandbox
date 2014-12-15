#pragma once
#include "Combat_GameState.h"
#include "Player.h"
#include "Scout.h"
#include "UnitControl.h"
#include "SparkHUD.h"
#include "Terrain.h"
#include "InputHandler.h"

Combat_GameState::Combat_GameState()
{

	InputHandler* inputHandler = new InputHandler();
	//Make some objects for start of game
	Player *player = new Player(400, 550);
	Scout *scout1 = new Scout(300, 300);
	Scout *scout2 = new Scout(400, 300);
	Scout *scout3 = new Scout(500, 300);

	//Menus
	UnitControl *control1 = new UnitControl(0, 0);

	//HUDs
	SparkHUD *sparkHUD = new SparkHUD(control1->getSX() + 5,
		control1->getSY() - SparkHUD_Assets::TEXTURE_H - 5);

	//Terrain
	Terrain *terrain = new Terrain(200, 0);

	//push objects into vector
	_objects.push_back(terrain);
	_objects.push_back(player);
	_objects.push_back(scout1);
	_objects.push_back(scout2);
	_objects.push_back(scout3);
	_objects.push_back(control1);
	_objects.push_back(sparkHUD);
}

Combat_GameState::~Combat_GameState()
{
	_objects.clear();
}

void Combat_GameState::selectObject(int x, int y)
{
	for (auto &object : _objects)
	{
		if (object->containsPoint(x, y))
			object->select();
	}
}

void Combat_GameState::update()
{
	for (auto &object : _objects)
		object->update();
}

void Combat_GameState::render()
{
	for (auto &object : _objects)
		object->render();
}

InputHandler* Combat_GameState::getInputHandler()
{
	return _inputHandler;
}