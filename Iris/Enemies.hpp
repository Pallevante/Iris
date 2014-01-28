#pragma once
#include "Entity.hpp"

class Enemy : public Entity {
public:
	Enemy();
	~Enemy();
	virtual void death() = 0;
	virtual void fire() = 0;
	virtual void move() = 0;
	virtual void useAbility() = 0;
private:
};