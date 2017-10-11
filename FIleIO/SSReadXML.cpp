#include "SSReadXML.h"
#include <SFML\Graphics.hpp>
#include <iostream>

SSReadXML::SSReadXML()
{
}


SSReadXML::~SSReadXML()
{
}


void SSReadXML::LoadTileSet(std::string XMLfilename, SpriteSheetResource* resource)
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

	std::string imagePath;
	std::string subTextureName;
	sf::Vector2i subTextPos;
	sf::Vector2i subTextDimensions;


	rapidxml::xml_node<>* root = doc.first_node();

	//get the imagepath of the spritesheet
	imagePath = root->first_attribute("imagePath")->value();
	sf::Image spriteSheetImage;
	sf::RenderTexture spriteSheetTexture;
	spriteSheetImage.loadFromFile("../Resources/medievalRTS_spritesheet.png");

	sf::Texture* fullText = new sf::Texture;
	fullText->loadFromFile("../Resources/medievalRTS_spritesheet.png");
	//pass this texture to our spriteSheetResource
	resource->setTexture(fullText);




	rapidxml::xml_node<>* subtexture = root->first_node("SubTexture");
	//loop through all subtextures and grab them
	sf::Image subImage;
	while (subtexture) {
		//grab texture name
		subTextureName = subtexture->first_attribute("name")->value();

		//grab texture positions
		subTextPos.x = atoi(subtexture->first_attribute("x")->value());
		subTextPos.y = atoi(subtexture->first_attribute("y")->value());

		//width of texture
		subTextDimensions.x = atoi(subtexture->first_attribute("width")->value());
		//height of texture
		subTextDimensions.y = atoi(subtexture->first_attribute("height")->value());

		//now perform adding this subtexture to some manager....





		//insert into our map
		resource->insertSprite(subTextureName, sf::Sprite(*fullText, sf::IntRect(subTextPos.x, subTextPos.y, subTextDimensions.x, subTextDimensions.y)));


		subtexture = subtexture->next_sibling();



	}

}
