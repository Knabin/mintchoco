#include "stdafx.h"
#include "enemy.h"

enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init(string imageName, float x, float y, float speed)
{
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{		
	_enemyMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

	distance = getDistance(_x, _y, _playerX, _playerY);
	angle = getAngle(_x, _y, _playerX, _playerY);

	if (distance > 165)
	{
		_x += cosf(angle) * _speed;
		_y -= sinf(angle) * _speed;
	}

	// ==============================		에너미 움직임 및 공격      ==============================//
	if (_x < _playerX)
	{
		_direction = ENEMY_RIGHT_MOVE;
		_enemyMotion = _enemyMotion_R;

		if (distance < 170)
		{
			switch (_random)
			{
			case 0:
				_direction = ENEMY_RIGHT_ATTACK;
				_enemyMotion = _enemyMotion_R_A;
				if (_enemyMotion->isPlay() == false)
				{
					_enemyMotion_R_A->start();
					_random = RND->getInt(3);
				}
				break;
			case 1:
				_direction = ENEMY_RIGHT_COMBO1;
				_enemyMotion = _enemyMotion_R_COMBO1;
				if (_enemyMotion->isPlay() == false) 
				{
					_enemyMotion_R_COMBO1->start();
					_random = RND->getInt(3);
				}
				break;
			case 2:
				_direction = ENEMY_RIGHT_COMBO2;
				_enemyMotion = _enemyMotion_R_COMBO2;
				if (_enemyMotion->isPlay() == false) 
				{
					_enemyMotion_R_COMBO2->start();
					_random = RND->getInt(3);
				}
				break;
			}
		}
		else
		{
			if (_enemyMotion->isPlay() == false)	_enemyMotion_R->start();
		}
	}
	else if (_x > _playerX + 150)
	{
		_direction = ENEMY_LEFT_MOVE;
		_enemyMotion = _enemyMotion_L;
		

		if (distance < 170)
		{
			switch (_random)
			{
			case 0:
				_direction = ENEMY_LEFT_ATTACK;
				_enemyMotion = _enemyMotion_L_A;
				if (_enemyMotion->isPlay() == false)
				{
					_enemyMotion_L_A->start();
					_random = RND->getInt(3);
				}
				break;
			case 1:
				_direction = ENEMY_LEFT_COMBO1;
				_enemyMotion = _enemyMotion_L_COMBO1;
				if (_enemyMotion->isPlay() == false)
				{
					_enemyMotion_L_COMBO1->start();
					_random = RND->getInt(3);
				}
				break;
			case 2:
				_direction = ENEMY_LEFT_COMBO2;
				_enemyMotion = _enemyMotion_L_COMBO2;
				if (_enemyMotion->isPlay() == false)
				{
					_enemyMotion_L_COMBO2->start();
					_random = RND->getInt(3);
				}
				break;
			}
		}
		else
		{
			if (_enemyMotion->isPlay() == false)	_enemyMotion_L->start();
		}

	}
	// ==============================		에너미 움직임 및 공격      ==============================//
	
	_rc.setCenterPos(_x, _y);

}

void enemy::render()
{
	_enemyImg->aniRender(getMemDC(),_rc.left,_rc.top,_enemyMotion);
}

void enemy::setPlayerPos(float x, float y)
{
	_playerX = x;
	_playerY = y;
}

