#include "LoadLevel.hpp"

Level* mLevel = new Level;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}

/*Sätter variablerna för nivå 1 i detta fall. kommer att utökas i framtida versioner.*/
void LoadLevel::setLevel(LevelEnum& levelToLoad){

	if (levelToLoad == FIRSTLEVEL){
		mLevel->set(4, 4, 0.5, 10, 10, 1, 0, 0, 0, 1, 90);
	}

	else if (levelToLoad == SECONDLEVEL){
		mLevel->set(3, 3, 0.6, 10, 10, 1, 5, 5, 1, 2, 150);
	}
}
/*Anropas av World för att hämta pekaren så den kan rita ut bakgrunden och spawna fiender.*/
Level* LoadLevel::getLevel(){
	return mLevel;
}

LoadLevel::LevelEnum LoadLevel::mCurrentLevel;