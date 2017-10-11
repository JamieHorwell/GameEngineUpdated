#pragma once
#include "Entity.h"
#include "../Physics/PhysicsComponent.h"
#include "../Audio/AudioComponent.h"
#include "../ResourceManager/BuildingTemplateResource.h"

class Building :
	public Entity
{
public:
	Building();
	Building(BuildingTemplateResource* BuildingTemplate, sf::Vector2f position);
	~Building();


	void spawnSoldier() { this->spawnSoldiers++; };

	void Delete();

	bool getDelete() { return toDelete; };
	void setDelete() { this->toDelete = true; }


	int getSpawnSoldiers() { return spawnSoldiers; };
	void decrementSpawn() { spawnSoldiers--; };

	std::string getUnitType() { return unitType; };

	sf::Vector2f getPos() { return currentpos; };

	RenderComponent* getRenderObj() const { return renderObj; };

private:
	//components for various subsystems
	RenderComponent* renderObj;
	PhysicsComponent* physicsObj;
	AudioComponent* audioObj;

	int spawnSoldiers;



	bool toDelete = false;

	sf::Vector2f currentpos;

	std::string unitType;
};

