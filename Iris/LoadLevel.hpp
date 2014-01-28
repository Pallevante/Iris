#pragma once
#include <SFML\Graphics.hpp>
#include "World.hpp"


class LoadLevel
{


public:
	LoadLevel();
	~LoadLevel();
	void setLevel();
	int getLevel();

protected:
	enum Level
	{
		firstLevel,
		secondLevel,
		thirdLevel,
		fourthLevel,
		fifthLevel,
		sixtLevel,
		seventhLevel,
		eighthLevel
	};

private:
	//::Sprite mSprite;
	//sf::Texture mTexture;
	sf::CircleShape shape;
	//EntityVector entityVector;
	Level level;
	//typedef std::vector<Entity*> EntityVector;
	Entity::EntityVector *entityVector;

};
