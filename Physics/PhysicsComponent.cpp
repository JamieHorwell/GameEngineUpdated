#include "PhysicsComponent.h"





PhysicsComponent::PhysicsComponent(b2Vec2 position, b2Vec2 dimensions, float maxVelocity, bool isStatic)
{
	this->isStatic = isStatic;
	//setup bodyDef and fixtureDef
	bodyDef.fixedRotation = true;
	if (isStatic) {
		bodyDef.type = b2_staticBody;
	}
	else {
		bodyDef.type = b2_dynamicBody;
	}
	
	bodyDef.position.Set(position.x, position.y);

	
	boxShape.SetAsBox(dimensions.x /2, dimensions.y/2);

	fixtureDef.shape = &boxShape;
	if (!isStatic) {
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
	}
	else {
		fixtureDef.density = 0.0f;
		fixtureDef.friction = 1.0f;
	}
	

	this->maxVel = maxVelocity;
}

PhysicsComponent::~PhysicsComponent()
{
	objBody->DestroyFixture(fixture);
	objBody->GetWorld()->DestroyBody(objBody);
}

void PhysicsComponent::updateVelocity(float x, float y)
{
	this->getBody()->SetLinearVelocity(b2Vec2(x, y));
}



