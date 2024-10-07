#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream> // easily c++  let create a long string with different data types

using std::vector;
using sf::CircleShape;
using sf::Color;
using sf::Sprite;
using sf::Vector2f;

using std::cin;
using std::cout;
using std::endl;

using std::vector;

typedef enum state {
	DEAD, ALIVE
}State;

class Entity
{
public:
	
	// Pure virtual function to make Entity an abstract class
	virtual void updateMove(sf::RenderWindow& target) = 0;
	// Virtual destructor to ensure proper cleanup of derived classes
	virtual ~Entity() = default;

	//getter
	sf::Sprite getImage();

protected: //derived classes can still access it but not outside of classes.

	State state;
	int health;
	sf::Vector2f position;  // Position of movement in an entity
	sf::Vector2f movement; //The amount of movement in an entity

	sf::Sprite image;
	sf::Texture texture; //images that can be used for drawing
};

