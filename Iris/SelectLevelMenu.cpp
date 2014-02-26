#include "SelectLevelMenu.hpp"


SelectLevelMenu::SelectLevelMenu() : Menu(Menu::ButtonVector{
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/Usa.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/Usa_select.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/Labutton.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/LaButton_Selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/back_selected.png"))
}, "resource/textures/backgrounds/test.jpg", 0){
	mButtonVector[USA * 2]->setPosition(100, 200);
	mButtonVector[USA * 2 + 1]->setPosition(100, 200);
	mButtonVector[LABUTTON * 2]->setPosition(100, 400);
	mButtonVector[LABUTTON * 2 + 1]->setPosition(100, 400);
	mButtonVector[BACK * 2]->setPosition(1000, 600);
	mButtonVector[BACK * 2 + 1]->setPosition(1000, 600);

	setInactive(USA);
	setInactive(BACK);
	setInactive(LABUTTON);

	setActive(mCurrentMenuItem);
}


SelectLevelMenu::~SelectLevelMenu()
{
}

unsigned int SelectLevelMenu::getMaxItems(){
	return NUM_CHOICES;
}


void SelectLevelMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
		up();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case SelectLevelMenu::BACK:
			ResourceManager::getSound("resource/sounds/menuback.ogg").play();
			World::currentState = World::INMENU;
			return;
			break;
		case SelectLevelMenu::USA:
			ResourceManager::getSound("resource/sounds/menuselect.ogg").play();
			World::currentState = World::PLAYING;
			return;
			break;
		
		default:
			break;
		}
	}
}