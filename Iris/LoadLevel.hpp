#pragma once
#include <SFML\Graphics.hpp>
#include "Level.hpp"

class LoadLevel{
public:
	enum LevelEnum  {
		firstLevel,
		secondLevel,
		thirdLevel,
		fourthLevel,
		fifthLevel,
		sixtLevel,
		seventhLevel,
		eighthLevel
	};

	LoadLevel();
	~LoadLevel();
	void setLevel(LevelEnum& levelToLoad);
	Level* getLevel();

private:
	LevelEnum mLevelEnum;
};