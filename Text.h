#pragma once

#include "Entity.h"

class Text
{
public:
	Text();
	~Text();

	void updateTexts();
	void renderTexts(sf::RenderTarget& target);

	//Font object
	sf::Font font;

	//text
	sf::Text text;

private:

	void initFonts();
	void initTexts();
};

