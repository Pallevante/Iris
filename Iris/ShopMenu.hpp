#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "ResourceManager.hpp"

class ShopMenu : public Menu{
public:
	enum mMenuItems{
		BACK,
		NUM_CHOICES
	};
	ShopMenu();
	~ShopMenu();

	unsigned int getMaxItems();
private:

};