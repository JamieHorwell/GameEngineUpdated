#pragma once
#include "Game_state.h"
class PauseState :
	public Game_state
{
public:
	PauseState(Game& game);
	~PauseState();

	void input();
	void update(float dt);
	void draw();

};

