#include "Player.hpp"
sf::Clock reloadTimer;

/*Public funktioner*/



Player::Player(float xPosition, float yPosition, float speedMultiplier) :

mDamage(10),
mSpeed(4 * speedMultiplier),
mIsAlive(true),
//Måste ändras relativt till bilden.
mRad(20.f)
{	
	mAnimation = new Animation("resource/Iris_flying_anim2.png", 100, 8);
	mAnimation->setPosition(sf::Vector2f(xPosition, yPosition));
}

Player::~Player(){}

void Player::tick(EntityVector &entities){
	move();
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

void Player::fire(EntityVector &entities){

	sf::Time isReloaded = reloadTimer.getElapsedTime();
	if (isReloaded.asMilliseconds() > 200){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			entities.push_back(new Ray(getPosition()));
			/* Spelar upp skjutljud */
			play("resource/shoot.wav");
			reloadTimer.restart();
		}
	}
}

