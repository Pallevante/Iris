#include "LoadLevel.hpp"

Level* mLevel = new Level;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}

/*Sätter variablerna för nivå 1 i detta fall. kommer att utökas i framtida versioner.*/
void LoadLevel::setLevel(LevelEnum& levelToLoad){
	if (levelToLoad == firstLevel){
		mLevel->set(3.0f, 5.0f, 0.5f, 4.0f, 5.0f,5.0f,5.0f,3,5, 1);
		
	}

}
/*Anropas av World för att hämta pekaren så den kan rita ut bakgrunden och spawna fiender.*/

Level* LoadLevel::getLevel(){
	return mLevel;
}