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

class stageManager2 : public gameNode
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


public:

	stageManager2();
	~stageManager2();

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


	//�������� ���� bool�� ������
	bool getNowstage1() { return _NowStage1; }
	bool getNowstage2() { return _NowStage2; }
	bool getNowstage3() { return _NowStage3; }


	//�������� �̵� �� ������
	stage01* getVStage1() { return _Stage1; }
	stage02* getVStage2() { return _Stage2; }
	stage03* getVStage3() { return _Stage3; }

	image* getPixelImage() { return _currentPixelCollision; } //�ȼ��̹��� ��


};

