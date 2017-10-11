#pragma once
#include "ResourceBase.h"
#include <SFML/Graphics.hpp>

class BuildingTemplateResource :
	public ResourceBase
{
public:
	BuildingTemplateResource(const unsigned int handle, const string& name, const string& path = "../Resources/");
	~BuildingTemplateResource();


	void init(sf::Sprite buildingSprite, std::string unitType);

	sf::Sprite getBuildingSprite() { return buildingSprite; };
	std::string getUnitType() { return unitType; };

private:
	sf::Sprite buildingSprite;
	std::string unitType;

};

