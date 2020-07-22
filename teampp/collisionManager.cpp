#include "stdafx.h"
#include "collisionManager.h"
#include "player.h"
#include "enemyManager.h"
#include "stageManager.h"
#include "itemManager.h"
#include "UiManager.h"
#include "npc.h"

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

	enemy_collision();//���̶� �÷��̾� �����̶� �浹��

	npcCollision();

	player_collision();

}

void collisionManager::release()
{
}

void collisionManager::stagedoor_collision() //�������� �̵�
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{	
		//1�������� -> 2��������
		if (isCollision(_stageManager->getVStage1()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage1() == true)
		{
			_stageManager->Stage2Move();
			_player->playerPosition_1at2();
		}
		//2�������� -> 3��������
		if (isCollision(_stageManager->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage2() == true)
		{
			_stageManager->Stage3Move();
			_player->playerPosition_2at3();			
		}
		//2�������� -> 1��������
		if (isCollision(_stageManager->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage2() == true)
		{
			_stageManager->Stage1Move();
			_player->playerPosition_2at1();
		}
		//3�������� -> 2��������
		if (isCollision(_stageManager->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage3() == true)
		{
			_stageManager->Stage2Move();
			_player->playerPosition_3at2();
		}
		//3�������� -> 4��������		
		if (isCollision(_stageManager->getVStage3()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage3() == true)
		{
			_stageManager->Stage4Move();
			_player->playerPosition_3at4();			
		}
		//4�������� -> boss��������
		if (isCollision(_stageManager->getVStage4()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage4() == true)
		{

			_stageManager->BossStageMove();
			_player->playerPosition_4atBoss();
		}
		//4�������� -> 3��������
		if (isCollision(_stageManager->getVStage4()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage4() == true)
		{
			_stageManager->Stage3Move();
			_player->playerPosition_4at3();
		}


	}	
}

void collisionManager::stagedoor_collision_image()	//�������� �̵� �̹��� ����
{
	//1�������� -> 2��������
	if (isCollision(_stageManager->getVStage1()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage1() == true)
	{
		_stageManager->Stage1_Stage2_Ok();
	}
	//2�������� -> 3��������
	if (isCollision(_stageManager->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage2() == true)
	{
		_stageManager->Stage2_Stage3_Ok();
	}
	//2�������� -> 1��������
	if (isCollision(_stageManager->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage2() == true)
	{
		_stageManager->Stage2_Stage1_Ok();
	}
	//3�������� -> 2��������
	if (isCollision(_stageManager->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage3() == true)
	{
		_stageManager->Stage3_Stage2_Ok();
	}
	//3�������� -> 4��������
	if (isCollision(_stageManager->getVStage3()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage3() == true)
	{
		_stageManager->Stage3_Stage4_Ok();
	}
	//4�������� -> ������������
	if (isCollision(_stageManager->getVStage4()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage4() == true)
	{
		_stageManager->Stage4_BossStage_Ok();
	}
	//4�������� -> 3��������
	if (isCollision(_stageManager->getVStage4()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage4() == true)
	{
		_stageManager->Stage4_Stage3_Ok();
	}

}


//�浹�� Hp ����
void collisionManager::playerHpMinus()
{
	if (isCollision(_itemManager->getVItem()->getRect(), _player->getPlayerRect()))
	{
		_uiManager->PlayerHpMinus();
	}

}
void collisionManager::enemy_collision()//���̶� �÷��̾� �����̶� �浹��
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

void collisionManager::npcCollision()
{
	vector<npc*> temp = _stageManager->getNpcVector();
	
	for (int i = 0; i < temp.size(); ++i)
	{
		if (_player->getIsAttacking() && getDistance(0, temp[i]->getRect().bottom, 0, _player->getPlayerZ()) <= 100 &&
			getDistance(temp[i]->getX(), temp[i]->getY(), _player->getPlayerX(), _player->getPlayerRect().getCenterY()) <= 200)
		{
			temp[i]->doReact();
		}
	}
}

void collisionManager::player_collision()//�÷��̾�� �� �����̶� �浹��
{
	vector<enemy*> ve = _enemyManager->getEnemiesVector();
	//if (isCollision(_player->getPlayerRect(), _enemyManager->get))
	//{
	//
	//}
}

