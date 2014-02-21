#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "ResourceManager.hpp"

class ShopMenu : public Menu{
public:
	enum mMenuItems{
		BACK,
		POWERUP_EXPLOSIVE,
		POWERUP_MAGNET,
		POWERUP_INVINCIBLE,
		POWERUP_SLOWDOWN,
		NUM_CHOICES
	};
	ShopMenu();
	~ShopMenu();

	unsigned int getMaxItems();
private:

};