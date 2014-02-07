#include "Player.hpp"
sf::Clock reloadTimer;

/*Public funktioner*/



Player::Player(float xPosition, float yPosition, float speedMultiplier) :

mDamage(10),
mSpeed(6 * speedMultiplier),
mAcceleration(0.8f * speedMultiplier),
mIsAlive(true),
//Måste ändras relativt till bilden.
mRad(20.f)
{	
	mAnimation = new Animation("resource/textures/entities/player.png", 100, 8);
	mAnimation->setPosition(sf::Vector2f(xPosition, yPosition));
}

Player::~Player(){}

void Player::tick(EntityVector &entities, float dt){
	move(dt);
	fire(entities);
	mAnimation->Update();
}

int Player::collide(Entity *entity, EntityVector &entities){
	
	if (entity->getDamage() > 0 && entity->getType() == Entity::Type::ENEMY){
		mHealth -= entity->getDamage() / 2;		
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

int Player::getHeight() const {
	return mAnimation->getSprite().getTextureRect().height;
}

int Player::getWidth() const {
	return mAnimation->getSprite().getTextureRect().width;
}



/*Private medlemsfunktioner*/
void Player::move(float dt){
	float currentX = mAnimation->getSprite().getPosition().x;
	float currentY = mAnimation->getSprite().getPosition().y;

	sf::Vector2f oldVelocity = mVelocity;

	/* Om den nuvarande hastigheten mVelocity är mindre än maxhastigheten, mSpeed, så ökas den nuvarande hastigheten med accelerationen, mAcceleration */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if (mVelocity.x < mSpeed){
			mVelocity.x += mAcceleration;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if (mVelocity.x > -mSpeed){
			mVelocity.x -= mAcceleration;
		}
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (mVelocity.y < mSpeed){
			mVelocity.y += mAcceleration;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if (mVelocity.y > -mSpeed){
			mVelocity.y -= mAcceleration;
		}
	}
	/* För att sakta ner spelaren gångras den nuvarande hastigheten med ett värde som är mindre än 1. */
	mVelocity.x = mVelocity.x*0.935f;
	currentX = currentX + (oldVelocity.x + mVelocity.x) * 0.5 * dt;

	mVelocity.y = mVelocity.y*0.935f;
	currentY = currentY + (oldVelocity.y + mVelocity.y) * 0.5 * dt;
	/* Den nuvarande positionen uppdateras med det nya värdet */
	mAnimation->setPosition(sf::Vector2f(currentX, currentY));
}

void Player::fire(EntityVector &entities){

	sf::Time isReloaded = reloadTimer.getElapsedTime();
	if (isReloaded.asMilliseconds() > 200){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			entities.push_back(new Ray(getPosition()));
			/* Spelar upp skjutljud */
			ResourceManager::play("resource/sounds/shoot.wav");
			reloadTimer.restart();
		}
	}
}

