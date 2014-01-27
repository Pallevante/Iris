#pragma once
#include <vector>
#include <SFML\Graphics.hpp>


//Basklass för alla entiteter. 
//Kommer nog behövas byggas ut.
class Entity : public sf::Drawable {
public:
	enum Type{
		PLAYER,
		RAY, 
		ENEMY
	};
	Entity();
	~Entity();
	typedef std::vector<Entity*> EntityVector;
	virtual Type getType() const = 0;
	virtual sf::Vector2f getPosition() const = 0;
	virtual float getRad() const = 0;
	virtual void tick(EntityVector &entities) = 0;
	virtual int getDamage() const = 0;
	virtual void setDamage(int newDamage) = 0;
	virtual bool isAlive() = 0;
	virtual int collide(Entity *e0, EntityVector &entities) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
private:
};