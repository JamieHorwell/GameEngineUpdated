#pragma once
#include "ResourceBase.h"
#include <SFML\Graphics.hpp>
class UnitTemplateResource :
	public ResourceBase
{
public:
	inline UnitTemplateResource(const unsigned int handle, const std::string & name, const std::string & path) : ResourceBase(handle,name,path){
		m_name = name;
	};
	inline ~UnitTemplateResource() {
	};

	//used to initialise resource values
	void init(int range, float attackpower, int team, int maxHealth, float maxSpeed, sf::Sprite sprite, float agroRange);

	int getRange() { return range; };
	float getAp() { return attackpower; };
	int getTeam() { return team; };
	int getMaxHealth() { return maxHealth; };
	float getMaxSpeed() { return maxSpeed; };
	sf::Sprite getSprite() { return unitSprite; };

	float getAgroRange() { return agroRange; };

private:
	int range;
	float attackpower;
	float agroRange;
	int team;
	int maxHealth;
	float maxSpeed;
	sf::Sprite unitSprite;
	
};
