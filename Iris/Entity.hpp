#pragma once
#include <vector>
#include <SFML\Graphics.hpp>


//Base class for all entities. 
//May need improvements. 
class Entity : public sf::Drawable {
public:
	Entity();
	~Entity();
	typedef std::vector<Entity*> EntityVector;
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual void tick(EntityVector &entities) = 0;
	virtual int getDamage() = 0;
	virtual bool isAlive() = 0;
	virtual int collide(Entity *e0, EntityVector &entities) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
private:
};