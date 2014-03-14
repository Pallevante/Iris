#include "LoadLevel.hpp"

Level* mLevel = new Level;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}

/*S�tter variablerna f�r niv� 1 i detta fall. kommer att ut�kas i framtida versioner.*/
void LoadLevel::setLevel(LevelEnum& levelToLoad){

	if (levelToLoad == FIRSTLEVEL){
		mLevel->set(3.0f, 4, 0, 0, 0.5f, 0, 0, 1, 90);
	}

	else if (levelToLoad == SECONDLEVEL){
		mLevel->set(2.0f, 6, 3.0f, 2, 0.6f, 0, 0, 2, 150);
	}
}
/*Anropas av World f�r att h�mta pekaren s� den kan rita ut bakgrunden och spawna fiender.*/
Level* LoadLevel::getLevel(){
	return mLevel;
}

LoadLevel::LevelEnum LoadLevel::mCurrentLevel;