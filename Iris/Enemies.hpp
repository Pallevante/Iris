#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
public:
	/*´Bas klass för fiender. 
		Använder lite speciella funktioner som kan behövas av Enity. */
	Enemy();
	~Enemy();
	virtual void death(float dt) = 0;
	virtual void fire(EntityVector &enteties) = 0;
	virtual void move(float dt) = 0;
	virtual void useAbility() = 0;
private:
};