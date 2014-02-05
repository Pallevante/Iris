#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Menu.hpp"

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

	int getMaxItems();
private:
};