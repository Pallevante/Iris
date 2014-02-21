#include "DefaultEnemy.hpp"

sf::Clock movementClock;


DefaultEnemy::DefaultEnemy(float speedMultiplier) :
mDamage(10),
mSpeed(4 * speedMultiplier),
mIsAlive(true),
//Måste ändras relativt till bilden.
mRad(64)
{
	mAnimation = new Animation("resource/textures/entities/enemy.png", 50, 2);
	mAnimation->setPosition(sf::Vector2f(1200, setYPos()));
}

float DefaultEnemy::setYPos(){
	float random =  rand() % 720 - mAnimation->getSprite().getGlobalBounds().height + 1;
	if (random < 0){
		random += mAnimation->getSprite().getGlobalBounds().height;
	}
	return random;
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
	return DEFAULT;
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
	if (e0->getDamage() > 0 && e0->getType() == RAY){
		mIsDying = true;
		ResourceManager::getSound("resource/sounds/Hitplopp.ogg").play();
		return 5;
	}
	else {
		return 0;
	}
}

bool DefaultEnemy::isAlive(){
	return mIsAlive;
}

void DefaultEnemy::tick(EntityVector &entities, float dt){
	move(entities, dt);
	mAnimation->Update();
	useAbility();
	fire(entities);
}

/*Enemy Basfunktioner*/
void DefaultEnemy::death(float dt){
	mAnimation->setPosition(sf::Vector2f(getPosition().x, getPosition().y - 15*dt));
	if (getPosition().y < -140){
		mIsAlive = false;
	}
}


void DefaultEnemy::move(EntityVector &enteties, float dt){
	float mXDir;
	float mYDir;
	sf::Time checkUpdateDir = movementClock.getElapsedTime();
	if (!mIsDying){
		if(getMovement() == DEFAULT){
			mAnimation->setPosition(sf::Vector2f(getPosition().x - 5 * dt, getPosition().y));
		}
		else if(getMovement() == WAVE){
			mAnimation->setPosition(sf::Vector2f(getPosition().x - 5, 200 + (70*sinf(0.005 * getPosition().x )) ));
		}

		/*Kommer användas för att hitta spelaren och följa den.*/
		else if(getMovement() == FOLLOWING){			
			if (checkUpdateDir.asMilliseconds() > 350){
				for (EntityVector::iterator i = enteties.begin(); i != enteties.end(); i++){
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

/*Dessa ska vara tomma såvida default enemy inte blir ändrad.*/
void DefaultEnemy::fire(EntityVector &enteties){
	return;
}
void DefaultEnemy::useAbility(){
	return;
}