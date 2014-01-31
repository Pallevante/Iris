#include "DefaultEnemy.hpp"

DefaultEnemy::DefaultEnemy(float speedMultiplier) :
mDamage(10),
mSpeed(4 * speedMultiplier),
mIsAlive(true),
//Måste ändras relativt till bilden.
mRad(64)
{
	mAnimation = new Animation("resource/enemy.png", 50, 2);
	mAnimation->setPosition(sf::Vector2f(1200, 500));
}

DefaultEnemy::~DefaultEnemy(){}

sf::Vector2f DefaultEnemy::getPosition() {
	return mAnimation->getSprite().getPosition();
}

float DefaultEnemy::getRad() const {
	return mRad;
}

DefaultEnemy::Type DefaultEnemy::getType() const {
	return ENEMY;
}

int DefaultEnemy::getDamage() const {
	return mDamage;
}

int DefaultEnemy::getHeight() const {
	return mAnimation->getSprite().getTextureRect().height;
}

int DefaultEnemy::getWidth() const {
	return mAnimation->getSprite().getTextureRect().width;
}

//Någonstans här insåg jag att DefaultEnemy är ett jävligt ocoolt namn på en klass.

void DefaultEnemy::setDamage(int newDamage){
	mDamage = newDamage;
}

int DefaultEnemy::collide(Entity *e0, EntityVector &entities){
	if (e0->getDamage() > 0 && e0->getType() != getType()){
		mIsDying = true;
		return 5;
	}
	else {
		return 0;
	}
}

bool DefaultEnemy::isAlive(){
	return mIsAlive;
}

void DefaultEnemy::tick(EntityVector &entities){
	move();
	mAnimation->Update();
	useAbility();
	fire(entities);
}

/*Enemy Basfunktioner*/
void DefaultEnemy::death(){
	mAnimation->setPosition(sf::Vector2f(getPosition().x, getPosition().y - 15));
	if (getPosition().y < -140){
		mIsAlive = false;
	}
}

void DefaultEnemy::move(){
	if (!mIsDying){
		//mAnimation->setPosition(sf::Vector2f(getPosition().x - 5, getPosition().y));
		mAnimation->setPosition(sf::Vector2f(getPosition().x - 5, 500 + (40*sin(0.005 * getPosition().x )) ));
	}
	else{
		death();
	}
}

/*Dessa ska vara tomma såvida default enemy inte blir ändrad.*/
void DefaultEnemy::fire(EntityVector &enteties){
	return;
}
void DefaultEnemy::useAbility(){
	return;
}