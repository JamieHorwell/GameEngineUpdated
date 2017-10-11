#pragma once
#include "Map.h"

#include "UnitManager.h"
#include "CameraManager.h"
#include "../Physics/PhysicsMain.h"
#include "../ResourceManager/MainManager.h"
class GameSetup
{
public:
	GameSetup(UnitManager* um, PhysicsMain* pm, MainManager* mm, CameraManager*& cm, Map *& map);
	~GameSetup();



	void InitMap(Map*& map, std::string levelFile);

	void initialiseUnits();

private:
	UnitManager* unitManager;
	PhysicsMain* physicsMain;
	MainManager* mm;
};

