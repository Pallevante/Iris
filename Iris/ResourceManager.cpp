#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){

}
ResourceManager::~ResourceManager(){

}

///* Adders */
//void ResourceManager::addAnimation(unsigned int TYPE, Animation &animation){
//	mAnimations.emplace(TYPE, &animation);
//}
//
///* emplace l�gger till i mapen om ID't, allts� TYPE, �r unikt och inte har n�got tidigare v�rde. Vi kan beh�va en changeTexture i framtiden. */
//void ResourceManager::addTexture(unsigned int TYPE, sf::Texture &texture){
//	mTextures.emplace(TYPE, &texture);
//}
//
//void ResourceManager::addLevel(unsigned int TYPE, sf::Texture &level){
//	mLevels.emplace(TYPE, &level);
//}
//
//void ResourceManager::addSound(unsigned int TYPE, sf::Sound &sound){
//	mSounds.emplace(TYPE, &sound);
//}
//
///* Getters */
//Animation& ResourceManager::getAnimation(unsigned int TYPE){
//	return *mAnimations[TYPE];
//}
//
//const sf::Texture& ResourceManager::getTexture(unsigned int TYPE){
//	return *mTextures[TYPE];
//}
//
//const sf::Texture& ResourceManager::getLevel(unsigned int TYPE){
//	return *mLevels[TYPE];
//}
//
//const sf::Sound& ResourceManager::getSound(unsigned int TYPE){
//	return *mSounds[TYPE];
//}

Animation& ResourceManager::getAnimation(const std::string& filename, int timePerFrame, int numFrames){
	if (mAnimations.count(filename) == 0){
		Animation newAnimation(filename, timePerFrame, numFrames);
		std::pair<std::map<std::string, Animation>::iterator, bool> insertion;
		insertion = mAnimations.insert(std::pair<std::string, Animation>(filename, newAnimation));
		if (insertion.second == false){

		}
	}

	return mAnimations.find(filename)->second;
}

/* Det h�r �r min bane */
std::map<std::string, Animation> ResourceManager::mAnimations;