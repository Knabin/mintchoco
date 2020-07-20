#pragma once
#include "gameNode.h"
#include "cheerleader.h"
#include "schoolboy.h"
#include <vector>

class enemyManager:public gameNode
{
private:
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;
private:

	vEnemy	_vCheerLeader;
	viEnemy _viCheerLeader;

	vEnemy _vSchoolBoy;
	viEnemy _viSchoolBoy;

	image* _enemyImg;


public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setEnemyCheerMove();
	void setEnemySchoolBoyMove();


	vector<enemy*> getVCheerLeader() { return _vCheerLeader; }
	vector<enemy*>::iterator getVICheerleader() { return _viCheerLeader; }

	vector<enemy*> getVShoolBoy() { return _vSchoolBoy; }
	vector<enemy*>::iterator getVISchoolBoy() { return _viSchoolBoy; }

	void setPlayerPos(float x, float y);
};

