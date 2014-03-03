#pragma once
#include <fstream>
#include <iostream>
#include "LoadLevel.hpp"
#include "Level.hpp"
#include "World.hpp"

class LoadSave{
public:
	LoadSave();
	~LoadSave();
	void load();
	void save();

	//std::string encrypt(std::string line);
	//std::string decrypt(std::string line);
	//LoadLevel::LevelEnum getLevel(int level);
private:
	std::string mFilename;
	std::string mContent[10];
	std::ifstream mSaveFile;
	int mCryptKey = 42; //Svaret på allt.
};