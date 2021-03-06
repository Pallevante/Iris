#pragma once
#include "Animation.hpp"
#include "Entity.hpp"
#include "Ray.hpp"
#include "ResourceManager.hpp"


class Player : public Entity{
public:
	Player(float xPosition, float yPosition, float speedMultiplier = 1);
	

	~Player();
	void updateAura(float score);
	virtual float getRad() const;
	virtual sf::Vector2f getPosition();
	virtual int getHeight() const;
	virtual int getWidth() const;
	virtual int getDamage()	const;
	virtual Type getType() const;
	virtual void setDamage(int newDamage);
	virtual int collide(Entity *e0, EntityVector &entities);
	virtual bool isAlive();
	virtual void tick(EntityVector &entities, float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw(mAura->getSprite(), states);
		target.draw(mAnimation->getSprite(), states);
	}
	void reset();
private:
	void idleAnimation();
	void move(float dt);
	void fire(EntityVector &enteties);	
	Animation* mAnimation;
	Animation* mAura;
	EntityVector &entities;
	float mSpeed;
	float opacity;
	int mHealth;
	int mDamage;
	float mRad;
	bool mIsAlive;
	sf::Vector2f mVelocity;
	float mAcceleration;
};