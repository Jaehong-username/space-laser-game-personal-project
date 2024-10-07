#pragma once

#include "Text.h"
#include "Menu.h"
#include "Player.h"
#include "Astroid.h"
class Game
{
public:

	Game() : uiMenu(videoMode.width = 800, videoMode.height = 800)
	{
		initVariables();
		initWindow();

		if (gameStart == true) {
			//init the player!
		}

	}
	~Game() 
	{
		//Destruct it to prevent memory leaks
		if (player != NULL) { //if player has been init on the heap! delete this player
			delete player;
		}
		delete window;
	}

	void pollEvents();
	void update();
	void render();

	//Getter
	sf::RenderWindow& getWindow();

private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event; //default initailzies
	
	bool gameStart;
	int astroidTimeBuffer;

	//Composition Relationship: has a relationship!
	//Game Resources
	Text uiText;
	
	Menu uiMenu;
	Astroid* astroid;
	vector<Astroid*> astroidVec; //Game scrren has astroids not the player!
	Player* player;
	
	//Game Logic


	//Game object

	//some func you dont wanna access
	void initVariables();
	void initWindow();
	void initGame();
	
	void populateAstroid();
	void updateAstroids(sf::RenderWindow& target);
	void drawAstroids(sf::RenderTarget& target);

	//Check Collision
	void laserCollision();
	void playerCollision();

	void checkGameOver();
};

