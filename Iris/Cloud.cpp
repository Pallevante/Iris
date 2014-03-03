#include "Cloud.hpp"

sf::Clock movementClock;

Cloud::Cloud(float speedMultiplier, sf::Vector2f position) :
mDamage(1),
mSpeed(6 * speedMultiplier),
mIsAlive(true),
mHealth(2){
	mAnimation = new Animation("resource/textures/entities/enemy.png", 50, 2);
	mAnimation->setPosition(position);
}


Cloud::~Cloud(){
	delete mAnimation;
}

float Cloud::getRad() const{
	return mRad;
}

sf::Vector2f Cloud::getPosition(){
	return mAnimation->getSprite().getPosition();
}

int Cloud::getHeight() const{
	return mAnimation->getSprite().getGlobalBounds().height;
}

int Cloud::getWidth() const{
	return mAnimation->getSprite().getGlobalBounds().width;
}

int Cloud::getDamage() const{
	return mDamage;
}

Cloud::Type Cloud::getType() const{
	return ENEMY;
}

void Cloud::setDamage(int newDamage){
	mDamage = newDamage;
}
//Kollision som känner om träffande entitet är RAY
int Cloud::collide(Entity *e0, EntityVector &entities){
	if (e0->getDamage() > 0 && e0->getType() == RAY){
		mHealth -= e0->getDamage();

		if (mHealth <= 0)
			mIsDying = true;

		ResourceManager::getSound("resource/sounds/Hitplopp.ogg").play();
		return 5;
	}
	else {
		return 0;
	}
}

bool Cloud::isAlive(){
	return mIsAlive;
}

Cloud::Movement Cloud::getMovement(){
	return DEFAULT;
}

void Cloud::tick(EntityVector &entities, float dt){
	move(entities, dt);
	fire(entities);
}

void Cloud::death(float dt){
	mAnimation->setPosition(sf::Vector2f(getPosition().x, getPosition().y - 15 * dt));
	setDamage(0);
	if (getPosition().y < -140){
		mIsAlive = false;
	}
}

void Cloud::fire(EntityVector &entities){}

void Cloud::move(EntityVector &entities, float dt){
	float mXDir;
	float mYDir;
	sf::Time checkUpdateDir = movementClock.getElapsedTime();
	if (!mIsDying){
		if (getMovement() == DEFAULT){
			mAnimation->setPosition(sf::Vector2f(getPosition().x - 5 * dt, getPosition().y));
		}
		else if (getMovement() == WAVE){
			mAnimation->setPosition(sf::Vector2f(getPosition().x - 5, 200 + (70 * sinf(0.005 * getPosition().x))));
		}

		/*Kommer användas för att hitta spelaren och följa den.*/
		else if (getMovement() == FOLLOWING){
			if (checkUpdateDir.asMilliseconds() > 350){
				for (EntityVector::iterator i = entities.begin(); i != entities.end(); i++){
					Entity* entity = *i;
					if (entity->getType() == PLAYER){
						/*Linjär algebra ftw*/
						float x = entity->getPosition().x - getPosition().x;
						float y = entity->getPosition().x - getPosition().x;
						mXDir = x / sqrt(powf(x, 2) + powf(y, 2)) * mSpeed;
						mYDir = y / sqrt(powf(x, 2) + powf(y, 2)) * mSpeed;

						movementClock.restart();
					}
				}
			}
			mAnimation->setPosition(sf::Vector2f((getPosition().x + mXDir) * dt, (getPosition().y + mYDir) * dt));
		}
	}
	else{
		death(dt);
	}
}

void Cloud::useAbility(){}