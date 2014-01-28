#include "Ray.hpp"


Ray::Ray(sf::Vector2f position, Animation *animation) :
mDamage(10),
mRad(3),
mSpeed(4),
mAnimation(animation)
{
	mAnimation->setPosition(position);
}

Ray::~Ray(){}

float Ray::getRad() const{
	return mRad;
}
sf::Vector2f Ray::getPosition(){
	return mAnimation->getSprite().getPosition();
}
int Ray::getDamage() const{
	return mDamage;
}
Ray::Type Ray::getType() const{
	return RAY;
}

void Ray::setDamage(int newDamage){
	mDamage = newDamage;
}

int Ray::collide(Entity *e0, EntityVector &entities){
	if (e0->getDamage() > 0){
		mIsAlive = false;		
	}
	return 0;
}

bool Ray::isAlive(){
	return mIsAlive;
}

void Ray::tick(EntityVector &entities){
	move();
}

void Ray::move(){
	float currentX = mAnimation->getSprite().getPosition().x;
	float currentY = mAnimation->getSprite().getPosition().y;

	mAnimation->setPosition(sf::Vector2f(currentX + mSpeed, currentY));
}