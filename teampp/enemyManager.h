#pragma once
#include "gameNode.h"
#include "cheerleader.h"
#include "schoolboy.h"
#include "schoolgirl.h"
#include "boss.h"			// 운천 보스 추가 
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

	// ===== 나빈 추가 ===== //
	vEnemy _vEnemies;		// 현재 스테이지에 있는 enemy들
	viEnemy _viEnemies;

	mSpawnPoint _mPoint;	// 각 스테이지마다 spawn될 지점을 저장한 map

	class stageManager* _sm;
	// ==================== //

	image* _enemyImg;

	// === 운천 추가 === 
	boss* _boss;
	//=================


public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	// === 운천 추가 === 
	void setBossMove();
	//=================


	// 스테이지 전환할 때, 해당 스테이지에서 처음부터 보여 줘야 하는 enemy들 설정하는 함수
	void setEnemiesVector(int stageNum);
	// enemy를 현재 스테이지에 맞게 spawn해 주는 함수, stageManager에서 count 체크 후 호출함
	void spawnEnemy(int stageNum);
	// enemy를 만들어서 반환하는 함수 (enemyType(0: 치어리더, 1: 남학생, 2: 여학생), 중점 좌표X, 중점 좌표Y)
	enemy* createEnemy(int enemyType, float x, float y);
	// enemy를 만들어서 반환하는 함수 (enemyType(0: 치어리더, 1: 남학생, 2: 여학생), 중점 좌표X, 중점 좌표Y, 스테이지 번호)
	enemy* createEnemy(int enemyType, float x, float y, int stageNum);

	// 현재 스테이지에 있는 enemy들을 반환해 주는 함수
	vector<enemy*>& getEnemiesVector() { return _vEnemies; }
	void removeEnemy(int index);

	void setPlayerPos(float x, float y);

	void setStageManagerMemoryAddressLink(class stageManager* sm) { _sm = sm; }
};

