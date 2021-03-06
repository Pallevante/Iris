#include "PauseMenu.hpp"

PauseMenu::PauseMenu() :
Menu(
/* Knappvektorernas ordning �r NORMAL, SELECTED, ACTIVE */
Menu::ButtonVector{
	/* Knapparna m�ste l�ggas in i r�tt ordning som de ska visas p� menyn */
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_resume.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_restart.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_main.png"))
},
Menu::ButtonVector{
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_resume_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_restart_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_main_selected.png"))
},
Menu::ButtonVector{
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_resume.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_restart.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/pause_main.png"))
	},
	"resource/textures/buttons/menu/pause_bg.png", 0)
		{
	setButtonPosition(RESUME, sf::Vector2f(516, 162));
	setButtonPosition(RESTART, sf::Vector2f(516, 309));
	setButtonPosition(MAIN_MENU, sf::Vector2f(516, 467));
};

PauseMenu::~PauseMenu(){

};

unsigned int PauseMenu::getMaxItems(){
	return NUM_CHOICES;
}

void PauseMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
		up();
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case PauseMenu::RESUME:
			World::currentState = World::PLAYING;
			return;
			break;
		case PauseMenu::RESTART:
			ResourceManager::getSound("resource/sounds/menu/menuback.ogg").play();
			World::currentState = World::RESTARTING;
			return;
			break;
		case PauseMenu::MAIN_MENU:
			ResourceManager::getSound("resource/sounds/menu/menuback.ogg").play();
			World::currentState = World::INMENU;
			return;
			break;
		default:
			break;
		}
	}
}