#pragma once
#include "gameNode.h"

struct tagStage3
{
	image* _StageImage;
	MYRECT _rc;
	float _x, _y;

	image* _pixelCollision;

};
class stage03 : public gameNode
{
private:

	tagStage3 _Stage3PixelBackGround;   //3�������� �ȼ� ��� ȭ��
	tagStage3 _Stage3BackGround;		//3�������� ��� ȭ��
	tagStage3 _Stage3LeftDoor;			//3�������� LeftDoor
	tagStage3 _Stage3RightDoor;			//2�������� RightDoor
	tagStage3 _Stage3LeftDoorOpen;		//3�������� LeftDoor �̹��� ����
	tagStage3 _Stage3RightDoorOpen;		//3�������� RightDoor �̹��� ����
	tagStage3 _Stage3LeftDoorLock;		//3�������� LeftDoor ��� �̹���
	tagStage3 _Stage3RightDoorLock;		//3�������� RightDoor ��� �̹���


	vector<class npc*> _vNpcs;

public:

	stage03();
	~stage03();


	HRESULT init();
	void release();
	void update();
	void render();

	void Stage3LeftDoorOpenDraw();		// ��������3 ����door ���� �� �̹��� ����
	void Stage3RightDoorOpenDraw();		// ��������3 ������door ���� �� �̹��� ����

	void Stage3LeftDoorLockDraw();		// ��������3 ����door ��� �̹��� ����
	void Stage3RightDoorLockDraw();		// ��������3 ������door ��� �̹��� ����

	image* getPixel() { return _Stage3PixelBackGround._pixelCollision; }
	vector<class npc*>& getNPCs() { return _vNpcs; }	// ��������3 npc ���� ������

	inline MYRECT& getRect() { return _Stage3LeftDoor._rc; }
	inline MYRECT& getRect2() { return _Stage3RightDoor._rc; }

};
