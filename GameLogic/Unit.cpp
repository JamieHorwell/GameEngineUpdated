#include "Unit.h"
#include "VectorCalc.h"
#include <iostream>
#include "../ResourceManager/UnitTemplateResource.h"


Unit::Unit()
{
}

Unit::Unit(UnitTemplateResource * unitTemplate, sf::Vector2f startPos)
{
	this->team = unitTemplate->getTeam();
	this->attackPower = unitTemplate->getAp();
	this->maxHealth = unitTemplate->getMaxHealth();
	this->currentHealth = unitTemplate->getMaxHealth();
	this->range = unitTemplate->getRange();
	this->audioObj = new AudioComponent();
	this->renderObj = new RenderComponent(unitTemplate->getSprite());
	this->physicsObj = new PhysicsComponent(b2Vec2(startPos.x, startPos.y), b2Vec2(renderObj->getsprite()->getGlobalBounds().width , renderObj->getsprite()->getGlobalBounds().height ),unitTemplate->getMaxSpeed());
	this->updatePos(startPos);
	this->agroRange = unitTemplate->getAgroRange();

}


Unit::~Unit()
{
}

void Unit::updatePos(sf::Vector2f newPos)
{
	this->currentpos = newPos;
	this->renderObj->setPos(newPos);
}

sf::Vector2f Unit::getDirectionToMove()
{
	return VectorCalc::normalise(targetPos - currentpos);
}

void Unit::addHealthBar(UnitHealthBar healthbar)
{
	myHealthBar = healthbar;
	myHealthBar.setPosition(this->getCurrentPos());
	myHealthBar.update(currentHealth, maxHealth);
	this->getRenderObj()->addChild(myHealthBar.getBackgroundHealth());
	this->getRenderObj()->addChild(myHealthBar.getCurrentHealth());
}

//set components to nullptrs, sub systems will clean these up
void Unit::kill()
{
	//set components to be cleaned up by relevant subsystems

	//delete renderobj
	//delete physobj
	this->audioObj->Delete();
	this->physicsObj->Delete();
	this->renderObj->Delete();
	delete this;
}

void Unit::attack(Unit* unitToAttack) {
	//send sound off to audio
	unitToAttack->setCurrentHealth(unitToAttack->getCurrentHealth()-attackPower);
}


void Unit::Delete()
{
	this->audioObj->Delete();
	this->physicsObj->Delete();
	this->renderObj->Delete();
}
