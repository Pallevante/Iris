#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Animation.hpp"
#include "DefaultEnemy.hpp"
#include "Entity.hpp"
#include "LoadLevel.hpp"
#include "MainMenu.hpp"
#include "Player.hpp"
#include "ResourceManager.hpp"
#include "ShopMenu.hpp"

class Level;


class World{
public:
	/*Används för att veta vad man ska rendera.*/
	enum GameState{
		INMENU,
		PLAYING,
		PAUSED,
		INSHOP,
		OUTRO,
		INTRO
	};

	static GameState currentState;

	World();
	~World();
	void run();
	/*Måste ladda in banan innan*/
	void startGame();
	/*Slänga in rätt parametrar för att loadMap ska ladda in
	music, bilder och fiender*/
	void loadMap();
private:
	/*Spelrelaterade funktioner*/
	void spawnEnemies();
	void renderImages();
	void tick(float dt);
	bool isColliding(Entity *entity1, Entity *entity2);
	void detectCollisions();
	void killDeadEntities();
	int aura(Entity *entity, std::vector<Entity*> &entities);

	//int score(/*Entity *entity, std::vector<Entity*> &entities*/);
	/*Menyrelaterade funktioner*/

	void menuInput(sf::Event &event);
	void pause();
	void enterStore();
	void enterSettings();
	void enterMap();
	

	/*Variabler*/
	typedef std::vector<Entity*> EntityVector;
	int mGold;
	int mScore;
	
	EntityVector entityVector;
	Player *mPlayer;
	MainMenu mainMenu;
	ShopMenu shopMenu;
	Level* mLevel;
	sf::Clock deltaTimer;
};
