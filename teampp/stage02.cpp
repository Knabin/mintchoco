#include "stdafx.h"
#include "stage02.h"
#include "npc.h"

stage02::stage02()
{
}

stage02::~stage02()
{
}

HRESULT stage02::init()
{
	// 스테이지 2 오른쪽 door 이미지 변경 선언

	_Stage2RightDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Stage2", "images/stage/UI_UnLocked_Door11.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage2RightDoorOpen._x = WINSIZEX - 300;
	_Stage2RightDoorOpen._y = WINSIZEY / 2 - 30;

	_Stage2RightDoorOpen._rc.setCenterPos(_Stage2RightDoorOpen._x, _Stage2RightDoorOpen._y);

	//==================================================================================================================================================//

	// 스테이지 2 왼쪽 door 이미지 변경 선언

	_Stage2LeftDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Stage2", "images/stage/UI_UnLocked_Door11.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage2LeftDoorOpen._x = 245;
	_Stage2LeftDoorOpen._y = WINSIZEY / 2 + 225;

	_Stage2LeftDoorOpen._rc.setCenterPos(_Stage2LeftDoorOpen._x, _Stage2LeftDoorOpen._y);

	//==================================================================================================================================================//

	// 스테이지 2 픽셀 배경 선언

	_Stage2PixelBackGround._pixelCollision = IMAGEMANAGER->addImage("stage2_pixel", "images/stage/stage02_pixel.bmp", 2400, 864, false, NULL);

	//==================================================================================================================================================//

	//스테이지 2 배경 선언

	IMAGEMANAGER->addImage("Test_Stage2", "images/stage/stage02.bmp", 2400, 864, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

	//스테이지 2 RightDoor 선언

	_Stage2RightDoor._StageImage = IMAGEMANAGER->addImage("Door2_Stage2", "images/stage/UI_UnLocked_Door22.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage2RightDoor._x = WINSIZEX - 300;
	_Stage2RightDoor._y = WINSIZEY / 2 - 30;

	_Stage2RightDoor._rc.setCenterPos(_Stage2RightDoor._x, _Stage2RightDoor._y);

	//==================================================================================================================================================//

	//스테이지 2 LeftDoor 선언

	_Stage2LeftDoor._StageImage = IMAGEMANAGER->addImage("Door2_Stage2", "images/stage/UI_UnLocked_Door2.bmp", 78, 114, true, RGB(255, 0, 255));

	_Stage2LeftDoor._x = 245;
	_Stage2LeftDoor._y = WINSIZEY / 2 + 225;

	_Stage2LeftDoor._rc.setCenterPos(_Stage2LeftDoor._x, _Stage2LeftDoor._y);


	//==================================================================================================================================================//
	
	// npc 추가

	npc* n1 = new npc;
	n1->init(1480, 370, 0, false);
	_vNpcs.push_back(n1);

	npc* n2 = new npc;
	n2->init(600, 390, 0, true);
	_vNpcs.push_back(n2);

	npc* n3 = new npc;
	n3->init(1530, 415, 1, true);
	_vNpcs.push_back(n3);

	npc* n4 = new npc;
	n4->init(2000, 650, 2, true);
	_vNpcs.push_back(n4);


	return S_OK;
}

void stage02::release()
{
	for (int i = 0; i < _vNpcs.size(); ++i)
	{
		_vNpcs[i]->release();
		SAFE_DELETE(_vNpcs[i]);
	}
	_vNpcs.clear();
}

void stage02::update()
{
}

void stage02::render()
{
	IMAGEMANAGER->findImage("Test_Stage2")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("Door2_Stage2")->render(getMemDC(), _Stage2RightDoor._x, _Stage2RightDoor._y - 143);

	IMAGEMANAGER->findImage("Door2_Stage2")->render(getMemDC(), _Stage2LeftDoor._x - 37, _Stage2LeftDoor._y - 173);
}

void stage02::Stage2RightDoorOpenDraw()   // 스테이지 2 오른쪽 door 접근 시 이미지 변경
{
	IMAGEMANAGER->findImage("Door_Stage2")->render(getMemDC(), _Stage2RightDoor._x, _Stage2RightDoor._y - 143);
}

void stage02::Stage2LeftDoorOpenDraw()   // 스테이지 2 왼쪽 door 접근 시 이미지 변경
{
	IMAGEMANAGER->findImage("Door_Stage2")->render(getMemDC(), _Stage2LeftDoor._x - 37, _Stage2LeftDoor._y - 173);
}
