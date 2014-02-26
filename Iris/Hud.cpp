#include "Hud.hpp"


Hud::Hud(){
	font.loadFromFile("resource/fonts/AGENTORANGE.ttf");
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
	goldText.setPosition(0, 10);	

}

void Hud::drawText(sf::RenderWindow &window){
	window.draw(goldText);

}