#pragma once
#include "Menu.hpp"
#include "World.hpp"

class FinishMenu : public Menu{
public:
	enum mMenuItems{
		NEXT_LEVEL,
		SHOP,
		MAIN_MENU,
		NUM_CHOICES
	};
	FinishMenu();
	~FinishMenu();

	unsigned int getMaxItems();
	void input(sf::Event& event);
private:

};