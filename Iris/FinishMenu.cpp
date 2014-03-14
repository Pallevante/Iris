#include "FinishMenu.hpp"


FinishMenu::FinishMenu() :
Menu(
/* Knappvektorernas ordning är NORMAL, SELECTED, ACTIVE */
Menu::ButtonVector{
	/* Knapparna måste läggas in i rätt ordning som de ska visas på menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_mainmenu.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_shop.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_nextlevel.png")),
},
Menu::ButtonVector{
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_mainmenu_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_shop_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_nextlevel_selected.png")),
},
Menu::ButtonVector{
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_mainmenu.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_shop.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/finish_nextlevel.png")),
	},
	"resource/textures/buttons/menu/finish_bg.png", ACTION)
		{

	setButtonPosition(MAIN_MENU, sf::Vector2f(280, 441));
	setButtonPosition(SHOP, sf::Vector2f(535, 441));
	setButtonPosition(ACTION, sf::Vector2f(786, 441));
};

FinishMenu::~FinishMenu(){

};

unsigned int FinishMenu::getMaxItems(){
	return NUM_CHOICES;
}

void FinishMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
		up();
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case FinishMenu::ACTION:
			if (World::currentState == World::INFINISHMENU) {
				World::mLevelInt = World::mLevelInt + 1;
				World::currentState = World::LOAD;
			}
			else if (World::currentState == World::INFAILEDFINISHMENU)
				World::currentState = World::RESTARTING;
			
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

void FinishMenu::updateActionButton(){
	if (World::currentState == World::INFAILEDFINISHMENU){
		setButtonTexture(ACTION, "resource/textures/buttons/menu/finish_retry.png", "resource/textures/buttons/menu/finish_retry_selected.png", "resource/textures/buttons/menu/finish_retry.png");
	}
	if (World::currentState == World::INFINISHMENU){
		setButtonTexture(ACTION, "resource/textures/buttons/menu/finish_nextlevel.png", "resource/textures/buttons/menu/finish_nextlevel_selected.png", "resource/textures/buttons/menu/finish_nextlevel.png");
	}
}