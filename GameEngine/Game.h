#pragma once
#include "../Renderer/Display.h"
#include "../ResourceManager/MainManager.h"
#include "../HumanInterface/InputToGame.h"
#include <memory>
#include <stack>
#include "Game_state.h"

class Game
{
public:
	Game();
	~Game();

	void gameLoop();

	void pushState(std::unique_ptr<Game_state> newState);
	void popState();

	void changeState(std::unique_ptr<Game_state> newState);

	


	InputToGame* getInput() { return &input; };


	


private:
	std::stack<std::unique_ptr<Game_state>> states;
	InputToGame input;
	
};

