#pragma once
#include "ResourceBase.h"
#include <string>
#include <SFML\Graphics.hpp>
#include <string>
class GUIElementResource
	:public ResourceBase
{
public:
	GUIElementResource(const unsigned int handle, const string& name, const string& path = "../Resources/");
	~GUIElementResource();

	void init(std::string text, sf::Vector2f pos, sf::Vector2f size, sf::Sprite background, sf::Font font, float fontSize);

	std::string getText() { return textToDisplay; };
	sf::Vector2f getPos() { return posToDisplay; };
	sf::Vector2f getSize() { return size; };
	sf::Sprite getSprite() { return background; };
	sf::Font getFont() { return font; };
	float getFontSize() { return fontSize; };



private:
	std::string textToDisplay;
	sf::Vector2f posToDisplay;
	sf::Vector2f size;
	sf::Sprite background;
	sf::Font font;
	float fontSize;
};

