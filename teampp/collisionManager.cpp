#include "stdafx.h"
#include "collisionManager.h"
#include "player.h"
#include "enemyManager.h"
#include "stageManager2.h"

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
	enemy_collision();//���̶� �÷��̾� �����̶� �浹��
}

void collisionManager::release()
{
}

void collisionManager::stagedoor_collision() //�������� �̵�
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{	
		//1�������� -> 2��������
		if (isCollision(_stageManager2->getVStage1()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage1() == true)
		{
			_stageManager2->Stage2Move();
		}

		//2�������� -> 3��������
		if (isCollision(_stageManager2->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
		{
			_stageManager2->Stage3Move();
		}

		//2�������� -> 1��������
		if (isCollision(_stageManager2->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
		{
			_stageManager2->Stage1Move();
		}

		//3�������� -> 2��������
		if (isCollision(_stageManager2->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage3() == true)
		{
			_stageManager2->Stage2Move();
		}
	}	
}

void collisionManager::stagedoor_collision_image()
{
	//1�������� -> 2��������
	if (isCollision(_stageManager2->getVStage1()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage1() == true)
	{
		_stageManager2->Stage1_Stage2_Ok();
	}

	//2�������� -> 3��������
	if (isCollision(_stageManager2->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
	{
		_stageManager2->Stage2_Stage3_Ok();
	}

	//2�������� -> 1��������
	if (isCollision(_stageManager2->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
	{
		_stageManager2->Stage2_Stage1_Ok();
	}


}

void collisionManager::enemy_collision()
{
	if (isCollision(_enemyManager->getEnemyRc(), _player->getComboAttackRc1()) && _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_COMBO_ATTACK1
		|| isCollision(_enemyManager->getEnemyRc(), _player->getComboAttackRc1()) && _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_COMBO_ATTACK1)//���̶� �÷��̾� ������ �浹��
	{
		_player->setComboAttack(true);//2���޺����� Ʈ��
	}

	if (isCollision(_enemyManager->getEnemyRc(), _player->getComboAttackRc2()) && _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_COMBO_ATTACK2
		|| isCollision(_enemyManager->getEnemyRc(), _player->getComboAttackRc2()) && _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_COMBO_ATTACK2)//���̶� �÷��̾��� 2���޺� ���� ��Ʈ�� �浹��
	{
		_player->setComboAttack2(true);//3���޺����� Ʈ��
	}
}
