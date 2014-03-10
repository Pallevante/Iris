#include "FinishMenu.hpp"


FinishMenu::FinishMenu() :
Menu(
/* Knappvektorernas ordning är NORMAL, SELECTED, ACTIVE */
Menu::ButtonVector{
	/* Knapparna måste läggas in i rätt ordning som de ska visas på menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_nextlevel.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_shop.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_mainmenu.png"))
},
Menu::ButtonVector{
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_nextlevel_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_shop_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_mainmenu_selected.png"))
},
Menu::ButtonVector{
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_nextlevel.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_shop.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_mainmenu.png"))
	},
	"resource/textures/backgrounds/finishmenu.png", 0)
		{
	setButtonPosition(NEXT_LEVEL, sf::Vector2f(109, 462));
	setButtonPosition(SHOP, sf::Vector2f(437, 462));
	setButtonPosition(MAIN_MENU, sf::Vector2f(750, 462));
};

FinishMenu::~FinishMenu(){

};

unsigned int FinishMenu::getMaxItems(){
	return NUM_CHOICES;
}

void FinishMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left){
		up();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case FinishMenu::NEXT_LEVEL:
			World::mLevelInt = World::mLevelInt + 1;
			World::currentState = World::LOAD;
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