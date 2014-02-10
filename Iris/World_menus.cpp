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
				ResourceManager::getSound("resource/sounds/menuselect.ogg").play();
				currentState = PLAYING;
				return;
				break;
			case MainMenu::SHOP:
				ResourceManager::getSound("resource/sounds/menuselect.ogg").play();
				currentState = INSHOP;
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
				ResourceManager::getSound("resource/sounds/menuback.ogg").play();
				currentState = INMENU;
				return;
				break;
			default:
				break;
			}
		}
	}
}