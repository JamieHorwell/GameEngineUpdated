#include "GUIInitialiser.h"



GUIInitialiser::GUIInitialiser()
{
}


GUIInitialiser::~GUIInitialiser()
{
}

GUIElement * GUIInitialiser::createGUIElement(std::string GUIType)
{
	GUIElementResource* GUITemplate = mm->GUIManager.GetElement(GUIType);
	GUIElement*  newGUIElement = new GUIElement(GUITemplate);
	return newGUIElement;
}
