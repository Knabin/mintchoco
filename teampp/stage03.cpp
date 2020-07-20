#include "stdafx.h"
#include "stage03.h"

stage03::stage03()
{
}

stage03::~stage03()
{
}

HRESULT stage03::init()
{
	// 스테이지 3 픽셀 배경 선언

	_Stage3PixelBackGround._pixelCollision = IMAGEMANAGER->addImage("stage3_pixel", "images/stage/stage03_pixel.bmp", 2769, 1280, false, NULL);

	//==================================================================================================================================================//

	//스테이지 3 배경 선언

	IMAGEMANAGER->addImage("Test_Stage3", "images/stage/stage03.bmp", 2769, 1280, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

	//스테이지 3 LeftDoor 선언

	_Stage3LeftDoor._StageImage = IMAGEMANAGER->addImage("Door_Stage3", "images/stage/UI_UnLocked_Door.bmp", 78, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Door2_Stage3", "images/stage/UI_UnLocked_Door2.bmp", 78, 114, true, RGB(255, 0, 255));

	_Stage3LeftDoor._x = 100;
	_Stage3LeftDoor._y = WINSIZEY / 2;

	_Stage3LeftDoor._rc = RectMakeCenter(_Stage3LeftDoor._x, _Stage3LeftDoor._y, _Stage3LeftDoor._StageImage->getWidth(), _Stage3LeftDoor._StageImage->getHeight());

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

	IMAGEMANAGER->findImage("Door_Stage3")->render(getMemDC(), _Stage3LeftDoor._x - 39, _Stage3LeftDoor._y - 57);
}
