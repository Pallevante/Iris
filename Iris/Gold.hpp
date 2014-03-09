#pragma once
#include "Entity.hpp"
#include "Animation.hpp"

class Gold : public Entity{
public:
	enum Movement{
		DEFAULT,
		MAGNET
	};
	Gold(sf::Vector2f position);
	~Gold();
	float setYPos();
	virtual int getHeight() const;
	virtual int getWidth() const;
	virtual Type getType() const;	
	virtual sf::Vector2f getPosition();
	virtual float getRad() const;
	virtual void tick(EntityVector &entities, float dt);
	virtual int getDamage() const;
	virtual void setDamage(int newDamage);
	virtual bool isAlive();
	virtual int collide(Entity *e0, EntityVector &entities);
	virtual void setMovement(Movement movement);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw(mAnimation->getSprite(), states);
	}
private:
	Movement mMovement;
	bool mIsAlive;
	float mSpeed, mAcceleration;
	void move(EntityVector &entities, float dt);
	Movement getMovement() const;
	Animation* mAnimation;
};