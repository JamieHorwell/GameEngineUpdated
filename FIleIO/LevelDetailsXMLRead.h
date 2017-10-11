#pragma once
#include <string>

class GameLogic;

class LevelDetailsXMLRead
{
public:
	LevelDetailsXMLRead();
	~LevelDetailsXMLRead();

	static void loadFile(std::string XMLfilename, GameLogic* gameLogic);

};

