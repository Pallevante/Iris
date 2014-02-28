#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class Menu{
public:
	typedef std::vector<sf::Sprite*> ButtonVector;
	enum ButtonState { NORMAL, SELECTED, ACTIVE };
	Menu(ButtonVector buttons, ButtonVector buttons_selected, ButtonVector buttons_active, const std::string& background, unsigned int currentMenuItem);
	~Menu();

	void drawMenu(sf::RenderWindow& window);
	unsigned int getCurrentMenuItem();

	void setCurrentMenuItem(unsigned int i);
	void setSelected(unsigned int i);
	void setUnselected(unsigned int i);
	void setActive(unsigned int i);
	void setInactive(unsigned int i);
	void setButtonPosition(unsigned int i, sf::Vector2f position);
	void up();
	void down();

	virtual unsigned int getMaxItems() = 0;
	virtual void input(sf::Event &event) = 0;
protected:
	ButtonVector mButtonVector;
	ButtonVector mButtonSelectedVector;
	ButtonVector mButtonActiveVector;
	sf::Sprite mBackground;
	unsigned int mCurrentMenuItem;
};