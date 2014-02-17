#pragma once
#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.hpp"
#include "DefaultEnemy.hpp"
#include "LoadLevel.hpp"
#include "MainMenu.hpp"
#include "ShopMenu.hpp"
#include <SFML/System/Clock.hpp>

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

	GameState currentState;

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
	MainMenu mainMenu;
	ShopMenu shopMenu;
	Level* mLevel;
	sf::Clock deltaTimer;
};
