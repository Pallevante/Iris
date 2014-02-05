#include "World.hpp"

void World::menuInput(sf::Event &event){
	if (currentState == INMENU){
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
			mainMenu.up();
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
			mainMenu.down();
		}

		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
			switch (mainMenu.getCurrentMenuItem()){
			case MainMenu::PLAY:
				currentState = PLAYING;
				return;
				break;
			case MainMenu::SHOP:
				currentState = INSHOP;
				return;
				break;
			case MainMenu::QUIT:
				return;
				break;
			default:
				break;
			}
		}
	}

	else if (currentState == INSHOP){
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
			shopMenu.up();
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
			shopMenu.down();
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
			switch (shopMenu.getCurrentMenuItem()){
			case ShopMenu::BACK:
				currentState = INMENU;
				return;
				break;
			default:
				break;
			}
		}
	}
}