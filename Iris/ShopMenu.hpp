#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Menu.hpp"

class ShopMenu : public Menu{
public:
	enum mMenuItems{
		BACK,
		NUM_CHOICES
	};
	ShopMenu();
	~ShopMenu();

	int getMaxItems();
private:

};