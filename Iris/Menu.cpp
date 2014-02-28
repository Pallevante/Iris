#include "Menu.hpp"

Menu::Menu(ButtonVector buttons, ButtonVector buttons_selected, ButtonVector buttons_active, const std::string& background, unsigned int currentMenuItem) :
mButtonVector(buttons),
mButtonSelectedVector(buttons_selected),
mButtonActiveVector(buttons_active),
mCurrentMenuItem(currentMenuItem),
mBackground(ResourceManager::getTexture(background))
{
	for (ButtonVector::size_type i = 0; i < mButtonSelectedVector.size(); i++){
		setUnselected(i);
	}
	for (ButtonVector::size_type i = 0; i < mButtonActiveVector.size(); i++){
		setInactive(i);
	}

	setCurrentMenuItem(mCurrentMenuItem);
}

Menu::~Menu(){}

void Menu::drawMenu(sf::RenderWindow& window){
	window.draw(mBackground);
	for (ButtonVector::size_type i = 0; i < mButtonVector.size(); i++){
		window.draw(*mButtonVector[i]);
		window.draw(*mButtonSelectedVector[i]);
		window.draw(*mButtonActiveVector[i]);
	}
}
unsigned int Menu::getCurrentMenuItem(){
	return mCurrentMenuItem;
}


void Menu::setSelected(unsigned int i){
	mButtonSelectedVector[i]->setColor(sf::Color(255, 255, 255, 255));
}

void Menu::setUnselected(unsigned int i){
	mButtonSelectedVector[i]->setColor(sf::Color(255, 255, 255, 0));
}

void Menu::setActive(unsigned int i){
	mButtonActiveVector[i]->setColor(sf::Color(255, 255, 255, 255));
}
void Menu::setInactive(unsigned int i){
	mButtonActiveVector[i]->setColor(sf::Color(255, 255, 255, 0));
}

void Menu::setButtonPosition(unsigned int i, sf::Vector2f position){
	mButtonVector[i]->setPosition(position);
	mButtonSelectedVector[i]->setPosition(position);
	mButtonActiveVector[i]->setPosition(position);
}

void Menu::setCurrentMenuItem(unsigned int i){
	Menu::setUnselected(mCurrentMenuItem);
	mCurrentMenuItem = i;
	Menu::setSelected(mCurrentMenuItem);
}

void Menu::down(){
	if (mCurrentMenuItem < getMaxItems()-1){
		setCurrentMenuItem(mCurrentMenuItem + 1);
	}
	ResourceManager::getSound("resource/sounds/menu/menuscroll.ogg").play();
}
void Menu::up(){
	if (mCurrentMenuItem > 0){
		setCurrentMenuItem(mCurrentMenuItem - 1);
	}
	ResourceManager::getSound("resource/sounds/menu/menuscroll.ogg").play();
}
