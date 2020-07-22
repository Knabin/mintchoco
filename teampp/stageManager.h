#pragma once
#include "gameNode.h"
#include "stage01.h"
#include "stage02.h"
#include "stage03.h"


enum NowStage  //���� �������� ���� ����
{
	S1 = 0,		//��������1
	S2,			//��������2
	S3			//��������3
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

	image* _currentPixelCollision;  //�ȼ��̹���

	//���� �������� ���� ����
	NowStage _NowStage;

	//playground���� �����ϱ� ���� �������� ���� bool��
	bool _NowStage1;
	bool _NowStage2;
	bool _NowStage3;

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


	//���� ���������� �����Դϴ�.
	void Stage1Move();
	void Stage2Move();
	void Stage3Move();

	//stagedoor �浹 �� �̹����� �ٲ�ϴ�.
	void Stage1_Stage2_Ok();
	void Stage2_Stage3_Ok();
	void Stage2_Stage1_Ok();
	void Stage3_Stage2_Ok();


	//�������� ���� bool�� ������
	bool getNowstage1() { return _NowStage1; }
	bool getNowstage2() { return _NowStage2; }
	bool getNowstage3() { return _NowStage3; }

	//�������� ���� enum(int) ������
	int getNowStage() { return _NowStage; }


	//�������� �̵� �� ������
	stage01* getVStage1() { return _Stage1; }
	stage02* getVStage2() { return _Stage2; }
	stage03* getVStage3() { return _Stage3; }

	image* getPixelImage() { return _currentPixelCollision; } //�ȼ��̹��� ��

	vector<class npc*>& getNpcVector() { return _vNpcs; }

	void setEnemyManagerMemoryAddressLink(class enemyManager* em) { _em = em; }

};

