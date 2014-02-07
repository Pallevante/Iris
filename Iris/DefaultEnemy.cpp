#include "DefaultEnemy.hpp"

DefaultEnemy::DefaultEnemy(float speedMultiplier) :
mDamage(10),
mSpeed(4 * speedMultiplier),
mIsAlive(true),
//M�ste �ndras relativt till bilden.
mRad(64)
{
	mAnimation = new Animation("resource/textures/entities/enemy.png", 50, 2);
	mAnimation->setPosition(sf::Vector2f(1200, setYPos()));
}

float DefaultEnemy::setYPos(){
	return rand() % 720 + 1;
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

DefaultEnemy::Movement DefaultEnemy::getMovement(){
	return WAVE;
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
	float mXDir;
	float mYDir;
	if (!mIsDying){
		if(getMovement() == DEFAULT){
			mAnimation->setPosition(sf::Vector2f(getPosition().x - 5, getPosition().y));
		}
		else if(getMovement() == WAVE){
			mAnimation->setPosition(sf::Vector2f(getPosition().x - 5, 500 + (70*sinf(0.005 * getPosition().x )) ));
		}
		/*else if(getMovement() == FOLLOWING){			
			if (checkUpdateDir.asMilliseconds() > 350){
				for (EntityVector::iterator i = mEnteties.begin(); i++){
					Entity* enteties = *i;
					if (enteties->getType() == PLAYER){
						float x = enteties->getPosition().x - getPosition().x;
						float y = enteties->getPosition().x - getPosition().x;
						mXDir = x / sqrt(powf(x, 2) + powf(y, 2)) * mSpeed;
						mYDir = y / sqrt(powf(x, 2) + powf(y, 2)) * mSpeed;
					}
				}
			}
			mAnimation->setPosition(sf::Vector2f(getPosition().x + mXDir, getPosition().y + mYDir));
		}	*/
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