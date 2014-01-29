#pragma once

class BaseLevel {
public:
	virtual float enemySpawnTimeMin() = 0;
	virtual float enemySpawnTimeMax() = 0;
	virtual float specialEnemySpawnTimeMin() = 0;
	virtual float specialEnemySpawnTimeMax() = 0;
	virtual float scoreRequirement() = 0;	
};