#include "ResourceManager.h"

sf::Texture& ResourceManager::getTexture(unsigned int TYPE){
	return *textures[TYPE];
}

/* emplace l�gger till i mapen om ID't, allts� TYPE, �r unikt och inte har n�got tidigare v�rde. Vi kan beh�va en changeTexture i framtiden. */ 
void ResourceManager::addTexture(unsigned int TYPE, sf::Texture &texture){
	textures.emplace(TYPE, &texture);
}