#include "LoadLevel.hpp"


LoadLevel::LoadLevel() {

	
}


LoadLevel::~LoadLevel(){
}

void LoadLevel::setVector(Entity::EntityVector &entityVector){
	mEntityVector = entityVector;
	
}
Entity::EntityVector LoadLevel::getVector(){

	return mEntityVector;
}

void LoadLevel::setLevel(/*Entity::EntityVector &entityVector*/){
	/*sätter banan till 1*/
	int level1 = 1;

	/*väljer bana 1*/
	if (level1 == 1){ levelEnum = LevelEnum::firstLevel; }

	switch (levelEnum)	{
	case LoadLevel::firstLevel:
	//	level->spawnBasicEnemies(3.0f, 4.0f, 3, getVector());

		break;
	case LoadLevel::secondLevel:
		break;
	case LoadLevel::thirdLevel:
		break;
	case LoadLevel::fourthLevel:
		break;
	case LoadLevel::fifthLevel:
		break;
	case LoadLevel::sixtLevel:
		break;
	case LoadLevel::seventhLevel:
		break;
	case LoadLevel::eighthLevel:
		break;
	default:
		break;
	}

}


int LoadLevel::getLevel(){


	return levelEnum;
}


























