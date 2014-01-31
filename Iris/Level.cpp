#include "Level.hpp"

Level::Level(){}

Level::~Level(){}

void Level::set(float spawnMini, float spawnMax, float requirment, float obstSpawnMin,
	float obstMax, int maxSpawnEnemies){

	mSpawnMini = spawnMini;
	mSpawnMax = spawnMax;
	mObstSpawnMin = obstSpawnMin;
	mObstMax = obstMax;
	mRequirment = requirment;
	mMaxSpawnEnemies = maxSpawnEnemies;
	
}

int Level::getRandomNumber(){


	return rand() % 10;
}

void Level::spawnBasicEnemies(Entity::EntityVector &mEntities){

	sf::Time spawnDefaultT = mDefaultCl.getElapsedTime();
	int spawnCount = 0;

	if (mSpawnMini < spawnDefaultT.asSeconds()
		&& spawnDefaultT.asSeconds() < mSpawnMax){
		getRandomNumber();

		if (getRandomNumber() == 1 && spawnCount < mMaxSpawnEnemies){
			spawnCount++;
			mEntities.push_back(new DefaultEnemy(1));
		}
	}

	if (mSpawn >= mSpawnMax){
		mEntities.push_back(new DefaultEnemy(1));
		mDefaultCl.restart();

	}

}
//float Level::getSpawnEnemyTime(){
//
// return mSpawn;
//}

float Level::percentRequirement(float requirement){
	mRequirment = requirement;

	return mRequirment;
}
//float Level::specialEnemySpawnTimeMin(float specialMin){
//
// mSpecialMin = specialMin;
// return specialMin;
//}
//float Level::specialEnemySpawnTimeMax(float specialMax){
//
// mSpecialMax = specialMax;
// return specialMax;
//}
float Level::obstacleSpawnTimeMin(float obstSpawn){

	mObstSpawnMin = obstSpawn;
	return obstSpawn;
}

float Level::obstacleSpawnTimeMax(float obstMax){

	mObstMax = mObstMax;
	return obstMax;
}

void Level::setBackground(sf::Texture &texture)
{
	mTexture = texture;
	mSprite.setTexture(mTexture);

}
sf::Sprite Level::getBackground(){

	return mSprite;
}

