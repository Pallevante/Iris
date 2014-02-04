#include "MainMenu.hpp"
#include "ResourceManager.hpp"

MainMenu::MainMenu() :
mCurrentMenuItem(0)
{
	sf::Sprite* sprite1 = new sf::Sprite();
	sf::Sprite* sprite2 = new sf::Sprite();
	sprite1->setTexture(ResourceManager::getTexture("resource/play.png"));
	sprite2->setTexture(ResourceManager::getTexture("resource/quit.png"));
	sprite1->setPosition(100, 200);
	sprite2->setPosition(100, 400);

	mButtonVector.push_back(sprite1);
	mButtonVector.push_back(sprite2);
	
	mActiveButton.setTexture(ResourceManager::getTexture("resource/activebutton.png"));
	mActiveButton.setPosition(mButtonVector[mCurrentMenuItem]->getPosition().x - 80, mButtonVector[mCurrentMenuItem]->getPosition().y);
}

MainMenu::~MainMenu(){}

void MainMenu::setCurrentMenuItem(unsigned int i){
	mCurrentMenuItem = i;
	mActiveButton.setPosition(mButtonVector[mCurrentMenuItem]->getPosition().x - 80, mButtonVector[mCurrentMenuItem]->getPosition().y);
}

int MainMenu::getCurrentMenuItem(){
	return mCurrentMenuItem;
}

int MainMenu::getMaxItems(){
	return NUM_CHOICES;
}

void MainMenu::drawMenu(sf::RenderWindow& window){
	for (int i = 0; i < mButtonVector.size(); i++){
		window.draw(*mButtonVector[i]);
		window.draw(mActiveButton);
	}
}