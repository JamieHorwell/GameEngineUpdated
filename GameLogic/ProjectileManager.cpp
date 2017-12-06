#include "ProjectileManager.h"





ProjectileManager::ProjectileManager(PhysicsMain * pm)
{
}

ProjectileManager::~ProjectileManager()
{
}

void ProjectileManager::updateProjectiles()
{
	//move all projectiles (i.e. update positions based on physics)
	//check if projectiles have hit targets
	//check if projectiles are out of range

	std::vector<Projectile*>::iterator currentProjectile;
	for (currentProjectile = projectiles.begin(); currentProjectile != projectiles.end();) {
		updateProjectilePos((*currentProjectile));

		//target unit may be deleted
		if ((*currentProjectile)->getTargetUnit() && VectorCalc::getLength((*currentProjectile)->getTargetUnit()->getCurrentPos() - (*currentProjectile)->getPos()) < 1) {
			Unit* target = (*currentProjectile)->getTargetUnit();
			target->setCurrentHealth(target->getCurrentHealth() - (*currentProjectile)->getDamage());
			currentProjectile = projectiles.erase(currentProjectile);
		}
		else if (VectorCalc::getLength((*currentProjectile)->getTargetPos() - (*currentProjectile)->getPos()) < 0.5) {
			currentProjectile = projectiles.erase(currentProjectile);
		}

		currentProjectile++;
	}

}

void ProjectileManager::updateProjectilePos(Projectile * proj)
{
	float x = proj->getPhysObj()->getBody()->GetPosition().x;
	float y = proj->getPhysObj()->getBody()->GetPosition().y;
	proj->updatePos(sf::Vector2f(x, y));
}
