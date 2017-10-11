#include "PauseState.h"



PauseState::PauseState(Game& game) : Game_state(game)
{
}



PauseState::~PauseState()
{
}

void PauseState::input()
{
}

void PauseState::update(float dt)
{
}

void PauseState::draw()
{
	Display::drawObjs();
}
