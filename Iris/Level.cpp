#include "Level.hpp"

//Level::Level(float spawnMini, float spawnMax, float requirement, float specialMin,
//	float specialMax, float obstMin, float obstMax, sf::Texture &texture): mSpawnMini(spawnMini),
//	mSpawnMax(spawnMax),mRequirment(requirement), mSpecialMin(specialMin), mSpecialMax(specialMax)
//	,mObstSpawn(obstMin),mObstMax(obstMax) ,mTexture(texture){
//	
//}

Level::Level(){

}
Level::~Level(){


}

int Level::getRandomNumber(){


	return rand() % 10;
}

void Level::spawnBasicEnemies(float minTime, float maxTime, int maxEnemiesSpawn,
	Entity::EntityVector &entityVector, Enemy *enemyType){

	mSpawnMini = minTime;
	mSpawnMax = maxTime;

	sf::Time spawnDefaultT = mDefaultCl.getElapsedTime();
	int spawnCount = 0;

	if (mSpawnMini < spawnDefaultT.asSeconds()
		&& spawnDefaultT.asSeconds() < mSpawnMax){

		getRandomNumber();

		if (getRandomNumber() == 1 && spawnCount < mMaxSpawnEnemies){
			spawnCount++;
			entityVector.push_back(enemyType);

		}

	}
		
	 if (mSpawn >= mSpawnMax){
		entityVector.push_back(enemyType);

		mDefaultCl.restart();
		
	}

}  
float Level::getSpawnEnemyTime(){

	return mSpawn;
}

float Level::percentRequirement(float requirement){
	mRequirment = requirement;

	return mRequirment;
}
//float Level::specialEnemySpawnTimeMin(float specialMin){
//
//	mSpecialMin = specialMin;
//	return specialMin;
//}
//float Level::specialEnemySpawnTimeMax(float specialMax){
//
//	mSpecialMax = specialMax;
//	return specialMax;
//}
float Level::obstacleSpawnTimeMin(float obstSpawn){

	mObstSpawn = obstSpawn;
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

