#include "LoadLevel.hpp"

Level* mLevel;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}


void LoadLevel::setLevel(LevelEnum& levelToLoad){
	if (levelToLoad == firstLevel){
		mLevel->set(3.0f, 5.0f, 0.5f, 4.0f, 5.0f,3,5.0f,5.0f,5);
		
	}
}

Level* LoadLevel::getLevel(){
	return mLevel;
}