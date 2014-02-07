#include "Ray.hpp"


Ray::Ray(sf::Vector2f position) :
mDamage(10),
mRad(64),
mSpeed(7),
mIsAlive(true)
{
	mAnimation = new Animation("resource/textures/entities/ray.png", 100, 13);
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


int Ray::getHeight() const {
	return mAnimation->getSprite().getTextureRect().height;
}

int Ray::getWidth() const {
	return mAnimation->getSprite().getTextureRect().width;
}

void Ray::setDamage(int newDamage){
	mDamage = newDamage;
}

int Ray::collide(Entity *e0, EntityVector &entities){
	if (e0->getDamage() > 0 && e0->getType() != Type::PLAYER){
		mIsAlive = false;		
	}
	return 0;
}

bool Ray::isAlive(){
	return mIsAlive;
}

void Ray::tick(EntityVector &entities){
	move();
	mAnimation->Update();
}

void Ray::move(){
	float currentX = mAnimation->getSprite().getPosition().x;
	float currentY = mAnimation->getSprite().getPosition().y;

	mAnimation->setPosition(sf::Vector2f(currentX + mSpeed, currentY));
}