#include "Level.hpp"


//Level::Level(float spawnMini, float spawnMax, float requirement, float specialMin,
<<<<<<< HEAD
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

=======
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

>>>>>>> majal
	mSpawnMin = spawnMin;
	mSpawnMax = spawnMax;
	mObstSpawnMin = obstSpawnMin;
	mObstMax = obstMax;
	mRequirment = requirment;
	mSpecialMin = specialMin;
	mSpecialMax = specialMax;
    mMaxSpecialSpawn = maxSpecialSpawn;
	mMaxSpawnEnemies = maxSpawnEnemies;
<<<<<<< HEAD
	mSpecialMin = specialMin;
	mSpecialMax = specialMax;
	mMaxSpecialSpawn = maxSpecialSpawn;

=======
//	mTexture = texture;
	
	mSpriteWhite.setTexture(ResourceManager::getLevel(chooseWhiteTexture));
	mSpriteColor.setTexture(ResourceManager::getLevel(chooseColoredTexture));
>>>>>>> majal
}

int Level::getRandomNumber(){
	return rand() % 10;
}

<<<<<<< HEAD
void Level::spawnBasicEnemies(Entity::EntityVector &entityVector){
=======
/*Kollar hur många som ska spawnas av default enemies*/
void Level::spawnBasicEnemies(Entity::EntityVector &entityVector){


>>>>>>> majal
	sf::Time spawnDefaultT = mDefaultCl.getElapsedTime();
	int spawnCount = 0;

	if (mSpawnMin < spawnDefaultT.asSeconds()
		&& spawnDefaultT.asSeconds() < mSpawnMax){

		getRandomNumber();

		if (getRandomNumber() == 1 && spawnCount < mMaxSpawnEnemies){
			spawnCount++;
<<<<<<< HEAD
			entityVector.push_back(new DefaultEnemy(1));
=======

			entityVector.push_back(new DefaultEnemy(1));

>>>>>>> majal
		}

	}
		
	 if (spawnDefaultT.asSeconds() >= mSpawnMax){
		 entityVector.push_back(new DefaultEnemy(1));

<<<<<<< HEAD
	if (spawnDefaultT.asSeconds() >= mSpawnMax){
		entityVector.push_back(new DefaultEnemy(1));
		mDefaultCl.restart();
=======
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

>>>>>>> majal
	}

	if (spawnSpecialT.asSeconds() >= mSpecialMax){

		entityVector.push_back(new DefaultEnemy(1));
		mSpecialCl.restart();
	}


}
<<<<<<< HEAD
=======
/*Kallar på spawn-funktioner*/
void Level::spawn(Entity::EntityVector &entityVector){

	if (mSpecialMax > 0 ){

		spawnSpecialEnemies(entityVector);

	}

	spawnBasicEnemies(entityVector);
}

>>>>>>> majal

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

<<<<<<< HEAD
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
=======

/*flyttar på spriten tills slutet av spriten når högra kanten av window */
void Level::moveBackground(sf::RenderWindow *window){
	mBackgroundRect = mSpriteWhite.getGlobalBounds();

	window->draw(mSpriteWhite);

	if (mBackgroundRect.left + mBackgroundRect.width > window->getSize().x){
		mSpriteWhite.move(-1, 0);

	}

>>>>>>> majal
}

