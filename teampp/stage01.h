#pragma once
#include "gameNode.h"

struct tagStage1
{
	image* _StageImage;
	MYRECT _rc;
	float _x, _y;

	image* _pixelCollision;
};
class stage01 : public gameNode
{
private:

	tagStage1 _Stage1PixelBackGround;   //1�������� �ȼ� ��� ȭ��
	tagStage1 _Stage1BackGround;		//1�������� ��� ȭ��
	tagStage1 _Stage1RightDoor;			//1�������� RightDoor
	tagStage1 _Stage1RightDoorOpen;		//1�������� RightDoor �̹��� ����


public:

	stage01();
	~stage01();

	HRESULT init();
	void release();
	void update();
	void render();

	void Stage1RightDoorOpenDraw();		// ��������1 ������door ���� �� �̹��� ����

	image* getPixel() { return _Stage1PixelBackGround._pixelCollision; }	//1�������� �ȼ� ��� ������

	inline MYRECT getRect() { return _Stage1RightDoor._rc; }	//1�������� Door ������
};