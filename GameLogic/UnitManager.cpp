#include "UnitManager.h"
#include <iostream>
#include "VectorCalc.h"



UnitManager::UnitManager(PhysicsMain* pm, AudioMain* am, MainManager* mm)
{
	this->pm = pm;
	this->am = am;
	this->unitInit.setmm(mm);
	
}


UnitManager::~UnitManager()
{
}


void UnitManager::updateUnitsPositions()
{
	//give renderobjs new physobjs positions
	for (int i = 0; i < units.size(); ++i) {
		float x = units.at(i)->getPhysObj()->getBody()->GetPosition().x;
		float y = units.at(i)->getPhysObj()->getBody()->GetPosition().y;
		units.at(i)->updatePos(sf::Vector2f(x,y));
	}
}

void UnitManager::updateUnitPos(Unit* u) {
	float x = u->getPhysObj()->getBody()->GetPosition().x;
	float y = u->getPhysObj()->getBody()->GetPosition().y;
	u->updatePos(sf::Vector2f(x,y));
}





void UnitManager::updateUnits()
{
	
	std::vector<Unit*>::iterator currentUnit;
	for (currentUnit = units.begin(); currentUnit != units.end();) {
		
		if ((*currentUnit)->getCurrentHealth() <= 0) {
			(*currentUnit)->getAudioComponent()->setToPlay(true);
			(*currentUnit)->getAudioComponent()->queueSoundToPlay("death", (*currentUnit)->getCurrentPos());
			(*currentUnit)->kill();
			currentUnit = units.erase(currentUnit);
			
		}
		else {


			count++;
				if(count > 150) {
				


					//check if unit can attack any other units
					for (Unit* um : units) {
						//check if in range, if so we can attack
						if (um != (*currentUnit)) {


							//units in agro range...
							if (um->getTeam() != (*currentUnit)->getTeam() && VectorCalc::getLength((*currentUnit)->getCurrentPos() - um->getCurrentPos()) < (*currentUnit)->getAgroRange() ) {
								if (VectorCalc::getLength((*currentUnit)->getCurrentPos() - um->getCurrentPos()) < VectorCalc::getLength((*currentUnit)->getCurrentPos() - (*currentUnit)->getTargetPos())) {
									(*currentUnit)->setTargetPos(um->getCurrentPos());
									(*currentUnit)->setPosToMove(true);
								}
								
							}



							//check if unit is in range
							if (VectorCalc::getLength((*currentUnit)->getCurrentPos() - um->getCurrentPos()) < (*currentUnit)->getRange()) {

								if (um->getCurrentHealth() > 0) {
									if (um->getTeam() != (*currentUnit)->getTeam()) {
										(*currentUnit)->attack(um);
										(*currentUnit)->getAudioComponent()->setToPlay(true);
										(*currentUnit)->getAudioComponent()->queueSoundToPlay("attack", (*currentUnit)->getCurrentPos());
									}
								}

							}

						}

					}
					count = 0;
				}
			



			if ((*currentUnit)->getPosToMove()) {

				sf::Vector2f distToTarget = (*currentUnit)->getTargetPos() - (*currentUnit)->getCurrentPos();

				VectorCalc::getLength(distToTarget);

				//very close to target pos
				if (VectorCalc::getLength(distToTarget) < 7) {
					(*currentUnit)->setPosToMove(false);
					(*currentUnit)->getPhysObj()->updateVelocity(0, 0);
				}

				//yes it has... get the direction vector
				sf::Vector2f dir = (*currentUnit)->getDirectionToMove();



				(*currentUnit)->getPhysObj()->getBody()->ApplyLinearImpulseToCenter(b2Vec2(dir.x * 100 , dir.y * 100 ), true);

				//check if unit it close to position it should be...
			}
			updateUnitPos((*currentUnit));
			//check units health
			++currentUnit;
		}

		
		
		
	}



}

void UnitManager::updateSelectedUnitTarget(sf::Vector2f targetPos)
{
	for (int i = 0; i < selectedUnits.size(); ++i) {
		//unit has new target to move to
		selectedUnits.at(i)->setPosToMove(true);
		//give unit the target
		selectedUnits.at(i)->setTargetPos(targetPos);

	}

}

void UnitManager::createUnit(std::string unitType, sf::Vector2f pos)
{
	
	Unit* newUnit = unitInit.createUnit(unitType,pos);
	units.push_back(newUnit);
	//add units comps to subsystems
	am->addAudioComponent(newUnit->getAudioComponent());
	Display::addRenderObj(newUnit->getRenderObj());
	pm->addPhysObj(newUnit->getPhysObj());
}

void UnitManager::removeUnit(Unit * um)
{
	//destory unit
	um->Delete();
	delete um;

}

void UnitManager::killAllUnits()
{
	std::vector<Unit*>::iterator currentUnit;
	for (currentUnit = units.begin(); currentUnit != units.end();) {

		(*currentUnit)->kill();
		currentUnit = units.erase(currentUnit);

	}
}

