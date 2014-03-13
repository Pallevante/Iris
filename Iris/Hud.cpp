#include "Hud.hpp"


Hud::Hud(){
	font.loadFromFile("resource/fonts/AGENTORANGE.ttf");

	progressBar.setTexture(ResourceManager::getTexture("resource/textures/hud/emptybar.png"));
	fillTexture.setTexture(ResourceManager::getTexture("resource/textures/hud/block.png"));
	progressBar.setPosition(222, 632);
	fillTexture.setPosition(222, 632);
	currentProgressRect = sf::IntRect(0, 0, 0, 0);
	fillTexture.setTextureRect(currentProgressRect);

	fillSpeed = 8.0f;
}

Hud::~Hud(){
}

void Hud::setText(){

	goldAmount.str("");
	goldAmount.clear();
	goldAmount <<  World::mGold;

	goldText.setFont(font);
	goldText.setCharacterSize(40);

	goldText.setString("Gold:" + goldAmount.str());
	goldText.setColor(sf::Color::White);
	goldText.setPosition(0, 632);

}

void Hud::updateProgressBar(){
	float currentSizeX = currentProgressRect.width;
	progress = fillTexture.getTexture()->getSize().x * World::mScore;

	if (currentSizeX != progress){
		if ((currentSizeX + fillSpeed <= progress) || (currentSizeX - fillSpeed <= progress)){
			currentSizeX = currentSizeX + fillSpeed;
		}
		if ((currentSizeX + fillSpeed >= progress) || (currentSizeX - fillSpeed >= progress)){
			currentSizeX = currentSizeX - fillSpeed;
		}
	}
	

	currentProgressRect = sf::IntRect(0, 0, currentSizeX, fillTexture.getTexture()->getSize().y);
	fillTexture.setTextureRect(currentProgressRect);
}

void Hud::drawText(sf::RenderWindow &window){
	updateProgressBar();
	window.draw(goldText);
	window.draw(fillTexture);
	window.draw(progressBar);
}