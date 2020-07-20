#include "stdafx.h"
#include "stage02.h"

stage02::stage02()
{
}

stage02::~stage02()
{
}

HRESULT stage02::init()
{
	//스테이지 2 배경 선언

	IMAGEMANAGER->addImage("Test_Stage2", "images/stage/stage02.bmp", 2112, 864, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

	//스테이지 2 RightDoor 선언

	_Stage2RightDoor._StageImage = IMAGEMANAGER->addImage("Door_Stage2", "images/stage/UI_UnLocked_Door.bmp", 78, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Door2_Stage2", "images/stage/UI_UnLocked_Door2.bmp", 78, 114, true, RGB(255, 0, 255));

	_Stage2RightDoor._x = WINSIZEX - 100;
	_Stage2RightDoor._y = WINSIZEY / 2;

	_Stage2RightDoor._rc = RectMakeCenter(_Stage2RightDoor._x, _Stage2RightDoor._y, _Stage2RightDoor._StageImage->getWidth(), _Stage2RightDoor._StageImage->getHeight());

	//==================================================================================================================================================//

	//스테이지 2 LeftDoor 선언

	_Stage2LeftDoor._StageImage = IMAGEMANAGER->addImage("Door_Stage2", "images/stage/UI_UnLocked_Door2.bmp", 78, 114, true, RGB(255, 0, 255));

	_Stage2LeftDoor._x = 100;
	_Stage2LeftDoor._y = WINSIZEY / 2;

	_Stage2LeftDoor._rc = RectMakeCenter(_Stage2LeftDoor._x, _Stage2LeftDoor._y, _Stage2LeftDoor._StageImage->getWidth(), _Stage2LeftDoor._StageImage->getHeight());


	return S_OK;
}

void stage02::release()
{
}

void stage02::update()
{
}

void stage02::render()
{
	IMAGEMANAGER->findImage("Test_Stage2")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("Door_Stage2")->render(getMemDC(), _Stage2RightDoor._x - 39, _Stage2RightDoor._y - 57);

	IMAGEMANAGER->findImage("Door_Stage2")->render(getMemDC(), _Stage2LeftDoor._x - 39, _Stage2LeftDoor._y - 57);
}
