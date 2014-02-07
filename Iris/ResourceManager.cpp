#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){

}
ResourceManager::~ResourceManager(){

}


//Animation& ResourceManager::getAnimation(const std::string& filename, int timePerFrame, int numFrames){
//	/* Jag valde att kolla om resursen redan existerade i mapen genom att räkna antalet resurser med samma filnamn */
//	if (mAnimations.count(filename) == 0){
//		mAnimations.insert(std::pair<std::string, Animation>(filename, Animation(filename, timePerFrame, numFrames)));
//	}
//	/* MÅSTE använda det här sättet att returnera på Animation eftersom Animation inte använder en defaultkonstruktor */
//	/* Provar man att använda return mAnimation[filename] istället så får man fel om att den saknar defaultkonstruktor */
//	return mAnimations.find(filename)->second;
//}
sf::Texture& ResourceManager::getTexture(const std::string& filename){
	if (mTextures.count(filename) == 0){
		sf::Texture newTexture;
		newTexture.loadFromFile(filename);

		mTextures.insert(std::pair<std::string, sf::Texture>(filename, newTexture));
	}
	return mTextures.find(filename)->second;
}
sf::Texture& ResourceManager::getLevel(const std::string& filename){
	if (mLevels.count(filename) == 0){
		sf::Texture newTexture;
		newTexture.loadFromFile(filename);

		mLevels.insert(std::pair<std::string, sf::Texture>(filename, newTexture));
	}
	return mLevels.find(filename)->second;
}
sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& filename){
	if (mSoundBuffers.count(filename) == 0){
		sf::SoundBuffer newSound;
		newSound.loadFromFile(filename);

		mSoundBuffers.insert(std::pair<std::string, sf::SoundBuffer>(filename, newSound));
	}
	return mSoundBuffers.find(filename)->second;
}

/* Funktionen arbetar både med resurshanteraren för att hålla koll på soundbuffers och undvika flera inladdningar av samma fil, */
/* samtidigt som den skapar Sounds som behövs och håller dem levande under programmets gång. */
sf::Sound& ResourceManager::getSound(const std::string& filename){
	if (mSounds.count(filename) == 0){
		sf::Sound newSound;
		newSound.setBuffer(getSoundBuffer(filename));
		mSounds.insert(std::pair<std::string, sf::Sound>(filename, newSound));
	}
	return mSounds[filename];
}



/* Det här är min bane */
//std::map<std::string, Animation> ResourceManager::mAnimations;
std::map<std::string, sf::Texture> ResourceManager::mTextures;
std::map<std::string, sf::Texture> ResourceManager::mLevels;
std::map<std::string, sf::Sound> ResourceManager::mSounds;
std::map<std::string, sf::SoundBuffer> ResourceManager::mSoundBuffers;
std::map<std::string, sf::Image> ResourceManager::mImages;