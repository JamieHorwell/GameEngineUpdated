#pragma once
#include "Unit.h"
#include "UnitInitialiser.h"
#include "../Physics/PhysicsMain.h"
#include "../Renderer/Display.h"
#include "../Audio/AudioMain.h"
#include <string>



class UnitManager
{
public:
	UnitManager(PhysicsMain* pm, AudioMain* am, MainManager* mm);
	~UnitManager();



	inline void addUnit(Unit *unit) { units.push_back(unit); };

	inline void addSelectedUnit(Unit *unit) { selectedUnits.push_back(unit); };

	void updateUnitsPositions();

	void updateUnitPos(Unit * u);

	void updateUnits();

	std::vector<Unit*> getUnits() { return units; };

	void updateSelectedUnitTarget(sf::Vector2f targetPos);

	void clearSelectedUnits() { selectedUnits.clear(); };

	

	void createUnit(std::string unitType, sf::Vector2f pos);


	void removeUnit(Unit* um);


	void killAllUnits();

	Unit* getKing() { return kingUnit; };
	void setKing(Unit* king) { this->kingUnit = king; };

private:
	//contains all units
	std::vector<Unit*> units;
	std::vector<Unit*> selectedUnits;


	Unit* kingUnit;
	
	UnitInitialiser unitInit;



	PhysicsMain* pm;
	AudioMain* am;

	int count = 0;

};

