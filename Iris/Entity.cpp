#include "Entity.hpp"

Entity::Entity(){}
Entity::~Entity(){}

/* Funktionen arbetar både med resurshanteraren för att hålla koll på soundbuffers och undvika flera inladdningar av samma fil, */
/* samtidigt som den skapar Sounds som behövs och håller dem levande under programmets gång. */
void Entity::play(const std::string& filename){
	
	if (mSounds.count(filename) == 0){
		sf::Sound newSound;
		newSound.setBuffer(ResourceManager::getSoundBuffer(filename));
		mSounds.insert(std::pair<std::string, sf::Sound>(filename, newSound));
	}

	mSounds[filename].play();
}
