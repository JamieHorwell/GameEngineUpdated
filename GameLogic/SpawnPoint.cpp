#include "SpawnPoint.h"



SpawnPoint::SpawnPoint()
{
}

SpawnPoint::SpawnPoint(UnitManager * um, std::string unitType, int maxCount, sf::Vector2f spawnPos, int squadSize = 1)
{
	this->um = um;
	this->unitType = unitType;
	this->maxCount = maxCount;
	this->counter = maxCount;
	this->spawnLocation = spawnPos;
	this->squadSize = squadSize;
}


SpawnPoint::~SpawnPoint()
{
}

void SpawnPoint::SpawnUnit()
{
	for (int i = 0; i < squadSize; ++i) {
		um->createUnit(unitType, spawnLocation);
		std::cout << um->getUnits().back()->getAgroRange();
	}
}

void SpawnPoint::update()
{
	counter--;
	if (counter < 1) {
		SpawnUnit();
		counter = maxCount;
	}
}
