#include "GameSetup.h"
#include "../Renderer/Display.h"
#include "UnitHealthBar.h"
#include "../FIleIO/LevelXMLRead.h"


GameSetup::GameSetup(UnitManager* um, PhysicsMain* pm, MainManager* mm, CameraManager*& cm, Map *& map)
{
	this->mm = mm;
	this->physicsMain = pm;
	
	//load map
	InitMap(map,"../Resources/TestLevel.xml");
	cm = new CameraManager(map->getWidth());

	
	
	
	this->unitManager = um;
	
}


GameSetup::~GameSetup()
{
}


void GameSetup::InitMap(Map*& map, std::string levelFile)
{
	map = new Map(mm, physicsMain);
	LevelXMLRead::loadFile(levelFile, map);
	physicsMain->initMapBorders(map->getWidth(),map->getHeight());

}


