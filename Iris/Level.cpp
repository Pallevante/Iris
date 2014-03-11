#include "Level.hpp"


ResourceManager::SpriteVector clVector;
ResourceManager::SpriteVector bgVector;
sf::Clock goldClock;
sf::Clock scrollClock;
//sf::Sprite baseImage;

Level::Level(){
	opacity = 0;
}
Level::~Level(){}

void Level::set(float spawnMin, float spawnMax, float requirment, float obstSpawnMin,float obstMax, 
	float specialMin, float specialMax, int maxSpecialSpawn, int maxSpawnEnemies, int level, 
	int levelTime){

	switch (level){
	case 1:
		chooseWhiteTexture = "resource/textures/backgrounds/Level1/grey.png";
		chooseColoredTexture = "resource/textures/backgrounds/Level1/color.png";
		break;
	case 2:
		chooseWhiteTexture = "resource/textures/backgrounds/Level2/grey.png";
		chooseColoredTexture = "resource/textures/backgrounds/Level2/color.png";
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
	/*
	for (ResourceManager::SpriteVector::size_type i = 0; i < bgVector.size(); i++){

	}*/
}

float Level::getRandomNumber(float maxNumber){
	return fmodf(rand(), maxNumber);
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
			entityVector.push_back(new Cloud(1, sf::Vector2f(1300, getRandomNumber(620))));
		}

	}

	if (spawnDefaultT.asSeconds() >= mSpawnMax){
		entityVector.push_back(new Cloud(1, sf::Vector2f(1300, getRandomNumber(620))));
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
			entityVector.push_back(new DefaultEnemy(1, sf::Vector2f(1300, getRandomNumber(620))));
		}
	}

	if (spawnSpecialT.asSeconds() >= mSpecialMax){
		entityVector.push_back(new DefaultEnemy(1, sf::Vector2f(1300, getRandomNumber(620))));
		mSpecialCl.restart();
	}
}

void Level::spawnGold(Entity::EntityVector &entityVector){
	sf::Time spawnGold = goldClock.getElapsedTime();
	/*Varannan sekund så spawnas guld.*/
	if (spawnGold.asSeconds() > 3){
		
		float yPos = getRandomNumber(620);				//Sätter position för Y som alla guldklimpar använder sig av.
		float xPos = 1300;								//Sätter X värdet för alla guldklimpar som kommer ändras med 50
		int numbOfGoldToSpawn = getRandomNumber(4);		//Hämtar antalet guld som skall spawnas.

		for (int index = 0; index < numbOfGoldToSpawn; index++){
			entityVector.push_back(new Gold(sf::Vector2f(xPos, yPos)));
			xPos += 50;
		}		
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
	if (level == 0){
		return "resource/sounds/Credits.wav";
	}
	if (level == 1){
		return "resource/sounds/Level1Theme.ogg";
	}
	if (level == 2){
		return "resource/sounds/Level2Theme.ogg";
	}

}


void Level::drawLevel(sf::RenderWindow& window, ResourceManager::SpriteVector& bgVector, float speed, sf::Color& color){
	/* Skapar och ritar ut sprites på relativa positioner */
	sf::Time scrollTime = scrollClock.getElapsedTime();
	float fPassedTime = scrollTime.asMilliseconds();

	for (ResourceManager::SpriteVector::size_type i = 0; i < bgVector.size(); i++){
		
		//Borde egentligen lägga in en svordomsmätare här men... Jag har helt ärligt tappat räkningen.
		/*
		if (World::currentState == World::PLAYING){	
			//Kollar sista posten i vektorns position samt storleken för att veta om den är i kanten på skärmen.
			if (bgVector[bgVector.size() - 1].getPosition().x + bgVector[bgVector.size() - 1].getGlobalBounds().width > 720){
				if (fmodf(fPassedTime, 1) == 0)
					bgVector[i].setPosition(bgVector[i].getPosition().x - speed, 0);
			}
			//else
				//World::currentState = World::INFINISHMENU;
		}		 
		*/
		if (World::currentState == World::PLAYING){
			sf::Vector2f currentPosition = bgVector[i].getPosition();

			sf::Vector2f newPosition = sf::Vector2f(currentPosition.x - (speed * fPassedTime/10000000), currentPosition.y);
		
			bgVector[i].setPosition(newPosition);
		}
		bgVector[i].setColor(color);
		window.draw(bgVector[i]);		
	}
	
}

void Level::restart(){
	for (ResourceManager::SpriteVector::size_type i = 0; i < bgVector.size(); i++){
		bgVector[i].setPosition(i * bgVector[i].getGlobalBounds().width, 0);
		clVector[i].setPosition(i * clVector[i].getGlobalBounds().width, 0);
	}
}


void Level::clearVectors(){
	bgVector.clear();
	clVector.clear();
}


/*flyttar på spriten tills slutet av spriten når högra kanten av window */
void Level::drawBackground(sf::RenderWindow &window){

	//baseImage.setTexture(ResourceManager::getTexture(chooseColoredTexture));

	int backgroundWidth = sf::Texture::getMaximumSize() * bgVector.size();

	//Nedan fungerar inte riktigt än. Behöver fixas innan release. Gärna innan testning på onsdag.
	//float speed = (baseImage.getLocalBounds().width - window.getSize().x) / (mLevelTime * 10);
	float speed = backgroundWidth / mLevelTime;


	drawLevel(window, bgVector, speed, sf::Color(255, 255, 255, 255));
	drawLevel(window, clVector, speed, sf::Color(255, 255, 255, opacity));
}