#include "BuildingTemplateResource.h"




BuildingTemplateResource::BuildingTemplateResource(const unsigned int handle, const string & name, const string & path)
	: ResourceBase(handle,name,path)
{
}

BuildingTemplateResource::~BuildingTemplateResource()
{
}

void BuildingTemplateResource::init(sf::Sprite buildingSprite, std::string unitType)
{
	this->buildingSprite = buildingSprite;
	this->unitType = unitType;
}
