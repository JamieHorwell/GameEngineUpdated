#include "UnitHealthBar.h"
#include <iostream>


UnitHealthBar::UnitHealthBar()
{
}

UnitHealthBar::UnitHealthBar(RenderComponent* currentHealth, RenderComponent* backgroundHealth)
{
	//setup healthbar render components
	this->currentHealth = currentHealth;
	this->backgroundHealth = backgroundHealth;
}


UnitHealthBar::~UnitHealthBar()
{
}

void UnitHealthBar::update(float currentHealth, float maxHealth)
{
	if (currentHealth > 0) {
		float ratio = currentHealth / maxHealth;
		int width = (int)(ratio * 20);
		this->currentHealth->getsprite()->setTextureRect(sf::IntRect({ 0,0 }, { width,3 }));
	}
}

UnitHealthBar & UnitHealthBar::operator=(const UnitHealthBar & h)
{
	this->currentHealth = new RenderComponent(h.getCurrentHealth()->getSpriteObj());
	this->backgroundHealth = new RenderComponent(h.getBackgroundHealth()->getSpriteObj());
	return *this;
}
	
