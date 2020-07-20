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

	tagStage3 _Stage3PixelBackGround;   //3스테이지 픽셀 배경 화면
	tagStage3 _Stage3BackGround;		//3스테이지 배경 화면
	tagStage3 _Stage3LeftDoor;			//3스테이지 LeftDoor

public:

	stage03();
	~stage03();


	HRESULT init();
	void release();
	void update();
	void render();

	image* getPixel() { return _Stage3PixelBackGround._pixelCollision; }

	inline MYRECT getRect() { return _Stage3LeftDoor._rc; }

};
