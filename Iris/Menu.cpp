#include "Menu.hpp"

Menu::Menu(ButtonVector buttons, const std::string& background, unsigned int currentMenuItem):
mButtonVector(buttons),
mCurrentMenuItem(currentMenuItem),
mBackground(ResourceManager::getTexture(background)),
mActiveButton(ResourceManager::getTexture("resource/buttons/activebutton.png"))
{
}

Menu::~Menu(){}

void Menu::drawMenu(sf::RenderWindow& window){
	window.draw(mBackground);
	for (ButtonVector::size_type i = 0; i < mButtonVector.size(); i++){
		window.draw(*mButtonVector[i]);
	}
	window.draw(mActiveButton);
}
int Menu::getCurrentMenuItem(){
	return mCurrentMenuItem;
}



void Menu::setActive(unsigned int i){
	mActiveButton.setPosition(mButtonVector[i]->getPosition().x - 80, mButtonVector[i]->getPosition().y);
}

void Menu::setCurrentMenuItem(unsigned int i){
	mCurrentMenuItem = i;
	Menu::setActive(mCurrentMenuItem);
}

void Menu::down(){
	if (mCurrentMenuItem < getMaxItems()-1){
		setCurrentMenuItem(mCurrentMenuItem + 1);
	}
}
void Menu::up(){
	if (mCurrentMenuItem > 0){
		setCurrentMenuItem(mCurrentMenuItem - 1);
	}
}