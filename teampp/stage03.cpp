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

	// �������� 2 ���� door �̹��� ���� ����

	_Stage3LeftDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Stage3", "images/stage/UI_UnLocked_Door.bmp", 78, 114, true, RGB(255, 0, 255));

	_Stage3LeftDoorOpen._x = 250;
	_Stage3LeftDoorOpen._y = WINSIZEY / 2 + 400;

	_Stage3LeftDoorOpen._rc.setCenterPos(_Stage3LeftDoorOpen._x, _Stage3LeftDoorOpen._y);

	//==================================================================================================================================================//

	// �������� 3 �ȼ� ��� ����

	_Stage3PixelBackGround._pixelCollision = IMAGEMANAGER->addImage("stage3_pixel", "images/stage/stage03_pixel.bmp", 2769, 1083, false, NULL);


	//==================================================================================================================================================//

	//�������� 3 ��� ����

	IMAGEMANAGER->addImage("Test_Stage3", "images/stage/stage03.bmp", 2769, 1083, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

	//�������� 3 LeftDoor ����

	_Stage3LeftDoor._StageImage = IMAGEMANAGER->addImage("Door2_Stage3", "images/stage/UI_UnLocked_Door2.bmp", 78, 114, true, RGB(255, 0, 255));
	

	_Stage3LeftDoor._x = 250;
	_Stage3LeftDoor._y = WINSIZEY / 2 + 400;

	_Stage3LeftDoor._rc.setCenterPos(_Stage3LeftDoor._x, _Stage3LeftDoor._y);

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

	IMAGEMANAGER->findImage("Door2_Stage3")->render(getMemDC(), _Stage3LeftDoor._x - 39, _Stage3LeftDoor._y - 57);
}

void stage03::Stage3LeftDoorOpenDraw()
{
	IMAGEMANAGER->findImage("Door_Stage3")->render(getMemDC(), _Stage3LeftDoor._x - 39, _Stage3LeftDoor._y - 57);
}
