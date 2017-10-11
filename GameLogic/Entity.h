#pragma once
#include "../Renderer/RenderComponent.h"
/*Entity will represent anything that is drawable and has a physics component, all ingame objects will then extend from this
in some way, contains reference to various sub-system components*/
class Entity
{
public:
	Entity();
	~Entity();

	inline int getId() { return id; };
	inline void setId(int id) { this->id = id; };




private:
	int id;

};

