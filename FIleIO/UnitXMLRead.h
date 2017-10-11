#pragma once
#include <string>
#include <fstream>
#include "../ResourceManager/UnitTemplateResource.h"
#include "../ResourceManager/SpriteSheetResource.h"
#include "../ResourceManager/ResourceManager.h"
class UnitXMLRead
{
public:
	UnitXMLRead();
	~UnitXMLRead();


	static void loadFile(std::string XMLfilename, ResourceManager<UnitTemplateResource>* UTM, ResourceManager<SpriteSheetResource>* SSM);
};

