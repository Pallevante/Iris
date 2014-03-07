#include "PauseMenu.hpp"

PauseMenu::PauseMenu() :
Menu(
/* Knappvektorernas ordning är NORMAL, SELECTED, ACTIVE */
Menu::ButtonVector{
	/* Knapparna måste läggas in i rätt ordning som de ska visas på menyn */
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
	"", 0)
		{
	setButtonPosition(RESUME, sf::Vector2f(300, 100));
	setButtonPosition(RESTART, sf::Vector2f(350, 250));
	setButtonPosition(MAIN_MENU, sf::Vector2f(350, 350));
};

PauseMenu::~PauseMenu(){

};

unsigned int PauseMenu::getMaxItems(){
	return NUM_CHOICES;
}

void PauseMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
		up();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case PauseMenu::RESUME:
			World::currentState = World::PLAYING;
			return;
			break;
		case PauseMenu::RESTART:
			//TODO: restarta level funktion
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