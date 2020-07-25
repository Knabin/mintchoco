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


public:

	stage02();
	~stage02();

	HRESULT init();
	void release();
	void update();
	void render();

	void Stage2RightDoorOpenDraw();    // ��������2 ������door ���� �� �̹��� ����
	void Stage2LeftDoorOpenDraw();		// ��������2 ����door ���� �� �̹��� ����

	image* getPixel() { return _Stage2PixelBackGround._pixelCollision; }

	inline MYRECT getRect() { return _Stage2RightDoor._rc; }			//2�������� RightDoor Rect ������
	inline MYRECT getRect2() { return _Stage2LeftDoor._rc; }			//2�������� LeftDoor Rect ������

};