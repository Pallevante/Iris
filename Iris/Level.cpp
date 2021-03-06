#include "Level.hpp"


ResourceManager::SpriteVector clVector;
ResourceManager::SpriteVector bgVector;
sf::Clock goldClock;
sf::Clock scrollClock;

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
		chooseWhiteTexture = "resource/textures/backgrounds/Level3/grey.png";
		chooseColoredTexture = "resource/textures/backgrounds/Level3/color.png";
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
		chooseWhiteTexture = "resource/textures/backgrounds/Final/default.png";
		chooseColoredTexture = "resource/textures/backgrounds/Final/default.png";
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

	/*M�ste t�mmas innan s� att n�sta bana inte hamnar �ver den gamla.*/
	if (!bgVector.empty() || !clVector.empty())
		clearVectors();
		

	auto future = std::async(ResourceManager::getLevel, chooseWhiteTexture);
	auto future2 = std::async(ResourceManager::getLevel, chooseColoredTexture);
	bgVector = future.get();
	clVector = future2.get();


	//H�mtar bakgrundsbilden utan att ladda in den igen (den ligger redan i ramminnet efter getLevel)
	baseImage = ResourceManager::getImage(chooseWhiteTexture);
	int backgroundWidth = baseImage.getSize().x;
	//Hastighet = bredd / tid
	backgroundSpeed = backgroundWidth / mLevelTime;
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

/*Kollar hur m�nga som ska spawnas av default enemies*/
void Level::spawnBasicEnemies(Entity::EntityVector &entityVector){
	//HAX
	if (mSpawnMax == 0)
		return;

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
			mSpecialCl.restart();
		}
	}

	if (spawnSpecialT.asSeconds() >= mSpecialMax){
		entityVector.push_back(new DefaultEnemy(1, sf::Vector2f(1300, getRandomNumber(620))));
		mSpecialCl.restart();
	}
}

void Level::spawnGold(Entity::EntityVector &entityVector){
	sf::Time spawnGold = goldClock.getElapsedTime();
	/*Var tredje sekund s� spawnas guld.*/
	if (spawnGold.asSeconds() > 3){
		
		float yPos = getRandomNumber(620);				//S�tter position f�r Y som alla guldklimpar anv�nder sig av.
		float xPos = 1300;								//S�tter X v�rdet f�r alla guldklimpar som kommer �ndras med 50
		int numbOfGoldToSpawn = getRandomNumber(4);		//H�mtar antalet guld som skall spawnas.

		for (int index = 0; index < numbOfGoldToSpawn; ++index){
			entityVector.push_back(new Gold(sf::Vector2f(xPos, yPos)));
			xPos += 50;
		}		
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


float Level::percentRequirement(){
	
	return mRequirment;
}

std::string Level::getTheme(int level){
	if (level == 0){
		return "resource/sounds/menuTheme.wav";
	}
	if (level == 1){
		return "resource/sounds/Level1Theme.wav";
	}
	if (level == 2){
		return "resource/sounds/Level2Theme.wav";
	}
	if (level == 3){
		return "resource/sounds/Level3Theme.wav";
	}
	if (level == 8){
		return "resource/sounds/Final.wav";
	}

}


void Level::drawLevel(sf::RenderWindow& window, ResourceManager::SpriteVector& bgVector, sf::Color& color, float dt){
	/* Skapar och ritar ut sprites p� relativa positioner */
	sf::Time scrollTime = scrollClock.getElapsedTime();
	float fPassedTime = scrollTime.asMilliseconds();

	for (ResourceManager::SpriteVector::size_type i = 0; i < bgVector.size(); i++){
		
		
		if (World::currentState == World::PLAYING){
			//Om positionen p� den f�rsta bilden sammanslaget med bredden p� f�nstret �r mer �n banl�ngden, FINISHMENU
			if (-(bgVector[0].getPosition().x - window.getSize().x) >= baseImage.getSize().x){
				if (World::mScore >= mRequirment){
					World::currentState = World::INFINISHMENU;
				}
				else{
					World::currentState = World::INFAILEDFINISHMENU;
				}
			}

			sf::Vector2f currentPosition = bgVector[i].getPosition();

			sf::Vector2f newPosition = sf::Vector2f(currentPosition.x - (backgroundSpeed * dt), currentPosition.y);

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
	ResourceManager::clearImages();
	ResourceManager::clearLevels();
	bgVector.clear();
	clVector.clear();
}


/*flyttar p� spriten tills slutet av spriten n�r h�gra kanten av window */
void Level::drawBackground(sf::RenderWindow &window, float dt){

	//baseImage.setTexture(ResourceManager::getTexture(chooseColoredTexture));

	
	//Nedan fungerar inte riktigt �n. Beh�ver fixas innan release. G�rna innan testning p� onsdag.
	//float speed = (baseImage.getLocalBounds().width - window.getSize().x) / (mLevelTime * 10);
	


	drawLevel(window, bgVector, sf::Color(255, 255, 255, 255), dt);
	drawLevel(window, clVector, sf::Color(255, 255, 255, opacity), dt);
}