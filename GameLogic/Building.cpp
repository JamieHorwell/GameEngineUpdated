#include "Building.h"



Building::Building()
{
}

Building::Building(BuildingTemplateResource * BuildingTemplate, sf::Vector2f position)
{
	this->currentpos = position;
	this->renderObj = new RenderComponent(BuildingTemplate->getBuildingSprite());
	this->renderObj->setPos(currentpos);
	this->unitType = BuildingTemplate->getUnitType();
}


Building::~Building()
{
}

void Building::Delete()
{
	renderObj->Delete();
}

