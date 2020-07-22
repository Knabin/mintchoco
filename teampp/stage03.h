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
	tagStage3 _Stage3RightDoor;			//2스테이지 RightDoor
	tagStage3 _Stage3LeftDoorOpen;		//3스테이지 LeftDoor 이미지 변경
	tagStage3 _Stage3RightDoorOpen;		//2스테이지 RightDoor 이미지 변경

	vector<class npc*> _vNpcs;

public:

	stage03();
	~stage03();


	HRESULT init();
	void release();
	void update();
	void render();

	void Stage3LeftDoorOpenDraw();
	void Stage3RightDoorOpenDraw();

	image* getPixel() { return _Stage3PixelBackGround._pixelCollision; }
	vector<class npc*>& getNPCs() { return _vNpcs; }	// 스테이지3 npc 벡터 접근자

	inline MYRECT getRect() { return _Stage3LeftDoor._rc; }
	inline MYRECT getRect2() { return _Stage3RightDoor._rc; }

};
