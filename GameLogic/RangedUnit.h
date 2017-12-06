#pragma once
#include "Unit.h"
class RangedUnit :
	public Unit
{
public:
	RangedUnit();
	RangedUnit(UnitTemplateResource* unitTemplate, sf::Vector2f startPos);

	void attack(Unit* unitToAttack);


	~RangedUnit();
};

