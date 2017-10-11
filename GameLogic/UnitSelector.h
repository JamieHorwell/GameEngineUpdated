#pragma once
#include <SFML\Graphics.hpp>
#include "UnitManager.h"
class UnitSelector
{
public:
	UnitSelector(UnitManager *um);
	~UnitSelector();


	void isUnitsinPos(sf::Vector2f pos);


	void selectUnitsBox(sf::RectangleShape box);

private:
	UnitManager* um;
};

