#include "ShopMenu.hpp"

ShopMenu::ShopMenu() :
Menu(
Menu::ButtonVector{
	/* Knapparna m�ste l�ggas in i r�tt ordning som de visas p� menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png"))
}, "resource/textures/backgrounds/shop.png", 0)
{
	mButtonVector[0]->setPosition(100, 100);
	setActive(mCurrentMenuItem);
}

ShopMenu::~ShopMenu(){

};

unsigned int ShopMenu::getMaxItems(){
	return NUM_CHOICES;
}