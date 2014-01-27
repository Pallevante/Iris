#include "ResourceManager.hpp"

/* emplace lägger till i mapen om ID't, alltså TYPE, är unikt och inte har något tidigare värde. Vi kan behöva en changeTexture i framtiden. */
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