#pragma once
#include <SFML\Graphics.hpp>
#include "World.hpp"


class LoadLevel
{


public:
	LoadLevel();
	~LoadLevel();
	void setLevel(Entity::EntityVector &entityVector);
	int getLevel();

protected:
	enum Level	{
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
	Level level;
	ResourceManager *mResourceManager;
	sf::Sprite mSprite;
	sf::Texture mTexture;
};
