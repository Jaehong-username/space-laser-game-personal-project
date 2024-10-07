#include "Menu.h"


Menu::Menu(float width, float height)
{
	printf("Width: %f\n", width);
	printf("Height: %f", height);
	texture[0].loadFromFile("Title.png");				//The title 
	images[0].setTexture(texture[0]);
	images[0].setPosition(width / 12, 100);

	texture[1].loadFromFile("Start.png");				//The start
	images[1].setTexture(texture[1]);
	images[1].setPosition(width / 6, 400);

	texture[2].loadFromFile("Exit.png");				//Exit
	images[2].setTexture(texture[2]);
	images[2].setPosition(width / 6, 600);

	texture[3].loadFromFile("StartHold.png");			//Start png change when player user mouse is over it
	images[3].setTexture(texture[3]);
	images[3].setPosition(width / 6, 400);

	texture[4].loadFromFile("ExitHold.png");			//Exit png change when player user moust is over it
	images[4].setTexture(texture[4]);
	images[4].setPosition(width / 6, 600);

	selectedMenu = 1;
}

void Menu::moveUp(sf::RenderTarget& target)
{
	//to make sure that we dont wanna go below zero  by continuously pressing up keyword!
	if (selectedMenu > 1) {
		selectedMenu--;
		printf("Selected Menu: %d\n", selectedMenu);
		target.draw(images[1]);
		
	}
}

void Menu::moveDown(sf::RenderTarget& target)
{
	if (selectedMenu < 2) {
		selectedMenu++;
		printf("Selected Menu: %d\n", selectedMenu);
		target.draw(images[2]);
	}
}


void Menu::updateMenu()
{
	uiText.updateTexts();
}

void Menu::renderMenu(sf::RenderTarget& target)
{
	for (int i = 0; i < 3; i++){
		target.draw(images[i]);

		if (selectedMenu == 1) {
			target.draw(images[3]);
		}
		else if (selectedMenu == 2) {
			target.draw(images[4]);
		}
	}
}

int Menu::getSelectedMenu()
{
	return selectedMenu;
}
