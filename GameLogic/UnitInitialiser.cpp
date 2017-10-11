#include "UnitInitialiser.h"
#include "../ResourceManager/MainManager.h"


UnitInitialiser::UnitInitialiser()
{
	
}


UnitInitialiser::~UnitInitialiser()
{
}

Unit* UnitInitialiser::createUnit(string unit, sf::Vector2f pos)
{

	UnitTemplateResource* unitTemplate = mm->unitTemplateManager.GetElement(unit);
	Unit*  newUnit = new Unit(unitTemplate,pos);
	newUnit->addHealthBar(standardBar);
	return newUnit;
}

void UnitInitialiser::setmm(MainManager * mm)
{
	this->mm = mm;
	RenderComponent* backgroundHealthBar = new RenderComponent(mm->textureManager.GetElement("BackgroundHealthBar.png")->getTexture());
	RenderComponent* currentHealthBar = new RenderComponent(mm->textureManager.GetElement("CurrentHealthBar.png")->getTexture());
	standardBar = UnitHealthBar(currentHealthBar, backgroundHealthBar);
}

