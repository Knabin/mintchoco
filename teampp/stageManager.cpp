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
	_ChainBottom._y = CAMERA->getTop() + 520;
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

	_PlayerStage1ChainLockAlready = false;
	_PlayerStage2ChainLockAlready = false;
	_PlayerStage3ChainLockAlready = false;
	_PlayerStage4ChainLockAlready = false;

	_ChainLockTime = 0;

	//=============================================================================================================================//

	//배틀스타트 백그라운드 선언

	_BattleStart._BattleStartImage = IMAGEMANAGER->addFrameImage("BattleStartScene", "images/ui/fight_start.bmp", 20480, 333, 16, 1, true, RGB(255, 0, 255));

	_BattleStart._currentFrameX = 0;
	_BattleStart._currentFrameY = 0;
	_BattleStart._FrameCount = 0;

	_BattleStart._BattleStartImage->setFrameX(0);
	_BattleStart._BattleStartImage->setFrameY(0);

	_PlayBattleStart = false;

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

	_enemyCount = 0;

	SOUNDMANAGER->addSound("chain on", "sounds/menu/UI_chains_appear.wav", false, false);
	SOUNDMANAGER->addSound("chain break", "sounds/menu/UI_chains_break.wav", false, false);

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
	if (_spawnCount % 1300 == 0)
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

	Stage4ChainLock();

	Stage3ChainLock();

	Stage2ChainLock();

	Stage1ChainLock();

	ChainLockMove();

}

void stageManager::render()
{
	NowStage();

	for (int i = 0; i < _vNpcs.size(); ++i)
		_vNpcs[i]->render();


	Stage4DoorLockDraw();
	
	Stage3DoorLockDraw();

	Stage2DoorLockDraw();

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
	_enemyCount = 0;

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
	_enemyCount = 0;

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
	_enemyCount = 0;

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
	_enemyCount = 0;

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
	_em->removeEnemies();

	if (!SOUNDMANAGER->isPlaySound("bgm chemi")) SOUNDMANAGER->playBGM("bgm chemi");
	SOUNDMANAGER->stopAll("bgm chemi");
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
			SOUNDMANAGER->play("chain on");
		}

		if (_LockCount >= 14 && _ChainLockState == LOCKING)
		{
			_LockCount = 0;
			_ChainLockState = LOCK;
		}

		if (_enemyCount >= 4 && _ChainLockState == LOCK)
		{
			_ClearCount = 0;
			_ChainLockState = CLEARING;
		}

		if (_ChainTop._y <= CAMERA->getTop() - 55 && _ChainBottom._y >= CAMERA->getTop() + 525 && _ChainLockState == CLEARING)
		{
			_ChainLockState = CLEAR;
			SOUNDMANAGER->play("chain break");
		}

		switch (_ChainLockState)
		{
			case CLEAR:
			{
				_PlayerStage1ChainLock = false;
				_PlayerStage2ChainLock = false;
				_PlayerStage3ChainLock = false;
				_PlayerStage4ChainLock = false;
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
				_ChainBottom._y = CAMERA->getTop() + 520;
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

				//if (_ClearCount >= 100)
				if(_enemyCount == 0)
				{
					_LockDamage1 = true;
					_LockDamage2 = false;
					_LockClear = false;
					IMAGEMANAGER->findImage("Lock2")->setFrameX(6);
				}

				//if (_ClearCount >= 200)
				if(_enemyCount == 1)
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

				//if (_ClearCount >= 300)
				if(_enemyCount == 2)
				{
					_LockDamage1 = false;
					_LockDamage2 = true;
					_LockClear = false;
					IMAGEMANAGER->findImage("Lock3")->setFrameX(6);
				}

				//if (_ClearCount >= 400)
				if(_enemyCount >= 3)
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
					CAMERA->setIsReturn(true);
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

		CAMERA->setIsFixed(false);
	}

}

void stageManager::ChainLockFrameDraw()
{
	if (_PlayerStage1ChainLock == true || _PlayerStage2ChainLock == true || _PlayerStage3ChainLock == true || _PlayerStage4ChainLock == true)
	{
		if (_ChainLockState == LOCKING)
		{
			ZORDER->pushObject(getMemDC(), "ChainLeft", IMAGEMANAGER->findImage("ChainLeft")->getFrameX(), IMAGEMANAGER->findImage("ChainLeft")->getFrameY(), 2, _ChainLeft._x + IMAGEMANAGER->findImage("ChainLeft")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainLeft._y + IMAGEMANAGER->findImage("ChainLeft")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainRight", IMAGEMANAGER->findImage("ChainRight")->getFrameX(), IMAGEMANAGER->findImage("ChainRight")->getFrameY(), 2, _ChainRight._x + IMAGEMANAGER->findImage("ChainRight")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainRight._y + IMAGEMANAGER->findImage("ChainRight")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainTop", IMAGEMANAGER->findImage("ChainTop")->getFrameX(), IMAGEMANAGER->findImage("ChainTop")->getFrameY(), 2, _ChainTop._x + IMAGEMANAGER->findImage("ChainTop")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainTop._y + IMAGEMANAGER->findImage("ChainTop")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainBottom", IMAGEMANAGER->findImage("ChainBottom")->getFrameX(), IMAGEMANAGER->findImage("ChainBottom")->getFrameY(), 2, _ChainBottom._x + IMAGEMANAGER->findImage("ChainBottom")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainBottom._y + IMAGEMANAGER->findImage("ChainBottom")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "Lock1", IMAGEMANAGER->findImage("Lock1")->getFrameX(), IMAGEMANAGER->findImage("Lock1")->getFrameY(), 2, _Lock._x + IMAGEMANAGER->findImage("Lock1")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _Lock._y + IMAGEMANAGER->findImage("Lock1")->getFrameHeight());
		}

		if (_ChainLockState == LOCK)
		{
			ZORDER->pushObject(getMemDC(), "ChainLeft", IMAGEMANAGER->findImage("ChainLeft")->getFrameX(), IMAGEMANAGER->findImage("ChainLeft")->getFrameY(), 2, _ChainLeft._x + IMAGEMANAGER->findImage("ChainLeft")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainLeft._y + IMAGEMANAGER->findImage("ChainLeft")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainRight", IMAGEMANAGER->findImage("ChainRight")->getFrameX(), IMAGEMANAGER->findImage("ChainRight")->getFrameY(), 2, _ChainRight._x + IMAGEMANAGER->findImage("ChainRight")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainRight._y + IMAGEMANAGER->findImage("ChainRight")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainTop", IMAGEMANAGER->findImage("ChainTop")->getFrameX(), IMAGEMANAGER->findImage("ChainTop")->getFrameY(), 2, _ChainTop._x + IMAGEMANAGER->findImage("ChainTop")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainTop._y + IMAGEMANAGER->findImage("ChainTop")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainBottom", IMAGEMANAGER->findImage("ChainBottom")->getFrameX(), IMAGEMANAGER->findImage("ChainBottom")->getFrameY(), 2, _ChainBottom._x + IMAGEMANAGER->findImage("ChainBottom")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainBottom._y + IMAGEMANAGER->findImage("ChainBottom")->getFrameHeight());
		}

		if (_ChainLockState == LOCK && _LockDamage1 == false && _LockDamage2 == false)
		{
			ZORDER->pushObject(getMemDC(), "Lock1", IMAGEMANAGER->findImage("Lock1")->getFrameX(), IMAGEMANAGER->findImage("Lock1")->getFrameY(), 2, _Lock._x + IMAGEMANAGER->findImage("Lock1")->getFrameWidth() / 2 + 4, WINSIZEY, WINSIZEY + _Lock._y + IMAGEMANAGER->findImage("Lock1")->getFrameHeight());
		}
		if (_ChainLockState == LOCK && _LockDamage1 == true)
		{
			ZORDER->pushObject(getMemDC(), "Lock2", IMAGEMANAGER->findImage("Lock2")->getFrameX(), IMAGEMANAGER->findImage("Lock2")->getFrameY(), 2, _Lock._x + IMAGEMANAGER->findImage("Lock2")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _Lock._y + IMAGEMANAGER->findImage("Lock2")->getFrameHeight());
		}
		if (_ChainLockState == LOCK && _LockDamage2 == true)
		{
			ZORDER->pushObject(getMemDC(), "Lock3", IMAGEMANAGER->findImage("Lock3")->getFrameX(), IMAGEMANAGER->findImage("Lock3")->getFrameY(), 2, _Lock._x + IMAGEMANAGER->findImage("Lock3")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _Lock._y + IMAGEMANAGER->findImage("Lock3")->getFrameHeight());
		}

		if (_ChainLockState == CLEARING)
		{
			ZORDER->pushObject(getMemDC(), "ChainLeft", IMAGEMANAGER->findImage("ChainLeft")->getFrameX(), IMAGEMANAGER->findImage("ChainLeft")->getFrameY(), 2, _ChainLeft._x + IMAGEMANAGER->findImage("ChainLeft")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainLeft._y + IMAGEMANAGER->findImage("ChainLeft")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainRight", IMAGEMANAGER->findImage("ChainRight")->getFrameX(), IMAGEMANAGER->findImage("ChainRight")->getFrameY(), 2, _ChainRight._x + IMAGEMANAGER->findImage("ChainRight")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainRight._y + IMAGEMANAGER->findImage("ChainRight")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainTop", IMAGEMANAGER->findImage("ChainTop")->getFrameX(), IMAGEMANAGER->findImage("ChainTop")->getFrameY(), 2, _ChainTop._x + IMAGEMANAGER->findImage("ChainTop")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainTop._y + IMAGEMANAGER->findImage("ChainTop")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "ChainBottom", IMAGEMANAGER->findImage("ChainBottom")->getFrameX(), IMAGEMANAGER->findImage("ChainBottom")->getFrameY(), 2, _ChainBottom._x + IMAGEMANAGER->findImage("ChainBottom")->getFrameWidth() / 2, WINSIZEY, WINSIZEY + _ChainBottom._y + IMAGEMANAGER->findImage("ChainBottom")->getFrameHeight());

			ZORDER->pushObject(getMemDC(), "Lock4", IMAGEMANAGER->findImage("Lock4")->getFrameX(), IMAGEMANAGER->findImage("Lock4")->getFrameY(), 2, _Lock._x + IMAGEMANAGER->findImage("Lock4")->getFrameWidth() / 2 - 12, WINSIZEY, WINSIZEY + _Lock._y + IMAGEMANAGER->findImage("Lock4")->getFrameHeight() + 5);
		}
	}
}

void stageManager::Stage1ChainLock()
{
	if (_NowStage == S1)
	{
		if (_player->getPlayerRect().right > WINSIZEX && !_PlayerStage1ChainLock && !_PlayerStage1ChainLockAlready)
		{
			_ChainLockTime++;
			CAMERA->cameraFixed();
			_PlayerStage1ChainLock = true;

			_Stage1->getRect().setCenterPos(7777, 7777);	
			_enemyCount = 0;
		}

		if (_enemyCount >= 4)
		{
			_PlayerStage1ChainLockAlready = true;
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
		if (_player->getPlayerRect().right > WINSIZEX - 350 && !_PlayerStage2ChainLock && !_PlayerStage2ChainLockAlready)
		{
			CAMERA->cameraFixed();
			_PlayerStage2ChainLock = true;

			_Stage2->getRect().setCenterPos(7777, 7777);
			_Stage2->getRect2().setCenterPos(7777, 7777);
			_enemyCount = 0;
		}

		if (_enemyCount >= 4)
		{
			CAMERA->setIsFixed(false);
			_PlayerStage2ChainLock = false;
			_PlayerStage2ChainLockAlready = true;

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
		if (_player->getPlayerRect().right > WINSIZEX + 450 && !_PlayerStage3ChainLock && !_PlayerStage3ChainLockAlready)
		{
			CAMERA->cameraFixed();
			_PlayerStage3ChainLock = true;

			_Stage3->getRect().setCenterPos(7777, 7777);
			_Stage3->getRect2().setCenterPos(7777, 7777);
			_enemyCount = 0;
		}

		if (_enemyCount >= 4)
		{
			CAMERA->setIsFixed(false);
			_PlayerStage3ChainLock = false;
			_PlayerStage3ChainLockAlready = true;

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
		if (_player->getPlayerRect().right > WINSIZEX + 300 && !_PlayerStage4ChainLock && !_PlayerStage4ChainLockAlready)
		{
			CAMERA->cameraFixed();
			_PlayerStage4ChainLock = true;

			_Stage4->getRect().setCenterPos(7777, 7777);
			_Stage4->getRect2().setCenterPos(7777, 7777);
			_enemyCount = 0;
		}

		if (_enemyCount >= 4)
		{
			CAMERA->setIsFixed(false);
			_PlayerStage4ChainLock = false;
			_PlayerStage4ChainLockAlready = true;

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

void stageManager::PlayBattleStartBackGroundDraw(HDC hdc)
{
	IMAGEMANAGER->findImage("BattleStartScene")->frameRender(hdc, 50, 100);
}