#include "stdafx.h"
#include "stageManager.h"

HRESULT stageManager::init()
{
	//스테이지 초기화
	_stage1 = new stage1;
	_stage2 = new stage2;
	_stage3 = new stage3;
	_stage1->init();
	_stageSelect = STAGE1;
	_currentPixelCollision = _stage1->getPixel();
	return S_OK;
}

void stageManager::release()
{
	_stage1->release();
	_stage2->release();
	_stage3->release();

	SAFE_DELETE(_stage1);
	SAFE_DELETE(_stage2);
	SAFE_DELETE(_stage3);

	ReleaseDC(_hWnd, getMemDC());
}

void stageManager::update()
{

	//스테이지 셀렉트
	switch (_stageSelect)
	{
	case 0:
		_stage1->update();
		break;
	case 1:

		_stage2->update();
		break;
	case 2:
	
		_stage3->update();
		break;
	}

	//스테이지 변경 test
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		stageClear();
		_stage1->init();
		_stageSelect = STAGE1;
		_currentPixelCollision = _stage1->getPixel();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		stageClear();
		_stage2->init();
		_stageSelect = STAGE2;
		_currentPixelCollision = _stage2->getPixel();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		stageClear();
		_stage3->init();
		_stageSelect = STAGE3;
		_currentPixelCollision = _stage3->getPixel();
	}


	
}

void stageManager::render()
{
	//스테이지 렌더
	switch (_stageSelect)
	{
	case 0:
		_stage1->render();
		break;
	case 1:
		_stage2->render();
		break;
	case 2:
		_stage3->render();
		break;
	}

}

void stageManager::stageClear()
{
	switch (_stageSelect)
	{
	case 0:
		_stage1->release();
		
		break;
	case 1:
		_stage2->release();
		break;
	case 2:
		_stage3->release();
		break;
	}

	ReleaseDC(_hWnd, getMemDC());
}
