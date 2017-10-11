#include "RenderComponent.h"
#include <iostream>



RenderComponent::RenderComponent(const sf::Sprite sprite)
{
	this->setsprite(sprite);
}



RenderComponent::RenderComponent(const sf::Texture &text)
{
	this->setTexture(text);
	
}

RenderComponent::RenderComponent(sf::Text text)
{
}



RenderComponent::RenderComponent()
{
}

RenderComponent::~RenderComponent()
{
	for (RenderComponent* c : children) {
		delete c;
	}
}

void RenderComponent::setPos(sf::Vector2f newPos) {
	sf::Vector2f posChange = newPos - sprite.getPosition();
	//update children position
	for (RenderComponent* child : children) {
		child->setPos(child->getPos() + posChange);
	}
	sprite.setPosition(newPos);
}

void RenderComponent::Delete()
{
	this->toDelete = true;
	for (RenderComponent* child : children) {
		child->Delete();
	}

}
