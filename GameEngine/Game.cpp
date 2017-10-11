#include "Game.h"
#include "Playing_State.h"


Game::Game()
{
	
	Display::initWindow(800, 600);
	pushState(std::make_unique<Playing_State>(*this));
	
}


Game::~Game()
{
}

void Game::gameLoop()
{
	sf::Clock clock;
	

	while (Display::isOpen()) {
		Display::checkWindowEvents();
		Display::clear();
		
		//now use state to decide how to input,update,draw
		states.top()->input();
		states.top()->update(clock.getElapsedTime().asSeconds());
		states.top()->draw();

		input.updateInput();

		
		Display::display();

		
		

	}

}

void Game::pushState(std::unique_ptr<Game_state> newState)
{
	states.push(std::move(newState));
}

void Game::popState()
{
	states.pop();
}

void Game::changeState(std::unique_ptr<Game_state> newState)
{
	popState();
	pushState(std::move(newState));
}


