#include "LoadLevel.hpp"

Level* mLevel;

LoadLevel::LoadLevel(){}


LoadLevel::~LoadLevel(){
}


void LoadLevel::setLevel(LevelEnum& levelToLoad){
	if (levelToLoad == firstLevel){
		mLevel->set(3, 5, 0.5, 4, 5,3,0,0,0);
		
	}
}

Level* LoadLevel::getLevel(){
	return mLevel;
}