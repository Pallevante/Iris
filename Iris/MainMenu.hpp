#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "ResourceManager.hpp"

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
private:
};