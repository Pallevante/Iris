#include "MainMenu.hpp"

MainMenu::MainMenu() :
Menu(
Menu::ButtonVector{ 
	/* Knapparna måste läggas in i rätt ordning som de visas på menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/play.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/play_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/shop.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/shop_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/quit.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/quit_selected.png"))
}, "resource/textures/backgrounds/menu.png", 0)
{
	/* Definera position på knapparna här */
	mButtonVector[PLAY * 2]->setPosition(100, 100);
	mButtonVector[PLAY * 2 + 1]->setPosition(100, 100);
	mButtonVector[SHOP * 2]->setPosition(100, 300);
	mButtonVector[SHOP * 2 + 1]->setPosition(100, 300);
	mButtonVector[QUIT * 2]->setPosition(100, 500);
	mButtonVector[QUIT * 2 + 1]->setPosition(100, 500);
	setInactive(PLAY);
	setInactive(SHOP);
	setInactive(QUIT);

	/* Körs nu för att uppdatera aktiv knapp-symbolen */
	setActive(mCurrentMenuItem);
}

MainMenu::~MainMenu(){
};

unsigned int MainMenu::getMaxItems(){
	return NUM_CHOICES;
}

void MainMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
		up();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		down();
	}

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case MainMenu::PLAY:
			ResourceManager::getSound("resource/sounds/menuselect.ogg").play();
			World::currentState = World::PLAYING;
			return;
			break;
		case MainMenu::SHOP:
			ResourceManager::getSound("resource/sounds/menuselect.ogg").play();
			World::currentState = World::INSHOP;
			return;
			break;
		case MainMenu::QUIT:
			ResourceManager::getSound("resource/sounds/menuback.ogg").play();
			World::currentState = World::EXIT;
			return;
			break;
		default:
			break;
		}
	}
}