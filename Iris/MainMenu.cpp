#include "MainMenu.hpp"

MainMenu::MainMenu() :
Menu(
Menu::ButtonVector{ 
	/* Knapparna m�ste l�ggas in i r�tt ordning som de visas p� menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/play.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/shop.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/quit.png"))
}, "resource/textures/backgrounds/menu.png", 0)
{
	/* Definera position p� knapparna h�r */
	mButtonVector[0]->setPosition(100, 100);
	mButtonVector[1]->setPosition(100, 300);
	mButtonVector[2]->setPosition(100, 500);
	/* K�rs nu f�r att uppdatera positionen p� aktiv knapp-symbolen */
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
			return;
			break;
		default:
			break;
		}
	}
}