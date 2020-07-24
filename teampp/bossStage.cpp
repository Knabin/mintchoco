#include "stdafx.h"
#include "bossStage.h"

bossStage::bossStage()
{
}

bossStage::~bossStage()
{
}

HRESULT bossStage::init()
{

	//스테이지 보스 왼쪽 door  이미지 변경 선언

	_BossStageLeftDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Boss_Stage", "images/stage/UI_UnLocked_Door11.bmp", 52, 76, true, RGB(255, 0, 255));

	_BossStageLeftDoorOpen._x = WINSIZEX / 2 - 330;
	_BossStageLeftDoorOpen._y = WINSIZEY / 2 + 395;

	_BossStageLeftDoorOpen._rc.setCenterPos(_BossStageLeftDoorOpen._x, _BossStageLeftDoorOpen._y);

	//==================================================================================================================================================//

	// 스테이지 보스 픽셀 배경 선언

	_BossStagePixelBackGround._pixelCollision = IMAGEMANAGER->addImage("boss_stage_pixel", "images/stage/boss_stage_pixel.bmp", 2769, 1080, false, NULL);


	//==================================================================================================================================================//

	//스테이지 보스 배경 선언

	IMAGEMANAGER->addImage("Boss_Stage1", "images/stage/boss_stage.bmp", 2769, 1080, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Boss_Stage2", "images/stage/boss_stage2.bmp", 2769, 1080, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

	//스테이지 보스 LeftDoor 선언

	_BossStageLeftDoor._StageImage = IMAGEMANAGER->addImage("Door2_Boss_Stage", "images/stage/UI_UnLocked_Door22.bmp", 52, 76, true, RGB(255, 0, 255));

	_BossStageLeftDoor._x = WINSIZEX / 2 - 330;
	_BossStageLeftDoor._y = WINSIZEY / 2 + 395;

	_BossStageLeftDoor._rc.setCenterPos(_BossStageLeftDoor._x, _BossStageLeftDoor._y);


	//==================================================================================================================================================//

	_isBroken = false;

	return S_OK;
}

void bossStage::release()
{
}

void bossStage::update()
{
}

void bossStage::render()
{
	if(_isBroken) IMAGEMANAGER->findImage("Boss_Stage2")->render(getMemDC(), 0, 0);
	else IMAGEMANAGER->findImage("Boss_Stage1")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("Door2_Boss_Stage")->render(getMemDC(), _BossStageLeftDoor._x - 42, _BossStageLeftDoor._y - 203);
}

void bossStage::BossStageLeftDoorOpenDraw()
{
	IMAGEMANAGER->findImage("Door_Boss_Stage")->render(getMemDC(), _BossStageLeftDoorOpen._x - 42, _BossStageLeftDoorOpen._y - 203);

}
