#pragma once

#include "Entity.h" //Linker Error Careful!!!   Player -> include Laser class and Laser -> include Player class!
#include "Astroid.h"
class Laser: public Entity //make sure to init for all members of Entity in the constructor!!
{
public:
	Laser(sf::Vector2f position) 
	{
		if (!texture.loadFromFile("laserBlue01.png")) {
			cout << "Laser File Not loaded successfully!" << endl;
		}
		
		state = ALIVE;
		health = 1;

		image.setTexture(texture);

		movement.x = 0.0f;
		movement.y = 5.0f;

		this->position = position;

		image.setPosition(position);

	}
	~Laser() {}

	virtual void updateMove(sf::RenderWindow& target) override;

	bool checkLaserOut();
	bool checkLaserCollision(Astroid& astroid);
private:
	

};

