#pragma once
#include "SFML\Graphics.hpp"
#include "../Renderer/Display.h"
class CameraManager
{
public:
	CameraManager(float mapSize);
	~CameraManager();

	void MoveCamera(sf::Vector2f move);

	bool checkBoundary(sf::Vector2f* move);

private:
	sf::Vector2f currentPos;
	sf::Vector2f cameraDimensions;
	sf::Vector2f topLeftBoundary;
	sf::Vector2f bottomRightBoundary;

};

