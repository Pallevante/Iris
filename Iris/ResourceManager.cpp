#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){

}
ResourceManager::~ResourceManager(){

}

sf::Texture& ResourceManager::getTexture(const std::string& filename){
	/* Jag valde att kolla om resursen redan existerade i mapen genom att räkna antalet resurser med samma filnamn */
	if (mTextures.count(filename) == 0){
		sf::Texture newTexture;
		newTexture.loadFromFile(filename);

		mTextures.insert(std::pair<std::string, sf::Texture>(filename, newTexture));
	}
	return mTextures.find(filename)->second;
}


sf::Texture& ResourceManager::getTexture(const std::string& filename, const sf::IntRect& intRect, const std::string& indexName){
	/* Jag valde att kolla om resursen redan existerade i mapen genom att räkna antalet resurser med samma filnamn */
	if (mTextures.count(indexName) == 0){
		sf::Texture newTexture;
		newTexture.loadFromFile(filename, intRect);

		mTextures.insert(std::pair<std::string, sf::Texture>(indexName, newTexture));
	}
	return mTextures.find(indexName)->second;
}

sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& filename){
	if (mSoundBuffers.count(filename) == 0){
		sf::SoundBuffer newSound;
		newSound.loadFromFile(filename);

		mSoundBuffers.insert(std::pair<std::string, sf::SoundBuffer>(filename, newSound));
	}
	return mSoundBuffers.find(filename)->second;
}

/* Funktionen arbetar både med resurshanteraren för att hålla koll på soundbuffers och undvika flera inladdningar av samma fil, */
/* samtidigt som den skapar Sounds som behövs och håller dem levande under programmets gång. */
sf::Sound& ResourceManager::getSound(const std::string& filename){
	if (mSounds.count(filename) == 0){
		sf::Sound newSound;
		newSound.setBuffer(getSoundBuffer(filename));
		mSounds.insert(std::pair<std::string, sf::Sound>(filename, newSound));
	}
	return mSounds[filename];
}
sf::Image& ResourceManager::getImage(const std::string& filename){
	if (mImages.count(filename) == 0){
		sf::Image newImage;
		newImage.loadFromFile(filename);
		mImages.insert(std::pair<std::string, sf::Image>(filename, newImage));
	}
	return mImages[filename];
}

/*Testversion för musik.*/
//Svordoms-mätare:
//Fan: 10
//Helvete: 6
//Jävla-Skit-fitts-funktion: 5
//Funka då för fan: 5
//*Suck*: 61
sf::Music* ResourceManager::getMusic(const std::string& filename){

		if (mMusic.count(filename) == 0){
			sf::Music* newMusic = new sf::Music;
			newMusic->openFromFile(filename);
			mMusic.insert(std::pair<std::string, sf::Music*>(filename, newMusic));
		}
	
	return mMusic[filename];
}




ResourceManager::SpriteVector ResourceManager::getLevel(const std::string& filename){
	/* Ser till att varje bild bara laddas in en gång. */
	if (mLevels.count(filename) == 0){
		sf::Image image;
		image = getImage(filename);
		sf::Sprite newSprite;

		/* Räkna hur många tiles som kommer behövas */
		int tileSize = sf::Texture::getMaximumSize();
		int imageWidth = image.getSize().x;
		int tileCount = (int)round(ceil(imageWidth / tileSize));

		/* Definera alla nya texturer ifrån en sf::Image och en IntRect som beräknas genom antalet tiles och bredden på tiles och bilden*/
		ResourceManager::SpriteVector spriteVector;

		for (int i = 0; i <= tileCount; i++){
			//sf::Texture newTexture;
			sf::IntRect newIntRect(i*tileSize, 0, tileSize, image.getSize().y);
			
			//newTexture.loadFromImage(image, newIntRect);
			
			newSprite.setTexture(getTexture(filename, newIntRect, "level" + filename + "_" + std::to_string(i)));
			newSprite.setPosition((i * sf::Texture::getMaximumSize()),0);
			spriteVector.push_back(newSprite);
		}
		mLevels.insert(std::pair<std::string, ResourceManager::SpriteVector>(filename, spriteVector));
	}
	return mLevels[filename];
}


void ResourceManager::drawLevel(sf::RenderWindow& window, SpriteVector& bgVector, float speed, sf::Color& color){
	/* Skapar och ritar ut sprites på relativa positioner */
	for (ResourceManager::SpriteVector::size_type i = 0; i < bgVector.size(); i++){

		bgVector[i].setPosition(bgVector[i].getPosition().x - speed, 0);
		bgVector[i].setColor(color);
		window.draw(bgVector[i]);


	}
}



/* Det här är min bane */
std::map<std::string, sf::Texture> ResourceManager::mTextures;
std::map<std::string, sf::Sound> ResourceManager::mSounds;
std::map<std::string, sf::SoundBuffer> ResourceManager::mSoundBuffers;
std::map<std::string, sf::Image> ResourceManager::mImages;

std::map<std::string, ResourceManager::SpriteVector> ResourceManager::mLevels;
std::map<std::string, sf::Music*> ResourceManager::mMusic;

