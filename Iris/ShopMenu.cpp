#include "ShopMenu.hpp"

ShopMenu::ShopMenu() :
Menu(
Menu::ButtonVector{
	/* Knapparna måste läggas in i rätt ordning som de visas på menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/buttons/back.png"))
}, "resource/backgrounds/shop.png", 0)
{
	mButtonVector[0]->setPosition(100, 100);
	setActive(mCurrentMenuItem);
}

ShopMenu::~ShopMenu(){

};

int ShopMenu::getMaxItems(){
	return NUM_CHOICES;
}