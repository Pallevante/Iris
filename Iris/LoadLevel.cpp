#include "LoadLevel.hpp"

Level* mLevel = new Level;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}

/*S�tter variablerna f�r niv� 1 i detta fall. kommer att ut�kas i framtida versioner.*/
void LoadLevel::setLevel(LevelEnum& levelToLoad){

	if (levelToLoad == FIRSTLEVEL){
		mLevel->set(4, 4, 0.5, 10, 10, 1, 0, 0, 0, 1, 90);
	}
	else if (levelToLoad == SECONDLEVEL){
		mLevel->set(3, 3, 0.6, 10, 10, 1, 5, 5, 1, 2, 150);
	}
	else if (levelToLoad == THIRDLEVEL){
		mLevel->set(3, 3, 0.6, 10, 10, 3, 3, 1, 1, 3, 150);
	}
	else if (levelToLoad == EIGHTLEVEL){
		mLevel->set(0, 0, 0.6, 4, 6, 1, 1, 4, 0, 8, 150);
	}
}
/*Anropas av World f�r att h�mta pekaren s� den kan rita ut bakgrunden och spawna fiender.*/
Level* LoadLevel::getLevel(){
	return mLevel;
}

LoadLevel::LevelEnum LoadLevel::mCurrentLevel;