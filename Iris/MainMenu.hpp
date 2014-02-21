#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Menu.hpp"
#include "World.hpp"

class MainMenu : public Menu{
public:
	enum mMenuItems{ 
		PLAY, 
		SHOP,
		QUIT, 
		NUM_CHOICES 
	};
	MainMenu();
	~MainMenu();

	unsigned int getMaxItems();
	void input(sf::Event& event);
private:
};