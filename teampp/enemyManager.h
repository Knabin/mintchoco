#pragma once
#include "gameNode.h"
#include "enemy.h"

class enemyManager:public gameNode
{
private:
	enemy* _enemy;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

