#include "World.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Iris");
sf::Clock spawnTimer;
sf::Music* music = new sf::Music;
LoadLevel mLoadLevel;
LoadLevel::LevelEnum mCurrentLevel;
int spawnTimeLimit =  500;
int FRAME_LIMIT = 60;

World::World(): 
entityVector(){	
	currentState = INMENU;
	Player *mPlayer;	
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FRAME_LIMIT);
	mPlayer = new Player(100, 100);
	entityVector.push_back(mPlayer);
	loadMap();	
}

World::~World(){}

bool isPlaying = false; /*Kollar om man spelar musik*/
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
				window.close();
				ResourceManager::clear();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
				pause();
			/* Debug-funktioner */
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F1)
				window.setFramerateLimit(10);
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F2)
				window.setFramerateLimit(FRAME_LIMIT);		
			/* Kollar inputen i en egen funktion f�r att slippa problem med placering av koden (kan anv�nda return i switchen) */

			if (currentState == INMENU || currentState == INSHOP)/* Kollar inputen i en egen funktion f�r att slippa problem med placering av koden (kan anv�nda return i switchen) */

			menuInput(event);
		}
		

		window.clear();

		if (currentState == INMENU){
			mainMenu.drawMenu(window);
		}

		if (currentState == INSHOP){
			shopMenu.drawMenu(window);
		}
		if (currentState == PAUSED){			
			music->pause();
			isPlaying = false;
			renderImages();
		}

		/*Anv�nder en instans av GameState f�r att veta vad den skall g�ra.
		G�ra s� att n�r man klickar play s� g�r den in i ett state som laddar sedan �ndrar load till PLAYING?*/
		if (currentState == PLAYING){
			//Lite halv homo l�sning men verkar fungera (den kompilerar).

			if (!loadedMap){
				loadMap();
			}

			/*S� man kan pausa musiken om man pausar spelet samt starta den igen.*/
			if (!isPlaying){	
				music->play();
				isPlaying = true;				
			}

			tick(dt);

			startGame();
		}
		window.display();
	}
}

void World::loadMap(){
	mCurrentLevel = mLoadLevel.LevelEnum::FIRSTLEVEL;
	mLoadLevel.setLevel(mCurrentLevel);
	mLevel = mLoadLevel.getLevel();
	music = ResourceManager::getMusic(mLevel->getTheme(1));
	loadedMap = true;
}



void World::startGame(){
	detectCollisions();
	killDeadEntities();
	spawnEnemies(); 
	renderImages();
}

void World::renderImages(){
	mLevel->drawBackground(window, currentState);
	for (EntityVector::size_type i = 0; i < entityVector.size(); i++){
		window.draw(*entityVector[i]);
	}
	
}

void World::tick(float dt){
	for (EntityVector::size_type i = 0; i < entityVector.size(); i++){
		entityVector[i]->tick(entityVector, dt);
	}
}


/* Tar emot tv� Entitypekare och returnerar om de kolliderar eller inte. Anv�nds som st�dfunktion till detectCollisions. */
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

/* G�r igenom entityVector och k�r isColliding p� alla par av entiteter.
Den utkommenterade biten kollar om sakerna som kolliderar har samma typ
(hostile eller friendly t ex) och struntar is�fall i att de kolliderar.

Typ-kollen b�r ske innan kollisions-kollen f�r att spara p� arbetskraft.*/
void World::detectCollisions(){
	for (unsigned int i = 0; i < entityVector.size(); i++){
		Entity *entity0 = entityVector[i];

		for (unsigned int j = i + 1; j < entityVector.size(); j++){
			Entity *entity1 = entityVector[j];
			/*Du anv�nder en check i collision i world om typen �r GOLD sedan h�mtar du damage f�r v�rdet.*/
			if (isColliding(entity0, entity1) && entity0->getType() != entity1->getType()){
				if (entity0->getType() == Entity::GOLD)
					mGold += entity0->getDamage();
				else if (entity1->getType() == Entity::GOLD)
					mGold += entity1->getDamage();

				entity0->collide(entity1, entityVector);
				entity1->collide(entity0, entityVector);
			}
		}
	}
}


/*Skapar en ny vektor som sedan l�gger in alla levande entiteter.
Den nya vektorn uppdaterar v�ran "main" vektor sedan.*/
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


/*
			 __	- FML.
            / _)
   _/\/\/\_/ /
  /			 |
 / (  |	  (  |
/   |_|--- |_|

*/
