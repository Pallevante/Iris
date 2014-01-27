#include "Player.hpp"
sf::Clock reloadTimer;

/*Public functions*/
Player::Player(float xPosition, float yPosition, int speedMultiplier) :
mDamage(10),
mSpeed(3 * speedMultiplier),
//Måste ändras relativt till bilden.
mRad(20)
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
	//We should have something else to make sure the user don't shoot's himself?
	if (entity->getDamage() > 0){
		mHealth -= entity->getDamage();
		if (mHealth <= 0) {
			mIsAlive = false;
		}
	}
	return 0;
}


/*Get functions*/
bool Player::isAlive(){
	return mIsAlive;
}

int Player::getDamage() const{
	return mDamage;
}

float Player::getPosition() const{
	mCircleShape.getPosition();
}

float Player::getRad() const{
	return mRad;
}


/*Set functions*/
int Player::setDamage(int newDamage){
	mDamage = newDamage;
}


/*Private memberfunctions*/
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
			mEnteties.push_back(new Ray(7, 0, getX() + mRad, getY() + mRad / 2));
		}
		reloadTimer.restart();
	}
}