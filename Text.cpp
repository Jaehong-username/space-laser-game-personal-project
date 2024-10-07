#include "Text.h"

Text::Text()
{
	//make sure we load the fonts first before init texts!
	initFonts();
	initTexts();
}

Text::~Text()
{
}

void Text::updateTexts()
{
	//declare a stream to hold strings
	std::stringstream ss;

	ss << "Welcome to the Adventure Game!" << std::endl;
	//uiText.setPosition(100, 100);
	text.setString(ss.str());

}

void Text::renderTexts(sf::RenderTarget& target)
{
	target.draw(text);
}

void Text::initFonts()
{
	//loading the content from the given file and checking if loaded correctly
	if (!font.loadFromFile("Diphylleia-Regular.ttf")) {
		std::cout << "Failed to load the font from the file" << std::endl;
	}
}

void Text::initTexts()
{
	text.setFont(font); //the font we initialized using initFonts()
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Green);
	text.setString("Initiailzing a text");
}
