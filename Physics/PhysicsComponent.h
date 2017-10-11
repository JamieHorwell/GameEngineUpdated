#pragma once
#include <Box2D\Box2D.h>


/*Class contains relevant information for a physics object to be placed in box2dworld*/

class PhysicsComponent
{
public:
	PhysicsComponent(b2Vec2 position, b2Vec2 dimensions, float maxVelocity, bool isStatic = false);
	~PhysicsComponent();

	//box2d components
	b2BodyDef getBodyDef() { return bodyDef; };
	b2Body* getBody() { return objBody; };
	b2Fixture* getFixture() { return fixture; };
	b2FixtureDef getFixtureDef() { return fixtureDef; };


	//place physics object into box2d world
	void setObjBody(b2World* world) { objBody = world->CreateBody(&bodyDef); };
	void setFixture(b2World* world) { if (objBody != nullptr) fixture = objBody->CreateFixture(&fixtureDef); };


	void updateVelocity(float x, float y);

	void SetPos(b2Vec2 pos) { bodyDef.position = pos; };

	void Delete() { toDelete = true; };
	bool getDelete() { return toDelete; };

	float getMaxVel() { return maxVel; };

	bool getStatic() { return isStatic; };

private:
	bool isStatic;
	bool toDelete = false;
	float maxVel;

	b2Body* objBody = nullptr;
	b2Fixture* fixture = nullptr;
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2PolygonShape boxShape;
};

