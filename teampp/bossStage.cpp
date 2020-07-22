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
	// 스테이지 보스 픽셀 배경 선언

	_BossStagePixelBackGround._pixelCollision = IMAGEMANAGER->addImage("boss_stage_pixel", "images/stage/boss_stage_pixel.bmp", 2769, 1083, false, NULL);


	//==================================================================================================================================================//

	//스테이지 보스 배경 선언

	IMAGEMANAGER->addImage("Test_Boss_Stage", "images/stage/boss_stage.bmp", 2769, 1083, false, RGB(0, 0, 0));

	//==================================================================================================================================================//

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
	IMAGEMANAGER->findImage("Test_Boss_Stage")->render(getMemDC(), 0, 0);
}
