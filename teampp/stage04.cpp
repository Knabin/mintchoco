#include "stdafx.h"
#include "stage04.h"
#include "npc.h"

stage04::stage04()
{
}

stage04::~stage04()
{
}

HRESULT stage04::init()
{
	//스테이지 4 오른쪽 door 이미지 변경 선언

	_Stage4RightDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Stage4", "images/stage/UI_UnLocked_Door11.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage4RightDoorOpen._x = WINSIZEX / 2 + 1200;
	_Stage4RightDoorOpen._y = WINSIZEY / 2 + 200;

	_Stage4RightDoorOpen._rc.setCenterPos(_Stage4RightDoorOpen._x, _Stage4RightDoorOpen._y);

	//==================================================================================================================================================//


	//스테이지 4 왼쪽 door  이미지 변경 선언

	_Stage4LeftDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Stage4", "images/stage/UI_UnLocked_Door11.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage4LeftDoorOpen._x = WINSIZEX / 2 - 390;
	_Stage4LeftDoorOpen._y = WINSIZEY / 2 + 200;

	_Stage4LeftDoorOpen._rc.setCenterPos(_Stage4LeftDoorOpen._x, _Stage4LeftDoorOpen._y);

	//==================================================================================================================================================//

	//스테이지 4 픽셀 배경 선언

	_Stage4PixelBackGround._pixelCollision = IMAGEMANAGER->addImage("stage4_pixel", "images/stage/stage04_pixel.bmp", 2112, 864, false, NULL);

	//==================================================================================================================================================//

	//스테이지 4 배경 선언

	IMAGEMANAGER->addImage("Test_Stage4", "images/stage/stage04.bmp", 2112, 864, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

	//스테이지 4 RightDoor 선언

	_Stage4RightDoor._StageImage = IMAGEMANAGER->addImage("Door2_Stage4", "images/stage/UI_UnLocked_Door22.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage4RightDoor._x = WINSIZEX / 2 + 1200;
	_Stage4RightDoor._y = WINSIZEY / 2 + 200;

	_Stage4RightDoor._rc.setCenterPos(_Stage4RightDoor._x, _Stage4RightDoor._y);

	//==================================================================================================================================================//

	//스테이지 4 LeftDoor 선언

	_Stage4LeftDoor._StageImage = IMAGEMANAGER->addImage("Door2_Stage4", "images/stage/UI_UnLocked_Door22.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage4LeftDoor._x = WINSIZEX / 2 - 390;
	_Stage4LeftDoor._y = WINSIZEY / 2 + 200;

	_Stage4LeftDoor._rc.setCenterPos(_Stage4LeftDoor._x, _Stage4LeftDoor._y);


	//==================================================================================================================================================//

	// npc 추가
	npc* n1 = new npc;
	n1->init(1480, 370, 0, false);
	_vNpcs.push_back(n1);

	npc* n2 = new npc;
	n2->init(1530, 415, 1, true);
	_vNpcs.push_back(n2);

	npc* n3 = new npc;
	n3->init(2000, 650, 2, true);
	_vNpcs.push_back(n3);



	return S_OK;
}

void stage04::release()
{
}

void stage04::update()
{
}

void stage04::render()
{
	IMAGEMANAGER->findImage("Test_Stage4")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("Door2_Stage4")->render(getMemDC(), _Stage4RightDoor._x + 7, _Stage4RightDoor._y - 173);

	IMAGEMANAGER->findImage("Door2_Stage4")->render(getMemDC(), _Stage4LeftDoor._x - 37, _Stage4LeftDoor._y - 173);
}

void stage04::Stage4RightDoorOpenDraw()
{
	IMAGEMANAGER->findImage("Door_Stage4")->render(getMemDC(), _Stage4RightDoor._x + 7, _Stage4RightDoor._y - 173);
}

void stage04::Stage4LeftDoorOpenDraw()
{
	IMAGEMANAGER->findImage("Door_Stage4")->render(getMemDC(), _Stage4LeftDoor._x - 37, _Stage4LeftDoor._y - 173);
}
