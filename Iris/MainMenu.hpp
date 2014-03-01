#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "World.hpp"
#include "ResourceManager.hpp"


class MainMenu : public Menu{
public:
	enum mMenuItems{ 
		PLAY, 
		LEVEL,
		SHOP,
		SOUND,
		MUSIC,
		EXIT, 
		NUM_CHOICES 
	};
	MainMenu();
	~MainMenu();

	unsigned int getMaxItems();
	void input(sf::Event& event);
private:
};