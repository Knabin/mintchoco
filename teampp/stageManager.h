#pragma once
#include "gameNode.h"
#include "stage01.h"
#include "stage02.h"
#include "stage03.h"
#include "stage04.h"
#include "bossStage.h"


enum NowStage  //���� �������� ���� ����
{
	S1 = 0,		//��������1
	S2,			//��������2
	S3,			//��������3
	S4,			//��������4
	BS			//���� ��������
};

struct tagMiniMap
{
	image* _MiniMapImage;
	RECT _rc;
	float _x, _y;
};

class stageManager : public gameNode
{
private:

	stage01* _Stage1;
	stage02* _Stage2;
	stage03* _Stage3;
	stage04* _Stage4;
	bossStage* _BossStage;

	image* _currentPixelCollision;  //�ȼ��̹���

	//���� �������� ���� ����
	NowStage _NowStage;

	//playground���� �����ϱ� ���� �������� ���� bool��
	bool _NowStage1;
	bool _NowStage2;
	bool _NowStage3;
	bool _NowStage4;
	bool _NowBossStage;

	//���� ���������� npc�� ������ ���� vector
	vector<class npc*> _vNpcs;

	// ���������� ���� �ð����� enemy�� spawn�ϱ� ���� int ��
	int _spawnCount;

	class enemyManager* _em;

public:

	stageManager();
	~stageManager();

	HRESULT init();
	void release();
	void update();
	void render();


	//���� ���������� ����ΰ�? swtich��
	void NowStage();
	int getNowStage() { return _NowStage; }


	//���� ���������� �����Դϴ�.
	void Stage1Move();
	void Stage2Move();
	void Stage3Move();
	void Stage4Move();
	void BossStageMove();

	//stagedoor �浹 �� �̹����� �ٲ�ϴ�.
	void Stage1_Stage2_Ok();
	void Stage2_Stage3_Ok();
	void Stage2_Stage1_Ok();
	void Stage3_Stage4_Ok();
	void Stage3_Stage2_Ok();
	void Stage4_BossStage_Ok();
	void Stage4_Stage3_Ok();


	//�������� ���� bool�� ������
	bool getNowstage1() { return _NowStage1; }
	bool getNowstage2() { return _NowStage2; }
	bool getNowstage3() { return _NowStage3; }
	bool getNowstage4() { return _NowStage4; }
	bool getNowbossStage() { return _NowBossStage; }


	//�������� �̵� �� ������
	stage01* getVStage1() { return _Stage1; }
	stage02* getVStage2() { return _Stage2; }
	stage03* getVStage3() { return _Stage3; }
	stage04* getVStage4() { return _Stage4; }

	image* getPixelImage() { return _currentPixelCollision; } //�ȼ��̹��� ��

	void setEnemyManagerMemoryAddressLink(class enemyManager* em) { _em = em; }

};

