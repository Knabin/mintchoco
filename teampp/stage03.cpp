#include "stdafx.h"
#include "stage03.h"
#include "npc.h"

stage03::stage03()
{
}

stage03::~stage03()
{
}

HRESULT stage03::init()
{

	// 스테이지 3 왼쪽 door 이미지 변경 선언

	_Stage3LeftDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Stage3", "images/stage/UI_UnLocked_Door11.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage3LeftDoorOpen._x = WINSIZEX;
	_Stage3LeftDoorOpen._y = WINSIZEY / 2 - 35;

	_Stage3LeftDoorOpen._rc.setCenterPos(_Stage3LeftDoorOpen._x, _Stage3LeftDoorOpen._y);

	//==================================================================================================================================================//

	// 스테이지 3 오른쪽  door 이미지 변경 선언

	_Stage3RightDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Stage3", "images/stage/UI_UnLocked_Door11.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage3RightDoorOpen._x = WINSIZEX + 850;
	_Stage3RightDoorOpen._y = WINSIZEY / 2 + 165;

	_Stage3RightDoorOpen._rc.setCenterPos(_Stage3RightDoorOpen._x, _Stage3RightDoorOpen._y);


	//==================================================================================================================================================//

	// 스테이지 3 픽셀 배경 선언

	_Stage3PixelBackGround._pixelCollision = IMAGEMANAGER->addImage("stage3_pixel", "images/stage/stage03_pixel.bmp", 2400, 865, false, NULL);


	//==================================================================================================================================================//

	//스테이지 3 배경 선언

	IMAGEMANAGER->addImage("Test_Stage3", "images/stage/stage03.bmp", 2400, 865, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

	//스테이지 3 LeftDoor 선언

	_Stage3LeftDoor._StageImage = IMAGEMANAGER->addImage("Door2_Stage3", "images/stage/UI_UnLocked_Door22.bmp", 52, 76, true, RGB(255, 0, 255));
	

	_Stage3LeftDoor._x = WINSIZEX;
	_Stage3LeftDoor._y = WINSIZEY / 2 - 35;

	_Stage3LeftDoor._rc.setCenterPos(_Stage3LeftDoor._x, _Stage3LeftDoor._y);

	//==================================================================================================================================================//

	_Stage3RightDoor._StageImage = IMAGEMANAGER->addImage("Door2_Stage3", "images/stage/UI_UnLocked_Door22.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage3RightDoor._x = WINSIZEX + 850;
	_Stage3RightDoor._y = WINSIZEY / 2 + 165;

	_Stage3RightDoor._rc.setCenterPos(_Stage3RightDoor._x, _Stage3RightDoor._y);


	//==================================================================================================================================================//
	return S_OK;

}

void stage03::release()
{
}

void stage03::update()
{
}

void stage03::render()
{
	IMAGEMANAGER->findImage("Test_Stage3")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("Door2_Stage3")->render(getMemDC(), _Stage3LeftDoor._x, _Stage3LeftDoor._y - 138);

	IMAGEMANAGER->findImage("Door2_Stage3")->render(getMemDC(), _Stage3RightDoor._x + 11, _Stage3RightDoor._y - 113);
}

void stage03::Stage3LeftDoorOpenDraw()
{
	IMAGEMANAGER->findImage("Door_Stage3")->render(getMemDC(), _Stage3LeftDoor._x, _Stage3LeftDoor._y - 138);
}

void stage03::Stage3RightDoorOpenDraw()
{
	IMAGEMANAGER->findImage("Door_Stage3")->render(getMemDC(), _Stage3RightDoor._x + 11, _Stage3RightDoor._y - 113);
}
