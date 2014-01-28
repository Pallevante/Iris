#pragma once
#include "Entity.hpp"
#include "Animation.h"

class Ray :	public Entity{
public:
	Ray(sf::Vector2f position, Animation *animation);
	~Ray();
	virtual float getRad() const;
	virtual sf::Vector2f getPosition();
	virtual int getDamage()	const;
	virtual Type getType() const;
	virtual void setDamage(int newDamage);
	virtual int collide(Entity *e0, EntityVector &entities);
	virtual bool isAlive();
	virtual void tick(EntityVector &entities);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw(mAnimation->getSprite(), states);
	}
private:
	void move();
	Animation* mAnimation;
	bool mIsAlive;
	float mDamage;
	float mRad;
	float mSpeed;
};

