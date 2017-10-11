#pragma once
#include "Building.h"
#include "../ResourceManager/BuildingTemplateResource.h"
#include "UnitManager.h"
#include "../Renderer/Display.h"
class BuildingManager
{
public:
	BuildingManager(UnitManager* um, MainManager* mm);
	~BuildingManager();


	void addBuilding(Building* building) { buildings.push_back(building); Display::addRenderObj(building->getRenderObj()); };

	void addBuilding(std::string buildingType, sf::Vector2f pos);

	void update();

	void destroyAllBuildings();

	void spawnUnit();

private:
	std::vector<Building*> buildings;
	UnitManager* um;
	MainManager* mm;
};

