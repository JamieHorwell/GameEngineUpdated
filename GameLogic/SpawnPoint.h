#pragma once
#include <SFML\Graphics.hpp>
#include "UnitManager.h"
class SpawnPoint
{
public:
	SpawnPoint();
	SpawnPoint(UnitManager *um, std::string unitType, int maxCount, sf::Vector2f spawnPos, int squadSize);
	~SpawnPoint();

	void SpawnUnit();

	void update();

private:
	int counter;
	int maxCount;
	sf::Vector2f spawnLocation;
	std::string unitType;
	UnitManager* um;
	int squadSize;
};

