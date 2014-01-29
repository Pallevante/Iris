#include "World.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Iris");
sf::Clock spawnTimer;
int spawnTimeLimit =  500;

World::World(): 

entityVector()
{
	currentState = PLAYING;
	Animation* playerAnimation = new Animation("resource/test.png", 200, 4);
	Player *mPlayer;
	window.setFramerateLimit(65);
	mPlayer = new Player(playerAnimation, 100, 100);
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
		}

		window.clear();
		/*Anv�nder en instans av GameState f�r att veta vad den skall g�ra.
		  G�ra s� att n�r man klickar play s� g�r den in i ett state som laddar sedan �ndrar load till PLAYING?*/
		if (currentState == PLAYING){
			startGame();
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


/* Tar emot tv� Entitypekare och returnerar om de kolliderar eller inte. Anv�nds som st�dfunktion till detectCollisions. */
bool World::isColliding(Entity *entity1, Entity *entity2){
	const float X0 = entity1->getPosition().x;
	const float Y0 = entity1->getPosition().y;
	const float R0 = entity1->getRad();

	const float X1 = entity2->getPosition().x;
	const float Y1 = entity2->getPosition().y;
	const float R1 = entity2->getRad();
	const float DX = X0 - X1;
	const float DY = Y0 - Y1;

	return DX * DX + DY * DY < (R0 + R1) * (R0 + R1);
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

			if (isColliding(entity0, entity1) && entity0->getType() != entity1->getType()){
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

/*Denna tiomern f�r vi h�mta ifr�n levelload sedan d� det kommmer olika m�nga fiender p� olika banor.*/
void World::spawnEnemies(){
	sf::Time time = spawnTimer.getElapsedTime();
	if(time.asMilliseconds() > 600){
		Animation* enemyAnimation = new Animation("resource/test.png", 50, 4);
		entityVector.push_back(new DefaultEnemy(enemyAnimation, 1));
		spawnTimer.restart();
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
