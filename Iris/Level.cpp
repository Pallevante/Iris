#include "Level.hpp"

ResourceManager::TextureVector clVector;
ResourceManager::TextureVector bgVector;
sf::Clock goldClock;
sf::Clock worldClock;

Level::Level(){

}
Level::~Level(){


}

void Level::set(float spawnMin, float spawnMax, float requirment, float obstSpawnMin,
	float obstMax, float specialMin, float specialMax, int maxSpecialSpawn, int maxSpawnEnemies, int level){
		
	switch (level){
	case 1:
		chooseWhiteTexture = "resource/textures/backgrounds/usa_bild_gr�.png";
		chooseColoredTexture = "resource/textures/backgrounds/usa_bild_bl�.png";
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

	bgVector = ResourceManager::getLevel(chooseWhiteTexture);
	clVector = ResourceManager::getLevel(chooseColoredTexture);

	
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

void Level::spawnGold(Entity::EntityVector &entityVector){
	sf::Time spawnGold = goldClock.getElapsedTime();
	/*Varannan sekund s� spawnas guld.*/
	if (spawnGold.asSeconds() > 2){
		entityVector.push_back(new Gold(1200, 350));		
		goldClock.restart();
	}
}


/*Kallar p� spawn-funktioner*/
void Level::spawn(Entity::EntityVector &entityVector){
	
	if (mSpecialMax > 0){
		spawnSpecialEnemies(entityVector);
	}
	spawnBasicEnemies(entityVector);
	spawnGold(entityVector);
}


float Level::percentRequirement(float requirement){
	mRequirment = requirement;
	return mRequirment;
}

std::string Level::getTheme(int level){
	if (level == 1){
		return "resource/sounds/Level1Theme.ogg";
	}
}


void Level::drawLevel(sf::RenderWindow& window, ResourceManager::TextureVector& bgVector, float speed, sf::Color& color, World::GameState state){
	/* Skapar och ritar ut sprites p� relativa positioner */
	for (std::vector<sf::Texture>::size_type it = 0; it < bgVector.size(); it++){
		sf::Sprite newSprite;
		newSprite.setTexture(bgVector[it]);
		if (state == World::PLAYING){
			newSprite.setPosition((it * 1024) - speed, 0);
		}
		newSprite.setColor(color);
		window.draw(newSprite);
	}
}

void Level::drawBackground(sf::RenderWindow &window, World::GameState& state){
	drawLevel(window, bgVector, (worldClock.getElapsedTime().asSeconds() * 200), sf::Color(255, 255, 255, 255), state);
	drawLevel(window, clVector, (worldClock.getElapsedTime().asSeconds() * 200), sf::Color(255, 255, 255, 0), state);
}

