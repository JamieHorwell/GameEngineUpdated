#include "InputToGame.h"
#include "MyKeyMapper.h"
#include "Controls.h"
#include <iostream>

#include "../Renderer/Display.h"


sf::Vector2f boxStart;


InputToGame::InputToGame()
{
	MyKeyMapper* currentMap = new MyKeyMapper();
	input.initialize(currentMap, 256);
	boxStart = sf::Vector2f(0, 0);
}


InputToGame::~InputToGame()
{
}

//abstract these to use messages rather than call individual components itself
void InputToGame::updateInput()
{
	input.update();
	if (gamelogic->getInGame()) {
		if (input.actionsActive(MOVECAMERAUP)) {
			gamelogic->getCameraManager()->MoveCamera(sf::Vector2f(0, -1));
		}
		if (input.actionsActive(MOVECAMERADOWN)) {
			gamelogic->getCameraManager()->MoveCamera(sf::Vector2f(0, 1));
		}
		if (input.actionsActive(MOVECAMERALEFT)) {
			gamelogic->getCameraManager()->MoveCamera(sf::Vector2f(-1, 0));
		}
		if (input.actionsActive(MOVECAMERARIGHT)) {
			gamelogic->getCameraManager()->MoveCamera(sf::Vector2f(1, 0));
		}
		if (input.actionsActive(LFTMOUSECLICK)) {

		}
		if (input.actionsHeld(LFTMOUSECLICK)) {
			gamelogic->getUnitSelector()->selectUnitsBox(Display::drawBox(boxStart));

		}
		if (input.firstInstanceAction(LFTMOUSECLICK)) {
			//start the unit select box at new position
			boxStart = sf::Vector2f(Display::getMousePos().x, Display::getMousePos().y);
			//clear selected units
			gamelogic->getUnitManager()->clearSelectedUnits();
			gamelogic->getUnitSelector()->isUnitsinPos(sf::Vector2f(Display::getMousePos().x, Display::getMousePos().y));


			if (Display::getRelativePos().x > 60 && Display::getRelativePos().x < 60 + 140 && Display::getRelativePos().y > 550 && Display::getRelativePos().y < 800) {
				if (gamelogic->getResources() > 0) {
					gamelogic->getBuildingManager()->spawnUnit();
					gamelogic->setResources(gamelogic->getResources() - 5);
				}
				
			}

		}
		//move selected units
		if (input.firstInstanceAction(RGHTMOUSCLICK)) {
			//give selected units new position to move to
			gamelogic->getUnitManager()->updateSelectedUnitTarget(sf::Vector2f(Display::getMousePos().x, Display::getMousePos().y));
		}
		if (input.firstInstanceAction(BUILDUNIT1)) {
			//add unit to team 0
			
		}
		if (input.firstInstanceAction(BUILDUNIT2)) {
			gamelogic->getUnitManager()->createUnit("medievalUnit_09.png", sf::Vector2f(Display::getMousePos().x, Display::getMousePos().y));
		}
	}
	else {
		if (input.firstInstanceAction(LFTMOUSECLICK)) {
			gamelogic->setInGame(true);
			gamelogic->init();
		}
	}
	

}
