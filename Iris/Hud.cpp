#include "Hud.hpp"


Hud::Hud(){
	font.loadFromFile("resource/fonts/AGENTORANGE.ttf");
	//progress = 0;
	progressBar.setTexture(ResourceManager::getTexture("resource/textures/hud/emptybar.png"));
	fillTexture.setTexture(ResourceManager::getTexture("resource/textures/hud/block.png"));
	progressBar.setPosition(222, 632);
	fillTexture.setPosition(222, 632);
	currentProgressRect = sf::IntRect(0, 0, 0,0);
	fillTexture.setTextureRect(currentProgressRect);
}

Hud::~Hud(){
}

void Hud::setText(){

	goldAmount.str("");
	goldAmount.clear();
	goldAmount <<  World::mGold;

	goldText.setFont(font);
	goldText.setCharacterSize(60);

	goldText.setString("Gold:" + goldAmount.str());
	goldText.setColor(sf::Color::White);
	goldText.setPosition(0, 10);	/*
	progress = 200 * World::mScore;

	if (progress > 200) 
		progress = 200;

	if (progress < 0)
		progress = 0;

	if (progress < 60) 
		progressColor = sf::Color::Red;

	else if (progress < 110 && progress > 60) 
		progressColor = sf::Color::Yellow;

	else if (progress < 200 && progress > 110) 
		progressColor = sf::Color::Green;

	progressBar.setFillColor(progressColor);
	progressBar.setSize(sf::Vector2f(progress, 40));
	progressBar.setPosition(sf::Vector2f(550, 700));*/
}

void Hud::updateProgressBar(){
	currentProgressRect = sf::IntRect(0, 0, progressBar.getTexture()->getSize().x * World::mScore, progressBar.getTexture()->getSize().y);
	fillTexture.setTextureRect(currentProgressRect);
}

void Hud::drawText(sf::RenderWindow &window){
	updateProgressBar();
	window.draw(goldText);
	window.draw(fillTexture);
	window.draw(progressBar);
}