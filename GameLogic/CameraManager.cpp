#include "CameraManager.h"
#include <iostream>


CameraManager::CameraManager(float mapSize)
{
	//setup boundaries
	topLeftBoundary = sf::Vector2f(0, 0);
	//set this up according to map size
	bottomRightBoundary = sf::Vector2f(mapSize, mapSize);

	//setup current position
	currentPos = Display::cameraView.getCenter();
	//setup cameraDimensions
	cameraDimensions.x = Display::cameraView.getSize().x / 2;
	cameraDimensions.y = Display::cameraView.getSize().y / 2;


}


CameraManager::~CameraManager()
{
}

void CameraManager::MoveCamera(sf::Vector2f move)
{
	//we can move the camera, not at edges
	if (checkBoundary(&move)) {
		Display::moveView(move);
		currentPos = Display::cameraView.getCenter();
	}
}

bool CameraManager::checkBoundary(sf::Vector2f* move)
{
	//camera hit right border
	if (currentPos.x + cameraDimensions.x + move->x > bottomRightBoundary.x) {
		move->x = 0;
	}
	//camera hit left border
	else if (currentPos.x - cameraDimensions.x + move->x < topLeftBoundary.x) {
		move->x = 0;
	}
	//camera hit top border
	if (currentPos.y - cameraDimensions.y + move->y  < topLeftBoundary.y) {
		move->y = 0;
	}
	//camera hit bottom border
	else if (currentPos.y + cameraDimensions.y + move->y > bottomRightBoundary.y) {
		move->y = 0;
	}


	return true;
}
