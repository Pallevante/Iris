#include "DefaultEnemy.hpp"

DefaultEnemy::DefaultEnemy(Animation *animation,  float speedMultiplier) :
mDamage(10),
mSpeed(4 * speedMultiplier),
mIsAlive(true),
//M�ste �ndras relativt till bilden.
mRad(20.f),
mAnimation(animation)
{
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

//N�gonstans h�r ins�g jag att DefaultEnemy �r ett j�vligt ocoolt namn p� en klass.

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
		mAnimation->setPosition(sf::Vector2f(getPosition().x - 5, getPosition().y));
	}
	else{
		death();
	}
}

/*Dessa ska vara tomma s�vida default enemy inte blir �ndrad.*/
void DefaultEnemy::fire(EntityVector &enteties){
	return;
}
void DefaultEnemy::useAbility(){
	return;
}