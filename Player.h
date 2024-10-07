#pragma once

#include "Entity.h"
#include "Laser.h"

class Player :public Entity{

public://Game() : uiMenu(videoMode.width = 800, videoMode.height = 800)
	Player(float width, float height)//: laser(this->position)
	{
		//Coloring the image of the object
		if (!texture.loadFromFile("playerShip1_blue.png"))
		{
			cout << "File loaded not successful!" << endl;
		}
		image.setTexture(texture);

		state = ALIVE;
		health = 100;
		//initial position
		this->position.x = width / 2;
		this->position.y = height / 1.5;

		this->movement.x = 20.f;
		this->movement.y = 20.f;

		image.setPosition(this->position);

		
		laser = nullptr;
		healthShape = nullptr;
		invincibleBufferTime = 200;
		createHealthBar(); //create heaalth Bar!
	}

	void shootLaser();
	virtual void updateMove(sf::RenderWindow& target) override;

	void updateLaser(sf::RenderWindow& target);
	void drawLaser(sf::RenderTarget& target);

	void loseHealthBar();
	void drawHealthBar(sf::RenderTarget& target);
	//Getter
	vector<Laser*>& getLaserVec();
	int getHealth();
	int getInvincibleBufferTime();
	//Setter
	void setHealth(int health);
	void setInvincibleBufferTime(int time);

private:
	
	//Composition Relationship!  The player has an ability to shoot multiple lasers to destroy enemies!
	Laser* laser; //if Laser laser as an objectit will be just an rectangular interestingly!
	vector<Laser*> laserVec;
	sf::CircleShape* healthShape;
	std::vector	<CircleShape*> healthBar;
	int invincibleBufferTime;
	void createHealthBar();
};

