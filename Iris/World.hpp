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
		LOAD,
		PAUSED,
		INLEVELSELECT,
		INFINISHMENU,
		INFAILEDFINISHMENU,
		INSHOP,
		OUTRO,
		RESTARTING,
		INTRO,
		EXIT
	};

	static GameState currentState;

	World();
	~World();
	void run();
	/*Måste ladda in banan innan*/
	void startGame();
	
	void loadMap(int level = 1); //Default som USA.
	static float mScore;
	static int mGold;	
	static int mLevelInt;
	void renderHUD();
	void restart();
private:
	/*Spelrelaterade funktioner*/
	void spawnEnemies();
	void renderImages();
	void tick(float dt);
	bool isColliding(Entity *entity1, Entity *entity2);
	void detectCollisions();
	void killDeadEntities();
	void resetVector();
	
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
	bool shopIsPlaying = false;
	EntityVector entityVector;
	Player *mPlayer;
	Level* mLevel;
	Hud* mHud;
	SelectLevelMenu *mSelectLevelM;
	sf::Clock deltaTimer;
	sf::Font goldFont;
};
