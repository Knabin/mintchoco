#include "stdafx.h"
#include "stage01.h"

stage01::stage01()
{
}

stage01::~stage01()
{
}

HRESULT stage01::init()
{
	// 스테이지 1 픽셀 배경 선언

	_Stage1PixelBackGround._pixelCollision = IMAGEMANAGER->addImage("stage1_pixel", "images/stage/stage01_pixel.bmp", 2016, 672, false, NULL);

	//==================================================================================================================================================//

	//스테이지 1 배경 선언

	IMAGEMANAGER->addImage("Test_Stage1", "images/stage/stage01.bmp", 2016, 672, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

	//스테이지 1 RightDoor 선언

	_Stage1RightDoor._StageImage = IMAGEMANAGER->addImage("Door_Stage1", "images/stage/UI_UnLocked_Door.bmp", 78, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Door2_Stage1", "images/stage/UI_UnLocked_Door2.bmp", 78, 114, true, RGB(255, 0, 255));

	_Stage1RightDoor._x = WINSIZEX + 150;
	_Stage1RightDoor._y = WINSIZEY / 2 - 50;

	_Stage1RightDoor._rc.setCenterPos(_Stage1RightDoor._x, _Stage1RightDoor._y);

	return S_OK;
}

void stage01::release()
{
}

void stage01::update()
{
	

}

void stage01::render()
{
	IMAGEMANAGER->findImage("Test_Stage1")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("Door_Stage1")->render(getMemDC(), _Stage1RightDoor._x - 39, _Stage1RightDoor._y - 57);
}
