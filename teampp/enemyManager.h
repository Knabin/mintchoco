#pragma once
#include "gameNode.h"
#include "cheerleader.h"
#include "schoolboy.h"
#include "schoolgirl.h"
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

	vEnemy _vSchoolGirl;
	viEnemy _viSchoolGirl;

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
	void setEnemySchoolGirlMove();

	void removeCheerLeader(int arrNum);
	void removeSchoolBoy(int arrNum);
	void removeSchoolGilr(int arrNum);


	vector<enemy*> getVCheerLeader() { return _vCheerLeader; }
	vector<enemy*>::iterator getVICheerleader() { return _viCheerLeader; }

	vector<enemy*> getVSchoolBoy() { return _vSchoolBoy; }
	vector<enemy*>::iterator getVISchoolBoy() { return _viSchoolBoy; }

	vector<enemy*> getVSchoolGirl() { return _vSchoolGirl; }
	vector<enemy*>::iterator getVISchoolGirl() { return _viSchoolGirl; }

	void setPlayerPos(float x, float y);
};

