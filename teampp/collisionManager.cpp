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
	_enemyCollisionCount = _enemyCollisionCount1  =  _enemyCollisionCount2 = _enemyCollisionCount3 = 0;

	_attackEffect = IMAGEMANAGER->addFrameImage("playerAttackEffect", "images/player/Kyoko_Attack_Effect.bmp", 612, 196, 3, 1, true, RGB(255, 0, 255));//�÷��̾ ���� �����Ҷ� ���� �浹�� ����Ʈ �̹���

	_attackEffectFrame = false;//�÷��̾ ���� ���������� ����� ����Ʈ

	_attackEffect->setFrameX(0);
	_attackEffect->setFrameY(0);
	return S_OK;
}

void collisionManager::render()
{
	stagedoor_collision_image();

	if (_attackEffectFrame)//�÷��̾ �����Ҷ� ���� �浹�� ȭ�鿡 �Ѹ� ����Ʈ
	{
		ZORDER->pushObject(getMemDC(), _attackEffect, _attackEffect->getFrameX(), _attackEffect->getFrameY(), 2, _enemyEffectPosX , 50, _enemyEffectPosY);
	}
}

void collisionManager::update()
{
	stagedoor_collision();

	enemy_collisionNoBlock();
	enemy_collisionLeftBlock();
	enemy_collisionRightBlock();

	npcCollision();

	player_collision();

	playerAttackHitEffect();//�÷��̾ ���� ���������� �浹�� ���� ����Ʈ�� �������� �����ϴ� �Լ�
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
		//boss�������� -> 4��������
		if (isCollision(_stageManager->getVBossStage()->getRect(), _player->getPlayerRect()) && _stageManager->getNowbossStage() == true)
		{
			_stageManager->Stage4Move();
			_player->playerPosition_Bossat4();
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
	//������������ -> 4��������
	if (isCollision(_stageManager->getVBossStage()->getRect(), _player->getPlayerRect()) && _stageManager->getNowbossStage() == true)
	{
		_stageManager->BossStage_Stage4_Ok();
	}

}

void collisionManager::enemy_collisionNoBlock()
{
	vector<enemy*> temp = _enemyManager->getEnemiesVector();

	for (int i = 0; i < temp.size(); i++)
	{
		// ============================================ ���ʹ̰� ���� ���°� �ƴ� �� ============================================ //
		if (temp[i]->getEnemyDirection() != ENEMY_LEFT_BLOCK && temp[i]->getEnemyDirection() != ENEMY_RIGHT_BLOCK)
		{
			if (isCollision(temp[i]->getEnemyRect(), _player->getAttackRc()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				//_player->setPlayerAttackRectRemove(0, 0, 0, 0);
				_enemyCollisionCount++;
				if (_enemyCollisionCount % 7 == 0)
				{
					if (_player->getPlayerdirection() != PLAYERDIRECTION_RIGHT_STRONG_ATTACK && _player->getPlayerdirection() != PLAYERDIRECTION_LEFT_STRONG_ATTACK &&
						_player->getPlayerdirection() != PLAYERDIRECTION_RIGHT_ULTIMATE && _player->getPlayerdirection() != PLAYERDIRECTION_LEFT_ULTIMATE)
					{
						temp[i]->setHitEnemyHP(1);
					}
					else if (_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_STRONG_ATTACK || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_STRONG_ATTACK)
					{
						temp[i]->setHitEnemyHP(4);
					}
					else if (_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_ULTIMATE || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_ULTIMATE)
					{
						temp[i]->setHitEnemyHP(15);
					}
					_enemyCollisionCount = 0;
				}
			}

			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc1()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				if (temp[i]->getEnemyDirection() == ENEMY_LEFT_IDLE || temp[i]->getEnemyDirection() == ENEMY_LEFT_MOVE ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_BACK_MOVE || temp[i]->getEnemyDirection() == ENEMY_LEFT_ATTACK ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_COMBO1 || temp[i]->getEnemyDirection() == ENEMY_LEFT_COMBO2 ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_SUBMOTION || temp[i]->getEnemyDirection() == ENEMY_LEFT_STUN ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_RUN)
				{
					temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_1);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_1());
				}
				else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_IDLE || temp[i]->getEnemyDirection() == ENEMY_RIGHT_MOVE ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_BACK_MOVE || temp[i]->getEnemyDirection() == ENEMY_RIGHT_ATTACK ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_COMBO1 || temp[i]->getEnemyDirection() == ENEMY_RIGHT_COMBO2 ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_SUBMOTION || temp[i]->getEnemyDirection() == ENEMY_RIGHT_STUN ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_RUN)
				{
					temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_1);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_1());
				}
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				_player->setComboAttack(true);//2���޺����� Ʈ��
				//_player->setPlayerAttackRectRemove1(0, 0, 0, 0);
				_enemyCollisionCount1++;
				if (_enemyCollisionCount1 % 1 == 0)
				{
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount1 = 0;
				}
			}

			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc2()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				_player->setComboAttack2(true);//3���޺����� Ʈ��
				//_player->setPlayerAttackRectRemove2(0, 0, 0, 0);
				_enemyCollisionCount2++;
				if (_enemyCollisionCount2 % 1 == 0)
				{
					if (temp[i]->getEnemyDirection() == ENEMY_LEFT_GETHIT_1)
					{
						temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_2);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_2());
					}
					else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_GETHIT_1)
					{
						temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_2);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_2());
					}
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount2 = 0;
				}
			}

			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc3()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				//_player->setPlayerAttackRectRemove3(0, 0, 0, 0);
				_enemyCollisionCount3++;
				if (_enemyCollisionCount3 % 1 == 0)
				{
					if (temp[i]->getEnemyDirection() == ENEMY_LEFT_GETHIT_2)
					{
						temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_3);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_3());
					}
					else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_GETHIT_2)
					{
						temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_3);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_3());
					}
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount3 = 0;
				}
			}
		}

	}
	//_player->setPlayerAttackRectRemove(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove1(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove2(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove3(0, 0, 0, 0);

}

void collisionManager::enemy_collisionLeftBlock()
{
	vector<enemy*> temp = _enemyManager->getEnemiesVector();

	for (int i = 0; i < temp.size(); i++)
	{

		// ============================================ ���ʹ̻��°� ���� �����̰� �÷��̾ �����ʿ��� ���ݽ� ============================================ //
		if (temp[i]->getEnemyDirection() == ENEMY_LEFT_BLOCK && temp[i]->getEnemyRect().getCenterX() < _player->getPlayerRect().getCenterX())
		{
			if (isCollision(temp[i]->getEnemyRect(), _player->getAttackRc()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				//_player->setPlayerAttackRectRemove(0, 0, 0, 0);
				_enemyCollisionCount++;
				if (_enemyCollisionCount % 7 == 0)
				{
					if (_player->getPlayerdirection() != PLAYERDIRECTION_RIGHT_STRONG_ATTACK && _player->getPlayerdirection() != PLAYERDIRECTION_LEFT_STRONG_ATTACK &&
						_player->getPlayerdirection() != PLAYERDIRECTION_RIGHT_ULTIMATE && _player->getPlayerdirection() != PLAYERDIRECTION_LEFT_ULTIMATE)
					{
						temp[i]->setHitEnemyHP(1);
					}
					else if (_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_STRONG_ATTACK || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_STRONG_ATTACK)
					{
						temp[i]->setHitEnemyHP(4);
					}
					else if (_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_ULTIMATE || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_ULTIMATE)
					{
						temp[i]->setHitEnemyHP(15);
					}
					_enemyCollisionCount = 0;
				}
			}

			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc1()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				if (temp[i]->getEnemyDirection() == ENEMY_LEFT_IDLE || temp[i]->getEnemyDirection() == ENEMY_LEFT_MOVE ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_BACK_MOVE || temp[i]->getEnemyDirection() == ENEMY_LEFT_ATTACK ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_COMBO1 || temp[i]->getEnemyDirection() == ENEMY_LEFT_COMBO2 ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_SUBMOTION || temp[i]->getEnemyDirection() == ENEMY_LEFT_STUN ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_RUN)
				{
					temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_1);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_1());
				}
				else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_IDLE || temp[i]->getEnemyDirection() == ENEMY_RIGHT_MOVE ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_BACK_MOVE || temp[i]->getEnemyDirection() == ENEMY_RIGHT_ATTACK ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_COMBO1 || temp[i]->getEnemyDirection() == ENEMY_RIGHT_COMBO2 ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_SUBMOTION || temp[i]->getEnemyDirection() == ENEMY_RIGHT_STUN ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_RUN)
				{
					temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_1);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_1());
				}
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				_player->setComboAttack(true);//2���޺����� Ʈ��
				//_player->setPlayerAttackRectRemove1(0, 0, 0, 0);
				_enemyCollisionCount1++;
				if (_enemyCollisionCount1 % 1 == 0)
				{
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount1 = 0;
				}
			}

			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc2()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				_player->setComboAttack2(true);//3���޺����� Ʈ��
				//_player->setPlayerAttackRectRemove2(0, 0, 0, 0);
				_enemyCollisionCount2++;
				if (_enemyCollisionCount2 % 1 == 0)
				{
					if (temp[i]->getEnemyDirection() == ENEMY_LEFT_GETHIT_1)
					{
						temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_2);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_2());
					}
					else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_GETHIT_1)
					{
						temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_2);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_2());
					}
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount2 = 0;
				}
			}

			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc3()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				//_player->setPlayerAttackRectRemove3(0, 0, 0, 0);
				_enemyCollisionCount3++;
				if (_enemyCollisionCount3 % 1 == 0)
				{
					if (temp[i]->getEnemyDirection() == ENEMY_LEFT_GETHIT_2)
					{
						temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_3);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_3());
					}
					else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_GETHIT_2)
					{
						temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_3);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_3());
					}
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount3 = 0;
				}
			}
		}
	}
	//_player->setPlayerAttackRectRemove(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove1(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove2(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove3(0, 0, 0, 0);
}


void collisionManager::enemy_collisionRightBlock()
{
	vector<enemy*> temp = _enemyManager->getEnemiesVector();

	for (int i = 0; i < temp.size(); i++)
	{

	// ============================================ ���ʹ̻��°� ������ �����̰� �÷��̾ ���ʿ��� ���ݽ� ============================================ //
		if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_BLOCK && temp[i]->getEnemyRect().getCenterX() > _player->getPlayerRect().getCenterX())
		{
			if (isCollision(temp[i]->getEnemyRect(), _player->getAttackRc()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				//_player->setPlayerAttackRectRemove(0, 0, 0, 0);
				_enemyCollisionCount++;
				if (_enemyCollisionCount % 7 == 0)
				{
					if (_player->getPlayerdirection() != PLAYERDIRECTION_RIGHT_STRONG_ATTACK && _player->getPlayerdirection() != PLAYERDIRECTION_LEFT_STRONG_ATTACK &&
						_player->getPlayerdirection() != PLAYERDIRECTION_RIGHT_ULTIMATE && _player->getPlayerdirection() != PLAYERDIRECTION_LEFT_ULTIMATE)
					{
						temp[i]->setHitEnemyHP(1);
					}
					else if (_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_STRONG_ATTACK || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_STRONG_ATTACK)
					{
						temp[i]->setHitEnemyHP(4);
					}
					else if (_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_ULTIMATE || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_ULTIMATE)
					{
						temp[i]->setHitEnemyHP(15);
					}
					_enemyCollisionCount = 0;
				}
			}
			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc1()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				if (temp[i]->getEnemyDirection() == ENEMY_LEFT_IDLE || temp[i]->getEnemyDirection() == ENEMY_LEFT_MOVE ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_BACK_MOVE || temp[i]->getEnemyDirection() == ENEMY_LEFT_ATTACK ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_COMBO1 || temp[i]->getEnemyDirection() == ENEMY_LEFT_COMBO2 ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_SUBMOTION || temp[i]->getEnemyDirection() == ENEMY_LEFT_STUN ||
					temp[i]->getEnemyDirection() == ENEMY_LEFT_RUN)
				{
					temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_1);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_1());
				}
				else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_IDLE || temp[i]->getEnemyDirection() == ENEMY_RIGHT_MOVE ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_BACK_MOVE || temp[i]->getEnemyDirection() == ENEMY_RIGHT_ATTACK ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_COMBO1 || temp[i]->getEnemyDirection() == ENEMY_RIGHT_COMBO2 ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_SUBMOTION || temp[i]->getEnemyDirection() == ENEMY_RIGHT_STUN ||
					temp[i]->getEnemyDirection() == ENEMY_RIGHT_RUN)
				{
					temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_1);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_1());
				}
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				_player->setComboAttack(true);//2���޺����� Ʈ��
				//_player->setPlayerAttackRectRemove1(0, 0, 0, 0);
				_enemyCollisionCount1++;
				if (_enemyCollisionCount1 % 1 == 0)
				{
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount1 = 0;
				}
			}

			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc2()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				_player->setComboAttack2(true);//3���޺����� Ʈ��
				//_player->setPlayerAttackRectRemove2(0, 0, 0, 0);
				_enemyCollisionCount2++;
				if (_enemyCollisionCount2 % 1 == 0)
				{
					if (temp[i]->getEnemyDirection() == ENEMY_LEFT_GETHIT_1)
					{
						temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_2);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_2());
					}
					else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_GETHIT_1)
					{
						temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_2);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_2());
					}
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount2 = 0;
				}
			}

			if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc3()) &&
				_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
				_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
			{
				_attackEffectFrame = true;
				_enemyEffectPosX = temp[i]->getEnemyRect().getCenterX();
				_enemyEffectPosY = temp[i]->getEnemyRect().bottom;
				//_player->setPlayerAttackRectRemove3(0, 0, 0, 0);
				_enemyCollisionCount3++;
				if (_enemyCollisionCount3 % 1 == 0)
				{
					if (temp[i]->getEnemyDirection() == ENEMY_LEFT_GETHIT_2)
					{
						temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_3);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_3());
					}
					else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_GETHIT_2)
					{
						temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_3);
						temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_3());
					}
					temp[i]->setHitEnemyHP(1);
					_enemyCollisionCount3 = 0;
				}
			}
		}
	}
	//_player->setPlayerAttackRectRemove(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove1(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove2(0, 0, 0, 0);
	//_player->setPlayerAttackRectRemove3(0, 0, 0, 0);
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

void collisionManager::player_collision()
{
	//���ʹ� �����̶� �÷��̾� �浹

	vector<enemy*> temp = _enemyManager->getEnemiesVector();
	
	for (int i = 0; i < temp.size(); ++i)
	{
		if (_player->getPlayerdirection() != PLAYERDIRECTION_LEFT_GUARD && _player->getPlayerdirection() != PLAYERDIRECTION_RIGHT_GUARD)
		{
			if (isCollision(_player->getPlayerRect(), temp[i]->getEnemyAttackRect()) &&
				temp[i]->getEnemyRect().bottom - 50 <= _player->getPlayerZ() &&
				temp[i]->getEnemyRect().bottom + 50 >= _player->getPlayerZ())
			{
				temp[i]->setEnemyAttackRect(0, 0, 0, 0);
				_count++;
				if (_count % 20 == 0)
				{
					if (_player->getPlayerdirection() == PLAYERDIRECTION_LEFT_COMBO_ATTACK1 || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_COMBO_ATTACK2 ||
						_player->getPlayerdirection() == PLAYERDIRECTION_LEFT_COMBO_ATTACK3 || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_DASH_ATTACK ||
						_player->getPlayerdirection() == PLAYERDIRECTION_LEFT_JUMP || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_JUMP_ATTACK ||
						_player->getPlayerdirection() == PLAYERDIRECTION_LEFT_MOVE || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_STOP ||
						_player->getPlayerdirection() == PLAYERDIRECTION_LEFT_STRONG_ATTACK || _player->getPlayerdirection() == PLAYERDIRECTION_LEFT_WALK)
					{
						_player->setPlayerDirection(PLAYERDIRECTION_LEFT_HIT);
					}
					else if (_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_COMBO_ATTACK1 || _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_COMBO_ATTACK2 ||
						_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_COMBO_ATTACK3 || _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_DASH_ATTACK ||
						_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_JUMP || _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_JUMP_ATTACK ||
						_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_MOVE || _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_STOP ||
						_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_STRONG_ATTACK || _player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_WALK)
					{
						_player->setPlayerDirection(PLAYERDIRECTION_RIGHT_HIT);
					}

					_player->setHitPlayerHP(1);
					_uiManager->PlayerHpMinus();
					_count = 0;
				}
			}
		}

		if (_player->getPlayerdirection() == PLAYERDIRECTION_LEFT_GUARD && _player->getPlayerX() < temp[i]->getEnemyRect().getCenterX())
		{
			if (isCollision(_player->getPlayerRect(), temp[i]->getEnemyAttackRect()) &&
				temp[i]->getEnemyRect().bottom - 50 <= _player->getPlayerZ() &&
				temp[i]->getEnemyRect().bottom + 50 >= _player->getPlayerZ())
			{
				temp[i]->setEnemyAttackRect(0, 0, 0, 0);
				_count++;
				if (_count % 20 == 0)
				{
					_player->setPlayerDirection(PLAYERDIRECTION_RIGHT_HIT);

					_player->setHitPlayerHP(1);
					_uiManager->PlayerHpMinus();
					_count = 0;
				}
			}
		}

		if (_player->getPlayerdirection() == PLAYERDIRECTION_RIGHT_GUARD && _player->getPlayerX() > temp[i]->getEnemyRect().getCenterX())
		{
			if (isCollision(_player->getPlayerRect(), temp[i]->getEnemyAttackRect()) &&
				temp[i]->getEnemyRect().bottom - 50 <= _player->getPlayerZ() &&
				temp[i]->getEnemyRect().bottom + 50 >= _player->getPlayerZ())
			{
				temp[i]->setEnemyAttackRect(0, 0, 0, 0);
				_count++;
				if (_count % 20 == 0)
				{
					_player->setPlayerDirection(PLAYERDIRECTION_LEFT_HIT);

					_player->setHitPlayerHP(1);
					_uiManager->PlayerHpMinus();
					_count = 0;
				}
			}
		}
	}

}

void collisionManager::playerAttackHitEffect()
{
	if (_attackEffectFrame)
	{
		_count++;
		if (_count % 5 == 0)
		{
			_attackEffect->setFrameX(_attackEffect->getFrameX() + 1);
			if (_attackEffect->getFrameX() >= _attackEffect->getMaxFrameX())
			{
				_attackEffect->setFrameX(0);
				_attackEffectFrame = false;
			}
			_count = 0;
		}
	}
}


