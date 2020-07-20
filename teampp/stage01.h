#pragma once
#include "gameNode.h"

struct tagStage1
{
	image* _StageImage;
	RECT _rc;
	float _x, _y;

	image* _pixelCollision;
};
class stage01 : public gameNode
{
private:

	tagStage1 _Stage1PixelBackGround;   //1스테이지 픽셀 배경 화면
	tagStage1 _Stage1BackGround;		//1스테이지 배경 화면
	tagStage1 _Stage1RightDoor;			//1스테이지 RightDoor


public:

	stage01();
	~stage01();

	HRESULT init();
	void release();
	void update();
	void render();

	image* getPixel() { return _Stage1PixelBackGround._pixelCollision; }

	inline RECT getRect() { return _Stage1RightDoor._rc; }	//1스테이지 Door 접근자
};
