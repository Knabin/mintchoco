#pragma once
#include "gameNode.h"
#include "cheerleader.h"
#include "schoolboy.h"
#include "schoolgirl.h"
#include "boss.h"			// ��õ ���� �߰� 
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

	// ===== ���� �߰� ===== //
	vEnemy _vEnemies;		// ���� ���������� �ִ� enemy��
	viEnemy _viEnemies;

	mSpawnPoint _mPoint;	// �� ������������ spawn�� ������ ������ map

	class stageManager* _sm;
	// ==================== //

	image* _enemyImg;

	// === ��õ �߰� === 
	boss* _boss;
	//=================


public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	// === ��õ �߰� === 
	void setBossMove();
	//=================


	// �������� ��ȯ�� ��, �ش� ������������ ó������ ���� ��� �ϴ� enemy�� �����ϴ� �Լ�
	void setEnemiesVector(int stageNum);
	// enemy�� ���� ���������� �°� spawn�� �ִ� �Լ�, stageManager���� count üũ �� ȣ����
	void spawnEnemy(int stageNum);
	// enemy�� ���� ��ȯ�ϴ� �Լ� (enemyType(0: ġ���, 1: ���л�, 2: ���л�), ���� ��ǥX, ���� ��ǥY)
	enemy* createEnemy(int enemyType, float x, float y);
	// enemy�� ���� ��ȯ�ϴ� �Լ� (enemyType(0: ġ���, 1: ���л�, 2: ���л�), ���� ��ǥX, ���� ��ǥY, �������� ��ȣ)
	enemy* createEnemy(int enemyType, float x, float y, int stageNum);

	// ���� ���������� �ִ� enemy���� ��ȯ�� �ִ� �Լ�
	vector<enemy*>& getEnemiesVector() { return _vEnemies; }
	void removeEnemy(int index);
	void removeEnemies();

	void setPlayerPos(float x, float y);

	void setStageManagerMemoryAddressLink(class stageManager* sm) { _sm = sm; }
};

