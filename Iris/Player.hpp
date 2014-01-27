#pragma once
#include "Entity.hpp"
#include "Ray.hpp"
#include "Animation.h"


class Player : public Entity{
public:
	Player(Animation &animation, float xPosition, float yPosition, int speedMultiplier = 1);
	~Player();
	virtual float getRad() const;
	virtual sf::Vector2f getPosition();
	virtual int getDamage()	const;
	virtual Type getType() const;
	virtual void setDamage(int newDamage);
	virtual int collide(Entity *e0, EntityVector &entities);
	virtual bool isAlive();
	virtual void tick(EntityVector &entities);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(mSprite, states);
		//Fucking hell vad jag hatar denna klassen...
	}
private: 
	void move();
	void fire(EntityVector &enteties);
	Animation &mAnimation;
	sf::Sprite mSprite = mAnimation.getSprite();

	float mSpeed;
	int mHealth;
	int mDamage;
	float mRad;
	bool mIsAlive;
};