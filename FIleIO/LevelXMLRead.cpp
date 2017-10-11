#include "LevelXMLRead.h"
#include "rapidxml.hpp"


LevelXMLRead::LevelXMLRead()
{
}

void LevelXMLRead::loadFile(std::string XMLfilename, Map* map)
{
	std::ifstream inFile(XMLfilename);


	if (!inFile) {
		throw "Could not load spritesheet: " + XMLfilename;
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

	//data to extract from xml file
	int tileXPos;
	int tileYPos;
	int tileSize;
	std::string solid;
	bool isSolid;
	std::string tileType;
	int mapWidth;
	int mapHeight;

	rapidxml::xml_node<>* root = doc.first_node();

	//get the imagepath of the spritesheet
	mapWidth = atoi(root->first_attribute("width")->value());
	mapHeight = atoi(root->first_attribute("width")->value());
	tileSize = atoi(root->first_attribute("tileSize")->value());
	map->init(mapWidth, mapHeight, tileSize);
	

	rapidxml::xml_node<>* mapTile = root->first_node("tile");
	//loop through all subtextures and grab them

	while (mapTile) {
		//grab maptile details
		tileXPos = atoi(mapTile->first_attribute("x")->value());
		tileYPos = atoi(mapTile->first_attribute("y")->value());
		tileType = mapTile->first_attribute("TileType")->value();
		solid = mapTile->first_attribute("solid")->value();
		 isSolid = (solid == "true") ? true : false;

		map->AddTile(tileXPos, tileYPos, tileType, isSolid);

		mapTile = mapTile->next_sibling();
	}

}


LevelXMLRead::~LevelXMLRead()
{
}
