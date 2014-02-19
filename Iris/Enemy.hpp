#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
public:
	/*�Bas klass f�r fiender. 
		Anv�nder lite speciella funktioner som kan beh�vas av Enity. */
	Enemy();
	~Enemy();

	enum Movement{
		DEFAULT,
		WAVE,
		FOLLOWING
	};
	/*Kan anv�nda en parameter vid skapandet av enemy f�r vilket r�relsem�nster denne skall ha. */
	virtual Movement getMovement() = 0;
	virtual void death(float dt) = 0;
	virtual void fire(EntityVector &enteties) = 0;
	virtual void move(EntityVector& entities, float dt) = 0;
	virtual void useAbility() = 0;
private:
};