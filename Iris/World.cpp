#include "World.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Iris");
sf::Clock spawnTimer;
sf::Music* music = new sf::Music;
sf::Music* menuMusic = new sf::Music;

LoadLevel mLoadLevel;
LoadLevel::LevelEnum mCurrentLevel;

int spawnTimeLimit = 500;
int FRAME_LIMIT = 60;
float World::mScore = 0;
int World::mGold = 0;
int World::mLevelInt = 1;


/* Det här är heeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeemskt dåligt sätt att lösa problem */
/* ... #YOLO  - Älskar dig simon <3*/
MainMenu mainMenu;
ShopMenu shopMenu;
FinishMenu finishMenu;
PauseMenu pauseMenu;

World::World(): 
entityVector(){	
	goldFont.loadFromFile("resource/fonts/AGENTORANGE.ttf");
	menuMusic = ResourceManager::getMusic(mLevel->getTheme(0));
	currentState = INMENU;
	//Player *mPlayer;
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FRAME_LIMIT);
	mPlayer = new Player(100, 100);
	entityVector.push_back(mPlayer);
	mHud = new Hud();
	mSelectLevelM = new SelectLevelMenu();
	
}

World::~World(){}


bool loadedMap = false;
void World::run(){
	while (window.isOpen())	{

		int deltaTime = deltaTimer.restart().asMicroseconds();
		float expectedTime = ((1.0f / FRAME_LIMIT) * 1000000);
		float dt = deltaTime / expectedTime;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				ResourceManager::clear();
				mLevel->clearVectors();
				window.close();
				
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
				pause();
			/* Debug-funktioner */
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F1)
				window.setFramerateLimit(10);
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F2)
				window.setFramerateLimit(FRAME_LIMIT);		
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F3)
				currentState = INFINISHMENU;
			/* Kollar inputen i en egen funktion för att slippa problem med placering av koden (kan använda return i switchen) */
			
			switch (currentState){
			case INMENU:
				mainMenu.input(event);
				break;
			case INSHOP:
				shopMenu.input(event);
				break;
			case INLEVELSELECT:
				mSelectLevelM->input(event);
				break;
			case INFINISHMENU:
				finishMenu.input(event);
				break;
			case PAUSED:
				pauseMenu.input(event);
				break;
			}
		}


		window.clear();

		if (currentState == EXIT)
			window.close();

		if (currentState == INMENU){
			
			music->stop();
			if (!menuIsPlaying){
				menuMusic->play();
				menuMusic->setLoop(true);
				menuIsPlaying = true;
			}
			mainMenu.drawMenu(window);
		}

		if (currentState == INSHOP){
			shopMenu.drawMenu(window);
		}
		if (currentState == PAUSED){
			music->pause();
			isPlaying = false;
			renderImages();
			sf::RectangleShape darkBox(sf::Vector2f(2000, 2000));
			darkBox.setFillColor(sf::Color(0,0,0, 150));
			window.draw(darkBox);
			pauseMenu.drawMenu(window);
		}
		if(currentState == INLEVELSELECT){
			mSelectLevelM->drawMenu(window);

		}
		if (currentState == INFINISHMENU){
			finishMenu.drawMenu(window);
			
			std::stringstream goldAmount;
			goldAmount.str("");
			goldAmount.clear();
			goldAmount << World::mGold;

			sf::Text gold;
			gold.setFont(goldFont);
			gold.setString(goldAmount.str());
			gold.setColor(sf::Color::White);
			gold.setCharacterSize(60);
			gold.setPosition(346, 140);
			window.draw(gold);

			std::stringstream scoreAmount;
			scoreAmount.str("");
			scoreAmount.clear();
			scoreAmount << World::mScore;

			sf::Text score;
			score.setFont(goldFont);
			score.setString(scoreAmount.str());
			score.setColor(sf::Color::White);
			score.setCharacterSize(60);
			score.setPosition(755, 140);
			window.draw(score);

		}


		/*Använder en instans av GameState för att veta vad den skall göra.
		Göra så att när man klickar play så går den in i ett state som laddar sedan ändrar load till PLAYING?*/
		if (currentState == PLAYING){
			//Lite halv homo lösning men verkar fungera (den kompilerar).
			
			if (!loadedMap){
				loadMap(mLevelInt);
			}
			//toneDownMusic(menuMusic, music);
			menuMusic->stop();
			/*Så man kan pausa musiken om man pausar spelet samt starta den igen.*/
			if (!isPlaying && loadedMap){
				music->play();
				isPlaying = true;
			}

			tick(dt);

			startGame();
		}
		window.display();
	}
}

/*Tonar ut ena musiken in in den andra.*/
void World::toneDownMusic(sf::Music* m0, sf::Music* m1){
	m1->setVolume(0);
	while (m0->getVolume() >= 0){
		m0->setVolume(m0->getVolume() - 1);
		m1->setVolume(m1->getVolume() + 1);

		/*Börjar spela musiken efter en viss volym.
			Fungerar Ej just nu.*/
		if (m1->getVolume() > 10){
			if (!isPlaying){
				m1->play();
				isPlaying = true;
			}
		}
	}
	m0->stop();
}

/*Load funktion.*/
void World::loadMap(int level){
	window.setTitle("Getting shit ready for you :) - FUCK DISTRICT 12");
	getEnum(level);
	mLoadLevel.setLevel(mCurrentLevel);
	mLevel = mLoadLevel.getLevel();
	music = ResourceManager::getMusic(mLevel->getTheme(level));
	
	window.setTitle("Iris");
	loadedMap = true;
}

void World::getEnum(int level){
	switch (level){
	case 1:
		 mCurrentLevel = LoadLevel::FIRSTLEVEL;
		break;
	case 2:
		 mCurrentLevel = LoadLevel::SECONDLEVEL;
		 break;
	}
}



void World::startGame(){
	detectCollisions();
	killDeadEntities();
	spawnEnemies();
	renderImages();
	//mPlayer->score();
}

void World::renderImages(){
	mLevel->drawBackground(window);
	for (EntityVector::size_type i = 0; i < entityVector.size(); i++){
		window.draw(*entityVector[i]);		
	}
	mHud->drawText(window);
}

void World::tick(float dt){	
	for (EntityVector::size_type i = 0; i < entityVector.size(); i++){
		entityVector[i]->tick(entityVector, dt);		
	}
	mHud->setText();
}




/* Tar emot två Entitypekare och returnerar om de kolliderar eller inte. Används som stödfunktion till detectCollisions. */
bool World::isColliding(Entity *entity1, Entity *entity2){
	int width1 = entity1->getWidth();
	int width2 = entity2->getWidth();
	int height1 = entity1->getHeight();
	int height2 = entity2->getHeight();
	sf::Vector2f position1 = entity1->getPosition();
	sf::Vector2f position2 = entity2->getPosition();


	if ((position1.x + width1 < position2.x) ||
		(position1.x > position2.x + width2) ||
		(position1.y > position2.y + height2) ||
		(position1.y + height1  < position2.y)){
		return false;
	}
	else{
		return true;
	}
}

/* Går igenom entityVector och kör isColliding på alla par av entiteter.
Den utkommenterade biten kollar om sakerna som kolliderar har samma typ
(hostile eller friendly t ex) och struntar isåfall i att de kolliderar.

Typ-kollen bör ske innan kollisions-kollen för att spara på arbetskraft.*/
void World::detectCollisions(){
	for (unsigned int i = 0; i < entityVector.size(); i++){
		Entity *entity0 = entityVector[i];

		for (unsigned int j = i + 1; j < entityVector.size(); j++){
			Entity *entity1 = entityVector[j];
			/*Du använder en check i collision i world om typen är GOLD sedan hämtar du damage för värdet.*/
			if (isColliding(entity0, entity1) && entity0->getType() != entity1->getType()){

				if (entity0->getType() == Entity::GOLD && entity1->getType() == Entity::PLAYER)
					mGold += entity0->getDamage();

				else if (entity1->getType() == Entity::GOLD&& entity0->getType() == Entity::PLAYER)
					mGold += entity1->getDamage();

				if (entity0->getType() == Entity::RAY && entity1->getType() == Entity::ENEMY
					|| entity0->getType() == Entity::ENEMY && entity1->getType() == Entity::RAY){					
					mScore += 0.10f;
				}				

				else if (mScore > 1){
					mScore = 1;
				}
				 if (entity0->getType() == Entity::PLAYER && entity1->getType() == Entity::ENEMY ||
					entity1->getType() == Entity::PLAYER && entity0->getType() == Entity::ENEMY){
					mScore -= 0.01f;
				}


				 else if (mScore <= 0){
					 mScore = 0;
				 }
				entity0->collide(entity1, entityVector);
				entity1->collide(entity0, entityVector);				
				/*Uppdaterar auran samt Level opacity.*/
				mLevel->opacityChange(mScore);
				mPlayer->updateAura(mScore);
			}

		}
	}
}
		

/*Skapar en ny vektor som sedan lägger in alla levande entiteter.
Den nya vektorn uppdaterar våran "main" vektor sedan.*/
void World::killDeadEntities(){
	EntityVector reserveEnteties;
	for (EntityVector::iterator i = entityVector.begin(); i != entityVector.end(); i++){
		Entity* enteties = *i;
		if (enteties->isAlive()){
			reserveEnteties.push_back(enteties);
		}
	
	}
	entityVector = reserveEnteties;
}


void World::spawnEnemies(){
	if (loadedMap)
		mLevel->spawn(entityVector);
}

void World::pause(){
	if (currentState == PLAYING){
		currentState = PAUSED;
		return;
	}
	else if (currentState == PAUSED){
		currentState = PLAYING;
		return;
	}
	else if (currentState == INSHOP){
		currentState = INMENU;
		return;
	}
}

World::GameState World::currentState;

/*

			 __  - FML. 
            / _)
   _/\/\/\_/ /
  /	         |
 / (  |	  (  |
/   |_|--- |_|

This is Dan. 
Dan has watched the progress of iris since the begining.
Dan had come to a conclusion about the programmers.
"You are fucking idiots" - Dan
*/

