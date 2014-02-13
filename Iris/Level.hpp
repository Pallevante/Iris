#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.hpp"
#include "ResourceManager.hpp"
#include "World.hpp"

class Level {
public:

	// Level(float spawnMini, float spawnMax, float requirement, float specialMin,
	// float specialMax, float obstMin, float obstMax, sf::Texture &texture);
	Level();
	~Level();
	/*Spawn:ar default enemies*/
	void spawnBasicEnemies(Entity::EntityVector &entityVector);
	/*Spawn:ar Skjutare*/
	void spawnSpecialEnemies(Entity::EntityVector &entityVector);

	void set(float spawnMini, float spawnMax, float requirment, 
		float obstSpawnMin,	float obstMax, float specialMin, 
		float specialMax, int maxSpecialSpawn, int maxSpawnEnemies, 
		int level);

	void spawn(Entity::EntityVector &entityVector);
	int getRandomNumber();
	float percentRequirement(float requirement);
	void drawBackground(sf::RenderWindow *window);
	void moveBackground(sf::RenderWindow *window);
	std::string getTheme(int level);
	sf::Sprite getBackground();
private:
	float mSpawnMin;
	float mSpawnMax;
	float mSpecialMin;
	float mSpecialMax;
	float mObstSpawnMin;
	float mObstMax;
	float mRequirment;
	// float mSpawn;
	float mRandomSpawn;
	/*maxx antal enemies som spawnas*/
	int mMaxSpawnEnemies;
	int mMaxSpecialSpawn;

	std::string chooseWhiteTexture;
	std::string chooseColoredTexture;

	sf::Clock mDefaultCl;
	sf::Clock mSpecialCl;

	sf::Sprite mSpriteWhite;
	sf::Sprite mSpriteColor;
	//sf::Texture mTexture;
	sf::FloatRect mBackgroundRect;
};