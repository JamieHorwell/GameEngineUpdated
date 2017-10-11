#include "GUIElement.h"
#include "../ResourceManager/GUIElementResource.h"
#include <iostream>



GUIElement::GUIElement(GUIElementResource * GUITemplate)
{
	this->textToDisplay.setString(GUITemplate->getText());
	this->textToDisplay.setCharacterSize(GUITemplate->getFontSize());
	fontt.loadFromFile("../Resources/Arial.ttf");
	this->textToDisplay.setFont(fontt);
	//this->textToDisplay.setCharacterSize(GUITemplate->getFontSize());
	this->pos = GUITemplate->getPos();
	box = GUITemplate->getSprite();
	box.setPosition(pos);
	box.setScale(0.5, 0.2);
	textToDisplay.setPosition(box.getPosition());
	std::cout << textToDisplay.getFont();
	this->textToDisplay.setFillColor(sf::Color::Black);
	this->guiDrawable = new GUIDrawable(&box);
	this->guiDrawable->addChild(new GUIDrawable(&textToDisplay));
	
}




GUIElement::~GUIElement()
{
	guiDrawable->Delete();
}

void GUIElement::Delete()
{
	guiDrawable->Delete();
}