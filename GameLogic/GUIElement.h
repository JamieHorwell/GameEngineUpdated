#pragma once
#include "../Renderer/RenderComponent.h"
#include <string>
#include "../Renderer/GUIDrawable.h"

class GUIElementResource;


class GUIElement
{
public:
	
	GUIElement(GUIElementResource* GUITemplate);
	~GUIElement();

	
	GUIDrawable* getGUIDrawable() { return guiDrawable; };


	void event();

	void Delete();

	void changeText(std::string newText) { textToDisplay.setString(newText); };





private:
	
	GUIDrawable* guiDrawable;
	sf::Text textToDisplay;
	sf::Vector2f pos;
	sf::Font fontt;
	sf::Sprite box;
};

