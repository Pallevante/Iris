#pragma once
#include "Menu.hpp"
#include "World.hpp"

class FinishMenu : public Menu{
public:
	enum mMenuItems{
		MAIN_MENU,
		SHOP,
		ACTION,
		NUM_CHOICES
	};
	FinishMenu();
	~FinishMenu();

	unsigned int getMaxItems();
	void input(sf::Event& event);
private:

};