#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "../GameLogic/Map.h"
class LevelXMLRead
{
public:
	LevelXMLRead();


	static void loadFile(std::string XMLfilename, Map* map);


	~LevelXMLRead();
};

