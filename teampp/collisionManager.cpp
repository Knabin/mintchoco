#include "stdafx.h"
#include "collisionManager.h"
#include "player.h"
#include "enemyManager.h"
#include "stageManager2.h"
#include "itemManager.h"
#include "UiManager.h"

HRESULT collisionManager::init()
{
	_count = 0;
	return S_OK;
}

void collisionManager::render()
{
	stagedoor_collision_image();
}

void collisionManager::update()
{
	stagedoor_collision();

	playerHpMinus();

	enemy_collision();//적이랑 플레이어 공격이랑 충돌시

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
			_player->playerPosition_1at2();
		}

		//2스테이지 -> 3스테이지
		if (isCollision(_stageManager2->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
		{
			_stageManager2->Stage3Move();
			_player->playerPosition_2at3();			
		}

		//2스테이지 -> 1스테이지
		if (isCollision(_stageManager2->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
		{
			_stageManager2->Stage1Move();
			_player->playerPosition_2at1();
		}

		//3스테이지 -> 2스테이지
		if (isCollision(_stageManager2->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage3() == true)
		{
			_stageManager2->Stage2Move();
			_player->playerPosition_3at2();
		}
	}	
}

void collisionManager::stagedoor_collision_image()	//스테이지 이동 이미지 변경
{
	//1스테이지 -> 2스테이지
	if (isCollision(_stageManager2->getVStage1()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage1() == true)
	{
		_stageManager2->Stage1_Stage2_Ok();
	}

	//2스테이지 -> 3스테이지
	if (isCollision(_stageManager2->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
	{
		_stageManager2->Stage2_Stage3_Ok();
	}

	//2스테이지 -> 1스테이지
	if (isCollision(_stageManager2->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
	{
		_stageManager2->Stage2_Stage1_Ok();
	}
	//3스테이지 -> 2스테이지
	if (isCollision(_stageManager2->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage3() == true)
	{
		_stageManager2->Stage3_Stage2_Ok();
	}

}


//충돌시 Hp 감소
void collisionManager::playerHpMinus()
{
	if (isCollision(_itemManager->getVItem()->getRect(), _player->getPlayerRect()))
	{
		_uiManager->PlayerHpMinus();
	}

}
void collisionManager::enemy_collision()
{
	if (isCollision(_enemyManager->getEnemyRc(), _player->getComboAttackRc1()) && _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_COMBO_ATTACK1
		|| isCollision(_enemyManager->getEnemyRc(), _player->getComboAttackRc1()) && _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_COMBO_ATTACK1)//적이랑 플레이어 공격이 충돌시
	{
		_player->setComboAttack(true);//2단콤보변수 트루
	}

	if (isCollision(_enemyManager->getEnemyRc(), _player->getComboAttackRc2()) && _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_COMBO_ATTACK2
		|| isCollision(_enemyManager->getEnemyRc(), _player->getComboAttackRc2()) && _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_COMBO_ATTACK2)//적이랑 플레이어의 2단콤보 공격 렉트랑 충돌시
	{
		_player->setComboAttack2(true);//3단콤보공격 트루
	}

}
