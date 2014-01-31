#pragma once
#include <SFML\Graphics.hpp>
#include "Level.hpp"
/*Denna frammåt dekleration löste mina problem med instanser samt felet
; före * som vi fick ett tag.*/
class Level;

class LoadLevel{
public:
	static enum LevelEnum {
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
	LevelEnum currentLevel;
private:

};
