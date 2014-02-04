#include "World.hpp"

void World::menu(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if(mainMenu.getCurrentMenuItem() > 0){
			mainMenu.setCurrentMenuItem(mainMenu.getCurrentMenuItem() - 1);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (mainMenu.getCurrentMenuItem() < mainMenu.getMaxItems()-1){
			mainMenu.setCurrentMenuItem(mainMenu.getCurrentMenuItem() + 1);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		switch (mainMenu.getCurrentMenuItem()){
		case MainMenu::PLAY:
			currentState = PLAYING;
			break;
		case MainMenu::QUIT:
			break;
		default:
			break;
		}
	}
}