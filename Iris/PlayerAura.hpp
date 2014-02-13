#pragma once
#include "Animation.hpp"
#include "Entity.hpp"
#include "Ray.hpp"
#include "ResourceManager.hpp"



class PlayerAura : public Entity{
public:
	PlayerAura(float xPosition, float yPosition, float speedMultiplier = 1);


	~PlayerAura();


	virtual float getRad() const;
	virtual sf::Vector2f getPosition();
	virtual sf::Color getColor();
	virtual int getHeight() const;
	virtual int getWidth() const;
	virtual int getDamage()	const;
	virtual Type getType() const;
	virtual void setDamage(int newDamage);
	virtual int collide(Entity *entity, EntityVector &entities);
	//int collide1(Entity *entity, Entity *entity1, EntityVector &entities);
	virtual bool isAlive();
	virtual void tick(EntityVector &entities, float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
		target.draw(mAnimation->getSprite(), states);
	}
	
		
private:
	void move(float dt);
	void fire(EntityVector &enteties);
	void aura();
	Animation* mAnimation;
	float mSpeed;
	int mHealth;
	int mDamage;
	float mRad;
	bool mIsAlive;
	sf::Vector2f mVelocity;
	float mAcceleration;
};