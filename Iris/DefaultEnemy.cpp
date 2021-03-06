#include "DefaultEnemy.hpp"




DefaultEnemy::DefaultEnemy(float speedMultiplier, sf::Vector2f position) :
mDamage(1),
mSpeed(500 * speedMultiplier),
mIsAlive(true),
mHealth(2),
//M�ste �ndras relativt till bilden.
mRad(64)
{
	mAnimation = new Animation("resource/textures/entities/enemy.png", 50, 2);
	mAnimation->setPosition(position);

	movementClock = new sf::Clock;
	enemyReloadTimer = new sf::Clock;
}


DefaultEnemy::~DefaultEnemy(){
	delete mAnimation;
	delete movementClock;
	delete enemyReloadTimer;
}

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

//N�gonstans h�r ins�g jag att DefaultEnemy �r ett j�vligt ocoolt namn p� en klass.

void DefaultEnemy::setDamage(int newDamage){
	mDamage = newDamage;
}

int DefaultEnemy::collide(Entity *e0, EntityVector &entities){

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
	mAnimation->setPosition(sf::Vector2f(getPosition().x, getPosition().y - mSpeed * 3 *dt));
	DefaultEnemy::setDamage(0);
	if (getPosition().y < -140){
		mIsAlive = false;
	}
}


void DefaultEnemy::move(EntityVector &enteties, float dt){
	//Dessa anv�nds f�r FOLLOWING funktionen.
	float mXDir;
	float mYDir;
	sf::Time checkUpdateDir = movementClock->getElapsedTime();


	if (!mIsDying){
		//D�dar fiender som inte redan �r d�ende och �r utanf�r sk�rmens yta p� v�nster sida.
		if (getPosition().x < -200){
			mIsAlive = false;
		}
		//Rak r�relse f�r fienderna.
		if(getMovement() == DEFAULT){
			mAnimation->setPosition(sf::Vector2f(getPosition().x - mSpeed * dt, getPosition().y));
		}

		//De r�r sig i ett v�gformat m�nster.
		else if(getMovement() == WAVE){
			mAnimation->setPosition(sf::Vector2f(getPosition().x - mSpeed, 200 + (70*sinf(0.005 * getPosition().x )) ));
		}

		/*Kommer anv�ndas f�r att hitta spelaren och f�lja den.*/
		else if(getMovement() == FOLLOWING){			
			if (checkUpdateDir.asMilliseconds() > 350){
				for (EntityVector::iterator i = enteties.begin(); i != enteties.end(); i++){
					Entity* entity = *i;
					if (entity->getType() == PLAYER){
						/*Linj�r algebra ftw*/
						float x = entity->getPosition().x - getPosition().x;
						float y = entity->getPosition().x - getPosition().x;
						mXDir = x / sqrt(powf(x, 2) + powf(y, 2)) * mSpeed;
						mYDir = y / sqrt(powf(x, 2) + powf(y, 2)) * mSpeed;

						movementClock->restart();
					}
				}
			}
			mAnimation->setPosition(sf::Vector2f((getPosition().x + mXDir) * dt, (getPosition().y + mYDir) * dt));
		}	
	}
	//Om fienden inte �r vid liv.
	else{
		death(dt);
	}
}


void DefaultEnemy::fire(EntityVector &entities){

	sf::Time checkReloadTime =	checkReloadTime = enemyReloadTimer->getElapsedTime();
	//De skjuter med stora intervaller men snabba skott.
	if (checkReloadTime.asMilliseconds() > 1000){
		ResourceManager::getSound("resource/sounds/GoblinShot.ogg").play();
		entities.push_back(new Ray(sf::Vector2f(getPosition().x, (getPosition().y + getHeight() /2)), true));
		enemyReloadTimer->restart();
	}
}
void DefaultEnemy::useAbility(){}
