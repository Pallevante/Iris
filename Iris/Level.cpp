#include "Level.hpp"

//Level::Level(float spawnMini, float spawnMax, float requirement, float specialMin,
//	float specialMax, float obstMin, float obstMax, sf::Texture &texture): mSpawnMini(spawnMini),
//	mSpawnMax(spawnMax),mRequirment(requirement), mSpecialMin(specialMin), mSpecialMax(specialMax)
//	,mObstSpawn(obstMin),mObstMax(obstMax) ,mTexture(texture){
//	
//}

Level::Level(){

	mRandomSpawn = rand() % 10;
	enemyAnimation = new Animation("resource/test.png", 200, 2);
}
Level::~Level(){


}
void Level::spawnBasicEnemies(float minTime, float maxTime, int maxEnemiesSpawn,
	Entity::EntityVector &entityVector){

	mSpawnMini = minTime;
	mSpawnMax = maxTime;
	sf::Time spawnDefaultT = mDefaultCl.getElapsedTime();
	int spawnCount = 0;

	while (mSpawnMini < spawnDefaultT.asSeconds()
		&& spawnDefaultT.asSeconds() < mSpawnMax){

		if (mRandomSpawn == 1 && spawnCount < mMaxSpawnEnemies){
			spawnCount++;
			entityVector.push_back(new DefaultEnemy(enemyAnimation, 0.5f));

		}

	}
		
	 if (mSpawn >= mSpawnMax){
		entityVector.push_back(new DefaultEnemy(enemyAnimation, 0.5f));

		mDefaultCl.restart();
		
	}
	//switch (rand () % 3)
	//{
	//case 1:
	//	normalSpawn = Min;
	//	break;
	//case 2:
	//	normalSpawn = Max;
	//	break;
	//case 3:
	//	normalSpawn = (Max * Min) / 2;
	//	break;
	//default:
	//	break;
	//}
}  
float Level::getSpawnEnemyTime(){

	return mSpawn;
}
//float Level::enemySpawnTimeMin(float spawnMini){
//
//	mSpawnMini = spawnMini;
//	return spawnMini;
//}
//float Level::enemySpawnTimeMax(float spawnMax){
//
//	mSpawnMax = spawnMax;
//	return spawnMax;
//}
float Level::percentRequirement(float requirement){
	mRequirment = requirement;

	return mRequirment;
}
float Level::specialEnemySpawnTimeMin(float specialMin){

	mSpecialMin = specialMin;
	return specialMin;
}
float Level::specialEnemySpawnTimeMax(float specialMax){

	mSpecialMax = specialMax;
	return specialMax;
}
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