#include "Player.hpp"
sf::Clock reloadTimer;

/*Public funktioner*/
Player::Player(float xPosition, float yPosition, int speedMultiplier) :
mDamage(10),
mSpeed(3 * speedMultiplier),
//Måste ändras relativt till bilden.
mRad(20.f)
{
	mCircleShape.setRadius(mRad);
	mCircleShape.setPosition(xPosition, yPosition);
	mCircleShape.setFillColor(sf::Color::Red);
}

Player::~Player(){}

void Player::tick(EntityVector &mEnteties){
	move();
	fire(mEnteties);
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

sf::Vector2f Player::getPosition() const{
	return mCircleShape.getPosition();
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		mCircleShape.move(mSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		mCircleShape.move(-mSpeed, 0);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		mCircleShape.move(0, mSpeed);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		mCircleShape.move(0, -mSpeed);

	}

}

void Player::fire(EntityVector &mEnteties){

	sf::Time isReloaded = reloadTimer.getElapsedTime();
	if (isReloaded.asMilliseconds() > 200){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			mEnteties.push_back(new Ray(getPosition()));
		}
		reloadTimer.restart();
	}
}