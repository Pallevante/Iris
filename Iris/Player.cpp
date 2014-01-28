#include "Player.hpp"
sf::Clock reloadTimer;

/*Public funktioner*/



Player::Player(Animation *animation, float xPosition, float yPosition, int speedMultiplier) :

mDamage(10),
mSpeed(3 * speedMultiplier),
//Måste ändras relativt till bilden.
mRad(20.f),
mAnimation(animation)
{	
	mAnimation->setPosition(sf::Vector2f(xPosition, yPosition));
}

Player::~Player(){}

void Player::tick(EntityVector &mEnteties){
	move();
	fire(mEnteties);
	mAnimation->Update();
}

int Player::collide(Entity *entity, EntityVector &enteties){
	
	if (entity->getDamage() > 0 && entity->getType() == Entity::Type::ENEMY){
		mHealth -= entity->getDamage();
		if (mHealth <= 0) {
			mIsAlive = false;
		}
	}
	return 0;
}


/*Get funktioner*/
bool Player::isAlive(){
	return mIsAlive;
}

int Player::getDamage() const{
	return mDamage;
}

sf::Vector2f Player::getPosition(){
	return mAnimation->getSprite().getPosition();
}

float Player::getRad() const{
	return mRad;
}

Player::Type Player::getType() const{
	return PLAYER;
}


/*Set funktioner*/
void Player::setDamage(int newDamage){
	mDamage = newDamage;
}


/*Private medlemsfunktioner*/
void Player::move(){
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

void Player::fire(EntityVector &mEnteties){

	sf::Time isReloaded = reloadTimer.getElapsedTime();
	if (isReloaded.asMilliseconds() > 200){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			Animation* rayAnimation = new Animation("resource/test.png", 200, 4);
			mEnteties.push_back(new Ray(getPosition(), rayAnimation));
		}
		reloadTimer.restart();
	}
}