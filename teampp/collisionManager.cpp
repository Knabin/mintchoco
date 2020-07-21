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
<<<<<<< HEAD
	playerHpMinus();
=======
	enemy_collision();//���̶� �÷��̾� �����̶� �浹��
>>>>>>> 6826daa34b45ff52297fd4b911c730c3fddd4343
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
			_player->playerPosition_1at2();
		}

		//2�������� -> 3��������
		if (isCollision(_stageManager2->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
		{
			_stageManager2->Stage3Move();
			_player->playerPosition_2at3();			
		}

		//2�������� -> 1��������
		if (isCollision(_stageManager2->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager2->getNowstage2() == true)
		{
			_stageManager2->Stage1Move();
			_player->playerPosition_2at1();
		}

		//3�������� -> 2��������
		if (isCollision(_stageManager2->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage3() == true)
		{
			_stageManager2->Stage2Move();
			_player->playerPosition_3at2();
		}
	}	
}

void collisionManager::stagedoor_collision_image()	//�������� �̵� �̹��� ����
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
	//3�������� -> 2��������
	if (isCollision(_stageManager2->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager2->getNowstage3() == true)
	{
		_stageManager2->Stage3_Stage2_Ok();
	}

}

<<<<<<< HEAD
//�浹�� Hp ����
void collisionManager::playerHpMinus()
{
	if (isCollision(_itemManager->getVItem()->getRect(), _player->getPlayerRect()))
	{
		_uiManager->PlayerHpMinus();
	}

=======
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
>>>>>>> 6826daa34b45ff52297fd4b911c730c3fddd4343
}
