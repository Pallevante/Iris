#include "SelectLevelMenu.hpp"


SelectLevelMenu::SelectLevelMenu() : Menu(Menu::ButtonVector{
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/LevelSelect_back.png")),	
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/usa_thumb_off.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/brazil_thumb_off.png")),	
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/europe_thumb_off.png"))
}, 
Menu::ButtonVector{
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/LevelSelect_back_selected.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/Usa_thumb_on.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/brazil_thumb_on.png")),
	new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/europe_thumb_on.png"))
},

Menu::ButtonVector{
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/LevelSelect_back.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/usa_thumb_off.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/brazil_thumb_off.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/europe_thumb_off.png"))
	},
"resource/textures/backgrounds/levelselect.png", USA){
	setButtonPosition(BACK, sf::Vector2f(50, 50));
	setButtonPosition(USA, sf::Vector2f(100, 200));
	setButtonPosition(BRAZIL, sf::Vector2f(650, 200));
	setButtonPosition(EUROPE, sf::Vector2f(1200, 200));
}


SelectLevelMenu::~SelectLevelMenu(){}

unsigned int SelectLevelMenu::getMaxItems(){
	return NUM_CHOICES;
}


void SelectLevelMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){		
		if (getCurrentMenuItem() % 2 != 0 && getCurrentMenuItem() != 1){
			setButtonPosition(USA, sf::Vector2f(getButtonPosition(USA).x + 550, 200)); //Ska skilja 500px i x-led.
			setButtonPosition(BRAZIL, sf::Vector2f(getButtonPosition(BRAZIL).x + 550, 200));
			setButtonPosition(EUROPE, sf::Vector2f(getButtonPosition(EUROPE).x + 550, 200));
		}
		up();
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
		if (getCurrentMenuItem() % 2 == 0 && getCurrentMenuItem() != 3){
			setButtonPosition(USA, sf::Vector2f(getButtonPosition(USA).x - 550, 200)); 
			setButtonPosition(BRAZIL, sf::Vector2f(getButtonPosition(BRAZIL).x - 550, 200));
			setButtonPosition(EUROPE, sf::Vector2f(getButtonPosition(EUROPE).x - 550, 200));
		}
		down();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
			ResourceManager::getSound("resource/sounds/menu/menuback.ogg").play();
		case SelectLevelMenu::BACK:			
			World::currentState = World::INMENU;
			return;
			break;
		case SelectLevelMenu::USA:
			World::mLevelInt = 1;
			World::currentState = World::LOAD;
			return;
			break;
		case SelectButtons::BRAZIL:
			World::mLevelInt = 2;
			World::currentState = World::LOAD;
			return;
			break;
		case SelectButtons::EUROPE :
			World::mLevelInt = 3;
			World::currentState = World::LOAD;
			return;
			break;
		default:
			break;
		}
	}
}