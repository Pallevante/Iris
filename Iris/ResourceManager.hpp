#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include "Animation.h"

/* Använd funktionerna för att lägga till nya resurser, och använd enumsen för att separera mellan unika entities/levels/etc. */

class ResourceManager{
public:
	/* Adders */
	void addAnimation(unsigned int TYPE, Animation &animation);
	void addTexture(unsigned int TYPE, sf::Texture &texture);
	void addLevel(unsigned int TYPE, sf::Texture &level);
	void addSound(unsigned int TYPE, sf::Sound &sound);

	/* Getters */
	Animation& getAnimation(unsigned int TYPE);
	const sf::Texture& getTexture(unsigned int TYPE);
	const sf::Texture& getLevel(unsigned int TYPE);
	const sf::Sound& getSound(unsigned int TYPE);
private:
	/* Medlemsvariablar */
	std::unordered_map<unsigned int, Animation*> mAnimations;
	std::unordered_map<unsigned int, sf::Texture*> mTextures;
	std::unordered_map<unsigned int, sf::Texture*> mLevels;
	std::unordered_map<unsigned int, sf::Sound*> mSounds;
};