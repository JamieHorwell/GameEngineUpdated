#pragma once
#include "../Renderer/RenderComponent.h"

class UnitHealthBar
{
public:
	UnitHealthBar();
	UnitHealthBar(RenderComponent* currentHealth, RenderComponent* backgroundHealth);
	~UnitHealthBar();

	//called everytime action takes place which damages parent unit
	void update(float currentHealth, float maxHealth);

	void setPosition(sf::Vector2f unitPosition) {
		currentHealth->setPos(unitPosition + sf::Vector2f(0, -15));
		backgroundHealth->setPos(unitPosition + sf::Vector2f(0, -15));
	}

	 RenderComponent* getCurrentHealth() const { return currentHealth; };
	 RenderComponent* getBackgroundHealth() const { return backgroundHealth; };

	UnitHealthBar& operator= (const UnitHealthBar& h);
	

private: 
	RenderComponent* currentHealth;
	RenderComponent* backgroundHealth;
};

