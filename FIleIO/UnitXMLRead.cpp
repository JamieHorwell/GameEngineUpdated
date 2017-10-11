#include "UnitXMLRead.h"
#include "rapidxml.hpp"


UnitXMLRead::UnitXMLRead()
{
}


UnitXMLRead::~UnitXMLRead()
{
}

void UnitXMLRead::loadFile(std::string XMLfilename, ResourceManager<UnitTemplateResource>* UTM, ResourceManager<SpriteSheetResource>* SSM)
{
	std::ifstream inFile(XMLfilename);


	if (!inFile) {
		throw "Could not load unitTemplates: " + XMLfilename;
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
	string spriteSheet;
	int team;
	std::string unitType;
	int health;
	float attackPower;
	int range;
	float maxSpeed;
	float agroRange;


	rapidxml::xml_node<>* root = doc.first_node();

	spriteSheet = root->first_attribute("spriteSheet")->value();

	rapidxml::xml_node<>* unitDetails = root->first_node("unit");
	//loop through all subtextures and grab them

	while (unitDetails) {
		//grab maptile details
		team = atoi(unitDetails->first_attribute("team")->value());
		unitType = unitDetails->first_attribute("unitType")->value();
		health = atoi(unitDetails->first_attribute("health")->value());
		attackPower = atof(unitDetails->first_attribute("attackPower")->value());
		range = atoi(unitDetails->first_attribute("range")->value());
		maxSpeed = atof(unitDetails->first_attribute("maxSpeed")->value());
		agroRange = atof(unitDetails->first_attribute("agroRange")->value());

		//get the relevant sprite from the spriteSheet
		sf::Sprite sprite = SSM->GetElement(spriteSheet)->getSprite(unitType);


		//create resource in resource manager
		UTM->Add(unitType);
		//now get that resource and init its fields
		
		UTM->GetElement(unitType)->init(range,attackPower,team,health,maxSpeed, sprite, agroRange);

		unitDetails = unitDetails->next_sibling();
	}


}
