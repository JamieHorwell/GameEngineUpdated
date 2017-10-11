#pragma once
#include "WindowsKeyInput.h"
#include "../GameLogic/GameLogic.h"

#define MOVESPEED 0.04f;

class InputToGame
{
public:
	InputToGame();
	~InputToGame();
	
	void connectGameLogic(GameLogic* gl) { this->gamelogic = gl; };

	void updateInput();


private:
	WindowsKeyInput input;
	GameLogic* gamelogic;

};

