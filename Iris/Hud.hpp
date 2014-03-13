#pragma once
#include <sstream>
#include "World.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
class Hud
{
public:
	Hud();
	~Hud();
	void setText();
	void drawText(sf::RenderWindow &window);
	void updateProgressBar();
private:
	sf::Font font;
	sf::Text goldText;
	std::stringstream goldAmount;
	//sf::RectangleShape progressBar;
	//float progress;
	//sf::Color progressColor;

	sf::Sprite progressBar;
	sf::Sprite fillTexture;
	
	sf::IntRect currentProgressRect;

};

