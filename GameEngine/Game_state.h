#pragma once
//#include "Game.h"
#include "../Renderer/Display.h"

class Game;

class Game_state
{
public:
	Game_state(Game& game);
	~Game_state();
	virtual void input() = 0;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
	Game* mGame;
	
protected:


};

