#include "ShopMenu.hpp"

ShopMenu::ShopMenu() :
Menu(
/* Knappvektorernas ordning är NORMAL, SELECTED, ACTIVE */
Menu::ButtonVector{
		/* Knapparna måste läggas in i rätt ordning som de ska visas på menyn */
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png")),
	},
Menu::ButtonVector{
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back_selected.png"))
	},
Menu::ButtonVector{
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png")),
	},
"resource/textures/backgrounds/shop.png", 0)
{
	setButtonPosition(POWERUP_POWERSHOT, sf::Vector2f(45, 33));
	setButtonPosition(POWERUP_MAGNET, sf::Vector2f(72, 295));
	setButtonPosition(POWERUP_INVINCIBLE, sf::Vector2f(211, 41));
	setButtonPosition(POWERUP_SLOWTIME, sf::Vector2f(226, 291));
	setButtonPosition(BACK, sf::Vector2f(1000, 500));
};

ShopMenu::~ShopMenu(){

};

unsigned int ShopMenu::getMaxItems(){
	return NUM_CHOICES;
}

void ShopMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
		up();
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case ShopMenu::BACK:
			ResourceManager::getSound("resource/sounds/menu/menuback.ogg").play();
			World::currentState = World::INMENU;
			return;
			break;
		case ShopMenu::POWERUP_POWERSHOT:
			ResourceManager::getSound("resource/sounds/menu/purchase_successful.ogg").play();
			return;
			break;
		case ShopMenu::POWERUP_MAGNET:
			ResourceManager::getSound("resource/sounds/menu/purchase_failed.ogg").play();
			return;
			break;
		case ShopMenu::POWERUP_INVINCIBLE:
			ResourceManager::getSound("resource/sounds/menu/purchase_failed.ogg").play();
			return;
			break;
		case ShopMenu::POWERUP_SLOWTIME:
			ResourceManager::getSound("resource/sounds/menu/purchase_failed.ogg").play();
			return;
			break;
		default:
			break;
		}
	}
}