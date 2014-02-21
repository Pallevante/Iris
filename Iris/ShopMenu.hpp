#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "World.hpp"
#include "ResourceManager.hpp"


class ShopMenu : public Menu{
public:
	enum mMenuItems{
		POWERUP_POWERSHOT,
		POWERUP_MAGNET,
		POWERUP_INVINCIBLE,
		POWERUP_SLOWTIME,
		BACK,
		NUM_CHOICES
	};
	ShopMenu();
	~ShopMenu();

	unsigned int getMaxItems();
	void input(sf::Event& event);
private:

};