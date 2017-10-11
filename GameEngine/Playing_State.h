#pragma once
#include "Game_state.h"
#include "SFML\Graphics.hpp"
#include "../Renderer/RenderComponent.h"
#include "../GameLogic/Map.h"
#include "../Physics/PhysicsMain.h"
#include "../GameLogic/GameLogic.h"
#include "../Audio/AudioMain.h"


class Playing_State : public Game_state
{
public:
	Playing_State(Game& game);
	~Playing_State();
	void input();
	void update(float dt);
	void draw();
	
private:
	sf::RectangleShape shape;
	sf::Sprite sprite;
	RenderComponent*  soldierComp;
	GameLogic* gameLogic;
	PhysicsMain pm;
	MainManager mm;
	AudioMain am;
};

