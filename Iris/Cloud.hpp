#pragma once
#include "Enemy.hpp"
#include <cstdlib>
#include "Animation.hpp"

class Cloud : public Enemy{
public:
	Cloud();
	Cloud(float speedMultiplier, sf::Vector2f position);
	~Cloud();
	virtual float getRad() const;
	virtual sf::Vector2f getPosition();
	virtual int getHeight() const;
	virtual int getWidth() const;
	virtual int getDamage()	const;
	virtual Type getType() const;
	virtual void setDamage(int newDamage);
	virtual int collide(Entity *e0, EntityVector &entities);
	virtual bool isAlive();

	virtual Movement getMovement();
	virtual void tick(EntityVector &entities, float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw(mAnimation->getSprite(), states);

	}
	/*Medlemsfunktioner för Enemy*/
	virtual void death(float dt);
	virtual void fire(EntityVector &enteties);
	virtual void move(EntityVector &enteties, float dt);
	virtual void useAbility();

private:
	float setYPos();
	Animation* mAnimation;
	float mSpeed;
	bool mIsAlive;
	bool mIsDying;
	float mHealth;
	float mRad;
	int mDamage;
};

