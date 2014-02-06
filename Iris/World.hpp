#pragma once
#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "DefaultEnemy.hpp"
#include "LoadLevel.hpp"
#include "MainMenu.hpp"
#include "ShopMenu.hpp"

class Level;


class World{
public:
	/*Anv�nds f�r att veta vad man ska rendera.*/
	enum GameState{
		INMENU,
		PLAYING,
		INSHOP,
		OUTRO,
		INTRO
	};

	GameState currentState;

	World();
	~World();
	void run();
	/*M�ste ladda in banan innan*/
	void startGame();
	/*Sl�nga in r�tt parametrar f�r att loadMap ska ladda in
	music, bilder och fiender*/
	void loadMap();
private:
	/*Spelrelaterade funktioner*/
	void spawnEnemies();
	void renderImages();
	void tick();
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
	EntityVector entityVector;

	MainMenu mainMenu;
	ShopMenu shopMenu;



	Level* mLevel;
};
