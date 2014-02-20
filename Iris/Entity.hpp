#pragma once
#include <map>
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include "ResourceManager.hpp"



//Basklass för alla entiteter. 
//Kommer nog behövas byggas ut.
class Entity : public sf::Drawable {
public:
	enum Type{
		PLAYER,
		RAY, 
		ENEMY,
		GOLD
	};
	Entity();
	~Entity();
	typedef std::vector<Entity*> EntityVector;
	virtual int getHeight() const = 0;
	virtual int getWidth() const = 0;
	virtual Type getType() const = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual float getRad() const = 0;
	virtual void tick(EntityVector &entities, float dt) = 0;
	virtual int getDamage() const = 0;
	virtual void setDamage(int newDamage) = 0;
	virtual bool isAlive() = 0;
	virtual int collide(Entity *e0, EntityVector &entities) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;


	/* Använd play("resource/exempel.ogg") för att spela upp ett ljud. Minneshantering sker automatiskt. */
	/* Funktionen arbetar både med resurshanteraren för att hålla koll på soundbuffers och undvika flera inladdningar av samma fil, */
	/* samtidigt som den skapar Sounds som behövs och håller dem levande under programmets gång. */


private:
	
};