#include "ShopMenu.hpp"

ShopMenu::ShopMenu() :
Menu(
Menu::ButtonVector{
	/* Knapparna måste läggas in i rätt ordning som de visas på menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back_selected.png"))
}, "resource/textures/backgrounds/shop.png", 0)
{
	mButtonVector[POWERUP_POWERSHOT * 2]->setPosition(45, 33);
	mButtonVector[POWERUP_POWERSHOT * 2 + 1]->setPosition(45, 33);
	mButtonVector[POWERUP_MAGNET * 2]->setPosition(72, 295);
	mButtonVector[POWERUP_MAGNET * 2 + 1]->setPosition(72, 295);
	mButtonVector[POWERUP_INVINCIBLE * 2]->setPosition(211, 41);
	mButtonVector[POWERUP_INVINCIBLE * 2 +1]->setPosition(211, 41);
	mButtonVector[POWERUP_SLOWTIME * 2]->setPosition(226, 291);
	mButtonVector[POWERUP_SLOWTIME * 2 + 1]->setPosition(226, 291);
	mButtonVector[BACK * 2]->setPosition(1000, 500);
	mButtonVector[BACK * 2 + 1]->setPosition(1000, 500);
	setInactive(POWERUP_POWERSHOT);
	setInactive(POWERUP_MAGNET);
	setInactive(POWERUP_INVINCIBLE);
	setInactive(POWERUP_SLOWTIME);
	setInactive(BACK);

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
			ResourceManager::getSound("resource/sounds/purchase_successful.wav").play();
			return;
			break;
		case ShopMenu::POWERUP_MAGNET:
			ResourceManager::getSound("resource/sounds/purchase_successful.wav").play();
			return;
			break;
		case ShopMenu::POWERUP_INVINCIBLE:
			ResourceManager::getSound("resource/sounds/purchase_successful.wav").play();
			return;
			break;
		case ShopMenu::POWERUP_SLOWTIME:
			ResourceManager::getSound("resource/sounds/purchase_successful.wav").play();
			return;
			break;
		default:
			break;
		}
	}
}