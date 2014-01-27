#include "ResourceManager.hpp"

/* Adders */
void ResourceManager::addAnimation(unsigned int TYPE, Animation &animation){
	mAnimations.emplace(TYPE, &animation);
}

/* emplace l�gger till i mapen om ID't, allts� TYPE, �r unikt och inte har n�got tidigare v�rde. Vi kan beh�va en changeTexture i framtiden. */
void ResourceManager::addTexture(unsigned int TYPE, sf::Texture &texture){
	mTextures.emplace(TYPE, &texture);
}

void ResourceManager::addLevel(unsigned int TYPE, sf::Texture &level){
	mLevels.emplace(TYPE, &level);
}

void ResourceManager::addSound(unsigned int TYPE, sf::Sound &sound){
	mSounds.emplace(TYPE, &sound);
}

/* Getters */
Animation& ResourceManager::getAnimation(unsigned int TYPE){
	return *mAnimations[TYPE];
}

const sf::Texture& ResourceManager::getTexture(unsigned int TYPE){
	return *mTextures[TYPE];
}

const sf::Texture& ResourceManager::getLevel(unsigned int TYPE){
	return *mLevels[TYPE];
}

const sf::Sound& ResourceManager::getSound(unsigned int TYPE){
	return *mSounds[TYPE];
}