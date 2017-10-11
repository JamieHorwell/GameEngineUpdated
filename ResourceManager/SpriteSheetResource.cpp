#include "SpriteSheetResource.h"
#include <sstream>
#include "../FIleIO/SSReadXML.h"




SpriteSheetResource::SpriteSheetResource(const unsigned int handle, const string & name, const string & path)
	:ResourceBase(handle, name, path)
{
	//we have the filepath 
	stringstream s;
	s << path << name;

	//now use XMLReader to load spritesheet textures
	SSReadXML::LoadTileSet(s.str(), this);
}

SpriteSheetResource::~SpriteSheetResource()
{
}

void SpriteSheetResource::insertSprite(std::string name, sf::Sprite sprite)
{
	spriteSheetMapper.insert(std::make_pair(name, sprite)); 
}

sf::Sprite SpriteSheetResource::getSprite(string name)
{
	return spriteSheetMapper.at(name);
}
