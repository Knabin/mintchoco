#pragma once
#include "gameNode.h"

struct tagStage2
{
	image* _StageImage;
	MYRECT _rc;
	float _x, _y;

	image* _pixelCollision;
};
class stage02 : public gameNode
{
private:

	tagStage2 _Stage2PixelBackGround;   //2�������� �ȼ� ��� ȭ��
	tagStage2 _Stage2BackGround;		//2�������� ��� ȭ��
	tagStage2 _Stage2RightDoor;			//2�������� RightDoor
	tagStage2 _Stage2LeftDoor;			//2�������� LeftDoor
	tagStage2 _Stage2RightDoorOpen;		//2�������� RightDoor �̹��� ����
	tagStage2 _Stage2LeftDoorOpen;		//2�������� LeftDoor �̹��� ����
	tagStage2 _Stage2RightDoorLock;		//2�������� RightDoor ��� �̹���
	tagStage2 _Stage2LeftDoorLock;		//2�������� LeftDoor ��� �̹���

	vector<class npc*> _vNpcs;

public:

	stage02();
	~stage02();

	HRESULT init();
	void release();
	void update();
	void render();

	void Stage2RightDoorOpenDraw();     // ��������2 ������door ���� �� ��// ��������2 ����door ���� �� �̹��� ������� ����
	void Stage2LeftDoorOpenDraw();		

	void Stage2RightDoorLockDraw();		// ��������2 ������door ��� �̹��� ����
	void Stage2LeftDoorLockDraw();		// ��������2 ����door ��� �̹��� ����

	image* getPixel() { return _Stage2PixelBackGround._pixelCollision; }
	vector<class npc*>& getNPCs() { return _vNpcs; }	// ��������2 npc ���� ������

	inline MYRECT& getRect() { return _Stage2RightDoor._rc; }			//2�������� RightDoor Rect ������
	inline MYRECT& getRect2() { return _Stage2LeftDoor._rc; }			//2�������� LeftDoor Rect ������

};
