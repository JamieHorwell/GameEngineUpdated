#pragma once
#include "Entity.h"
#include "Unit.h"
#include "../Physics/PhysicsComponent.h"
#include "../Renderer/RenderComponent.h"

class ProjectileTemplateResource;


class Projectile :
	public Entity
{
public:
	Projectile(ProjectileTemplateResource &projResource, sf::Vector2f pos, sf::Vector2f targetpos, Unit &targetUnit);
	~Projectile();


	

private: 
	sf::Vector2f pos;
	sf::Vector2f targetpos;

	float damage;
	float speed;

	PhysicsComponent* physicsObj;
	RenderComponent* renderObj;

	Unit* targetUnit;
	
};

