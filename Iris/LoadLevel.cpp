#include "LoadLevel.hpp"

Level* mLevel;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}

/*S�tter variablerna f�r niv� 1 i detta fall. kommer att ut�kas i framtida versioner.*/
void LoadLevel::setLevel(LevelEnum& levelToLoad){
	if (levelToLoad == firstLevel){
		mLevel->set(3, 5, 0.5, 4, 5, 1);
	}
}
/*Anropas av World f�r att h�mta pekaren s� den kan rita ut bakgrunden och spawna fiender.*/
Level* LoadLevel::getLevel(){
	return mLevel;
}