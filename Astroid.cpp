#include "Astroid.h"

void Astroid::updateMove(sf::RenderWindow& target)
{
	image.move(0, +movement.y);
	position.y += movement.y;
}

bool Astroid::checkAstroidOut(sf::RenderWindow& target)
{
	return (position.y > target.getSize().y);
}


