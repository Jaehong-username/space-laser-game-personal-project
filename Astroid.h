#pragma once
#include "Entity.h"

typedef enum astroidColor{
	ORIGINAL, GREEN, YELLOW, BLUE
}AstroidColor;

class Astroid: public Entity
{
public:
	Astroid(sf::RenderWindow& target) {
		if (!texture.loadFromFile("meteorBrown_big1.png")) {
			cout << "Astroid File Not loaded successfully!" << endl;
		}
		image.setTexture(texture);
		astroidColor = rand() % 4;

		switch (astroidColor) {
		
		case GREEN:
			image.setColor(sf::Color::Green);
			break;
		case YELLOW:
			image.setColor(sf::Color::Yellow);
			break;
		case BLUE:
			image.setColor(sf::Color::Blue);
			break;
		}
		

		state = ALIVE;
		health = 1;

		

		movement.x = 0;
		movement.y = rand() % 7 + 2; //minimum velocity 2 to 8

		position.x = rand() % target.getSize().x;
		position.y = 0;

		image.setPosition(position);
	}
	~Astroid(){}

	virtual void updateMove(sf::RenderWindow& target) override;
	bool checkAstroidOut(sf::RenderWindow& target);

private:
	
	int astroidColor;
};

