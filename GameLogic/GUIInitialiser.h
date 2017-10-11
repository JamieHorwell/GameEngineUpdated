#pragma once
#include "GUIElement.h"
#include "../ResourceManager/MainManager.h"
#include <string>

class GUIInitialiser
{
public:
	GUIInitialiser();
	~GUIInitialiser();


	void init(MainManager* mm) { this->mm = mm; };

	GUIElement* createGUIElement(std::string GUIType);

private:
	MainManager* mm;
};

