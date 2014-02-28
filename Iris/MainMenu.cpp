#include "MainMenu.hpp"

MainMenu::MainMenu() :
Menu(
Menu::ButtonVector{ 
	/* Knapparna måste läggas in i rätt ordning som de visas på menyn */
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/play.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/level.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/shop.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/music.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/sound.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/exit.png"))
	},
Menu::ButtonVector{
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/play_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/level_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/shop_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/music_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/sound_selected.png")),
		new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/exit_selected.png"))
	},
Menu::ButtonVector{
			new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/play.png")),
			new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/level.png")),
			new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/shop.png")),
			new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/music.png")),
			new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/sound.png")),
			new sf::Sprite(ResourceManager::getTexture("resource/textures/buttons/menu/exit.png"))
	},
"resource/textures/backgrounds/menu.png", 0)
{
	/* Definera position på knapparna här */
	setButtonPosition(PLAY, sf::Vector2f(0, 72));
	setButtonPosition(LEVEL, sf::Vector2f(0, 173));
	setButtonPosition(SHOP, sf::Vector2f(0, 263));
	setButtonPosition(SOUND, sf::Vector2f(0, 355));
	setButtonPosition(MUSIC, sf::Vector2f(0, 449));
	setButtonPosition(EXIT, sf::Vector2f(0, 539));
}

MainMenu::~MainMenu(){
};

unsigned int MainMenu::getMaxItems(){
	return NUM_CHOICES;
}

void MainMenu::input(sf::Event& event){
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up){
		up();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		down();
	}

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
		switch (getCurrentMenuItem()){
		case MainMenu::PLAY:
			ResourceManager::getSound("resource/sounds/menu/menuclick.ogg").play();
			World::currentState = World::PLAYING;
			return;
			break;
		case MainMenu::SHOP:
			ResourceManager::getSound("resource/sounds/menu/click_shop.ogg").play();
			World::currentState = World::INSHOP;
			return;
			break;
		case MainMenu::EXIT:
			ResourceManager::getSound("resource/sounds/menu/menuback.ogg").play();
			World::currentState = World::EXIT;
			return;
			break;
		default:
			ResourceManager::getSound("resource/sounds/menu/menuback.ogg").play();
			return;
			break;
		}
	}
}