#pragma once
#include "ResourceBase.h"
#include <SFML\Graphics.hpp>
#include <map>

/*sprite sheet contains large texture with all textures game units/structures/map tiles reference*/
class SpriteSheetResource :
	public ResourceBase
{
public:
	SpriteSheetResource(const unsigned int handle, const string& name, const string& path = "../Resources/");
	~SpriteSheetResource();


	void insertSprite(std::string name, sf::Sprite sprite);

	void setTexture(sf::Texture *spriteSheetText) { this->spriteSheetText = spriteSheetText; };

	sf::Sprite getSprite(string name);


private:
	std::map<string, sf::Sprite> spriteSheetMapper;
	sf::Texture* spriteSheetText;


};

