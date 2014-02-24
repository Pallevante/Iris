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
<<<<<<< HEAD
=======
#include "Hud.hpp"
#include <SFML/System/Clock.hpp>
>>>>>>> majal

class Level;
class Hud;

class World{
public:
	/*Används för att veta vad man ska rendera.*/
	enum GameState{
		INMENU,
		PLAYING,
		PAUSED,
		INSHOP,
		OUTRO,
		INTRO,
		EXIT
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
	static float mScore;
	static int mGold;
	void renderHUD();
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
	void pause();
	void enterStore();
	void enterSettings();
	void enterMap();
	DefaultEnemy enemy(DefaultEnemy &enemy);

	/*Variabler*/
	typedef std::vector<Entity*> EntityVector;

	

	EntityVector entityVector;
	Player *mPlayer;
	Level* mLevel;
	Hud* mHud;
	sf::Clock deltaTimer;
};
