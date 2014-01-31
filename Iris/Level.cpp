#include "Level.hpp"

//Level::Level(float spawnMini, float spawnMax, float requirement, float specialMin,
//	float specialMax, float obstMin, float obstMax, sf::Texture &texture): mSpawnMini(spawnMini),
//	mSpawnMax(spawnMax),mRequirment(requirement), mSpecialMin(specialMin), mSpecialMax(specialMax)
//	,mObstSpawn(obstMin),mObstMax(obstMax) ,mTexture(texture){
//	
//}

Level::Level(){

	enemyAnimation = new Animation("resource/test.png", 200, 4);
}
Level::~Level(){


}

void Level::set(float spawnMini, float spawnMax, float requirment, float obstSpawnMin,
	float obstMax, int maxSpawnEnemies, float specialMin, float specialMax, int maxSpecialSpawn){
	
	mSpawnMini = spawnMini;
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

	if (mSpawnMini < spawnDefaultT.asSeconds()
		&& spawnDefaultT.asSeconds() < mSpawnMax){

		getRandomNumber();

		if (getRandomNumber() == 1 && spawnCount < mMaxSpawnEnemies){
			spawnCount++;
			mEntityVector.push_back(new DefaultEnemy(enemyAnimation, 1.0f));

		}

	}
		
	 if (spawnDefaultT.asSeconds() >= mSpawnMax){
		 mEntityVector.push_back(new DefaultEnemy(enemyAnimation, 1.0f));

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
			mEntityVector.push_back(new DefaultEnemy(enemyAnimation, 1.0f));

		}

	}

	if (spawnSpecialT.asSeconds() >= mSpecialMax){
		mEntityVector.push_back(new DefaultEnemy(enemyAnimation, 1.0f));

		mDefaultCl.restart();

	}

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
//float Level::obstacleSpawnTimeMin(float obstSpawn){
//
//	mObstSpawnMin = obstSpawn;
//	return obstSpawn;
//}
//
//float Level::obstacleSpawnTimeMax(float obstMax){
//
//	mObstMax = mObstMax;
//	return obstMax;
//}
//
void Level::setBackground(sf::Texture &texture)
{
	mTexture = texture;
	mSprite.setTexture(mTexture);

}
//sf::Sprite Level::getBackground(){
//
//	return mSprite;
//}

void Level::drawBackground(sf::RenderWindow *window){

	window->draw(mSprite);
	
}

void Level::moveBackground(){

	mSprite.move(-1, 0);

}