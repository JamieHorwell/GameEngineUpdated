#include "GameLogic.h"






GameLogic::GameLogic(PhysicsMain* pm, AudioMain* am, MainManager *mm)
{
	//begin the game
	this->physics = pm;
	this->audio = am;
	this->um = new UnitManager(pm,am,mm);
	this->pm = new ProjectileManager(pm);
	this->bm = new BuildingManager(um, mm);
	this->us = new UnitSelector(um);
	this->mm = mm;
	gm.init(mm);
	gm.AddGUIElement("title");
	gm.AddGUIElement("start");
	
}

GameLogic::~GameLogic()
{
}

void GameLogic::update(float dt)
{
	if (inGame) {
		checkWinConditions(dt);
		if (um->getKing()->getCurrentHealth() < 0) {
			lost = true;
		}
		if (!win) {
			//update all game logic
			updateGUI(dt);
			pm->updateProjectiles();
			um->updateUnits();
			bm->update();
			for (int i = 0; i < spawnPoints.size(); ++i) {
				spawnPoints.at(i).update();
			}
		}
	}
	
}

void GameLogic::initNextLevel(std::string level)
{
	
	//clean up level
	um->killAllUnits();
	bm->destroyAllBuildings();
	physics->clean();
	map->clean();
	cleanSpawns();

	//load next level
	gs->InitMap(*&map,"../Resources/Level2.xml");
	//init units etc on level
	LevelDetailsXMLRead::loadFile("../Resources/Level2Details.xml",this);

}

void GameLogic::checkWinConditions(float dt)
{
	if (dt > timeToBeat) {
		win = true;
		initNextLevel("2");
		this->level = 2;
		timeToBeat = 250;
		win = false;
	}
	else if (um->getKing()->getCurrentHealth() < 0) {
		lost = true;
	}
}

void GameLogic::cleanSpawns()
{
	std::vector<SpawnPoint>::iterator currentSpawn;
	for (currentSpawn = spawnPoints.begin(); currentSpawn != spawnPoints.end();) {
		currentSpawn = spawnPoints.erase(currentSpawn);

	}
}

void GameLogic::updateGUI(float dt)
{
	std::stringstream time;
	time << "time: " << (timeToBeat - dt);
	gm.getGUIObjs().at(0)->changeText(time.str());
	std::stringstream levelGUI;
	levelGUI << "level: " << level;
	gm.getGUIObjs().at(2)->changeText(levelGUI.str());

	std::stringstream resourceGUI;
	resourceGUI << "resources: " << resources;
	gm.getGUIObjs().at(3)->changeText(resourceGUI.str());
}

void GameLogic::init()
{
	//delete all guiObjs
	for (GUIElement* gEl : gm.getGUIObjs()) {
		gEl->Delete();
	}
	gm.getGUIObjs().clear();
	this->level = 1;
	this->gs = new GameSetup(um, physics, mm, *&cm, *&map);
	LevelDetailsXMLRead::loadFile("../Resources/TestLevelDetails.xml", this);
	gm.AddGUIElement("time");
	gm.AddGUIElement("build");
	gm.AddGUIElement("level");
	gm.AddGUIElement("resource");
	resources = 100;
}
