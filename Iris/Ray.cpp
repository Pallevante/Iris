#include "Ray.hpp"


Ray::Ray(sf::Vector2f position, bool isEnemy) :
mDamage(1),
mRad(64),
mSpeed(420),
mIsEnemy(isEnemy),
mIsAlive(true){
	//Sätter animationen på ray.
	if (!mIsEnemy)
		mAnimation = new Animation("resource/textures/entities/ray.png", 100, 17);
	else if (mIsEnemy)
		mAnimation = new Animation("resource/textures/entities/imp_ray.png", 100, 5);

		mAnimation->setPosition(position);

}

Ray::~Ray(){
	delete mAnimation;
}

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
	/*Detta är så att vi slipper göra flera undantag i collide.*/
	if (!mIsEnemy)
		return RAY;
	else
		return ENEMY;
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
	if (e0->getType() == ENEMY && getType() == RAY){
		mIsAlive = false;
	}
	else if (e0->getType() == PLAYER && getType() == ENEMY){
		mIsAlive = false;
	}
	return 0;
}

bool Ray::isAlive(){
	return mIsAlive;
}

void Ray::tick(EntityVector &entities, float dt){
	move(dt);
	mAnimation->Update();
}

void Ray::move(float dt){
	float currentX = mAnimation->getSprite().getPosition().x;
	float currentY = mAnimation->getSprite().getPosition().y;

	if (!mIsEnemy)
		currentX = currentX + (mSpeed * dt);
	else if(mIsEnemy)
		currentX = currentX + (-2 *mSpeed * dt);

	mAnimation->setPosition(sf::Vector2f(currentX, currentY));
}