#include "stdafx.h"
#include "collisionManager.h"
#include "player.h"
#include "enemyManager.h"
#include "stageManager2.h"

HRESULT collisionManager::init()
{
	return S_OK;
}

void collisionManager::render()
{
}

void collisionManager::update()
{
	stagedoor_collision();
}

void collisionManager::release()
{
}

void collisionManager::stagedoor_collision() //스테이지 이동
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{	
		//1스테이지 -> 2스테이지
		if (isCollision(_stageManager2->getVStage1()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage1() == true)
		{
			_stageManager2->Stage2Move();
		}

		//2스테이지 -> 3스테이지
		if (isCollision(_stageManager2->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
		{
			_stageManager2->Stage3Move();
		}

		//2스테이지 -> 1스테이지
		if (isCollision(_stageManager2->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
		{
			_stageManager2->Stage1Move();
		}

		//3스테이지 -> 2스테이지
		if (isCollision(_stageManager2->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage3() == true)
		{
			_stageManager2->Stage2Move();
		}
	}	
}
