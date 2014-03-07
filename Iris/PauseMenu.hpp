#pragma once
#include "Menu.hpp"
#include "World.hpp"

class PauseMenu : public Menu{
public:
	enum mMenuItems{
		RESUME,
		RESTART,
		MAIN_MENU,
		NUM_CHOICES
	};
	PauseMenu();
	~PauseMenu();

	unsigned int getMaxItems();
	void input(sf::Event& event);
private:

};