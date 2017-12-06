#pragma once
#include "Entity.h"
#include "../Physics/PhysicsComponent.h"
#include "../Audio/AudioComponent.h"
#include "UnitHealthBar.h"

class UnitTemplateResource;


class Unit	
	: public Entity
{
public:
	Unit();
	Unit(UnitTemplateResource* unitTemplate, sf::Vector2f startPos);

	~Unit();

	void updatePos(sf::Vector2f newPos);

	PhysicsComponent* getPhysObj() { return physicsObj; };
	 RenderComponent* getRenderObj() const { return renderObj; };

	void setPosToMove(bool setPosToMove) { this->posToMove = setPosToMove; };
	bool getPosToMove() { return posToMove; };

	void setTargetPos(sf::Vector2f targetPos) { this->targetPos = targetPos; };
	sf::Vector2f getTargetPos() { return this->targetPos; };

	sf::Vector2f getDirectionToMove(); 

	sf::Vector2f getCurrentPos() { return currentpos; };

	void addHealthBar(UnitHealthBar healthbar);

	void kill();

	float getCurrentHealth() { return currentHealth; };

	void setCurrentHealth(float newHealth) { currentHealth = newHealth; 
	this->getHealthBar().update(currentHealth, maxHealth);
	};

	UnitHealthBar getHealthBar() const { return myHealthBar; };


	void attack(Unit* unitToAttack);

	int getRange() { return this->range; };

	void Delete();

	int getTeam() { return team; };

	AudioComponent* getAudioComponent() { return audioObj; };

	float getAgroRange() { return agroRange; };


protected:
	int team;
	int range = 5;
	float attackPower = 0.001;
	float maxHealth;
	float currentHealth;
	float agroRange;
	bool posToMove = false;
	sf::Vector2f targetPos;

	//components for various subsystems
	RenderComponent* renderObj;
	PhysicsComponent* physicsObj;
	AudioComponent* audioObj;


	UnitHealthBar myHealthBar;
	sf::Vector2f currentpos;
	sf::Vector2f currentVel;
	float maxVel;
};

