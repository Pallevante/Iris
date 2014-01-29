#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

#include <string>

class ResourceManager{

public:
	ResourceManager();
	~ResourceManager(); 

	/* P� grund av funktionernas natur s� m�ste man ange allt f�r en Animation-konstruktor f�r att h�mta ut den. */
	/* Vi stryker animation i resurshanteraren tills vidare */
	//static Animation& getAnimation(const std::string& filename, int timePerFrame, int numFrames);

	/* getters & adders: Om s�kv�gen inte hittas i den valda mappen (mTextures, etc)
	s� l�ggs den till och returneras direkt. */
	static sf::Texture& getTexture(const std::string& filename);
	static sf::Texture& getLevel(const std::string& filename);
	static sf::SoundBuffer& getSound(const std::string& filename);

	/* K�r clear innan avslut av programmet f�r att t�mma minnet. */
	static void clear(){
		//mAnimations.clear();
		mTextures.clear();
		mLevels.clear();
		mSounds.clear();
	}
private:
	//static std::map<std::string, Animation> mAnimations;
	static std::map<std::string, sf::Texture> mTextures;
	static std::map<std::string, sf::Texture> mLevels;
	static std::map<std::string, sf::SoundBuffer> mSounds;
};