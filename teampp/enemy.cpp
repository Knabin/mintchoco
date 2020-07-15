#include "stdafx.h"
#include "enemy.h"

enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init()
{
	switch (_cheerleaderDirection)
	{
	case IDLE:
		IMAGEMANAGER->addFrameImage("치어리더아이들", "CheerLeader_Idle.bmp", 2034, 432, 12, 2, true, RGB(255, 0, 255));
		break;
	case WALK:
		IMAGEMANAGER->addFrameImage("치어리더무브", "CheerLeader_Walk.bmp", 2736, 438, 12, 2, true, RGB(255, 0, 255));
		break;

	}
	
	_cheerleaderDirection = IDLE;
	_enemyDirection = ENEMY_LEFT_MOVE;

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_rc = RectMakeCenter(_x, _y, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());

	int leftIdle[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("enemyLeftIdle", "치어리더아이들", leftIdle,12,8,true);

	int rightIdle[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("enemyRightIdle", "치어리더아이들", rightIdle, 12, 8, true);

	int leftMove[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("enemyLeftMove", "치어리더무브", leftMove, 12, 8, true);

	int rightMove[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("enemyRightMove", "치어리더무브", rightMove, 12, 8, true);

	_enemyMotion = KEYANIMANAGER->findAnimation("enemyLeftMove");

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{		
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_enemyDirection = ENEMY_RIGHT_MOVE;
		_enemyMotion = KEYANIMANAGER->findAnimation("enemyRightMove");
		_enemyMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_enemyDirection = ENEMY_LEFT_MOVE;
		_enemyMotion = KEYANIMANAGER->findAnimation("enemyLeftMove");
		_enemyMotion->start();
	}

	if ((_rc.left + _rc.right) / 2 <= 300)
	{
		_cheerleaderDirection = IDLE;
		_enemyDirection = ENEMY_RIGHT_MOVE;
	}
	if ((_rc.left + _rc.right) / 2 >= WINSIZEX - 300)
	{
		_cheerleaderDirection = IDLE;
		_enemyDirection = ENEMY_LEFT_MOVE;
	}

	switch (_enemyDirection)
	{
	case ENEMY_RIGHT_IDLE:
		break;
	case ENEMY_LEFT_MOVE:
		_x -= ENEMYSPEED;
		break;
	case ENEMY_RIGHT_MOVE:
		_x += ENEMYSPEED;
		break;
	}

	_rc = RectMakeCenter(_x, _y, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	KEYANIMANAGER->update();
}

void enemy::render()
{
	_enemyImg->aniRender(getMemDC(), _rc.left, _rc.top, _enemyMotion);
	//Rectangle(getMemDC(), _rc);
}  
