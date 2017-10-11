#pragma once
#include "rapidxml.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <SFML\Graphics.hpp>
#include "../ResourceManager/SpriteSheetResource.h"
class SSReadXML
{
public:
	SSReadXML();
	~SSReadXML();



	static void LoadTileSet(std::string filename, SpriteSheetResource* resource);
};

