#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "Animation.h"
#include <string>

class ResourceManager{

public:
	ResourceManager();
	~ResourceManager(); 

	/* getters & adders: Om sökvägen inte hittas i den valda mappen (mAnimations, mTextures, etc)
	så läggs den till och returneras direkt. */
	/* På grund av funktionernas natur så måste man ange allt för en Animation-konstruktor för att hämta ut den. */
	static Animation& getAnimation(const std::string& filename, int timePerFrame, int numFrames);
	static sf::Texture& getTexture(const std::string& filename);
	static sf::Texture& getLevel(const std::string& filename);
	static sf::SoundBuffer& getSound(const std::string& filename);

	/* Kör clear innan avslut av programmet för att tömma minnet. */
	static void clear(){
		mAnimations.clear();
		mTextures.clear();
		mLevels.clear();
		mSounds.clear();
	}
private:
	static std::map<std::string, Animation> mAnimations;
	static std::map<std::string, sf::Texture> mTextures;
	static std::map<std::string, sf::Texture> mLevels;
	static std::map<std::string, sf::SoundBuffer> mSounds;
};