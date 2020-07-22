#pragma once
#include "gameNode.h"
#include "cheerleader.h"
#include "schoolboy.h"
#include "schoolgirl.h"
#include <vector>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

class enemyManager:public gameNode
{
private:
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;

	typedef vector<MYPOINT>				vPoint;
	typedef vector<MYPOINT>::iterator	viPoint;

	typedef map<int, vPoint>			mSpawnPoint;
	typedef map<int, vPoint>::iterator miSpawnPoint;
private:

	vEnemy	_vCheerLeader;
	viEnemy _viCheerLeader;

	vEnemy _vSchoolBoy;
	viEnemy _viSchoolBoy;

	vEnemy _vSchoolGirl;
	viEnemy _viSchoolGirl;

	// ===== ³ªºó Ãß°¡ ===== //
	vEnemy _vEnemies;
	viEnemy _viEnemies;

	mSpawnPoint _mPoint;


	class stageManager* _sm;
	// ==================== //

	image* _enemyImg;

	MYRECT _enemyRc;



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

	void setEnemiesVector(int stageNum);
	void spawnEnemy(int stageNum);
	enemy* createEnemy(int enemyType, float x, float y);

	void removeCheerLeader(int arrNum);
	void removeSchoolBoy(int arrNum);
	void removeSchoolGilr(int arrNum);


	vector<enemy*> getVCheerLeader() { return _vCheerLeader; }
	vector<enemy*>::iterator getVICheerleader() { return _viCheerLeader; }

	vector<enemy*> getVSchoolBoy() { return _vSchoolBoy; }
	vector<enemy*>::iterator getVISchoolBoy() { return _viSchoolBoy; }

	vector<enemy*> getVSchoolGirl() { return _vSchoolGirl; }
	vector<enemy*>::iterator getVISchoolGirl() { return _viSchoolGirl; }

	MYRECT getEnemyRc() { return _enemyRc; }

	void setPlayerPos(float x, float y);

	void setStageManagerMemoryAddressLink(class stageManager* sm) { _sm = sm; }
};

