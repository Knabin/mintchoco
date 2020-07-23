#pragma once
#include "gameNode.h"

struct tagStage4
{
	image* _StageImage;
	MYRECT _rc;
	float _x, _y;

	image* _pixelCollision;

};
class stage04 : public gameNode
{
private:
		
	tagStage4 _Stage4PixelBackGround;
	tagStage4 _Stage4BackGround;
	tagStage4 _Stage4RightDoor;
	tagStage4 _Stage4LeftDoor;
	tagStage4 _Stage4RightDoorOpen;
	tagStage4 _Stage4LeftDoorOpen;

	vector<class npc*> _vNpcs;
	
	
public:

	stage04();
	~stage04();

	HRESULT init();
	void release();
	void update();
	void render();

	void Stage4RightDoorOpenDraw();
	void Stage4LeftDoorOpenDraw();

	image* getPixel() { return _Stage4PixelBackGround._pixelCollision; }
	vector<class npc*>& getNPCs() { return _vNpcs; }	// 스테이지4 npc 벡터 접근자

	inline MYRECT getRect() { return _Stage4RightDoor._rc; }
	inline MYRECT getRect2() { return _Stage4LeftDoor._rc; }



};

