#include "SelectLevelMenu.hpp"


SelectLevelMenu::SelectLevelMenu() : Menu(Menu::ButtonVector{
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/usa_thumb_off.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/Usa_thumb_on.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/brazil_thumb_off.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/brazil_thumb_on.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/LevelSelect_back.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/LevelSelect_back_selected.png"))
}, "resource/textures/backgrounds/levelselect.png", 0){

	mButtonVector[BACK * 2]->setPosition(50, 50);
	mButtonVector[BACK * 2 + 1]->setPosition(50, 50);
	mButtonVector[USA * 2]->setPosition(100, 200);
	mButtonVector[USA * 2 + 1]->setPosition(100, 200);
	mButtonVector[BRAZIL * 2]->setPosition(650, 200);
	mButtonVector[BRAZIL * 2 + 1]->setPosition(650, 200);


	setInactive(USA);
	setInactive(BACK);
	setInactive(BRAZIL);

	setActive(mCurrentMenuItem);
}


SelectLevelMenu::~SelectLevelMenu()
{
}

unsigned int SelectLevelMenu::getMaxItems(){
	return NUM_CHOICES;
}


void SelectLevelMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left){
		up();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
			ResourceManager::getSound("resource/sounds/menuback.ogg").play();
		case SelectLevelMenu::BACK:			
			World::currentState = World::INMENU;
			return;
			break;
		case SelectLevelMenu::USA:
			World::mLevelInt = 1;
			World::currentState = World::PLAYING;
			return;
			break;
		case SelectButtons::BRAZIL:
			World::mLevelInt = 2;
			World::currentState = World::PLAYING;
		default:
			break;
		}
	}
}