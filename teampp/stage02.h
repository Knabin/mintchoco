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

	tagStage2 _Stage2PixelBackGround;   //2스테이지 픽셀 배경 화면
	tagStage2 _Stage2BackGround;		//2스테이지 배경 화면
	tagStage2 _Stage2RightDoor;			//2스테이지 RightDoor
	tagStage2 _Stage2LeftDoor;			//2스테이지 LeftDoor


public:

	stage02();
	~stage02();

	HRESULT init();
	void release();
	void update();
	void render();

	image* getPixel() { return _Stage2PixelBackGround._pixelCollision; }

	inline RECT getRect() { return _Stage2RightDoor._rc; }			//2스테이지 RightDoor Rect 접근자
	inline RECT getRect2() { return _Stage2LeftDoor._rc; }			//2스테이지 LeftDoor Rect 접근자

};
