#pragma once
#include "gameNode.h"
#include "cheerleader.h"
#include <vector>

class enemyManager:public gameNode
{
private:
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;
private:

	vEnemy	_vCheerLeader;
	viEnemy _viCheerLeader;

	image* _enemyImg;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setEnemyCheer();

	vector<enemy*> getVCheerLeader() { return _vCheerLeader; }
	vector<enemy*>::iterator getVICheerleader() { return _viCheerLeader; }
};

