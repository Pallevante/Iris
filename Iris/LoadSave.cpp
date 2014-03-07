#include "LoadSave.hpp"


/*
Saving-funktionen ska vara uppbyggd enligt följande:
Nuvarande bana man är på.
Guldet.
Alla power-ups man köpt.
*/


LoadSave::LoadSave(): 
	mFilename("saves/Savefile"),
	mSaveFile(mFilename)
{}

LoadSave::~LoadSave(){}

//Laddar in filens rader i en sträng-array.
void LoadSave::load(){	
	if (mSaveFile.good()){
		for (int line = 0; mSaveFile.good(); line++){
			std::getline(mSaveFile, mContent[line]);
		}
		//World::mCurrentLevel = getLevel(std::stoi(decrypt(mContent[0])));
		//World::mGold = std::stoi(decrypt(mContent[1]));
		for (int index = 2; mSaveFile.good(); index++){
			//Här får vi ha en ability vector pekare/referens
		}
	}
	else
		return;
}
/*Allt denna gör för tillfället är fuck all.*/
void LoadSave::save(){}

/*LoadLevel::LevelEnum LoadSave::getLevel(int level){
	switch (level){
	case 1:
		return LoadLevel::FIRSTLEVEL;
		break;
	case 2:
		return LoadLevel::SECONDLEVEL;
		break;
	case 3:
		return LoadLevel::THIRDLEVEL;
		break;
	case 4:
		return LoadLevel::FOURTHLEVEL;
		break;
	case 5:
		return LoadLevel::FIFTHLEVEL;
		break;
	case 6:
		return LoadLevel::SIXTHLEVEL;
		break;
	case 7:
		return LoadLevel::SEVENTHLEVEL;
		break;
	case 8: 
		return LoadLevel::EIGHTLEVEL;
		break;
	}
}

/*
std::string LoadSave::encrypt(std::string line){
	for (int index = 0; index <= line.length; index++){
		line[index] += mCryptKey;
	}
	return line;
}

std::string LoadSave::decrypt(std::string line){
	for (int index = 0; index <= line.length; index++){
		line[index] -= mCryptKey;
	}
	return line;
}*/