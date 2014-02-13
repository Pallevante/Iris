#pragma once
#include <SFML\Graphics.hpp>
#include "Level.hpp"
/*Denna frammåt dekleration löste mina problem med instanser samt felet
; före * som vi fick ett tag.*/
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

	LoadLevel();
	~LoadLevel();
	/*Anropas av World.*/
	void setLevel(LevelEnum& levelToLoad);	
	Level* getLevel();
private:

};
