#pragma once
#include "ResourceBase.h"
#include <SFML\Graphics.hpp>
class FontResource :
	public ResourceBase
{
public:
	FontResource(const unsigned int handle, const std::string& name, const std::string& path = "../Resources/");
	~FontResource();

	sf::Font& getFont() { return font; };

private: 
	sf::Font font;
	
};

