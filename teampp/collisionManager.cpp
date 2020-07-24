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

	npcCollision();

	player_collision();

}

void collisionManager::release()
{
}

void collisionManager::stagedoor_collision() //스테이지 이동
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{	
		//1스테이지 -> 2스테이지
		if (isCollision(_stageManager->getVStage1()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage1() == true)
		{
			_stageManager->Stage2Move();
			_player->playerPosition_1at2();
		}
		//2스테이지 -> 3스테이지
		if (isCollision(_stageManager->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage2() == true)
		{
			_stageManager->Stage3Move();
			_player->playerPosition_2at3();			
		}
		//2스테이지 -> 1스테이지
		if (isCollision(_stageManager->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage2() == true)
		{
			_stageManager->Stage1Move();
			_player->playerPosition_2at1();
		}
		//3스테이지 -> 2스테이지
		if (isCollision(_stageManager->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage3() == true)
		{
			_stageManager->Stage2Move();
			_player->playerPosition_3at2();
		}
		//3스테이지 -> 4스테이지		
		if (isCollision(_stageManager->getVStage3()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage3() == true)
		{
			_stageManager->Stage4Move();
			_player->playerPosition_3at4();			
		}
		//4스테이지 -> boss스테이지
		if (isCollision(_stageManager->getVStage4()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage4() == true)
		{
			_stageManager->BossStageMove();
			_player->playerPosition_4atBoss();
		}
		//4스테이지 -> 3스테이지
		if (isCollision(_stageManager->getVStage4()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage4() == true)
		{
			_stageManager->Stage3Move();
			_player->playerPosition_4at3();
		}
		//boss스테이지 -> 4스테이지
		if (isCollision(_stageManager->getVBossStage()->getRect(), _player->getPlayerRect()) && _stageManager->getNowbossStage() == true)
		{
			_stageManager->Stage4Move();
			_player->playerPosition_Bossat4();
		}


	}	
}

void collisionManager::stagedoor_collision_image()	//스테이지 이동 이미지 변경
{
	//1스테이지 -> 2스테이지
	if (isCollision(_stageManager->getVStage1()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage1() == true)
	{
		_stageManager->Stage1_Stage2_Ok();
	}
	//2스테이지 -> 3스테이지
	if (isCollision(_stageManager->getVStage2()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage2() == true)
	{
		_stageManager->Stage2_Stage3_Ok();
	}
	//2스테이지 -> 1스테이지
	if (isCollision(_stageManager->getVStage2()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage2() == true)
	{
		_stageManager->Stage2_Stage1_Ok();
	}
	//3스테이지 -> 2스테이지
	if (isCollision(_stageManager->getVStage3()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage3() == true)
	{
		_stageManager->Stage3_Stage2_Ok();
	}
	//3스테이지 -> 4스테이지
	if (isCollision(_stageManager->getVStage3()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage3() == true)
	{
		_stageManager->Stage3_Stage4_Ok();
	}
	//4스테이지 -> 보스스테이지
	if (isCollision(_stageManager->getVStage4()->getRect(), _player->getPlayerRect()) && _stageManager->getNowstage4() == true)
	{
		_stageManager->Stage4_BossStage_Ok();
	}
	//4스테이지 -> 3스테이지
	if (isCollision(_stageManager->getVStage4()->getRect2(), _player->getPlayerRect()) && _stageManager->getNowstage4() == true)
	{
		_stageManager->Stage4_Stage3_Ok();
	}
	//보스스테이지 -> 4스테이지
	if (isCollision(_stageManager->getVBossStage()->getRect(), _player->getPlayerRect()) && _stageManager->getNowbossStage() == true)
	{
		_stageManager->BossStage_Stage4_Ok();
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
void collisionManager::enemy_collision()//적이랑 플레이어 공격이랑 충돌시
{
	vector<enemy*> temp = _enemyManager->getEnemiesVector();

	for (int i = 0; i < temp.size(); i++)
	{

		if (isCollision(temp[i]->getEnemyRect(), _player->getAttackRc()) &&
			_player->getPlayerZ() - 50 <= temp[i]->getEnemyRect().bottom &&
			_player->getPlayerZ() + 50 >= temp[i]->getEnemyRect().bottom)
		{
			_player->setPlayerAttackRectRemove(0, 0, 0, 0);
			_enemyCollisionCount++;
			if (_enemyCollisionCount % 5 == 0)
			{
				temp[i]->setHitEnemyHP(1);
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
			_player->setComboAttack(true);//2단콤보변수 트루
			_player->setPlayerAttackRectRemove1(0, 0, 0, 0);
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
			_player->setComboAttack2(true);//3단콤보공격 트루
			_player->setPlayerAttackRectRemove2(0, 0, 0, 0);
			_enemyCollisionCount2++;
			if (_enemyCollisionCount2 % 1 == 0)
			{
				if (temp[i]->getEnemyDirection() == ENEMY_LEFT_GETHIT_1)
				{
					temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_2);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_2());
				}
				else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_GETHIT_2)
				{
					temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_2);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_2());
				}
				temp[i]->setHitEnemyHP(1);
				_enemyCollisionCount2 = 0;
			}
		}

		if (isCollision(temp[i]->getEnemyRect(), _player->getComboAttackRc3()) &&
			_player->getPlayerZ() - 10 <= temp[i]->getEnemyRect().bottom &&
			_player->getPlayerZ() + 10 >= temp[i]->getEnemyRect().bottom)
		{
			_player->setPlayerAttackRectRemove3(0, 0, 0, 0);
			_enemyCollisionCount3++;
			if (_enemyCollisionCount3 % 1 == 0)
			{
				if (temp[i]->getEnemyDirection() == ENEMY_LEFT_GETHIT_2)
				{
					temp[i]->setEnemyDirection(ENEMY_LEFT_GETHIT_3);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_L_hit_3());
				}
				else if (temp[i]->getEnemyDirection() == ENEMY_RIGHT_GETHIT_3)
				{
					temp[i]->setEnemyDirection(ENEMY_RIGHT_GETHIT_2);
					temp[i]->setEnemyMotion(temp[i]->getEnemyMotion_R_hit_3());
				}
				temp[i]->setHitEnemyHP(1);
				_enemyCollisionCount3 = 0;
			}
		}
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

void collisionManager::player_collision()
{
	//에너미 공격이랑 플레이어 충돌

	vector<enemy*> temp = _enemyManager->getEnemiesVector();
	
	for (int i = 0; i < temp.size(); ++i)
	{
		if (isCollision(_player->getPlayerRect(), temp[i]->getEnemyAttackRect()) &&
			temp[i]->getEnemyRect().bottom - 50 <= _player->getPlayerZ() &&
			temp[i]->getEnemyRect().bottom + 50 >= _player->getPlayerZ())
		{

			temp[i]->setEnemyAttackRect(0, 0, 0, 0);
			_count++;
			if (_count % 20 == 0)
			{
				_player->setHitPlayerHP(1);
				_count = 0;
			}
			
		}
	}

}

