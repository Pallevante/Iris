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

void Level::set(float spawnMin, float spawnMax, float requirment, float obstSpawnMin,
	float obstMax, int maxSpawnEnemies, float specialMin, float specialMax, int maxSpecialSpawn){
	

	float	mSpawnMin = spawnMin;
	float	mSpawnMax = spawnMax;
	float	mObstSpawnMin = obstSpawnMin;
	float	mObstMax = obstMax;
	float	mRequirment = requirment;
	float	mMaxSpawnEnemies = maxSpawnEnemies;
	float	mSpecialMin = specialMin;
	float	mSpecialMax = specialMax;
	float   mMaxSpecialSpawn = maxSpecialSpawn;


}

int Level::getRandomNumber(){


	return rand() % 10;
}


void Level::spawnBasicEnemies(Entity::EntityVector &mEntities){


	sf::Time spawnDefaultT = mDefaultCl.getElapsedTime();
	int spawnCount = 0;

	if (mSpawnMin < spawnDefaultT.asSeconds()
		&& spawnDefaultT.asSeconds() < mSpawnMax){

		getRandomNumber();

		if (getRandomNumber() == 1 && spawnCount < mMaxSpawnEnemies){
			spawnCount++;

			mEntityVector.push_back(new DefaultEnemy(1));

		}

	}
		
	 if (spawnDefaultT.asSeconds() >= mSpawnMax){
		 mEntityVector.push_back(new DefaultEnemy(1));

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
			mEntityVector.push_back(new DefaultEnemy(1));

		}

	}

	if (spawnSpecialT.asSeconds() >= mSpecialMax){

		mEntityVector.push_back(new DefaultEnemy(1));
		mSpecialCl.restart();
	}


}



float Level::percentRequirement(float requirement){
	mRequirment = requirement;

	return mRequirment;
}



void Level::setBackground(sf::Texture &texture)
{
	mTexture = texture;
	mSprite.setTexture(mTexture);

}


void Level::drawBackground(sf::RenderWindow *window){

	window->draw(mSprite);
	
}

void Level::moveBackground(){

	mSprite.move(-1, 0);

}

