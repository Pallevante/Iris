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
				ResourceManager::play("resource/sounds/menuselect.ogg");
				currentState = PLAYING;
				return;
				break;
			case MainMenu::SHOP:
				ResourceManager::play("resource/sounds/menuselect.ogg");
				currentState = INSHOP;
				return;
				break;
			case MainMenu::QUIT:
				ResourceManager::play("resource/sounds/menuback.ogg");
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
				ResourceManager::play("resource/sounds/menuback.ogg");
				currentState = INMENU;
				return;
				break;
			default:
				break;
			}
		}
	}
}