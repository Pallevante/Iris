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

void Level::set(float spawnMin, float spawnMax, float requirment, float obstSpawnMin,
	float obstMax, float specialMin, float specialMax, int maxSpecialSpawn, int maxSpawnEnemies, int level){
	

	switch (level)
	{
	case 1:
		chooseLevel ="resource/";
		break;
	case 2:
		chooseLevel = "resource/";
		break;
	case 3:
		chooseLevel = "resource/";
		break;
	case 4:
		chooseLevel = "resource/";
		break;
	case 5:
		chooseLevel = "resource/";
		break;
	case 6:
		chooseLevel = "resource/";
		break;
	case 7:
		chooseLevel = "resource/";
		break;
	case 8:
		chooseLevel = "resource/";
		break;
	default:
		break;
	}
	ResourceManager::getLevel(chooseLevel);

	mSpawnMin = spawnMin;
	mSpawnMax = spawnMax;
	mObstSpawnMin = obstSpawnMin;
	mObstMax = obstMax;
	mRequirment = requirment;
	mSpecialMin = specialMin;
	mSpecialMax = specialMax;
    mMaxSpecialSpawn = maxSpecialSpawn;
	mMaxSpawnEnemies = maxSpawnEnemies;
//	mTexture = texture;
	mSprite.setTexture(ResourceManager::getTexture("resource/test.png"));

}

int Level::getRandomNumber(){


	return rand() % 10;
}

/*Kollar hur många som ska spawnas av default enemies*/
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
/*Kallar på spawn-funktioner*/
void Level::spawn(Entity::EntityVector &entityVector){

	if (mSpecialMax > 0 ){

		spawnSpecialEnemies(entityVector);

	}

	spawnBasicEnemies(entityVector);
}


float Level::percentRequirement(float requirement){
	mRequirment = requirement;

	return mRequirment;
}


/*flyttar på view*/
void Level::moveBackground(sf::RenderWindow *window){

	window->draw(mSprite);

	if (mSprite.getGlobalBounds().left > window->getSize().x - 1){
		mSprite.move(-1, 0);
	}
	else if (mSprite.getGlobalBounds().left <= window->getSize().x - 1){
		mSprite.move(0, 0);
	}


}

