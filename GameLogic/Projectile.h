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

	sf::Vector2f getPos() { return pos; };
	sf::Vector2f getTargetPos() { return targetpos; };
	Unit* getTargetUnit() { return targetUnit; };


	PhysicsComponent* getPhysObj() { return physicsObj; };

	void updatePos(sf::Vector2f newPos);

	float getDamage() { return damage; };


private: 
	sf::Vector2f pos;

	//the position the target was at when the 
	sf::Vector2f targetpos;

	float damage;
	float speed;

	PhysicsComponent* physicsObj;
	RenderComponent* renderObj;

	Unit* targetUnit;
	
};

