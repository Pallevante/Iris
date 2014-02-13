#include "Gold.hpp"

Gold::Gold(float xPosition, float yPosition): 

mSpeed(6),
mAcceleration(0.5f),
mIsAlive(true)
//M�ste �ndras relativt till bilden.
{
	mAnimation = new Animation("resource/textures/entities/gold.png", 100, 8);
	mAnimation->setPosition(sf::Vector2f(xPosition, yPosition));

}


Gold::~Gold(){}

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
	move(entities, dt);
}

/*Du anv�nder en check i collision i world om typen �r GOLD sedan h�mtar du damage f�r v�rdet.*/
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
		return getDamage();
	}
	else
		return 0;
}

void Gold::setMovement(Movement movement){
	mMovement = movement;
}

void Gold::move(EntityVector &entities, float dt){

}