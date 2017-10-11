#include "LevelDetailsXMLRead.h"
#include "rapidxml.hpp"
#include <iostream>
#include <fstream>
#include "../GameLogic/GameLogic.h"

LevelDetailsXMLRead::LevelDetailsXMLRead()
{
}


LevelDetailsXMLRead::~LevelDetailsXMLRead()
{
}

void LevelDetailsXMLRead::loadFile(std::string XMLfilename, GameLogic * gameLogic)
{
	std::ifstream inFile(XMLfilename);


	if (!inFile) {
		throw "Could not load levelDetails: " + XMLfilename;
	}

	std::string xmlDump;

	std::string line;
	while (std::getline(inFile, line)) {
		xmlDump += line;
	}
	std::vector<char> xmlData;
	xmlData = std::vector<char>(xmlDump.begin(), xmlDump.end());
	xmlData.push_back('\0');


	//parse document using RapidXML
	rapidxml::xml_document<> doc;

	doc.parse<rapidxml::parse_no_data_nodes>(&xmlData[0]);



	rapidxml::xml_node<>* root = doc.first_node();

	rapidxml::xml_node<>* spawnPoints = root->first_node("SpawnPoints");
	rapidxml::xml_node<>* spawnPoint = spawnPoints->first_node("SpawnPoint");
	std::string unitType;
	int maxCount;
	float spawnx;
	float spawny;
	int squadsize;

	while (spawnPoint) {
		unitType = spawnPoint->first_attribute("unitType")->value();
		maxCount = atoi(spawnPoint->first_attribute("maxCount")->value());
		spawnx = atoi(spawnPoint->first_attribute("spawnx")->value());
		spawny = atoi(spawnPoint->first_attribute("spawny")->value());
		squadsize = atoi(spawnPoint->first_attribute("squadsize")->value());

		gameLogic->addSpawnLocation(SpawnPoint(gameLogic->getUnitManager(), unitType, maxCount, {spawnx,spawny},squadsize));
		//gameLogic->addSpawnLocation(unitType, spawnx, spawny, squadsize);


		spawnPoint = spawnPoint->next_sibling();
	}

	rapidxml::xml_node<>* units = root->first_node("Units");
	rapidxml::xml_node<>* unit = units->first_node("Unit");
	std::string King;
	bool isKing;
	while (unit) {
		unitType = unit->first_attribute("unitType")->value();
		King = unit->first_attribute("king")->value();
		spawnx = atoi(unit->first_attribute("posx")->value());
		spawny = atoi(unit->first_attribute("posy")->value());
		gameLogic->getUnitManager()->createUnit(unitType, {spawnx,spawny});
		isKing = (King == "true") ? true : false;

		if (isKing) {
			gameLogic->getUnitManager()->setKing(gameLogic->getUnitManager()->getUnits().back());
			std::cout << "king created";
		}
		unit = unit->next_sibling();
	}

	rapidxml::xml_node<>* buildings = root->first_node("Buildings");
	rapidxml::xml_node<>* building = buildings->first_node("Building");
	std::string buildingType;
	while (building) {
		buildingType = building->first_attribute("buildingType")->value();
		spawnx = atoi(building->first_attribute("posx")->value());
		spawny = atoi(building->first_attribute("posy")->value());

		gameLogic->getBuildingManager()->addBuilding(buildingType, {spawnx,spawny});

		building = building->next_sibling();
	}


}
