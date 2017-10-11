#include "Playing_State.h"

#include <iostream>
#include "Game.h"
#include "../FIleIO/UnitXMLRead.h"
#include "../FIleIO/SoundXMLRead.h"

Playing_State::Playing_State(Game& game) : Game_state(game)
{
	//initialise subsystems


	mm.initialise();
	am.init("../resources/Hamlet.ogg", &mm);

	UnitXMLRead::loadFile("../Resources/UnitDetails.xml", &mm.unitTemplateManager, &mm.SSManager);
	SoundXMLRead::loadSound("../Resources/soundDetails.xml", &mm.soundManager);

	pm.init();
	gameLogic = new GameLogic(&pm, &am, &mm);
	mGame->getInput()->connectGameLogic(gameLogic);

}

Playing_State::~Playing_State()
{
}

void Playing_State::input()
{
	//get input of playing state
}

void Playing_State::update(float dt)
{
	pm.updatePhysics();
	gameLogic->update(dt);
	am.update();
}

void Playing_State::draw()
{
	//draw 
	Display::drawObjs();
}
