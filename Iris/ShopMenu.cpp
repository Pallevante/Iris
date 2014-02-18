#include "ShopMenu.hpp"

ShopMenu::ShopMenu() :
Menu(
Menu::ButtonVector{
	/* Knapparna måste läggas in i rätt ordning som de visas på menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powerup.png"), sf::IntRect(0, 0, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().x / 2, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().y / 2)),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powerup.png"), sf::IntRect(0, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().y / 2, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().x / 2, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().y / 2)),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powerup.png"), sf::IntRect(ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().x / 2, 0, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().x / 2, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().y / 2)),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powerup.png"), sf::IntRect(ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().x / 2, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().y / 2, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().x / 2, ResourceManager::getTexture("resource/textures/buttons/powerup.png").getSize().y / 2)),
}, "resource/textures/backgrounds/shop.png", 0)
{
	mButtonVector[0]->setPosition(100, 100);
	mButtonVector[1]->setPosition(400, 100);
	mButtonVector[2]->setPosition(400, 400);
	mButtonVector[3]->setPosition(900, 100);
	mButtonVector[4]->setPosition(900, 400);
	setActive(mCurrentMenuItem);
}

ShopMenu::~ShopMenu(){

};

unsigned int ShopMenu::getMaxItems(){
	return NUM_CHOICES;
}