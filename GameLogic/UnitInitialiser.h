#pragma once
#include "Unit.h"



class MainManager;

class UnitInitialiser
{
public:
	UnitInitialiser();
	~UnitInitialiser();

	Unit* createUnit(std::string unit, sf::Vector2f pos);



	void setmm(MainManager* mm);


private:
	 MainManager* mm;

	 UnitHealthBar standardBar;
};

