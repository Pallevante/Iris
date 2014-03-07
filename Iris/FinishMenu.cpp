#include "FinishMenu.hpp"


FinishMenu::FinishMenu() :
Menu(
/* Knappvektorernas ordning är NORMAL, SELECTED, ACTIVE */
Menu::ButtonVector{
	/* Knapparna måste läggas in i rätt ordning som de ska visas på menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/next.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/shop.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/main.png"))
},
Menu::ButtonVector{
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/next.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/shop_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/main.png"))
},
Menu::ButtonVector{
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/next.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/shop.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/main.png"))
	},
	"", 0)
		{
	setButtonPosition(NEXT_LEVEL, sf::Vector2f(45, 33));
	setButtonPosition(SHOP, sf::Vector2f(45, 120));
	setButtonPosition(MAIN_MENU, sf::Vector2f(45, 250));
};

FinishMenu::~FinishMenu(){

};

unsigned int FinishMenu::getMaxItems(){
	return NUM_CHOICES;
}

void FinishMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
		up();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case FinishMenu::NEXT_LEVEL:
			World::mLevelInt = World::mLevelInt + 1;
			World::currentState = World::PLAYING;
			return;
			break;
		case FinishMenu::SHOP:
			World::currentState = World::INSHOP;
			return;
			break;
		case FinishMenu::MAIN_MENU:
			ResourceManager::getSound("resource/sounds/menu/menuback.ogg").play();
			World::currentState = World::INMENU;
			return;
			break;
		default:
			break;
		}
	}
}