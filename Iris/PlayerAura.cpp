#include "PlayerAura.hpp"

/*Public funktioner*/


PlayerAura::PlayerAura(float xPosition, float yPosition, float speedMultiplier) :
mHealth(0),
mSpeed(4 * speedMultiplier),
mIsAlive(true),
//Måste ändras relativt till bilden.
mRad(20.f)
{
	
	mAnimation = new Animation("resource/playerAura.png", 100, 1);
	mAnimation->setPosition(sf::Vector2f(xPosition, yPosition));
	mAnimation->setColor(sf::Color(255, 0, 255, 255));
		


}

PlayerAura::~PlayerAura(){}

void PlayerAura::tick(EntityVector &entities){
	move();
	mAnimation->Update();
	
}

int PlayerAura::collide(Entity *entity, EntityVector &entities){

	if (entity->getDamage() > 0 && entity->getType() == Entity::Type::ENEMY){
		mHealth -= entity->getDamage() / 2;
	}
	return 0;
}


/*Get funktioner*/
bool PlayerAura::isAlive(){
	return mIsAlive;
}

int PlayerAura::getDamage() const{
	return mDamage;
}

sf::Vector2f PlayerAura::getPosition(){
	return mAnimation->getSprite().getPosition();
}

float PlayerAura::getRad() const{
	return mRad;
}

PlayerAura::Type PlayerAura::getType() const{
	return PLAYER;
}


/*Set funktioner*/
void PlayerAura::setDamage(int newDamage){
	mDamage = newDamage;
}

int PlayerAura::getHeight() const {
	return mAnimation->getSprite().getTextureRect().height;
}

int PlayerAura::getWidth() const {
	return mAnimation->getSprite().getTextureRect().width;
}


/*Private medlemsfunktioner*/
void PlayerAura::move(){

	float currentX = mAnimation->getSprite().getPosition().x;
	float currentY = mAnimation->getSprite().getPosition().y;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		currentX += mSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		currentX -= mSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

		currentY += mSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		currentY -= mSpeed;
	}
	
		mAnimation->setPosition(sf::Vector2f(currentX, currentY));
		
		
}


