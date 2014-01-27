#include "ResourceManager.h"

/* emplace l�gger till i mapen om ID't, allts� TYPE, �r unikt och inte har n�got tidigare v�rde. Vi kan beh�va en changeTexture i framtiden. */
void ResourceManager::addTexture(unsigned int TYPE, sf::Texture &texture){
	textures.emplace(TYPE, &texture);
}

void ResourceManager::addSound(unsigned int TYPE, sf::Sound &sound){
	sounds.emplace(TYPE, &sound);
}

sf::Texture& ResourceManager::getTexture(unsigned int TYPE){
	return *textures[TYPE];
}

sf::Sound& ResourceManager::getSound(unsigned int TYPE){
	return *sounds[TYPE];
}