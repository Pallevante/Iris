#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <memory>

/* Använd funktionerna för att lägga till nya resurser, och använd enumsen för att separera mellan unika entities/levels/etc. */

class ResourceManager{
public:
	void addTexture(unsigned int TYPE, sf::Texture &texture);
	void addLevel(unsigned int TYPE, sf::Texture &level);
	void addSound(unsigned int TYPE, sf::Sound &sound);

	sf::Texture& getTexture(unsigned int TYPE);
	sf::Texture& getLevel(unsigned int TYPE);
	sf::Sound& getSound(unsigned int TYPE);
private:
	std::unordered_map<unsigned int, sf::Texture*> textures;
	std::unordered_map<unsigned int, sf::Texture*> levels;
	std::unordered_map<unsigned int, sf::Sound*> sounds;
};