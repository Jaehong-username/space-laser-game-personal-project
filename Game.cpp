#include "Game.h"


void Game::pollEvents()
{
	//event polling
	while (window->pollEvent(event)) //while we are getting events from window we wanna save them in to vara event we created
	{
		//switch (event.type)  //what type of event it was and sends an event to the buffer
		if (event.type == sf::Event::Closed) {
			window->close();
		}

		else if (event.type == sf::Event::KeyPressed) {

			switch (event.key.code) {
			case sf::Keyboard::Escape:
				window->close();
				break;

			case sf::Keyboard::Up:
				uiMenu.moveUp(*window);
				break;

			case sf::Keyboard::Down:
				uiMenu.moveDown(*window);
				break;

			case sf::Keyboard::L:
				if (player != nullptr) {
					cout << "Shooting a laser!" << endl;
					player->shootLaser();
				}
				break;

			case sf::Keyboard::Return: //Enter
				switch (uiMenu.getSelectedMenu())
				{
				case 1:
					std::cout << "Start Button has been clicked! Let's start the game!" << std::endl;
					gameStart = true;
					initGame();
					break;
				case 2:
					std::cout << "Exit Button has been clicked! Closing the window" << std::endl;
					window->close();
					break;
				}
				break;
			}
		}
		
	
	}
}

sf::RenderWindow& Game::getWindow()
{
	return *window;
}

void Game::update()
{
	uiText.updateTexts();
	uiMenu.updateMenu();

	if (gameStart == true) {

		//Player Update
		if (player != nullptr) {
			player->updateMove(*window);
			player->updateLaser(*window);

			//Checking Collision
			laserCollision(); //Check the laser collision
			playerCollision(); //check the player collision

			//Decrement the timer
			if (player->getInvincibleBufferTime() > 0) {
				player->setInvincibleBufferTime(player->getInvincibleBufferTime() - 1);
			}
			
			checkGameOver();

		}

		//Astroid Update
		//Update astroid Time Buffer!
		if (astroidTimeBuffer == 0) {
			//Make a new astroid
			populateAstroid();
			astroidTimeBuffer = 100;
		}
		else {
			astroidTimeBuffer--;
		}

		updateAstroids(*window);
		

	}

	

	
	

}

void Game::render()
{
	window->clear(sf::Color(0, 0, 0, 255)); //RGB alpha  alpha is transparency
	//clear old frame for not overlapp with the previous frame clear it with the blue color

	//draw game objects
	uiText.renderTexts(*window);

	if (gameStart == false) {
		uiMenu.renderMenu(*window);
	}

	else //Game Started!!
	{
		//When running the game, draw a player object
		window->draw((*player).getImage());
		player->drawLaser(*window);
		drawAstroids(*window);
		player->drawHealthBar(*window);
	}

	//tell app that window is done drawing
	window->display(); 
}


void Game::initVariables()
{
	window = nullptr;
	gameStart = false;
	astroidTimeBuffer = 100;

	player = nullptr;
	astroid = nullptr;
}

void Game::initWindow()
{
	//Already defined it!
	//videoMode.width = 800;
	//videoMode.height = 800;
	videoMode.getDesktopMode();

	window = new sf::RenderWindow(videoMode/*sf::VideoMode(800, 600)*/, "Welcome to Adventure Game!");
	window->setFramerateLimit(144); //60 or 30;
	
}

//precondition! if gameStart == true
void Game::initGame()
{
	cout << "A player has been initialized!" << endl;
	player = new Player(window->getSize().x, window->getSize().y);
}

void Game::populateAstroid()
{
	astroid = new Astroid(*window); //allocate space on the heap
	astroidVec.push_back(astroid);
}

void Game::laserCollision()
{
	if (player != NULL) { //if a player exists in the game

		for (int i = 0; i < player->getLaserVec().size(); i++)
		{
			for (int j = 0; j < this->astroidVec.size(); j++)
			if (player->getLaserVec()[i]->checkLaserCollision(*astroidVec[j]))
			{
				cout << "Laser hit the astroid!" << endl;
				delete astroidVec[j];
				delete player->getLaserVec()[i];
				astroidVec.erase(astroidVec.begin() + j);
				player->getLaserVec().erase(player->getLaserVec().begin() + i); //remove that laser out of the vector
				
				cout << "Laser Destroyed!" << endl;
				cout << "Astroid destroyed!" << endl;
			}

		}

	}
	
}

void Game::playerCollision()
{
	if (player != nullptr) {
		for (int i = 0; i < this->astroidVec.size(); i++) {
			if (player->getImage().getGlobalBounds().intersects(astroidVec[i]->getImage().getGlobalBounds()) && player->getInvincibleBufferTime() == 0) {
				cout << "The Player has been hit by an astroid! Lose one health bar!" << endl;
				player->setHealth(player->getHealth() - 10); // - 10 Health!
				player->loseHealthBar();
				cout << "Player Health: " << player->getHealth() << endl;
				//restore the time buffer
				player->setInvincibleBufferTime(200);
			}
		}
	}
}

void Game::checkGameOver()
{
	if (player != nullptr) {
		if (player->getHealth() == 0) {
			cout << "Player Health is 0. Destroyed!" << endl;
			system("pause");
			window->close();
		}
	}
}


void Game::updateAstroids(sf::RenderWindow& target) 
{
	for (int i = 0; i < astroidVec.size(); i++)
	{
		astroidVec[i]->updateMove(target);
		if (astroidVec[i]->checkAstroidOut(target)) { //check if the laser is out of the scrren
			delete astroidVec[i]; //to prevent memory leaks
			astroidVec.erase(astroidVec.begin() + i); //remove that laser out of the vector
			cout << "Astroid out of the screen!" << endl;
		}
	}
}


void Game::drawAstroids(sf::RenderTarget & target)
{
	for (int i = 0; i < astroidVec.size(); i++)
	{
		target.draw(astroidVec[i]->getImage());
	}
}



