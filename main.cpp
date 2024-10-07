
#include "Game.h"
#include "Menu.h"

int main(void) {

	
	//Init srand
	std::srand((time(NULL)));

	//Init Game engine
	Game game;

	//game loop
	while (game.getWindow().isOpen())
	{	
		//Poll events
		game.pollEvents();

		//update: within the update function it has the poll event func as well
		game.update();

		//render:  draw your game
		game.render();
	}

	//end of application
}