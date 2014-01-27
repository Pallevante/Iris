#include "ResourceManager.hpp"

/* emplace l�gger till i mapen om ID't, allts� TYPE, �r unikt och inte har n�got tidigare v�rde. Vi kan beh�va en changeTexture i framtiden. */
void ResourceManager::addTexture(unsigned int TYPE, sf::Texture &texture){
	textures.emplace(TYPE, &texture);
}

void ResourceManager::addLevel(unsigned int TYPE, sf::Texture &level){
	textures.emplace(TYPE, &level);
}

void ResourceManager::addSound(unsigned int TYPE, sf::Sound &sound){
	sounds.emplace(TYPE, &sound);
}

sf::Texture& ResourceManager::getTexture(unsigned int TYPE){
	return *textures[TYPE];
}

sf::Texture& ResourceManager::getLevel(unsigned int TYPE){
	return *levels[TYPE];
}

sf::Sound& ResourceManager::getSound(unsigned int TYPE){
	return *sounds[TYPE];
}