#pragma once

class BaseLevel {
public:
	virtual float enemySpawnTimeMin() = 0;
	virtual float enemySpawnTimeMax() = 0;
	virtual float numbOfEmnemies() = 0;
	virtual float percentRequirement() = 0;
	virtual float specialEnemySpawnTimeMin() = 0;
	virtual float specialEnemySpawnTimeMax() = 0;
	virtual float numbOfSpecialEnemies() = 0;
	virtual float obstacleSpawnTimeMin() = 0;
	virtual float obstacleSpawnTimeMax() = 0;
	virtual float scoreRequirement() = 0;	
};