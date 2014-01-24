#pragma once
#include "Entity.hpp"
class Player : public Entity{
public:
	Player(float xPosition, float yPosition);
	~Player();
	virtual float getRad() const;
	virtual float getX() const;
	virtual float getY() const;
	virtual int getDamage()	const;
	virtual int setDamage(int newDamage) const;
	virtual int collide(Entity *e0, EntityVector &entities);
	virtual bool isAlive();
	virtual void tick(EntityVector &entities);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private: 
	int mHealth;
	int mDamage;
	float mRad;
	bool mIsAlive;
};