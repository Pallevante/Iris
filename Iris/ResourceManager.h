#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>

/* Resource manager som nuvarande enbart kan ta emot texturer. */
class ResourceManager{
public:
	void addTexture(unsigned int TYPE, sf::Texture &texture);

	sf::Texture& getTexture(unsigned int TYPE);
private:
	std::unordered_map<unsigned int, sf::Texture*> textures;
};