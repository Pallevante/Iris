#pragma once
#include <SFML\Graphics.hpp>
#include "Level.hpp"


class LoadLevel
{


public:
	LoadLevel();
	~LoadLevel();
	void setLevel();
	int getLevel();
	void setVector(Entity::EntityVector &entityVector);
	Entity::EntityVector getVector();


protected:
	enum LevelEnum	{
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
	LevelEnum levelEnum;
	Level *level;
	ResourceManager *mc;
	sf::Sprite mSprite;
	sf::Texture mTexture;
	Entity::EntityVector mEntityVector;
};
