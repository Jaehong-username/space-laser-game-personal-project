#pragma once

#include "Text.h"

class Menu
{
public:
	Menu(float width, float height);
	~Menu() {}

	void moveUp(sf::RenderTarget& target);
	void moveDown(sf::RenderTarget& target);

	void updateMenu();
	void renderMenu(sf::RenderTarget& target);

	//Getter
	int getSelectedMenu();

private:
	int selectedMenu;

	Text uiText; //Menu has an uiText. Composition - has a relationship!

	sf::Sprite images[5];
	sf::Texture texture[5]; //images that can be used for drawing
};

