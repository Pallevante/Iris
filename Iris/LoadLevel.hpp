#pragma once
#include <SFML\Graphics.hpp>
#include "Level.hpp"


class LoadLevel
{


public:
	LoadLevel();
	~LoadLevel();
	void setLevel(/*Entity::EntityVector &entityVector*/);
	int getLevel();
	void setVector(Entity::EntityVector &entityVector);
	Entity::EntityVector getVector();
	//virtual float enemySpawnTimeMin();
	//virtual float enemySpawnTimeMax();
	//virtual float percentRequirement();
	//virtual float specialEnemySpawnTimeMin();
	//virtual float specialEnemySpawnTimeMax();
	//virtual float obstacleSpawnTimeMin();
	//virtual float ostacleSpawnTimeMax();
	//virtual float scoreRequirement();

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
