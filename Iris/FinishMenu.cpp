#include "FinishMenu.hpp"
//
//FinishMenu::FinishMenu() :
//Menu(
///* Knappvektorernas ordning är NORMAL, SELECTED, ACTIVE */
//Menu::ButtonVector{
//		/* Knapparna måste läggas in i rätt ordning som de ska visas på menyn */
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png")),
//	},
//Menu::ButtonVector{
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot_selected.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet_selected.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour_selected.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime_selected.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back_selected.png"))
//	},
//Menu::ButtonVector{
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/powershot.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/magnet.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/luckyfour.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/slowtime.png")),
//		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png")),
//	},
//"resource/textures/backgrounds/shop.png", 0)
//{
//	setButtonPosition(NEXT_LEVEL, sf::Vector2f(45, 33));
//	setButtonPosition(MAIN_MENU, sf::Vector2f(72, 295));
//};
//
//ShopMenu::~ShopMenu(){
//
//};
//
//unsigned int ShopMenu::getMaxItems(){
//	return NUM_CHOICES;
//}
//
//void ShopMenu::input(sf::Event& event){
//	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
//		up();
//	}
//	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
//		down();
//	}
//
//}