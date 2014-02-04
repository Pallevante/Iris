#include "World.hpp"

//
//void World::menuInput(sf::Event &event){
//	if (currentState == INMENU){
//		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
//			if (mainMenu.getCurrentMenuItem() > 0){
//				mainMenu.setCurrentMenuItem(mainMenu.getCurrentMenuItem() - 1);
//			}
//		}
//		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
//			if (mainMenu.getCurrentMenuItem() < mainMenu.getMaxItems() - 1){
//				mainMenu.setCurrentMenuItem(mainMenu.getCurrentMenuItem() + 1);
//			}
//		}
//
//		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
//			switch (mainMenu.getCurrentMenuItem()){
//			case MainMenu::PLAY:
//				currentState = PLAYING;
//				return;
//				break;
//			case MainMenu::SHOP:
//				currentState = INSHOP;
//				return;
//				break;
//			case MainMenu::QUIT:
//				return;
//				break;
//			default:
//				return;
//				break;
//			}
//		}
//	}
//
//	if (currentState == INSHOP){
//		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
//			if (shopMenu.getCurrentMenuItem() > 0){
//				shopMenu.setCurrentMenuItem(shopMenu.getCurrentMenuItem() - 1);
//			}
//		}
//		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
//			if (shopMenu.getCurrentMenuItem() < shopMenu.getMaxItems() - 1){
//				shopMenu.setCurrentMenuItem(shopMenu.getCurrentMenuItem() + 1);
//			}
//		}
//
//		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
//			switch (shopMenu.getCurrentMenuItem()){
//			case ShopMenu::BACK:
//				currentState = INMENU;
//				return;
//				break;
//			default:
//				break;
//			}
//		}
//	}
//}
//
//void World::shopInput(sf::Event &event){
//
//}
//
