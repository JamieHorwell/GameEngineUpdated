#include "Projectile.h"





Projectile::Projectile(ProjectileTemplateResource & projResource, sf::Vector2f pos, sf::Vector2f targetpos, Unit & targetUnit)
{
}

Projectile::~Projectile()
{
}

void Projectile::updatePos(sf::Vector2f newPos)
{
	this->pos = newPos;
	this->renderObj->setPos(newPos);
}

