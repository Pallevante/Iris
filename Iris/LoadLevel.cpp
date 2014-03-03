#include "LoadLevel.hpp"

Level* mLevel = new Level;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}

/*S�tter variablerna f�r niv� 1 i detta fall. kommer att ut�kas i framtida versioner.*/
void LoadLevel::setLevel(LevelEnum& levelToLoad){

	if (levelToLoad == FIRSTLEVEL){
		mLevel->set(2, 3, 0.5, 4, 5, 1, 0, 0, 0, 1, 90);
	}

	else if (levelToLoad == SECONDLEVEL){
		mLevel->set(0.5, 1.5, 0.6, 4, 5, 1, 0, 0, 0, 2, 120);
	}
}
/*Anropas av World f�r att h�mta pekaren s� den kan rita ut bakgrunden och spawna fiender.*/
Level* LoadLevel::getLevel(){
	return mLevel;
}

LoadLevel::LevelEnum LoadLevel::mCurrentLevel;