#pragma once
#include <SFML\Graphics.hpp>
#include "World.hpp"
#include "Enemies.hpp"


class Level {
public:

<<<<<<< HEAD
// Level(float spawnMini, float spawnMax, float requirement, float specialMin,
// float specialMax, float obstMin, float obstMax, sf::Texture &texture);
	Level();
	~Level();
/*Spawn:ar default enemies*/
	void spawnBasicEnemies(Entity::EntityVector &entityVector);
/*Spawn:ar Skjutare*/
	void spawnSpecialEnemies(Entity::EntityVector &entityVector);
	void set(float spawnMini, float spawnMax, float requirment, float obstSpawnMin,
	float obstMax, int maxSpawnEnemies, float specialMin,
	float specialMax, int maxSpecialSpawn);
	void spawn(Entity::EntityVector &entityVector);
	void drawBackground(sf::RenderWindow *window);
	int getRandomNumber();
	float percentRequirement();
	void setBackground(sf::Texture &texture);
	void moveBackground(sf::RenderWindow *window);

	sf::Sprite getBackground();
private:
=======
//	Level(float spawnMini, float spawnMax, float requirement, float specialMin,
//		float specialMax, float obstMin, float obstMax, sf::Texture &texture);
	Level();
	~Level();
	/*Spawn:ar default enemies*/
	void spawnBasicEnemies(Entity::EntityVector &entityVector);
	/*Spawn:ar Skjutare*/
	void spawnSpecialEnemies(Entity::EntityVector &entityVector);
	void set(float spawnMini, float spawnMax, float requirment, float obstSpawnMin, 
		float obstMax, float specialMin, 
		float specialMax, int maxSpecialSpawn, int maxSpawnEnemies, int level);
	void spawn(Entity::EntityVector &entityVector);
	int getRandomNumber();
	float percentRequirement(float requirement);
	void moveBackground(sf::RenderWindow *window);

	sf::Sprite getBackground();
	private:
>>>>>>> majal
	float mSpawnMin;
	float mSpawnMax;
	float mSpecialMin;
	float mSpecialMax;
	float mObstSpawnMin;
	float mObstMax;
	float mRequirment;
<<<<<<< HEAD
// float mSpawn;
=======
//	float mSpawn;
>>>>>>> majal
	float mRandomSpawn;
/*maxx antal enemies som spawnas*/
	int mMaxSpawnEnemies;
	int mMaxSpecialSpawn;

<<<<<<< HEAD
	sf::Clock mDefaultCl;
	sf::Clock mSpecialCl;

	sf::Sprite mSprite;
	sf::Texture mTexture;
	sf::View view;
=======
	std::string chooseWhiteTexture;
	std::string chooseColoredTexture;

	sf::Clock mDefaultCl;
	sf::Clock mSpecialCl;

	sf::Sprite mSpriteWhite;
	sf::Sprite mSpriteColor;
	//sf::Texture mTexture;
	sf::FloatRect mBackgroundRect;
>>>>>>> majal
};