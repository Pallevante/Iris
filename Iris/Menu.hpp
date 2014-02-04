#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Menu{
public:
//	typedef std::vector<sf::Sprite*> ButtonVector;
	//Menu();
	//~Menu();

	virtual int getCurrentMenuItem() = 0;
	virtual int getMaxItems() = 0;
private:/*
	ButtonVector mButtonVector;
	sf::Sprite mBackground;
	enum mMenuItems;
	int mCurrentMenuItem;
	*/
};