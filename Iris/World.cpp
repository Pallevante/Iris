#include "World.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Iris");
sf::Clock spawnTimer;
sf::Music* music = new sf::Music;
sf::Music* menuMusic = new sf::Music;
sf::Music* shopMusic = new sf::Music;
LoadLevel mLoadLevel;
LoadLevel::LevelEnum mCurrentLevel;

int spawnTimeLimit = 500;
int FRAME_LIMIT = 60;
float World::mScore = 0;
int World::mGold = 0;
int World::mLevelInt = 1;


/* Det h�r �r heeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeemskt d�ligt s�tt att l�sa problem */
/* ... #YOLO  - �lskar dig simon <3*/
MainMenu mainMenu;
ShopMenu shopMenu;
FinishMenu finishMenu;
PauseMenu pauseMenu;

World::World(): 
entityVector(){	
	goldFont.loadFromFile("resource/fonts/AGENTORANGE.ttf");
	menuMusic = ResourceManager::getMusic(mLevel->getTheme(0));
	shopMusic = ResourceManager::getMusic("resource/sounds/ShopTest.ogg");
	currentState = INMENU;
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
			/* Kollar inputen i en egen funktion f�r att slippa problem med placering av koden (kan anv�nda return i switchen) */
			
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

		if (currentState == RESTARTING){
			restart();
			music->setPlayingOffset(sf::Time::Zero);
			mScore = 0;
			currentState = PLAYING;
		}

		if (currentState == LOAD){
			if (!loadedMap || mLevelInt != mCurrentLevel){
				loadMap(mLevelInt);
				currentState = PLAYING;
			}
		}


		if (currentState == INMENU){

			shopMusic->stop();
			music->stop();

			if (!menuIsPlaying){
				shopIsPlaying = false;
				menuMusic->play();
				menuMusic->setLoop(true);
				menuIsPlaying = true;
			}
			mainMenu.drawMenu(window);
		}

		if (currentState == INSHOP){
			menuMusic->stop();		

			if (!shopIsPlaying){
				menuIsPlaying = false;
				shopMusic->play();
				shopMusic->setLoop(true);
				shopIsPlaying = true;
			}
			shopMenu.drawMenu(window);
		}

		if (currentState == PAUSED){
			music->pause();
			isPlaying = false;
			renderImages();
			sf::RectangleShape darkBox(sf::Vector2f(2000, 2000));
			//Boxen f�r pausmenyn
			sf::Sprite pauseBG;
			pauseBG.setTexture(ResourceManager::getTexture("resource/textures/buttons/menu/pause_bg.png"));
			pauseBG.setPosition(461, 136);

			//Titel f�r pausmeny
			sf::Sprite pauseTitle;
			pauseTitle.setTexture(ResourceManager::getTexture("resource/textures/buttons/menu/gamepaused_title.png"));
			pauseTitle.setPosition(280, 22);

			darkBox.setFillColor(sf::Color(0,0,0, 150));
			window.draw(darkBox);
			window.draw(pauseBG);
			window.draw(pauseTitle);
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


		/*Anv�nder en instans av GameState f�r att veta vad den skall g�ra.
		G�ra s� att n�r man klickar play s� g�r den in i ett state som laddar sedan �ndrar load till PLAYING?*/
		if (currentState == PLAYING){
			//Lite halv homo l�sning men verkar fungera (den kompilerar).
			
			if (!loadedMap){
				loadMap(mLevelInt);
			}
			//toneDownMusic(menuMusic, music);
			menuMusic->stop();
			/*S� man kan pausa musiken om man pausar spelet samt starta den igen.*/
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

		/*B�rjar spela musiken efter en viss volym.
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
	//Stannar musiken s� den kan bytas
	if (isPlaying){
		music->stop();
		isPlaying = false;
	}

	resetVector();
	window.setTitle("The game is loading! :)");	
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
	for (EntityVector::size_type i = 0; i < entityVector.size(); ++i){
		window.draw(*entityVector[i]);		
	}
	mHud->drawText(window);
} 

void World::tick(float dt){	
	if (mGold > 100)
		window.setTitle("Iris - Achivement: Oh Jew!");
	for (EntityVector::size_type i = 0; i < entityVector.size(); ++i){
		entityVector[i]->tick(entityVector, dt);		
	}
	mHud->setText();
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
		

/*Skapar en ny vektor som sedan l�gger in alla levande entiteter.
Den nya vektorn uppdaterar v�ran "main" vektor sedan.*/
void World::killDeadEntities(){
	EntityVector reserveEnteties;
	for (EntityVector::iterator i = entityVector.begin(); i != entityVector.end(); ++i){
		Entity* enteties = *i;
		if (enteties->isAlive()){
			reserveEnteties.push_back(enteties);
		}
	
	}
	entityVector = reserveEnteties;
}
/*�terst�ller vektorn till ursprungsl�ge med enbart spelaren i.
  Kan vara bra att ha �ven vid ny bana.*/
void World::resetVector(){
	EntityVector reserveVector;
	for (EntityVector::iterator i = entityVector.begin(); i != entityVector.end(); ++i){
		Entity* entities = *i;
		if (entities->getType() == Entity::PLAYER){
			reserveVector.push_back(entities);
		}
	}
	entityVector = reserveVector;
}


void World::restart(){
	window.clear();
	resetVector();
	mLevel->restart();
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

