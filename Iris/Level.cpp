#include "Level.hpp"


ResourceManager::SpriteVector clVector;
ResourceManager::SpriteVector bgVector;
sf::Clock goldClock;
sf::Sprite baseImage;

Level::Level(){
	opacity = 0;
}
Level::~Level(){


}

void Level::set(float spawnMin, float spawnMax, float requirment, float obstSpawnMin,float obstMax, 
	float specialMin, float specialMax, int maxSpecialSpawn, int maxSpawnEnemies, int level, 
	int levelTime){

	switch (level){
	case 1:
		chooseWhiteTexture = "resource/textures/backgrounds/Level1/grey.png";
		chooseColoredTexture = "resource/textures/backgrounds/Level1/color.png";
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
	

	mSpawnMin = spawnMin;
	mSpawnMax = spawnMax;
	mObstSpawnMin = obstSpawnMin;
	mObstMax = obstMax;
	mRequirment = requirment;
	mSpecialMin = specialMin;
	mSpecialMax = specialMax;
	mMaxSpecialSpawn = maxSpecialSpawn;
	mMaxSpawnEnemies = maxSpawnEnemies;
	mLevelTime = levelTime;
	/*Måste tömmas innan så att nästa bana inte hamnar över den gamla.*/
	if (!bgVector.empty())
		bgVector.clear();
	if (!clVector.empty())
		clVector.clear();

	bgVector = ResourceManager::getLevel(chooseWhiteTexture);
	clVector = ResourceManager::getLevel(chooseColoredTexture);	

}

int Level::getRandomNumber(){
	return rand() % 10;
}

void Level::opacityChange(float score){	

	opacity = 255 * score;
	if (score >= 1.0f) {
		opacity = 255;
	}
	if (score <= 0){
		opacity = 0;
	}
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

void Level::spawnGold(Entity::EntityVector &entityVector){
	sf::Time spawnGold = goldClock.getElapsedTime();
	/*Varannan sekund så spawnas guld.*/
	if (spawnGold.asSeconds() > 2){
		entityVector.push_back(new Gold(1200, 350));		
		goldClock.restart();
	}
}


/*Kallar på spawn-funktioner*/
void Level::spawn(Entity::EntityVector &entityVector){
	
	if (mSpecialMax > 0){
		spawnSpecialEnemies(entityVector);
	}
	spawnBasicEnemies(entityVector);
	spawnGold(entityVector);
}


float Level::percentRequirement(){
	
	return mRequirment;
}

std::string Level::getTheme(int level){
	if (level == 1){
		return "resource/sounds/Level1Theme.ogg";
	}
}


void Level::drawLevel(sf::RenderWindow& window, ResourceManager::SpriteVector& bgVector, float speed, sf::Color& color){
	/* Skapar och ritar ut sprites på relativa positioner */
	for (ResourceManager::SpriteVector::size_type i = 0; i < bgVector.size(); i++){
		baseImage.setTexture(ResourceManager::getTexture(chooseColoredTexture));
		//Borde egentligen lägga in en svordomsmätare här men... Jag har helt ärligt tappat räkningen.

		if (World::currentState == World::PLAYING){			
			if(bgVector[bgVector.size() - 1].getPosition().x + bgVector[bgVector.size() -1].getGlobalBounds().width > 9000)
				bgVector[i].setPosition(bgVector[i].getPosition().x - speed, 0);
		}		

		bgVector[i].setColor(color);
		window.draw(bgVector[i]);		
	}
}


/*flyttar på spriten tills slutet av spriten når högra kanten av window */
void Level::drawBackground(sf::RenderWindow &window){

	//baseImage.setTexture(ResourceManager::getTexture(chooseColoredTexture));

	drawLevel(window, bgVector, (20), sf::Color(255, 255, 255, 255));
	drawLevel(window, clVector, (20), sf::Color(255, 255, 255, opacity));
}