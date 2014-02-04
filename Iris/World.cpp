#include "World.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Iris");
sf::Clock spawnTimer;
sf::Music music;
LoadLevel mLoadLevel;
LoadLevel::LevelEnum mCurrentLevel;

int spawnTimeLimit =  500;

World::World(): 

entityVector()
{
	music.openFromFile("resource/Level1Theme.ogg");
	music.play();
	currentState = PLAYING;	
	Player *mPlayer;
	window.setFramerateLimit(65);
	mPlayer = new Player(100, 100);
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
		}
		
		window.clear();
		/*Använder en instans av GameState för att veta vad den skall göra.
		  Göra så att när man klickar play så går den in i ett state som laddar sedan ändrar load till PLAYING?*/
		if (currentState == PLAYING){
			//Lite halv homo lösning men verkar fungera (den kompilerar).
			mCurrentLevel = mLoadLevel.LevelEnum::FIRSTLEVEL;
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

/*Denna tiomern får vi hämta ifrån levelload sedan då det kommmer olika många fiender på olika banor.*/
void World::spawnEnemies(){
	mLevel->spawn();
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
