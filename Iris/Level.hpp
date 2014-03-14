#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.hpp"
#include "Cloud.hpp"
#include "Gold.hpp"
#include "ResourceManager.hpp"
#include "World.hpp"
#include <thread>
#include <future>

class Level {
public:	
	Level();
	~Level();
	/*Spawn:ar default enemies*/
	void spawnBasicEnemies(Entity::EntityVector &entityVector);
	/*Spawn:ar Skjutare*/
	void spawnSpecialEnemies(Entity::EntityVector &entityVector);
	
	/*Spawn:ar Guld*/
	void spawnGold(Entity::EntityVector &entityVector);
	void set(float basicEnemySpawnTime,int maxBasicEnemySpawn, 
		float specialEnemySpawnTime, int maxSpecialEnemySpawn,
		float requirment, float obstSpawnTime, int maxObstSpawn,int level
		, int levelTime);

	float opacity;
	void opacityChange(float score);
	void clearVectors();
	void spawn(Entity::EntityVector &entityVector);
	void restart();
	float getRandomNumber(float maxNumber = 10);

	float percentRequirement();
	void drawBackground(sf::RenderWindow &window, float dt);

	std::string getTheme(int level);
	sf::Sprite getBackground();
	const float getOpacity();
private:
	float mBasicEnemySpawnTime;
	float mSpecialEnemySpawnTime;
	float mObstSpawnTime;
	float mRequirment;
	
	/*maxx antal enemies som spawnas*/
	int mMaxBasicEnemySpawn;
	int mMaxSpecialEnemySpawn;
	int mMaxObstSpawn;
	int mLevelTime;
	void drawLevel(sf::RenderWindow& window, ResourceManager::SpriteVector& bgVector, sf::Color& color, float dt);
	void moveLevel(sf::RenderWindow& window, ResourceManager::SpriteVector& bgVector, sf::Color& color);


	std::string chooseWhiteTexture;
	std::string chooseColoredTexture;

	sf::Clock mDefaultCl;
	sf::Clock mSpecialCl;

	sf::Sprite mSpriteWhite;
	sf::Sprite mSpriteColor;
	//sf::Texture mTexture;
	sf::FloatRect mBackgroundRect;

	sf::Image baseImage;
	float backgroundSpeed;

};