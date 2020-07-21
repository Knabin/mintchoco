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

	tagStage1 _Stage1PixelBackGround;   //1스테이지 픽셀 배경 화면
	tagStage1 _Stage1BackGround;		//1스테이지 배경 화면
	tagStage1 _Stage1RightDoor;			//1스테이지 RightDoor
	tagStage1 _Stage1RightDoorOpen;		//1스테이지 RightDoor 이미지 변경

	vector<class npc*> _vNpcs;

public:

	stage01();
	~stage01();

	HRESULT init();
	void release();
	void update();
	void render();

	void Stage1RightDoorOpenDraw();		// 스테이지1 오른쪽door 접근 시 이미지 변경

	image* getPixel() { return _Stage1PixelBackGround._pixelCollision; }	//1스테이지 픽셀 배경 접근자
	vector<class npc*>& getNPCs() { return _vNpcs; }	// 스테이지1 npc 벡터 접근자

	inline MYRECT getRect() { return _Stage1RightDoor._rc; }	//1스테이지 Door 접근자
};
