#include "PhysicsMain.h"
#include <iostream>


PhysicsMain::PhysicsMain()
{
	
}


PhysicsMain::~PhysicsMain()
{
	//destroy all physics objects
	for (int i = 0; i < physObjs.size(); ++i) {
		DestroyPhysObj(physObjs[i]);
	}
	physObjs.clear();
	//get rest of bodies in box2d world and destroy them before deleting 
}

//initialise box2d world with no gravity
void PhysicsMain::init()
{

	b2Vec2 grav(0, 0);
	mapObj = new b2World(grav);

}

//intialise map borders so box2d objects do not go out of bounds
void PhysicsMain::initMapBorders(float maxX, float maxY)
{
	float bottomx = maxX;
	float bottomy = maxY;


	//bottom border
	b2BodyDef borderDef;
	borderDef.position.Set(0,bottomy);
	b2Body* borderBody = mapObj->CreateBody(&borderDef);

	b2EdgeShape borderEdge;
	borderEdge.Set(b2Vec2(0,0),b2Vec2(bottomx, 0));
	borderBody->CreateFixture(&borderEdge, 0.0f);

	//top border
	borderDef.position.Set(0, 0);
	borderBody = mapObj->CreateBody(&borderDef);

	borderEdge.Set(b2Vec2(0,0), b2Vec2(bottomx,0));
	borderBody->CreateFixture(&borderEdge, 0.0f);

	//left border
	borderDef.position.Set(0, 0);
	borderBody = mapObj->CreateBody(&borderDef);

	borderEdge.Set(b2Vec2(0, 0), b2Vec2(0, bottomy));
	borderBody->CreateFixture(&borderEdge, 0.0f);


	//right border
	borderDef.position.Set(bottomx,0);
	borderBody = mapObj->CreateBody(&borderDef);

	borderEdge.Set(b2Vec2(0, 0), b2Vec2(0, bottomy));
	borderBody->CreateFixture(&borderEdge, 0.0f);

}

void PhysicsMain::updatePhysics()
{
	//check max velocities?


	std::vector<PhysicsComponent*>::iterator currentObj;
	for (currentObj = physObjs.begin(); currentObj != physObjs.end(); ) {
		//check if object needs to be deleted
		if ((*currentObj)->getDelete()) {
			DestroyPhysObj((*currentObj));
		currentObj = physObjs.erase(currentObj);

	}
		else {
			
			b2Vec2 vel = (*currentObj)->getBody()->GetLinearVelocity();


			//apply damping if above max velocity
			if (vel.LengthSquared() > (*currentObj)->getMaxVel()) {
				(*currentObj)->getBody()->SetLinearDamping(0.9);
			}
			else {
				(*currentObj)->getBody()->SetLinearDamping(0.15);
			}
			++currentObj;
		}
	}



	//update all bodies in the world with a fixed time step
	mapObj->Step(0.010, 4, 2);
	

}

//init obj in box2d world
void PhysicsMain::addPhysObj(PhysicsComponent * physObj)
{
	
	physObj->setObjBody(mapObj);
	physObj->setFixture(mapObj);
	physObjs.push_back(physObj);
	

	
}

void PhysicsMain::DestroyPhysObj(PhysicsComponent * physObj)
{
	//now delete physicsComponents
	delete physObj;
}

void PhysicsMain::clean()
{
	std::vector<PhysicsComponent*>::iterator currentObj;
	for (currentObj = physObjs.begin(); currentObj != physObjs.end(); ) {
		//check if object needs to be deleted
		DestroyPhysObj((*currentObj));
		currentObj = physObjs.erase(currentObj);
	}
}
