#pragma once
#include "ResourceBase.h"
#include <SFML\Graphics.hpp>
#include <stdio.h>
#include <tchar.h>
class TextureResource :
	public ResourceBase
{
public:
	TextureResource(const unsigned int handle, const string& name, const string& path = "../Resources/");
	~TextureResource();

	sf::Texture& getTexture() { return texture; };

private:
	sf::Texture texture;
};

