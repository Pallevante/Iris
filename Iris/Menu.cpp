#include "Menu.hpp"

Menu::Menu(ButtonVector buttons, const std::string& background, unsigned int currentMenuItem):
mButtonVector(buttons),
mCurrentMenuItem(currentMenuItem),
mBackground(ResourceManager::getTexture(background))
{
}

Menu::~Menu(){}

void Menu::drawMenu(sf::RenderWindow& window){
	window.draw(mBackground);
	for (ButtonVector::size_type i = 0; i < mButtonVector.size(); i++){
		window.draw(*mButtonVector[i]);
	}
}
unsigned int Menu::getCurrentMenuItem(){
	return mCurrentMenuItem;
}

void Menu::setActive(unsigned int i){
	mButtonVector[i * 2 + 1]->setColor(sf::Color(255,255,255,255));
}
void Menu::setInactive(unsigned int i){
	mButtonVector[i * 2 + 1]->setColor(sf::Color(255, 255, 255, 0));
}

void Menu::setCurrentMenuItem(unsigned int i){
	Menu::setInactive(mCurrentMenuItem);
	mCurrentMenuItem = i;
	Menu::setActive(mCurrentMenuItem);
}

void Menu::down(){
	if (mCurrentMenuItem < getMaxItems()-1){
		setCurrentMenuItem(mCurrentMenuItem + 1);
	}
	ResourceManager::getSound("resource/sounds/menuscroll.ogg").play();
}
void Menu::up(){
	if (mCurrentMenuItem > 0){
		setCurrentMenuItem(mCurrentMenuItem - 1);
	}
	ResourceManager::getSound("resource/sounds/menuscroll.ogg").play();
}
