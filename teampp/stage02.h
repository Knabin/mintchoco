#pragma once
#include "gameNode.h"

struct tagStage2
{
	image* _StageImage;
	RECT _rc;
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


public:

	stage02();
	~stage02();

	HRESULT init();
	void release();
	void update();
	void render();

	image* getPixel() { return _Stage2PixelBackGround._pixelCollision; }

	inline RECT getRect() { return _Stage2RightDoor._rc; }			//2�������� RightDoor Rect ������
	inline RECT getRect2() { return _Stage2LeftDoor._rc; }			//2�������� LeftDoor Rect ������

};
