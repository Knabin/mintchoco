#include "stdafx.h"
#include "stageManager.h"
#include "npc.h"
#include "enemyManager.h"
#include "player.h"

stageManager::stageManager()
{
}

stageManager::~stageManager()
{
}

HRESULT stageManager::init()
{

	//체인 락 선언

	_ChainLeft._ChainLockImage = IMAGEMANAGER->addFrameImage("ChainLeft", "images/ui/chain_left.bmp", 1060, 808, 20, 1, true, RGB(127, 127, 127));
	_ChainLeft._x = CAMERA->getLeft() - 5;
	_ChainLeft._y = CAMERA->getTop();
	_ChainLeft._Mrc.setCenterPos(_ChainLeft._x, _ChainLeft._y);

	_ChainLeft._ChainLockImage->setFrameX(0);
	_ChainLeft._ChainLockImage->setFrameY(0);

	_ChainLeft._currentFrameX = 0;
	_ChainLeft._currentFrameY = 0;

	//=============================================================================================================================//

	_ChainRight._ChainLockImage = IMAGEMANAGER->addFrameImage("ChainRight", "images/ui/chain_right.bmp", 920, 808, 20, 1, true, RGB(127, 127, 127));
	_ChainRight._x = CAMERA->getLeft() + 1240;
	_ChainRight._y = CAMERA->getTop();
	_ChainRight._Mrc.setCenterPos(_ChainRight._x, _ChainRight._y);

	_ChainRight._ChainLockImage->setFrameX(0);
	_ChainRight._ChainLockImage->setFrameY(0);

	_ChainRight._currentFrameX = 0;
	_ChainRight._currentFrameY = 0;

	//=============================================================================================================================//

	_ChainTop._ChainLockImage = IMAGEMANAGER->addFrameImage("ChainTop", "images/ui/chain_top.bmp", 1440, 920, 1 , 20, true, RGB(127, 127, 127));
	_ChainTop._x = CAMERA->getLeft() - 5;
	_ChainTop._y = CAMERA->getTop() - 5;
	_ChainTop._Mrc.setCenterPos(_ChainTop._x, _ChainTop._y);

	_ChainTop._ChainLockImage->setFrameX(0);
	_ChainTop._ChainLockImage->setFrameY(0);

	_ChainTop._currentFrameX = 0;
	_ChainTop._currentFrameY = 0;

	//=============================================================================================================================//

	_ChainBottom._ChainLockImage = IMAGEMANAGER->addFrameImage("ChainBottom", "images/ui/chain_bottom.bmp", 1440, 1080, 1, 20, true, RGB(127, 127, 127));
	_ChainBottom._x = CAMERA->getLeft() - 5;
	_ChainBottom._y = CAMERA->getTop() + 475;
	_ChainBottom._Mrc.setCenterPos(_ChainBottom._x, _ChainBottom._y);

	_ChainBottom._ChainLockImage->setFrameX(0);
	_ChainBottom._ChainLockImage->setFrameY(0);

	_ChainBottom._currentFrameX = 0;
	_ChainBottom._currentFrameY = 0;

	//=============================================================================================================================//

	_Lock._ChainLockImage = IMAGEMANAGER->addFrameImage("Lock1", "images/ui/Stage_UI_Lock_Appear.bmp", 650, 116, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Lock2", "images/ui/Stage_UI_Lock_Damage1.bmp", 650, 116, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Lock3", "images/ui/Stage_UI_Lock_Damage2.bmp", 650, 116, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Lock4", "images/ui/Stage_UI_Lock_Disappear.bmp", 840, 130, 7, 1, true, RGB(255, 0, 255));
	_Lock._x = CAMERA->getLeft() + 585;
	_Lock._y = CAMERA->getTop() + 15;
	_Lock._rc = RectMakeCenter(_Lock._x, _Lock._y, _Lock._ChainLockImage->getWidth() / 7, _Lock._ChainLockImage->getHeight());

	_Lock._ChainLockImage->setFrameX(0);
	_Lock._ChainLockImage->setFrameY(0);

	_Lock._currentFrameX, _Lock._currentFrameY = 0;


	//=============================================================================================================================//

	//체인 락 구현에 필요한 bool값, 카운트, 상태 선언

	_LockChainCount = 0;
	_ClearCount = 0;
	_LockCount = 0;
	_ChainLockState = CLEAR;

	_LeftChainShake = false;
	_RightChainShake = false;
	_TopChainShake = false;
	_BottomChainShake = false;

	_LockDamage1 = false;
	_LockDamage2 = false;
	_LockClear = false;

	_PlayerStage1ChainLock = false;
	_PlayerStage2ChainLock = false;
	_PlayerStage3ChainLock = false;
	_PlayerStage4ChainLock = false;

	_ChainLockTime = 0;

	//=============================================================================================================================//

	//배틀스타트 백그라운드 선언

	_BattleStart._BattleStartImage = IMAGEMANAGER->addFrameImage("BattleStartScene", "images/ui/fight_start.bmp", 20480, 333, 16, 1, true, RGB(255, 0, 255));

	_BattleStart._currentFrameX = 0;
	_BattleStart._currentFrameY = 0;
	_BattleStart._FrameCount = 0;

	_BattleStart._BattleStartImage->setFrameX(0);
	_BattleStart._BattleStartImage->setFrameY(0);

	_PlayBattleStart = true;

	//-----------------------------------------------------------------------------------------------------------------------------//

	_Stage1 = new stage01;
	_Stage1->init();

	_Stage2 = new stage02;
	_Stage2->init();

	_Stage3 = new stage03;
	_Stage3->init();

	_Stage4 = new stage04;
	_Stage4->init();

	_BossStage = new bossStage;
	_BossStage->init();

	_currentPixelCollision = _Stage1->getPixel();

	_NowStage = S1;
	_NowStage1 = true;
	_NowStage2 = false;
	_NowStage3 = false;
	_NowStage4 = false;
	_NowBossStage = false;

	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;
	_bossIntroX = 1900;

	//-----------------------------------------------------------------------------------------------------------------------------//

	return S_OK;
}

void stageManager::release()
{
	_Stage1->release();
	_Stage2->release();
	_Stage3->release();
	_Stage4->release();
	_BossStage->release();

	SAFE_DELETE(_Stage1);
	SAFE_DELETE(_Stage2);
	SAFE_DELETE(_Stage3);
	SAFE_DELETE(_Stage4);
	SAFE_DELETE(_BossStage);

	ReleaseDC(_hWnd, getMemDC());
}

void stageManager::update()
{	
	_spawnCount++;

	// 너무 빠르거나 느리면 숫자 수정해 주세요
	if (_spawnCount % 1500 == 0)
	{
		_em->spawnEnemy(_NowStage);
		_spawnCount = 0;
	}


	for (int i = 0; i < _vNpcs.size(); ++i)
		_vNpcs[i]->update();


	if (_PlayBattleStart == true)
	{
		PlayBattleStartFrame();
	}

	//Stage4ChainLock();

	//Stage3ChainLock();

	//Stage2ChainLock();

	Stage1ChainLock();

	ChainLockMove();

}

void stageManager::render()
{
	NowStage();

	for (int i = 0; i < _vNpcs.size(); ++i)
		_vNpcs[i]->render();

	if (_PlayBattleStart == true)
	{
		PlayBattleStartBackGroundDraw();
	}

	//Stage4DoorLockDraw();
	
	//Stage3DoorLockDraw();

	//Stage2DoorLockDraw();

	Stage1DoorLockDraw();

	ChainLockFrameDraw();

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

		case S4:
		{
			_Stage4->render();
		}
		break;

		case BS:
		{
			_BossStage->render();
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
	_NowStage4 = false;
	_NowBossStage = false;
	_currentPixelCollision = _Stage1->getPixel();
	CAMERA->setBackWidth(_currentPixelCollision->getWidth());
	CAMERA->setBackHeight(_currentPixelCollision->getHeight());

	_vNpcs = _Stage1->getNPCs();
	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;

	if(!SOUNDMANAGER->isPlaySound("bgm classroom")) SOUNDMANAGER->playBGM("bgm classroom");
	SOUNDMANAGER->stopAll("bgm classroom");
}

void stageManager::Stage2Move()
{
	_NowStage = S2;
	_NowStage1 = false;
	_NowStage2 = true;
	_NowStage3 = false;
	_NowStage4 = false;
	_NowBossStage = false;
	_currentPixelCollision = _Stage2->getPixel();
	CAMERA->setBackWidth(_currentPixelCollision->getWidth());
	CAMERA->setBackHeight(_currentPixelCollision->getHeight());

	_vNpcs = _Stage2->getNPCs();
	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;

	if (!SOUNDMANAGER->isPlaySound("bgm hall")) SOUNDMANAGER->playBGM("bgm hall");
	SOUNDMANAGER->stopAll("bgm hall");
}

void stageManager::Stage3Move()
{
	_NowStage = S3;
	_NowStage1 = false;
	_NowStage2 = false;
	_NowStage3 = true;
	_NowStage4 = false;
	_NowBossStage = false;
	_currentPixelCollision = _Stage3->getPixel();
	CAMERA->setBackWidth(_currentPixelCollision->getWidth());
	CAMERA->setBackHeight(_currentPixelCollision->getHeight());

	_vNpcs = _Stage3->getNPCs();
	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;

	if (!SOUNDMANAGER->isPlaySound("bgm hall")) SOUNDMANAGER->playBGM("bgm hall");
	SOUNDMANAGER->stopAll("bgm hall");
}

void stageManager::Stage4Move()
{
	_NowStage = S4;
	_NowStage1 = false;
	_NowStage2 = false;
	_NowStage3 = false;
	_NowStage4 = true;
	_NowBossStage = false;
	_currentPixelCollision = _Stage4->getPixel();
	CAMERA->setBackWidth(_currentPixelCollision->getWidth());
	CAMERA->setBackHeight(_currentPixelCollision->getHeight());
	
	_vNpcs = _Stage4->getNPCs();
	_em->setEnemiesVector(_NowStage);

	_spawnCount = 0;

	if (!SOUNDMANAGER->isPlaySound("bgm chemi")) SOUNDMANAGER->playBGM("bgm chemi");
	SOUNDMANAGER->stopAll("bgm chemi");
}

void stageManager::BossStageMove()
{
	_NowStage = BS;
	_NowStage1 = false;
	_NowStage2 = false;
	_NowStage3 = false;
	_NowStage4 = false;
	_NowBossStage = true;
	_currentPixelCollision = _BossStage->getPixel();
	CAMERA->setBackWidth(_currentPixelCollision->getWidth());
	CAMERA->setBackHeight(_currentPixelCollision->getHeight());

	_vNpcs.clear();
	_em->setEnemiesVector(_NowStage);

	if (!SOUNDMANAGER->isPlaySound("bgm boss")) SOUNDMANAGER->playBGM("bgm boss");
	SOUNDMANAGER->stopAll("bgm boss");
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

void stageManager::Stage3_Stage4_Ok()
{
	_Stage3->Stage3RightDoorOpenDraw();
}

void stageManager::Stage3_Stage2_Ok()
{
	_Stage3->Stage3LeftDoorOpenDraw();
}

void stageManager::Stage4_BossStage_Ok()
{
	_Stage4->Stage4RightDoorOpenDraw();
}

void stageManager::Stage4_Stage3_Ok()
{
	_Stage4->Stage4LeftDoorOpenDraw();
}

void stageManager::BossStage_Stage4_Ok()
{
	_BossStage->BossStageLeftDoorOpenDraw();
}

void stageManager::ChainLockMove()
{
	_LockChainCount++;

	if (_PlayerStage1ChainLock == true || _PlayerStage2ChainLock == true || _PlayerStage3ChainLock == true || _PlayerStage4ChainLock == true)
	{
		if (_ChainLockState == CLEAR)
		{
			_ChainLockState = LOCKING;
			_LeftChainShake = true;
			_RightChainShake = true;
			_TopChainShake = true;
			_BottomChainShake = true;
		}

		if (_LockCount >= 14 && _ChainLockState == LOCKING)
		{
			_LockCount = 0;
			_ChainLockState = LOCK;
		}

		if (_ClearCount >= 500 && _ChainLockState == LOCK)
		{
			_ClearCount = 0;
			_ChainLockState = CLEARING;
		}

		if (_ChainTop._y <= CAMERA->getTop() - 55 && _ChainBottom._y >= CAMERA->getTop() + 525 && _ChainLockState == CLEARING)
		{
			_ChainLockState = CLEAR;
		}

		switch (_ChainLockState)
		{
			case CLEAR:
			{
	
			}
			break;

			case LOCKING:
			{
				_ChainLeft._x = CAMERA->getLeft() - 5;
				_ChainLeft._y = CAMERA->getTop();
				_ChainLeft._Mrc.setCenterPos(_ChainLeft._x, _ChainLeft._y);

				_ChainRight._x = CAMERA->getLeft() + 1240;
				_ChainRight._y = CAMERA->getTop();
				_ChainRight._Mrc.setCenterPos(_ChainRight._x, _ChainRight._y);

				_ChainTop._x = CAMERA->getLeft() - 5;
				_ChainTop._y = CAMERA->getTop() - 5;
				_ChainTop._Mrc.setLeftTopPos(_ChainTop._x, _ChainTop._y);

				_ChainBottom._x = CAMERA->getLeft() - 5;
				_ChainBottom._y = CAMERA->getTop() + 475;
				_ChainBottom._Mrc.setCenterPos(_ChainBottom._x, _ChainBottom._y);

				_Lock._x = CAMERA->getLeft() + 585;
				_Lock._y = CAMERA->getTop() + 15;
				_Lock._ChainLockImage->setFrameX(0);
				_Lock._ChainLockImage->setFrameY(0);

				_LockCount++;

				if (_LockCount < 14)
				{
					IMAGEMANAGER->findImage("ChainLeft")->setFrameY(0);

					if (_LockChainCount % 1 == 0)
					{
						if (_ChainLeft._currentFrameX > IMAGEMANAGER->findImage("ChainLeft")->getMaxFrameX()) _ChainLeft._currentFrameY = 0;
						IMAGEMANAGER->findImage("ChainLeft")->setFrameX(_ChainLeft._currentFrameX);
						_ChainLeft._currentFrameX++;
						_LockChainCount = 0;

					}

					IMAGEMANAGER->findImage("ChainRight")->setFrameY(0);

					if (_LockChainCount % 1 == 0)
					{
						if (_ChainRight._currentFrameX > IMAGEMANAGER->findImage("ChainRight")->getMaxFrameX()) _ChainRight._currentFrameY = 0;
						IMAGEMANAGER->findImage("ChainRight")->setFrameX(_ChainRight._currentFrameX);
						_ChainRight._currentFrameX++;
						_LockChainCount = 0;

					}

					IMAGEMANAGER->findImage("ChainTop")->setFrameX(0);

					if (_LockChainCount % 1 == 0)
					{
						if (_ChainTop._currentFrameY > IMAGEMANAGER->findImage("ChainTop")->getMaxFrameY()) _ChainTop._currentFrameX = 0;
						IMAGEMANAGER->findImage("ChainTop")->setFrameY(_ChainTop._currentFrameY);
						_ChainTop._currentFrameY++;
						_LockChainCount = 0;
					}

					IMAGEMANAGER->findImage("ChainBottom")->setFrameX(0);

					if (_LockChainCount % 1 == 0)
					{
						if (_ChainBottom._currentFrameY > IMAGEMANAGER->findImage("ChainBottom")->getMaxFrameY()) _ChainBottom._currentFrameX = 0;
						IMAGEMANAGER->findImage("ChainBottom")->setFrameY(_ChainBottom._currentFrameY);
						_ChainBottom._currentFrameY++;
						_LockChainCount = 0;
					}

					IMAGEMANAGER->findImage("Lock1")->setFrameY(0);

					if (_LockChainCount % 2 == 0)
					{
						if (_Lock._currentFrameX > IMAGEMANAGER->findImage("Lock1")->getMaxFrameX()) _Lock._currentFrameX = 0;
						IMAGEMANAGER->findImage("Lock1")->setFrameX(_Lock._currentFrameX);
						_Lock._currentFrameX++;
						_LockChainCount = 0;

					}
				}

			}
			break;

			case LOCK:
			{
				_ClearCount++;

				if (_ClearCount >= 100)
				{
					_LockDamage1 = true;
					_LockDamage2 = false;
					_LockClear = false;
					IMAGEMANAGER->findImage("Lock2")->setFrameX(6);
				}

				if (_ClearCount >= 200)
				{

					IMAGEMANAGER->findImage("Lock2")->setFrameY(0);

					if (_LockChainCount % 5 == 0)
					{
						if (_Lock._currentFrameX > IMAGEMANAGER->findImage("Lock2")->getMaxFrameX()) _Lock._currentFrameX = 0;
						IMAGEMANAGER->findImage("Lock2")->setFrameX(_Lock._currentFrameX);
						_Lock._currentFrameX++;
						_LockChainCount = 0;
					}
				}

				if (_ClearCount >= 300)
				{
					_LockDamage1 = false;
					_LockDamage2 = true;
					_LockClear = false;
					IMAGEMANAGER->findImage("Lock3")->setFrameX(6);
				}

				if (_ClearCount >= 400)
				{
					IMAGEMANAGER->findImage("Lock3")->setFrameY(0);

					if (_LockChainCount % 5 == 0)
					{
						if (_Lock._currentFrameX > IMAGEMANAGER->findImage("Lock3")->getMaxFrameX()) _Lock._currentFrameX = 0;
						IMAGEMANAGER->findImage("Lock3")->setFrameX(_Lock._currentFrameX);
						_Lock._currentFrameX++;
						_LockChainCount = 0;

					}
				}

			}
			break;

			case CLEARING:
			{
				_ChainLeft._x -= 2.0f;
				_ChainRight._x += 2.0f;
				_ChainTop._y -= 2.0f;
				_ChainBottom._y += 2.0f;
				_LockDamage1 = false;
				_LockDamage2 = false;
				_LockClear = true;

				IMAGEMANAGER->findImage("Lock4")->setFrameY(0);

				if (_LockChainCount % 8 == 0)
				{
					IMAGEMANAGER->findImage("Lock4")->setFrameX(_Lock._currentFrameX);
					_Lock._currentFrameX++;
					_LockChainCount = 0;
				}
				if (_Lock._currentFrameX > IMAGEMANAGER->findImage("Lock4")->getMaxFrameX())
				{
					_LockDamage1 = false;
					_LockDamage2 = false;
					_LockClear = false;
				}
			}
			break;
		}
	}

	if (_PlayerStage1ChainLock == false && _PlayerStage2ChainLock == false && _PlayerStage3ChainLock == false && _PlayerStage4ChainLock == false)
	{
		_ClearCount = 0;
		_LockChainCount = 0;
		_ClearCount = 0;
		_LockCount = 0;
		_ChainLockState = CLEAR;

		_LeftChainShake = false;
		_RightChainShake = false;
		_TopChainShake = false;
		_BottomChainShake = false;

		_LockDamage1 = false;
		_LockDamage2 = false;
		_LockClear = false;
	}

}

void stageManager::ChainLockFrameDraw()
{
	if (_PlayerStage1ChainLock == true || _PlayerStage2ChainLock == true || _PlayerStage3ChainLock == true || _PlayerStage4ChainLock == true)
	{
		if (_ChainLockState == LOCKING)
		{
			IMAGEMANAGER->findImage("ChainLeft")->frameRender(getMemDC(), _ChainLeft._x, _ChainLeft._y);

			IMAGEMANAGER->findImage("ChainRight")->frameRender(getMemDC(), _ChainRight._x, _ChainRight._y);

			IMAGEMANAGER->findImage("ChainTop")->frameRender(getMemDC(), _ChainTop._x, _ChainTop._y);

			IMAGEMANAGER->findImage("ChainBottom")->frameRender(getMemDC(), _ChainBottom._x, _ChainBottom._y);

			IMAGEMANAGER->findImage("Lock1")->frameRender(getMemDC(), _Lock._x, _Lock._y);
		}

		if (_ChainLockState == LOCK)
		{
			IMAGEMANAGER->findImage("ChainLeft")->frameRender(getMemDC(), _ChainLeft._x, _ChainLeft._y);

			IMAGEMANAGER->findImage("ChainRight")->frameRender(getMemDC(), _ChainRight._x, _ChainRight._y);

			IMAGEMANAGER->findImage("ChainTop")->frameRender(getMemDC(), _ChainTop._x, _ChainTop._y);

			IMAGEMANAGER->findImage("ChainBottom")->frameRender(getMemDC(), _ChainBottom._x, _ChainBottom._y);
		}

		if (_ChainLockState == LOCK && _LockDamage1 == false && _LockDamage2 == false)
		{
			IMAGEMANAGER->findImage("Lock1")->frameRender(getMemDC(), _Lock._x + 4, _Lock._y);
		}
		if (_ChainLockState == LOCK && _LockDamage1 == true)
		{
			IMAGEMANAGER->findImage("Lock2")->frameRender(getMemDC(), _Lock._x, _Lock._y);
		}
		if (_ChainLockState == LOCK && _LockDamage2 == true)
		{
			IMAGEMANAGER->findImage("Lock3")->frameRender(getMemDC(), _Lock._x, _Lock._y);
		}

		if (_ChainLockState == CLEARING)
		{
			IMAGEMANAGER->findImage("ChainLeft")->frameRender(getMemDC(), _ChainLeft._x, _ChainLeft._y);

			IMAGEMANAGER->findImage("ChainRight")->frameRender(getMemDC(), _ChainRight._x, _ChainRight._y);

			IMAGEMANAGER->findImage("ChainTop")->frameRender(getMemDC(), _ChainTop._x, _ChainTop._y);

			IMAGEMANAGER->findImage("ChainBottom")->frameRender(getMemDC(), _ChainBottom._x, _ChainBottom._y);

			IMAGEMANAGER->findImage("Lock4")->frameRender(getMemDC(), _Lock._x - 12, _Lock._y + 5);
		}
	}
}

void stageManager::Stage1ChainLock()
{
	if (_NowStage == S1)
	{
		if (_player->getPlayerRect().right > WINSIZEX)
		{
			_ChainLockTime++;
			CAMERA->cameraFixed();
			_PlayerStage1ChainLock = true;

			_Stage1->getRect().setCenterPos(7777, 7777);	
		}

		if (_ChainLockTime > 530)
		{
			CAMERA->setIsFixed(false);
			_PlayerStage1ChainLock = false;

			_Stage1->getRect().setCenterPos(WINSIZEX + 155 , WINSIZEY / 2 - 125);
		}
	}
}

void stageManager::Stage1DoorLockDraw()
{
	if (_PlayerStage1ChainLock == true)
	{
		_Stage1->Stage1RightDoorLockDraw();
	}
}

void stageManager::Stage2ChainLock()
{
	if (_NowStage == S2)
	{
		if (_player->getPlayerRect().right > WINSIZEX - 350)
		{
			CAMERA->cameraFixed();
			_PlayerStage2ChainLock = true;

			_Stage2->getRect().setCenterPos(7777, 7777);
			_Stage2->getRect2().setCenterPos(7777, 7777);
		}

		else
		{
			CAMERA->setIsFixed(false);
			_PlayerStage2ChainLock = false;

			_Stage2->getRect().setCenterPos(WINSIZEX - 300, WINSIZEY / 2 - 30);
			_Stage2->getRect2().setCenterPos(245, WINSIZEY / 2 + 225);

		}
	}
}

void stageManager::Stage2DoorLockDraw()
{
	if (_PlayerStage2ChainLock == true)
	{
		_Stage2->Stage2RightDoorLockDraw();
		_Stage2->Stage2LeftDoorLockDraw();
	}
}

void stageManager::Stage3ChainLock()
{
	if (_NowStage == S3)
	{
		if (_player->getPlayerRect().right > WINSIZEX + 450)
		{
			CAMERA->cameraFixed();
			_PlayerStage3ChainLock = true;

			_Stage3->getRect().setCenterPos(7777, 7777);
			_Stage3->getRect2().setCenterPos(7777, 7777);
		}

		else
		{
			CAMERA->setIsFixed(false);
			_PlayerStage3ChainLock = false;

			_Stage3->getRect().setCenterPos(WINSIZEX, WINSIZEY / 2 - 10);
			_Stage3->getRect2().setCenterPos(WINSIZEX + 850, WINSIZEY / 2 + 165);

		}
	}
}

void stageManager::Stage3DoorLockDraw()
{
	if (_PlayerStage3ChainLock == true)
	{
		_Stage3->Stage3RightDoorLockDraw();
		_Stage3->Stage3LeftDoorLockDraw();
	}
}

void stageManager::Stage4ChainLock()
{
	if (_NowStage == S4)
	{
		if (_player->getPlayerRect().right > WINSIZEX + 300)
		{
			CAMERA->cameraFixed();
			_PlayerStage4ChainLock = true;

			_Stage4->getRect().setCenterPos(7777, 7777);
			_Stage4->getRect2().setCenterPos(7777, 7777);
		}

		else
		{
			CAMERA->setIsFixed(false);
			_PlayerStage4ChainLock = false;

			_Stage4->getRect().setCenterPos(WINSIZEX / 2 + 1200, WINSIZEY / 2 + 200);
			_Stage4->getRect2().setCenterPos(WINSIZEX / 2 - 390, WINSIZEY / 2 + 200);

		}
	}
}

void stageManager::Stage4DoorLockDraw()
{
	if (_PlayerStage4ChainLock == true)
	{
		_Stage4->Stage4RightDoorLockDraw();
		_Stage4->Stage4LeftDoorLockDraw();
	}
}

void stageManager::PlayBattleStartFrame()
{
	_BattleStart._FrameCount++;

	IMAGEMANAGER->findImage("BattleStartScene")->setFrameY(0);

	if (_BattleStart._FrameCount % 5 == 0)
	{
		IMAGEMANAGER->findImage("BattleStartScene")->setFrameX(_BattleStart._currentFrameX);
		_BattleStart._currentFrameX++;
		_BattleStart._FrameCount = 0;
	}
	if (_BattleStart._currentFrameX > IMAGEMANAGER->findImage("BattleStartScene")->getMaxFrameX())
	{
		_PlayBattleStart = false;
	}
}

void stageManager::PlayBattleStartBackGroundDraw()
{
	IMAGEMANAGER->findImage("BattleStartScene")->frameRender(getMemDC(), CAMERA->getLeft(), CAMERA->getTop());
}