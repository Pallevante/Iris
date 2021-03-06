#pragma once
#include "Menu.hpp"
#include "World.hpp"

class SelectLevelMenu: public Menu{
public:
	SelectLevelMenu();
	~SelectLevelMenu();
	virtual unsigned int getMaxItems();
	virtual void input(sf::Event &event);
	enum SelectButtons
	{
		BACK,
		USA,
		BRAZIL,
		EUROPE,
		NUM_CHOICES
	};

};

