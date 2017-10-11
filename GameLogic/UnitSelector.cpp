#include "UnitSelector.h"
#include <iostream>




UnitSelector::UnitSelector(UnitManager * um)
{
	this->um = um;
}

UnitSelector::~UnitSelector()
{
}

void UnitSelector::isUnitsinPos(sf::Vector2f pos)
{
	for (Unit* u : um->getUnits()) {
		//check point lies in units box
		sf::FloatRect unitBounds = u->getRenderObj()->getsprite()->getLocalBounds();
		unitBounds.width /= 3;
		unitBounds.height /= 3;

		if (u->getCurrentPos().x - unitBounds.width/2 < pos.x && 
			u->getCurrentPos().x + unitBounds.width/2 > pos.x &&
			u->getCurrentPos().y + unitBounds.height/2 > pos.y &&
			u->getCurrentPos().y - unitBounds.height/2 < pos.y) {

			um->addSelectedUnit(u);
		}
	}

}

//change to rely on box centre pos
void UnitSelector::selectUnitsBox(sf::RectangleShape box)
{

	
	box.getGlobalBounds().left;
	box.getGlobalBounds().top;

	float width = box.getLocalBounds().width;
	float height = box.getLocalBounds().height;
	sf::Vector2f boxPos = sf::Vector2f(box.getGlobalBounds().left , box.getGlobalBounds().top);

	sf::FloatRect cursorBox(boxPos, sf::Vector2f(width,height));


	for (Unit* u : um->getUnits()) {
		//check centre point of unit lies in box
		sf::Vector2f uPos = u->getCurrentPos();

		
		if (cursorBox.contains(uPos)) {
			um->addSelectedUnit(u);
		}
		
	}
}
