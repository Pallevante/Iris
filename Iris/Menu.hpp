#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class Menu{
public:
	typedef std::vector<sf::Sprite*> ButtonVector;
	Menu(ButtonVector buttons, const std::string& background, unsigned int currentMenuItem);
	~Menu();

	void drawMenu(sf::RenderWindow& window);
	unsigned int getCurrentMenuItem();
	void setCurrentMenuItem(unsigned int i);
	void setActive(unsigned int i);
	void up();
	void down();

	virtual unsigned int getMaxItems() = 0;
protected:
	ButtonVector mButtonVector;
	sf::Sprite mActiveButton;
	sf::Sprite mBackground;
	unsigned int mCurrentMenuItem;
};