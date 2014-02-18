#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
#include <string>



class ResourceManager{

public:
	ResourceManager();
	~ResourceManager(); 

	typedef std::vector<sf::Sprite> SpriteVector;

	/* getters & adders: Om sökvägen inte hittas i den valda mappen (mTextures, etc)
	så läggs den till och returneras direkt. */
	static sf::Texture& getTexture(const std::string& filename);
	static sf::Texture& getTexture(const std::string& filename, const sf::IntRect& intRect, const std::string& indexName);
	static sf::Sound& getSound(const std::string& filename);
	static sf::SoundBuffer& getSoundBuffer(const std::string& filename);
	static sf::Image& getImage(const std::string& filename);
	static ResourceManager::SpriteVector getLevel(const std::string& filename);
	static sf::Music* getMusic(const std::string& filename);
	/* Exempel på användning:
	Initialisera en TextureVector ****UTANFÖR GAMELOOPEN****
	ResourceManager::TextureVector bgVector = ResourceManager::getLevel("resource/textures/backgrounds/level1.png");

	Använd drawLevel ****inuti gameloopen****
	ResourceManager::drawLevel(window, bgVector, (worldClock.getElapsedTime().asSeconds() * 200), sf::Color(255, 255, 255, opacity);

	Ange bara vårt renderwindow, din initialiserade TextureVector, hastigheten som den ska röra sig i relativ till nuvarande tiden, och en färg (för opacity)
	*/
	static void drawLevel(sf::RenderWindow& window, SpriteVector& bgVector, float speed, sf::Color& color);

	/* Kör clear innan avslut av programmet för att tömma minnet. */  

	static void clear(){
		mTextures.clear();
		mLevels.clear();
		mSoundBuffers.clear();
		mSounds.clear();
		mMusic.clear();
	}
private:
	static std::map<std::string, sf::Texture> mTextures;
	static std::map<std::string, sf::Sound> mSounds;
	static std::map<std::string, sf::SoundBuffer> mSoundBuffers;
	static std::map<std::string, sf::Image> mImages;
	static std::map<std::string, sf::Music*> mMusic; 
	static std::map<std::string, ResourceManager::SpriteVector> mLevels;
};