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
	_hp = 70;
	_isStart = false;

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{	
	if (distance > 165 && !_isStart)
	{
		if (_playerX > _x)
		{
			_enemyMotion = _enemyMotion_R;
			_direction = ENEMY_RIGHT_MOVE;
		}
		else
		{
			_enemyMotion = _enemyMotion_L;
			_direction = ENEMY_LEFT_MOVE;
		}

		_isStart = true;
	}

	_isAttackCount++;
	_isStunCount++;
	_enemyMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

	distance = getDistance(_x, _y, _playerX, _playerY);
	angle = getAngle(_x, _y, _playerX, _playerY);

	if (distance > 165 && (_direction == ENEMY_RIGHT_IDLE || _direction == ENEMY_LEFT_IDLE))
	{
		if (_playerX > _x)
		{
			_enemyMotion = _enemyMotion_R;
			_direction = ENEMY_RIGHT_MOVE;
		}
		else
		{
			_enemyMotion = _enemyMotion_L;
			_direction = ENEMY_LEFT_MOVE;
		}
		
	}

	if (distance > 165 && (_direction == ENEMY_RIGHT_MOVE || _direction == ENEMY_LEFT_MOVE) && (_direction != ENEMY_LEFT_SUBMOTION && _direction != ENEMY_RIGHT_SUBMOTION))
	{
		_x += cosf(angle) * _speed;
		_y -= sinf(angle) * _speed;
	}

	// ==============================		에너미 움직임 및 공격      ==============================//
	if (_direction != ENEMY_LEFT_SUBMOTION && _direction != ENEMY_RIGHT_SUBMOTION)
	{
		if (_x < _playerX)
		{
			if (_enemyMotion->isPlay() == false)
			{
				_enemyMotion = _enemyMotion_R_IDLE;
				_direction = ENEMY_RIGHT_IDLE;
			}
		
			//if (_hp < 30)
			//{
			//	_direction = ENEMY_RIGHT_STUN;
			//	if (_isStunCount % 40 == 0)
			//	{
			//		_direction = ENEMY_RIGHT_MOVE;
			//	}
			//	_isStunCount = 0;
			//}

			if (_isAttackCount > 75)
			{
				//_enemyMotion = _enemyMotion_R;
				//_direction = ENEMY_RIGHT_MOVE;
				if (distance < 170)
				{
					switch (_random)
					{
					case 0:
						_direction = ENEMY_RIGHT_ATTACK;
						_enemyMotion = _enemyMotion_R_A;
						if (_enemyMotion->isPlay() == false)
						{
							_enemyMotion->start();
							_random = RND->getInt(4);
							_isAttackCount = 0;
						}
						break;
					case 1:
						_direction = ENEMY_RIGHT_COMBO1;
						_enemyMotion = _enemyMotion_R_COMBO1;
						if (_enemyMotion->isPlay() == false)
						{
							_enemyMotion->start();
							_random = RND->getInt(4);
							_isAttackCount = 0;
						}
						break;
					case 2:
						_direction = ENEMY_RIGHT_COMBO2;
						_enemyMotion = _enemyMotion_R_COMBO2;
						if (_enemyMotion->isPlay() == false)
						{
							_enemyMotion->start();
							_random = RND->getInt(4);
							_isAttackCount = 0;
						}
						break;
					case 3:
						_direction = ENEMY_RIGHT_SUBMOTION;
						_enemyMotion = _enemyMotion_R_submotion;
				
						break;
					}
				}
			}

			if (_enemyMotion->isPlay() == false)	_enemyMotion->start();

		}
		else
		{
			if (_enemyMotion->isPlay() == false)
			{
				_enemyMotion = _enemyMotion_L_IDLE;
				_direction = ENEMY_LEFT_IDLE;
			}

			if (_isAttackCount > 75)
			{
				//_enemyMotion = _enemyMotion_L;
				//_direction = ENEMY_LEFT_MOVE;
				if (distance < 170)
				{
					switch (_random)
					{
					case 0:
						_direction = ENEMY_LEFT_ATTACK;
						_enemyMotion = _enemyMotion_L_A;
						if (_enemyMotion->isPlay() == false)
						{
							_enemyMotion->start();
							_random = RND->getInt(4);
							_isAttackCount = 0;
						}
						break;
					case 1:
						_direction = ENEMY_LEFT_COMBO1;
						_enemyMotion = _enemyMotion_L_COMBO1;
						if (_enemyMotion->isPlay() == false)
						{
							_enemyMotion->start();
							_random = RND->getInt(4);
							_isAttackCount = 0;
						}
						break;
					case 2:
						_direction = ENEMY_LEFT_COMBO2;
						_enemyMotion = _enemyMotion_L_COMBO2;
						if (_enemyMotion->isPlay() == false)
						{
							_enemyMotion->start();
							_random = RND->getInt(4);
							_isAttackCount = 0;
						}
						break;
					case 3:
						_direction = ENEMY_LEFT_SUBMOTION;
						_enemyMotion = _enemyMotion_L_submotion;					
					}
				}
			}
			else
			{
				if (_enemyMotion->isPlay() == false)	_enemyMotion->start();
			}

		}
	}
	_isStunCount = 0;

	if (_direction == ENEMY_LEFT_SUBMOTION || _direction == ENEMY_RIGHT_SUBMOTION)
	{
		if (_enemyMotion->isPlay() == false)
		{
			_enemyMotion->start();
			_random = RND->getInt(4);
			_isAttackCount = 0;

			if (_direction == ENEMY_LEFT_SUBMOTION)
			{
				_enemyMotion = _enemyMotion_L_IDLE;
				_direction = ENEMY_LEFT_IDLE;
			}
			else
			{
				_enemyMotion = _enemyMotion_R_IDLE;
				_direction = ENEMY_RIGHT_IDLE;
			}
		}
	}
	
	// ==============================		에너미 움직임 및 공격      ==============================//
	
	_rc.setCenterPos(_x, _y);

}

void enemy::render()
{

}

void enemy::setPlayerPos(float x, float y)
{
	_playerX = x;
	_playerY = y;
}

