#pragma once
#include "Entity.hpp"
class Player : public Entity{
public:
	Player(float xPosition, float yPosition, int speedMultiplier = 1);
	~Player();
	virtual float getRad() const;
	virtual sf::Vector2f getPosition() const;
	virtual int getDamage()	const;
	virtual Type getType() const;
	virtual void setDamage(int newDamage);
	virtual int collide(Entity *e0, EntityVector &entities);
	virtual bool isAlive();
	virtual void tick(EntityVector &entities);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw(mCircleShape, states);
	}
private: 
	void move();
	void fire(EntityVector &enteties);
	sf::CircleShape mCircleShape;
	float mSpeed;
	int mHealth;
	int mDamage;
	float mRad;
	bool mIsAlive;
};