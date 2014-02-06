#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){

}
ResourceManager::~ResourceManager(){

}


//Animation& ResourceManager::getAnimation(const std::string& filename, int timePerFrame, int numFrames){
//	/* Jag valde att kolla om resursen redan existerade i mapen genom att r�kna antalet resurser med samma filnamn */
//	if (mAnimations.count(filename) == 0){
//		mAnimations.insert(std::pair<std::string, Animation>(filename, Animation(filename, timePerFrame, numFrames)));
//	}
//	/* M�STE anv�nda det h�r s�ttet att returnera p� Animation eftersom Animation inte anv�nder en defaultkonstruktor */
//	/* Provar man att anv�nda return mAnimation[filename] ist�llet s� f�r man fel om att den saknar defaultkonstruktor */
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

/* Funktionen arbetar b�de med resurshanteraren f�r att h�lla koll p� soundbuffers och undvika flera inladdningar av samma fil, */
/* samtidigt som den skapar Sounds som beh�vs och h�ller dem levande under programmets g�ng. */
void ResourceManager::play(const std::string& filename){
	if (mSounds.count(filename) == 0){
		sf::Sound newSound;
		newSound.setBuffer(getSoundBuffer(filename));
		mSounds.insert(std::pair<std::string, sf::Sound>(filename, newSound));
	}

	mSounds[filename].play();
}


/* Det h�r �r min bane */
//std::map<std::string, Animation> ResourceManager::mAnimations;
std::map<std::string, sf::Texture> ResourceManager::mTextures;
std::map<std::string, sf::Texture> ResourceManager::mLevels;
std::map<std::string, sf::SoundBuffer> ResourceManager::mSoundBuffers;
std::map<std::string, sf::Sound> ResourceManager::mSounds;
