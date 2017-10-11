#include "GUIManager.h"



GUIManager::GUIManager()
{
	
}


GUIManager::~GUIManager()
{
}

void GUIManager::init(MainManager * mm)
{
	Gi.init(mm);
}

void GUIManager::AddGUIElement(std::string guiType)
{
	GUIElement* newElement = Gi.createGUIElement(guiType);
	
	Display::addGUIDrawable(newElement->getGUIDrawable());
	guiObjs.push_back(newElement);
}

std::vector<GUIElement*> GUIManager::getGUIObjs()
{
	return guiObjs;
}
