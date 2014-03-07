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
#include "Hud.hpp"
#include <SFML/System/Clock.hpp>
#include "SelectLevelMenu.hpp"
#include "FinishMenu.hpp"
#include "PauseMenu.hpp"

class Level;
class Hud;
class SelectLevelMenu;



class World{
public:
	/*Används för att veta vad man ska rendera.*/
	enum GameState{
		INMENU,
		PLAYING,
		PAUSED,
		INLEVELSELECT,
		INFINISHMENU,
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
	void loadMap(int level = 1);
	static float mScore;
	static int mGold;	
	static int mLevelInt;
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

	void menuInput(sf::Event &event);

	void pause();
	void enterStore();
	void enterSettings();
	void enterMap();


	void toneDownMusic(sf::Music* m0, sf::Music* m1); 

	void getEnum(int level = 1);
	/*Variabler*/
	typedef std::vector<Entity*> EntityVector;

	bool isPlaying = false; /*Kollar om man spelar musik*/
	bool menuIsPlaying = false;
	EntityVector entityVector;
	Player *mPlayer;
	Level* mLevel;
	Hud* mHud;
	SelectLevelMenu *mSelectLevelM;
	sf::Clock deltaTimer;
	
};
