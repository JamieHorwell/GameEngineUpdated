#pragma once
#include "ResourceBase.h"
#include <SFML\Graphics.hpp>
class ProjectileResource:
	public ResourceBase
{
public:

	ProjectileResource(const unsigned int handle, const std::string &name, const std::string &path);
	~ProjectileResource();



private:
	float attackpower;
	sf::Sprite projectileSprite;
};

