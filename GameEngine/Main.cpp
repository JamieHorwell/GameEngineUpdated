#pragma comment(lib,"Renderer.lib")
#include <SFML\Graphics.hpp>
#include "../Renderer/Display.h"
#include "Game.h"

using namespace std;



int main() {

	Game game;
	game.gameLoop();

	return 0;
}