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

	tagStage2 _Stage2PixelBackGround;   //2스테이지 픽셀 배경 화면
	tagStage2 _Stage2BackGround;		//2스테이지 배경 화면
	tagStage2 _Stage2RightDoor;			//2스테이지 RightDoor
	tagStage2 _Stage2LeftDoor;			//2스테이지 LeftDoor
	tagStage2 _Stage2RightDoorOpen;		//2스테이지 RightDoor 이미지 변경
	tagStage2 _Stage2LeftDoorOpen;		//2스테이지 LeftDoor 이미지 변경
	tagStage2 _Stage2RightDoorLock;		//2스테이지 RightDoor 잠긴 이미지
	tagStage2 _Stage2LeftDoorLock;		//2스테이지 LeftDoor 잠긴 이미지

	vector<class npc*> _vNpcs;

public:

	stage02();
	~stage02();

	HRESULT init();
	void release();
	void update();
	void render();

	void Stage2RightDoorOpenDraw();     // 스테이지2 오른쪽door 접근 시 이// 스테이지2 왼쪽door 접근 시 이미지 변경미지 변경
	void Stage2LeftDoorOpenDraw();		

	void Stage2RightDoorLockDraw();		// 스테이지2 오른쪽door 잠긴 이미지 변경
	void Stage2LeftDoorLockDraw();		// 스테이지2 왼쪽door 잠긴 이미지 변경

	image* getPixel() { return _Stage2PixelBackGround._pixelCollision; }
	vector<class npc*>& getNPCs() { return _vNpcs; }	// 스테이지2 npc 벡터 접근자

	inline MYRECT& getRect() { return _Stage2RightDoor._rc; }			//2스테이지 RightDoor Rect 접근자
	inline MYRECT& getRect2() { return _Stage2LeftDoor._rc; }			//2스테이지 LeftDoor Rect 접근자

};
