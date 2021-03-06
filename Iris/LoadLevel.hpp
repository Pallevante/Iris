#pragma once
#include <SFML\Graphics.hpp>
#include "Level.hpp"
/*Denna framm�t dekleration l�ste mina problem med instanser samt felet
; f�re * som vi fick ett tag.*/
class Level;

class LoadLevel{
public:
	static enum LevelEnum {
		FIRSTLEVEL,
		SECONDLEVEL,
		THIRDLEVEL,
		FOURTHLEVEL,
		FIFTHLEVEL,
		SIXTHLEVEL,
		SEVENTHLEVEL,
		EIGHTLEVEL
	};
	static LevelEnum mCurrentLevel;
	LoadLevel();
	~LoadLevel();
	/*Anropas av World.*/
	void setLevel(LevelEnum& levelToLoad);	
	Level* getLevel();
private:

};
