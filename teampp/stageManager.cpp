#include "stdafx.h"
#include "stageManager.h"
#include "npc.h"
#include "enemyManager.h"

stageManager::stageManager()
{
}

stageManager::~stageManager()
{
}

HRESULT stageManager::init()
{
	_Stage1 = new stage01;
	_Stage1->init();

	_Stage2 = new stage02;
	_Stage2->init();

	_Stage3 = new stage03;
	_Stage3->init();

	_currentPixelCollision = _Stage1->getPixel();

	_NowStage = S1;
	_NowStage1 = true;
	_NowStage2 = false;
	_NowStage3 = false;

	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;

	return S_OK;
}

void stageManager::release()
{
	_Stage1->release();
	_Stage2->release();
	_Stage3->release();

	SAFE_DELETE(_Stage1);
	SAFE_DELETE(_Stage2);
	SAFE_DELETE(_Stage3);

	ReleaseDC(_hWnd, getMemDC());
}

void stageManager::update()
{
	_spawnCount++;

	if (_spawnCount % 100 == 0)
	{
		_em->spawnEnemy(_NowStage);
		_spawnCount = 0;
	}


	for (int i = 0; i < _vNpcs.size(); ++i)
		_vNpcs[i]->update();

}

void stageManager::render()
{
	NowStage();
	for (int i = 0; i < _vNpcs.size(); ++i)
		_vNpcs[i]->render();
}

void stageManager::NowStage()
{
	switch (_NowStage)
	{
		case S1:
		{
			_Stage1->render();	
		}
		break;

		case S2:
		{
			_Stage2->render();
		}
		break;

		case S3:
		{
			_Stage3->render();
		}
		break;
	}
}

void stageManager::Stage1Move()
{
	_NowStage = S1;
	_NowStage1 = true;
	_NowStage2 = false;
	_NowStage3 = false;
	_currentPixelCollision = _Stage1->getPixel();
	CAMERA->setBackWidth(_currentPixelCollision->getWidth());
	CAMERA->setBackHeight(_currentPixelCollision->getHeight());

	_vNpcs = _Stage1->getNPCs();
	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;
}

void stageManager::Stage2Move()
{
	_NowStage = S2;
	_NowStage1 = false;
	_NowStage2 = true;
	_NowStage3 = false;
	_currentPixelCollision = _Stage2->getPixel();
	CAMERA->setBackWidth(_currentPixelCollision->getWidth());
	CAMERA->setBackHeight(_currentPixelCollision->getHeight());

	_vNpcs = _Stage2->getNPCs();
	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;
}

void stageManager::Stage3Move()
{
	_NowStage = S3;
	_NowStage1 = false;
	_NowStage2 = false;
	_NowStage3 = true;
	_currentPixelCollision = _Stage3->getPixel();
	CAMERA->setBackWidth(_currentPixelCollision->getWidth());
	CAMERA->setBackHeight(_currentPixelCollision->getHeight());

	_vNpcs = _Stage3->getNPCs();
	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;
}

void stageManager::Stage1_Stage2_Ok()
{
	_Stage1->Stage1RightDoorOpenDraw();
}

void stageManager::Stage2_Stage3_Ok()
{
	_Stage2->Stage2RightDoorOpenDraw();
}

void stageManager::Stage2_Stage1_Ok()
{
	_Stage2->Stage2LeftDoorOpenDraw();
}

void stageManager::Stage3_Stage2_Ok()
{
	_Stage3->Stage3LeftDoorOpenDraw();
}
