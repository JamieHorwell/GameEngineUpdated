#include "GUIElementResource.h"






GUIElementResource::GUIElementResource(const unsigned int handle, const string & name, const string & path)
	:ResourceBase(handle, name, path)
{
}

GUIElementResource::~GUIElementResource()
{
}

void GUIElementResource::init(std::string text, sf::Vector2f pos, sf::Vector2f size, sf::Sprite background, sf::Font font, float fontSize)
{
	textToDisplay = text;
	posToDisplay = pos;
	this->size = size;
	this->background = background;
	this->font = font;
	this->fontSize = fontSize;
}
