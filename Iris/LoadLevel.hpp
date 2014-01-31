#pragma once
#include <SFML\Graphics.hpp>
#include "Level.hpp"
/*Denna framm�t dekleration l�ste mina problem med instanser samt felet
; f�re * som vi fick ett tag.*/
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
