#pragma once
#include "PhysicsComponent.h"
#include <vector>

/*handles updating of all physics objects which reside in box2d world,
as well as storing pointers to all physics objects, managing when to delete
them*/

class PhysicsMain
{
public:
	PhysicsMain();
	~PhysicsMain();
	
	//setup world, pass in world co-ords
	void init();

	//initialise world edges
	void initMapBorders(float maxX, float maxY);



	void updatePhysics();

	void addPhysObj(PhysicsComponent* physObj);

	PhysicsComponent* getPhysicComp() { return physObjs.at(0); };
	
	void DestroyPhysObj(PhysicsComponent* physObj);


	void clean();


private:
	std::vector<PhysicsComponent*> physObjs;
	b2World* mapObj;
	
};

