#include "World.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Iris");
sf::Clock spawnTimer;
LoadLevel mLoadLevel;
LoadLevel::LevelEnum mCurrentLevel;

int spawnTimeLimit =  500;

World::World(): 

entityVector()
{
	currentState = INMENU;	
	Player *mPlayer;
	PlayerAura *mPlayerAura;
	window.setFramerateLimit(65);
	mPlayerAura = new PlayerAura(100, 100);
	mPlayer = new Player(100, 100);
	entityVector.push_back(mPlayerAura);
	entityVector.push_back(mPlayer);
	
}

World::~World(){}

void World::run(){

		while (window.isOpen())	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
				pause();
			
			/* Kollar inputen i en egen funktion för att slippa problem med placering av koden (kan använda return i switchen) */
			menuInput(event);
		}
		
		window.clear();

		if (currentState == INMENU){
			mainMenu.drawMenu(window);
		}

		if (currentState == INSHOP){
			shopMenu.drawMenu(window);
		}
		

		if (currentState == PLAYING){
			//Lite halv homo lösning men verkar fungera (den kompilerar).
			mCurrentLevel = mLoadLevel.LevelEnum::firstLevel;
			//mLoadLevel.setLevel(mCurrentLevel);
			mLevel = mLoadLevel.getLevel();
			startGame();
		}
		if (currentState == PAUSED){
			renderImages();
		}
		window.display();
	}
}
void World::startGame(){
	tick();
	detectCollisions();
	killDeadEntities();
	spawnEnemies();
	renderImages();
	
}

void World::renderImages(){
	for (EntityVector::size_type i = 0; i < entityVector.size(); i++){
		window.draw(*entityVector[i]);
	}
}

void World::tick(){
	for (EntityVector::size_type i = 0; i < entityVector.size(); i++){
		entityVector[i]->tick(entityVector);
	}
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

			if (isColliding(entity0, entity1) && entity0->getType() != entity1->getType()){
				entity0->collide(entity1, entityVector);
				entity1->collide(entity0, entityVector);
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

void World::auraAddSub(Entity *entity, Entity::EntityVector &entities){
	
	

	

}


/*Denna tiomern får vi hämta ifrån levelload sedan då det kommmer olika många fiender på olika banor.*/
void World::spawnEnemies(){
	sf::Time time = spawnTimer.getElapsedTime();
	if(time.asMilliseconds() > 600){
		entityVector.push_back(new DefaultEnemy(1));
		spawnTimer.restart();
	}
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
}



/*
				__	- FML.
			   / _)
	  _/\/\/\_/ /
	 /			|
	/ (	 |	 (	|
   /   |_|--- |_|

 */
