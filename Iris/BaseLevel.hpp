#pragma once

class BaseLevel {
public:
	virtual float enemySpawnTimeMin() = 0;
	virtual float enemySpawnTimeMax() = 0;
	virtual float percentRequirement() = 0;
	virtual float specialEnemySpawnTimeMin() = 0;
	virtual float specialEnemySpawnTimeMax() = 0;
	virtual float obstacleSpawnTimeMin() = 0;
	virtual float ostacleSpawnTimeMax() = 0;
	virtual float scoreRequirement() = 0;	
};