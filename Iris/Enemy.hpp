#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
public:
	/*´Bas klass för fiender. 
		Använder lite speciella funktioner som kan behövas av Enity. */
	Enemy();
	~Enemy();

	enum Movement{
		DEFAULT,
		WAVE,
		FOLLOWING
	};
	/*Kan använda en parameter vid skapandet av enemy för vilket rörelsemönster denne skall ha. */
	virtual Movement getMovement() = 0;
	virtual void death(float dt) = 0;
	virtual void fire(EntityVector &enteties) = 0;
	virtual void move(EntityVector& entities, float dt) = 0;
	virtual void useAbility() = 0;
private:
};