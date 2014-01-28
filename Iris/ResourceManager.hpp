#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Animation.h"
#include <string>
#include <utility>

/* Använd funktionerna för att lägga till nya resurser, och använd enumsen för att separera mellan unika entities/levels/etc. */

class ResourceManager{

public:
	ResourceManager();
	~ResourceManager(); 

	/* Låt stå tills vidare /BQ */
	//void addAnimation(unsigned int TYPE, Animation &animation);
	//void addTexture(unsigned int TYPE, sf::Texture &texture);
	//void addLevel(unsigned int TYPE, sf::Texture &level);
	//void addSound(unsigned int TYPE, sf::Sound &sound);

	//Animation& getAnimation(unsigned int TYPE);
	//const sf::Texture& getTexture(unsigned int TYPE);
	//const sf::Texture& getLevel(unsigned int TYPE);
	//const sf::Sound& getSound(unsigned int TYPE);

	//mina tårar börjar fylla rummet
	static Animation& getAnimation(const std::string& filename, int timePerFrame, int numFrames);

	static void clear(){
		mAnimations.clear();
	}
	//ResourceManager::getAnimation("resource/test.png", 200, 2);
private:
	static std::map<std::string, Animation> mAnimations;

	/* Låt stå tills vidare /BQ */
	/* Medlemsvariablar */
	//std::unordered_map<unsigned int, Animation*> mAnimations;
	//std::unordered_map<unsigned int, sf::Texture*> mTextures;
	//std::unordered_map<unsigned int, sf::Texture*> mLevels;
	//std::unordered_map<unsigned int, sf::Sound*> mSounds;
};