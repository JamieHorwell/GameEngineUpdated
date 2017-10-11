#include "UnitTemplateResource.h"
#include "SpriteSheetResource.h"




//UnitTemplateResource::UnitTemplateResource(const unsigned int handle, const std::string & name, const std::string & path)
//	:ResourceBase(handle,name,path)
//{
//	m_name = name;
//}
//
//UnitTemplateResource::~UnitTemplateResource()
//{
//}

void UnitTemplateResource::init(int range, float attackpower, int team, int maxHealth, float maxSpeed, sf::Sprite sprite, float agroRange)
{
	this->range = range;
	this->attackpower = attackpower;
	this->team = team;
	this->maxHealth = maxHealth;
	this->maxSpeed = maxSpeed;
	this->unitSprite = sprite;
	this->agroRange = agroRange;
}

