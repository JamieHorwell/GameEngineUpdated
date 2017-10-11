#pragma once
#include "Projectile.h"
#include "../Physics/PhysicsMain.h"
class ProjectileManager
{
public:
	ProjectileManager(PhysicsMain* pm);
	~ProjectileManager();

	void updateProjectiles();

private:
	std::vector<Projectile*> projectiles;

};

