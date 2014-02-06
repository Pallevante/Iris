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
		chooseWhiteTexture = "resource/test.jpg";
		chooseColoredTexture = "resource/TestRawr.jpg";
		break;
	case 2:
		chooseWhiteTexture = "resource/test.png";
		chooseColoredTexture = "resource/TestRawr.jpg";
		break;
	case 3:
		chooseWhiteTexture = "resource/test.png";
		chooseColoredTexture = "resource/TestRawr.jpg";
		break;
	case 4:
		chooseWhiteTexture = "resource/test.png";
		chooseColoredTexture = "resource/TestRawr.jpg";
		break;
	case 5:
		chooseWhiteTexture = "resource/test.png";
		chooseColoredTexture = "resource/TestRawr.jpg";
		break;
	case 6:
		chooseWhiteTexture = "resource/test.png";
		chooseColoredTexture = "resource/TestRawr.jpg";
		break;
	case 7:
		chooseWhiteTexture = "resource/test.png";
		chooseColoredTexture = "resource/TestRawr.jpg";
		break;
	case 8:
		chooseWhiteTexture = "resource/test.png";
		chooseColoredTexture = "resource/TestRawr.jpg";
		break;
	default:
		break;
	}
//	ResourceManager::getLevel(chooseLevel);

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
	
	mSpriteWhite.setTexture(ResourceManager::getLevel(chooseWhiteTexture));
	mSpriteColor.setTexture(ResourceManager::getLevel(chooseColoredTexture));
}

int Level::getRandomNumber(){


	return rand() % 10;
}

/*Kollar hur m�nga som ska spawnas av default enemies*/
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
/*Kallar p� spawn-funktioner*/
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


/*flyttar p� spriten tills slutet av spriten n�r h�gra kanten av window */
void Level::moveBackground(sf::RenderWindow *window){
	mBackgroundRect = mSpriteWhite.getGlobalBounds();

	window->draw(mSpriteWhite);

	if (mBackgroundRect.left + mBackgroundRect.width > window->getSize().x){
		mSpriteWhite.move(-1, 0);

	}

}

