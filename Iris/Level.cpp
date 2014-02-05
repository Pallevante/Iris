#include "Level.hpp"


//Level::Level(float spawnMini, float spawnMax, float requirement, float specialMin,
// float specialMax, float obstMin, float obstMax, sf::Texture &texture): mSpawnMini(spawnMini),
// mSpawnMax(spawnMax),mRequirment(requirement), mSpecialMin(specialMin), mSpecialMax(specialMax)
// ,mObstSpawn(obstMin),mObstMax(obstMax) ,mTexture(texture){
//
//}

Level::Level(){
}
Level::~Level(){


}

void Level::set(float spawnMin, float spawnMax, float requirment, float obstSpawnMin,
	float obstMax, int maxSpawnEnemies, float specialMin, float specialMax, int maxSpecialSpawn){

	mSpawnMin = spawnMin;
	mSpawnMax = spawnMax;
	mObstSpawnMin = obstSpawnMin;
	mObstMax = obstMax;
	mRequirment = requirment;
	mMaxSpawnEnemies = maxSpawnEnemies;
	mSpecialMin = specialMin;
	mSpecialMax = specialMax;
	mMaxSpecialSpawn = maxSpecialSpawn;

}

int Level::getRandomNumber(){
	return rand() % 10;
}

void Level::spawnBasicEnemies(Entity::EntityVector &entityVector){
	sf::Time spawnDefaultT = mDefaultCl.getElapsedTime();
	int spawnCount = 0;

	if (mSpawnMin < spawnDefaultT.asSeconds()
		&& spawnDefaultT.asSeconds() < mSpawnMax){

		getRandomNumber();

		if (getRandomNumber() == 1 && spawnCount < mMaxSpawnEnemies){
			spawnCount++;
			entityVector.push_back(new DefaultEnemy(1));
		}
	}

	if (spawnDefaultT.asSeconds() >= mSpawnMax){
		entityVector.push_back(new DefaultEnemy(1));
		mDefaultCl.restart();
	}

}

void Level::spawnSpecialEnemies(Entity::EntityVector &entityVector){

	sf::Time spawnSpecialT = mSpecialCl.getElapsedTime();
	int spawnCount = 0;

	if (mSpecialMin < spawnSpecialT.asSeconds()
		&& spawnSpecialT.asSeconds() < mSpecialMax){

		getRandomNumber();

	if (getRandomNumber() == 1 && spawnCount < mMaxSpecialSpawn){
	spawnCount++;
	entityVector.push_back(new DefaultEnemy(1));

	}
}

	if (spawnSpecialT.asSeconds() >= mSpecialMax){
		entityVector.push_back(new DefaultEnemy(1));
		mSpecialCl.restart();
	}
}


void Level::spawn(Entity::EntityVector &entityVector){
	if (mSpecialMax > 0 ){
		spawnSpecialEnemies(entityVector);
	}
	spawnBasicEnemies(entityVector);
}


float Level::percentRequirement(){
	return mRequirment;
}



void Level::setBackground(sf::Texture &texture){
	mTexture = texture;
	mSprite.setTexture(mTexture);
}


void Level::drawBackground(sf::RenderWindow *window){
	window->draw(mSprite);
}

void Level::moveBackground(sf::RenderWindow *window){

	view.setViewport(sf::FloatRect(1.0f, 1.0f, 1.0f, 1.0f));
	view.setCenter(window->getSize().x / 2, window->getSize().y / 2);


	if (mSprite.getGlobalBounds().left > window->getSize().x - 1){
		view.move(1, 0);
	}
	else if (mSprite.getGlobalBounds().left <= window->getSize().x - 1){
		view.move(0, 0);
	}
}

