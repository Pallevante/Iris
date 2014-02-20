#include "ShopMenu.hpp"

ShopMenu::ShopMenu() :
Menu(
Menu::ButtonVector{
	/* Knapparna måste läggas in i rätt ordning som de visas på menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime.png")),
}, "resource/textures/backgrounds/shop.png", 0)
{
	mButtonVector[BACK]->setPosition(1000, 500);
	mButtonVector[POWERUP_POWERSHOT]->setPosition(100, 100);
	mButtonVector[POWERUP_MAGNET]->setPosition(100, 400);
	mButtonVector[POWERUP_INVINCIBLE]->setPosition(300, 100);
	mButtonVector[POWERUP_SLOWTIME]->setPosition(300, 400);
	setActive(mCurrentMenuItem);
}

ShopMenu::~ShopMenu(){

};

unsigned int ShopMenu::getMaxItems(){
	return NUM_CHOICES;
}

void ShopMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
		up();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case ShopMenu::BACK:
			ResourceManager::getSound("resource/sounds/menuback.ogg").play();
			World::currentState = World::INMENU;
			return;
			break;
		case ShopMenu::POWERUP_POWERSHOT:

			return;
			break;
		default:
			break;
		}
	}
}