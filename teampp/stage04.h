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
	tagStage4 _Stage4RightDoorLock;
	tagStage4 _Stage4LeftDoorLock;

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

	void Stage4RightDoorLockDraw();
	void Stage4LeftDoorLockDraw();		


	image* getPixel() { return _Stage4PixelBackGround._pixelCollision; }
	vector<class npc*>& getNPCs() { return _vNpcs; }	// ��������4 npc ���� ������

	inline MYRECT& getRect() { return _Stage4RightDoor._rc; }
	inline MYRECT& getRect2() { return _Stage4LeftDoor._rc; }



};

