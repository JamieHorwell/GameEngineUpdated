#pragma once
#include "GameSetup.h"
#include "UnitManager.h"
#include "CameraManager.h"
#include "SpawnPoint.h"
#include "../ResourceManager/MainManager.h"
#include "../Physics/PhysicsMain.h"
#include "UnitSelector.h"
#include "../Audio/AudioMain.h"
#include "GUIManager.h"
#include "../FIleIO/LevelDetailsXMLRead.h"
#include "BuildingManager.h"
#include "ProjectileManager.h"
#include <sstream>
//main sub-system class
class GameLogic
{
public:
	GameLogic(PhysicsMain* pm,AudioMain* am, MainManager* mm);
	~GameLogic();

	UnitManager*& getUnitManager() { return um; };
	UnitSelector* getUnitSelector() { return us; };


	CameraManager* getCameraManager() { return cm; };

	//update all game logic here
	void update(float dt);

	PhysicsMain* getPhysics() { return physics; };

	void shutdown();


	void addSpawnLocation(SpawnPoint spawnPoint) { spawnPoints.push_back(spawnPoint); };

	void addSpawnLocation(std::string unitType, float spawnx, float spawny, int squadsize) { spawnPoints.push_back(SpawnPoint(this->um, unitType, 1000, {spawnx,spawny}, squadsize)); };


	void initNextLevel(std::string level);


	void checkWinConditions(float dt);

	void cleanSpawns();


	bool getInGame() { return inGame; };

	void setInGame(bool inGame) { this->inGame = inGame; };

	
	BuildingManager*& getBuildingManager() { return bm; };


	void updateGUI(float dt);

	void init();

	void setLevel(int level) { this->level = level; };
	int getLevel() { return level; };

	int getResources() { return resources; };
	void setResources(int resources) { this->resources = resources; };

private:
	GameSetup* gs;
	UnitManager* um;
	UnitSelector* us;
	CameraManager* cm;
	PhysicsMain* physics;
	MainManager* mm;
	AudioMain* audio;
	Map* map;
	GUIManager gm;
	std::vector<SpawnPoint> spawnPoints;
	BuildingManager* bm;
	ProjectileManager* pm;

	float timeToBeat = 100;
	
	int level;

	int resources;

	bool inGame = false;

	bool lost = false;
	bool win = false;
};

