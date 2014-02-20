#pragma once
#include <map>
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include "ResourceManager.hpp"



//Basklass f�r alla entiteter. 
//Kommer nog beh�vas byggas ut.
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


	/* Anv�nd play("resource/exempel.ogg") f�r att spela upp ett ljud. Minneshantering sker automatiskt. */
	/* Funktionen arbetar b�de med resurshanteraren f�r att h�lla koll p� soundbuffers och undvika flera inladdningar av samma fil, */
	/* samtidigt som den skapar Sounds som beh�vs och h�ller dem levande under programmets g�ng. */


private:
	
};