#pragma once
#include "GUIInitialiser.h"
#include "../Renderer/Display.h"
class GUIManager
{
public:
	GUIManager();
	~GUIManager();

	void init(MainManager* mm);

	void AddGUIElement(std::string guiType);

	std::vector<GUIElement*>& getGUIObjs();




private:
	GUIInitialiser Gi;
	std::vector<GUIElement*> guiObjs;
};

