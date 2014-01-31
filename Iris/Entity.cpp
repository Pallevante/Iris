#include "Entity.hpp"

Entity::Entity(){}
Entity::~Entity(){}

/* Funktionen arbetar b�de med resurshanteraren f�r att h�lla koll p� soundbuffers och undvika flera inladdningar av samma fil, */
/* samtidigt som den skapar Sounds som beh�vs och h�ller dem levande under programmets g�ng. */
void Entity::play(const std::string& filename){
	
	if (mSounds.count(filename) == 0){
		sf::Sound newSound;
		newSound.setBuffer(ResourceManager::getSoundBuffer(filename));
		mSounds.insert(std::pair<std::string, sf::Sound>(filename, newSound));
	}

	mSounds[filename].play();
}
