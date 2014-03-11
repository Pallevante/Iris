#include "Gold.hpp"

Gold::Gold(sf::Vector2f position) :

mSpeed(300),
mAcceleration(0.5f),
mIsAlive(true)
//Måste ändras relativt till bilden.
{
	mAnimation = new Animation("resource/textures/entities/gold.png", 100, 4);
	mAnimation->setPosition(position);
}
float Gold::setYPos(){
	float random = rand() % 720 - mAnimation->getSprite().getGlobalBounds().height + 1;
	if (random < 0){
		random += mAnimation->getSprite().getGlobalBounds().height;
	}
	return random;
}

Gold::~Gold(){
	delete mAnimation;
}

int Gold::getHeight() const{
	return mAnimation->getSprite().getTextureRect().height;
}

int Gold::getWidth() const{
	return mAnimation->getSprite().getTextureRect().width;
}

Gold::Type Gold::getType() const{
	return GOLD;
}

sf::Vector2f Gold::getPosition(){
	return mAnimation->getSprite().getPosition();
}

float Gold::getRad() const {
	float x = mAnimation->getSprite().getTextureRect().width;
	float y = mAnimation->getSprite().getTextureRect().height;

	return sqrtf(powf(x, 2) + powf(y, 2)) / 2;
}

void Gold::tick(EntityVector &entities, float dt){
	mAnimation->Update();
	move(entities, dt);
}

/*Du använder en check i collision i world om typen är GOLD sedan hämtar du damage för värdet.*/
int Gold::getDamage() const{
	return 1;
}

void Gold::setDamage(int newDamage){
	return;
}

bool Gold::isAlive(){
	return mIsAlive;
}

int Gold::collide(Entity *e0, EntityVector &entities){
	if (e0->getType() == PLAYER){
		mIsAlive = false;
		ResourceManager::getSound("resource/sounds/Coin.ogg").play();
	}
	return 0;
}

void Gold::setMovement(Movement movement){
	mMovement = movement;
}

void Gold::move(EntityVector &entities, float dt){
	mAnimation->setPosition(sf::Vector2f(getPosition().x - mSpeed * dt, getPosition().y));
}