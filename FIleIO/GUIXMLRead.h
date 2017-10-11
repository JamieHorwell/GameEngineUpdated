#pragma once
#include <string>
#include "../ResourceManager/ResourceManager.h"
#include "../ResourceManager/TextureResource.h"
#include "../ResourceManager/GUIElementResource.h"
#include "../ResourceManager/FontResource.h"
class GUIXMLRead
{
public:
	GUIXMLRead();
	~GUIXMLRead();



	static void loadFile(std::string XMLfilename, ResourceManager<GUIElementResource>* GUIManager, ResourceManager<TextureResource>* TextureManager, ResourceManager<FontResource>* fontManager);
};

