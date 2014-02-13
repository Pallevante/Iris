#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){

}
ResourceManager::~ResourceManager(){

}

sf::Texture& ResourceManager::getTexture(const std::string& filename){
	/* Jag valde att kolla om resursen redan existerade i mapen genom att r�kna antalet resurser med samma filnamn */
	if (mTextures.count(filename) == 0){
		sf::Texture newTexture;
		newTexture.loadFromFile(filename);

		mTextures.insert(std::pair<std::string, sf::Texture>(filename, newTexture));
	}
	return mTextures.find(filename)->second;
}

sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& filename){
	if (mSoundBuffers.count(filename) == 0){
		sf::SoundBuffer newSound;
		newSound.loadFromFile(filename);

		mSoundBuffers.insert(std::pair<std::string, sf::SoundBuffer>(filename, newSound));
	}
	return mSoundBuffers.find(filename)->second;
}

/* Funktionen arbetar b�de med resurshanteraren f�r att h�lla koll p� soundbuffers och undvika flera inladdningar av samma fil, */
/* samtidigt som den skapar Sounds som beh�vs och h�ller dem levande under programmets g�ng. */
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

/*Testversion f�r musik.*/
//Svordoms-m�tare:
//Fan: 10
//Helvete: 6
//J�vla-Skit-fitts-funktion: 5
//Funka d� f�r fan: 5
//*Suck*: 61
sf::Music* ResourceManager::getMusic(const std::string& filename){

		if (mMusic.count(filename) == 0){
			sf::Music* newMusic = new sf::Music;
			newMusic->openFromFile(filename);
			mMusic.insert(std::pair<std::string, sf::Music*>(filename, newMusic));
		}
	
	return mMusic[filename];
}




std::vector<sf::Texture>& ResourceManager::getLevel(const std::string& filename){
	/* Ser till att varje bild bara laddas in en g�ng. */
	if (mLevels.count(filename) == 0){
		sf::Image image;
		image = getImage(filename);

		/* R�kna hur m�nga tiles som kommer beh�vas */
		int tileSize = sf::Texture::getMaximumSize();
		int imageWidth = image.getSize().x;
		int tileCount = ceil(imageWidth / tileSize);
		/* Definera alla nya texturer ifr�n en sf::Image och en IntRect som ber�knas genom antalet tiles och bredden p� tiles och bilden*/
		std::vector<sf::Texture> textureVector;
		for (int i = 0; i <= tileCount; i++){
			sf::Texture newTexture;
			sf::IntRect newIntRect(i*tileSize, 0, tileSize, image.getSize().y);
			newTexture.loadFromImage(image, newIntRect);
			textureVector.push_back(newTexture);
		}
		mLevels.insert(std::pair<std::string, std::vector<sf::Texture>>(filename, textureVector));
	}
	return mLevels[filename];
}

void ResourceManager::drawLevel(sf::RenderWindow &window, TextureVector& bgVector, float speed, sf::Color& color){
	/* Skapar och ritar ut sprites p� relativa positioner */
	for (std::vector<sf::Texture>::size_type i = 0; i < bgVector.size(); i++){
		sf::Sprite newSprite;
		newSprite.setTexture(bgVector[i]);
		newSprite.setPosition((i * bgVector[i].getSize().x) - speed, 0);
		newSprite.setColor(color);
		window.draw(newSprite);
	}
}

/* Det h�r �r min bane */
std::map<std::string, sf::Texture> ResourceManager::mTextures;
std::map<std::string, sf::Sound> ResourceManager::mSounds;
std::map<std::string, sf::SoundBuffer> ResourceManager::mSoundBuffers;
std::map<std::string, sf::Image> ResourceManager::mImages;
std::map<std::string, std::vector<sf::Texture>> ResourceManager::mLevels;
std::map<std::string, sf::Music*> ResourceManager::mMusic;

