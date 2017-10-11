#include "GUIXMLRead.h"
#include "rapidxml.hpp"
#include <fstream>


GUIXMLRead::GUIXMLRead()
{
}


GUIXMLRead::~GUIXMLRead()
{
}

void GUIXMLRead::loadFile(std::string XMLfilename, ResourceManager<GUIElementResource>* GUIManager, ResourceManager<TextureResource>* TextureManager, ResourceManager<FontResource>* fontManager)
{
	std::ifstream inFile(XMLfilename);


	if (!inFile) {
		throw "Could not load GUIElements: " + XMLfilename;
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
	std::string name;
	float x;
	float y;
	std::string text;
	std::string font;
	int fontSize;
	std::string texture;
	int size;
	


	rapidxml::xml_node<>* root = doc.first_node();

	
	rapidxml::xml_node<>* elementDetails = root->first_node("GUIelement");
	//loop through all subtextures and grab them

	while (elementDetails) {
		//grab maptile details
		name = elementDetails->first_attribute("name")->value();
		x = atof(elementDetails->first_attribute("x")->value());
		y = atof(elementDetails->first_attribute("y")->value());
		text = elementDetails->first_attribute("textToDisplay")->value();
		font = elementDetails->first_attribute("font")->value();
		fontSize = atoi(elementDetails->first_attribute("fontSize")->value());
		texture = elementDetails->first_attribute("texture")->value();
		size = atoi(elementDetails->first_attribute("size")->value());

		//get the relevant sprite from the textureManager
		sf::Sprite sprite(TextureManager->GetElement(texture)->getTexture());

		sf::Font fontToUse = fontManager->GetElement(font)->getFont();
		//create resource in resource manager
		
		GUIManager->Add(name);

		

		////now get that resource and init its fields

		GUIManager->GetElement(name)->init(text,sf::Vector2f(x,y),sf::Vector2f(size,size),sprite,fontToUse,fontSize);

		elementDetails = elementDetails->next_sibling();
	}
}
