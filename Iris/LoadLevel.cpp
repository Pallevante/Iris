#include "LoadLevel.hpp"

Level* mLevel = new Level;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}

/*Sätter variablerna för nivå 1 i detta fall. kommer att utökas i framtida versioner.*/
void LoadLevel::setLevel(LevelEnum& levelToLoad){

	if (levelToLoad == FIRSTLEVEL){
		mLevel->set(3, 5, 0.5, 4, 5, 1, 0, 0, 0, 1);
	}
}
/*Anropas av World för att hämta pekaren så den kan rita ut bakgrunden och spawna fiender.*/

Level* LoadLevel::getLevel(){
	return mLevel;
}