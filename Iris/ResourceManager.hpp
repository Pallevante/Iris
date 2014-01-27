#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <memory>

/* Resource manager som nuvarande enbart kan ta emot texturer. */
class ResourceManager{
public:
	void addTexture(unsigned int TYPE, sf::Texture &texture);
	void addSound(unsigned int TYPE, sf::Sound &sound);

	sf::Texture& getTexture(unsigned int TYPE);
	sf::Sound& getSound(unsigned int TYPE);
private:
	std::unordered_map<unsigned int, sf::Texture*> textures;
	std::unordered_map<unsigned int, sf::Sound*> sounds;
};