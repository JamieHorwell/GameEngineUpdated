#pragma once
#include "ResourceManager.h"
#include "TextureResource.h"
#include "SoundResource.h"
#include "ResourceBase.h"
#include "FontResource.h"
#include "SpriteSheetResource.h"
#include "UnitTemplateResource.h"
#include "GUIElementResource.h"
#include "BuildingTemplateResource.h"


class MainManager
{
public:
	//include managers for all types of resources here
	MainManager();
	~MainManager();

	void initialise();
	void shutdown();

	ResourceManager<TextureResource> textureManager;
	ResourceManager<SpriteSheetResource> SSManager;
	ResourceManager<SoundResource> soundManager;
	ResourceManager<UnitTemplateResource> unitTemplateManager;
	ResourceManager<FontResource> fontManager;
	ResourceManager<GUIElementResource> GUIManager;
	ResourceManager<BuildingTemplateResource> buildingManager;

};

