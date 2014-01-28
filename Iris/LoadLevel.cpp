#include "LoadLevel.hpp"


LoadLevel::LoadLevel(){


}


LoadLevel::~LoadLevel(){
}


void LoadLevel::setLevel(){
	int level1 = 1;


	if (level1 == 1){ level = Level::firstLevel; }

	switch (level)
	{
	case LoadLevel::firstLevel:
		entityVector->push_back(new Player(400, 400, 2));
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


	return level;
}