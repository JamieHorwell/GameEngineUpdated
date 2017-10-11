#include "MainManager.h"
#include "../FIleIO/GUIXMLRead.h"

MainManager::MainManager()
{


}


MainManager::~MainManager()
{
}

void MainManager::initialise()
{
	//initialise all resource managers using file locations

	
	//stray textures that arent in spritesheet... TODO: load them  in batch from a xml file like other resources
	textureManager.Add("BackgroundHealthBar.png");
	textureManager.Add("CurrentHealthBar.png");
	textureManager.Add("bricks.png");

	//stray fonts
	fontManager.Add("Arial.ttf");

	//add the spritesheet, this will then load in from  file
	SSManager.Add("medievalRTS_spritesheet.xml");
	buildingManager.Add("Barracks");
	buildingManager.GetElement("Barracks")->init(SSManager.GetElement("medievalRTS_spritesheet.xml")->getSprite("medievalStructure_20.png"),"medievalUnit_03.png");


	GUIXMLRead::loadFile("../Resources/GUIElements.xml", &GUIManager, &textureManager, &fontManager);
}

void MainManager::shutdown()
{
	//cleanup all resource managers
}
