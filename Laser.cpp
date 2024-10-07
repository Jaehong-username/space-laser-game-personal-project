#include "Laser.h"
#include "Astroid.h"
void Laser::updateMove(sf::RenderWindow& target)
{
	image.move(0, -movement.y);
	position.y -= movement.y;
}

bool Laser::checkLaserOut()
{
	return (position.y < 0);
}

bool Laser::checkLaserCollision(Astroid& astroid)
{
	return (image.getGlobalBounds().intersects(astroid.getImage().getGlobalBounds()));
}

/*
if (laserVec[i].getGlobalBounds().intersects(Application::getEnemyVec()[j].getGlobalBounds()) && invincibleTime >= 100)
{
	laserVec.erase(laserVec.begin() + i);
	Application::getEnemyVec().erase(Application::getEnemyVec().begin() + j);
	return true; //break;     
}
*/