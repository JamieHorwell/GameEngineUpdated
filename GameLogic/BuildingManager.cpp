#include "BuildingManager.h"



BuildingManager::BuildingManager(UnitManager * um, MainManager* mm)
{
	this->um = um;
	this->mm = mm;
}


BuildingManager::~BuildingManager()
{
}

void BuildingManager::addBuilding(std::string buildingType, sf::Vector2f pos)
{
	buildings.push_back(new Building(mm->buildingManager.GetElement(buildingType),pos));
	Display::addRenderObj(buildings.back()->getRenderObj());
}

void BuildingManager::update()
{
	if (buildings.size() > 0) {
		std::vector<Building*>::iterator currentBuilding;
		for (currentBuilding = buildings.begin(); currentBuilding != buildings.end();) {

			if ((*currentBuilding)->getDelete()) {
				currentBuilding = buildings.erase(currentBuilding);
			}
			else {

				if ((*currentBuilding)->getSpawnSoldiers() > 0) {
					um->createUnit((*currentBuilding)->getUnitType(), (*currentBuilding)->getPos());
					(*currentBuilding)->decrementSpawn();
				}


				++currentBuilding;
			}


		}
	}
	


}

void BuildingManager::destroyAllBuildings()
{
	std::vector<Building*>::iterator currentBuilding;
	for (currentBuilding = buildings.begin(); currentBuilding != buildings.end();) {

		(*currentBuilding)->Delete();
		currentBuilding = buildings.erase(currentBuilding);

	}
}

void BuildingManager::spawnUnit()
{
	if (buildings.size() > 0) {
		buildings.front()->spawnSoldier();
	}
}
