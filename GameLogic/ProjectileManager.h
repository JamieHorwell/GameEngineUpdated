#pragma once
#include "Projectile.h"
#include "../Physics/PhysicsMain.h"
class ProjectileManager
{
public:
	ProjectileManager(PhysicsMain* pm);
	~ProjectileManager();

	void updateProjectiles();


	void updateProjectilePos(Projectile * proj);

private:
	std::vector<Projectile*> projectiles;

};

