#include "SoundXMLRead.h"
#include <iostream>
#include <fstream>
#include "rapidxml.hpp"
#include <SFML\Audio.hpp>


SoundXMLRead::SoundXMLRead()
{
}


SoundXMLRead::~SoundXMLRead()
{
}

void SoundXMLRead::loadSound(std::string XMLfilename, ResourceManager<SoundResource>* soundManager)
{
	std::ifstream inFile(XMLfilename);


	if (!inFile) {
		throw "Could not load sounds: " + XMLfilename;
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
	string soundID;
	string file;


	rapidxml::xml_node<>* root = doc.first_node();

	

	rapidxml::xml_node<>* soundDetails = root->first_node("sound");
	//loop through all sounds and grab them

	while (soundDetails) {
		//grab sound details
		soundID = soundDetails->first_attribute("soundid")->value();
		file = soundDetails->first_attribute("file")->value();

		


		//create resource in resource manager
		soundManager->Add(file);

		//now get that resource and init its fields, change sounds name to something more relevant
		soundManager->GetElement(file)->init(soundID);

		soundDetails = soundDetails->next_sibling();
	}
}
