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
	_point = IMAGEMANAGER->addFrameImage("point", "images/enemys/enemy_point.bmp", 560, 70, 8, 1, true, RGB(255, 0, 255));
	_stunImg = IMAGEMANAGER->addFrameImage("stunImg", "images/enemys/enemy_stun.bmp", 420, 54, 6, 1, true, RGB(255, 0, 255));
	// ============================	느낌표 ============================ //
	_ani_point = new animation;
	_ani_point->init(_point->getWidth(), _point->getHeight(), _point->getFrameWidth(), _point->getFrameHeight());
	_ani_point->setPlayFrame(0, 7, false, false);
	_ani_point->setFPS(1);
	// ============================	느낌표 ============================ //

	// ============================	느낌표 ============================ //
	_ani_stunImg = new animation;
	_ani_stunImg->init(_stunImg->getWidth(), _stunImg->getHeight(), _stunImg->getFrameWidth(), _stunImg->getFrameHeight());
	_ani_stunImg->setPlayFrame(0, 3, false, false);
	_ani_stunImg->setFPS(0.5);
	// ============================	느낌표 ============================ //
	_hp = 70;

	_isStart = false;
	_isPoint = false;
	_isStun = false;

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


	if (!_isStart)
	{
		if (_playerX > _x)
		{
			_enemyMotion = _enemyMotion_R_idle;
			_direction = ENEMY_RIGHT_IDLE;

		}
		else
		{
			_enemyMotion = _enemyMotion_L_idle;
			_direction = ENEMY_LEFT_IDLE;

		}
		if (distance < 300)
		{
			_isStart = true;
		
		}
		if (_enemyMotion->isPlay() == false)
		{
			_enemyMotion->start();
		}
	}

	if (_isStart == true && (_direction != ENEMY_LEFT_STUN && _direction != ENEMY_RIGHT_STUN))		//에너미 느낌표 뜨는 곳
	{
		if (_isPoint == false)
		{
			ZORDER->pushObject(getMemDC(), _point, _ani_point, 1, _x, 0, _y - _rc.getHeight() / 2);
			if (_ani_point->isPlay() == false)
			{
				_ani_point->start();
			}
			_ani_point->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
		}
			
		_isAttackCount++;
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
			if (_enemyMotion->isPlay() == false)
			{
				_enemyMotion->start();
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
					_enemyMotion = _enemyMotion_R_idle;
					_direction = ENEMY_RIGHT_IDLE;
				}
				if (_isAttackCount > 75)
				{
					_isPoint = true;	//에너미 느낌표 꺼지는 곳
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
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;
						case 1:
							_direction = ENEMY_RIGHT_COMBO1;
							_enemyMotion = _enemyMotion_R_combo1;
							if (_enemyMotion->isPlay() == false)
							{
								_enemyMotion->start();
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;
						case 2:
							_direction = ENEMY_RIGHT_COMBO2;
							_enemyMotion = _enemyMotion_R_combo2;
							if (_enemyMotion->isPlay() == false)
							{
								_enemyMotion->start();
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;
						case 3:
							_direction = ENEMY_RIGHT_SUBMOTION;
							_enemyMotion = _enemyMotion_R_submotion;

							break;
						case 4:
							_direction = ENEMY_RIGHT_BLOCK;
							_enemyMotion = _enemyMotion_R_block;
							if (_enemyMotion->isPlay() == false)
							{
								_enemyMotion->start();
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;
						case 5:
							_direction = ENEMY_RIGHT_BACK_MOVE;
							_enemyMotion = _enemyMotion_R_back;
							if (_enemyMotion->isPlay() == false)
							{
								_enemyMotion->start();
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
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
					_enemyMotion = _enemyMotion_L_idle;
					_direction = ENEMY_LEFT_IDLE;
				}

				if (_isAttackCount > 75)
				{
					_isPoint = true;	//에너미 느낌표 꺼지는 곳
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
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;
						case 1:
							_direction = ENEMY_LEFT_COMBO1;
							_enemyMotion = _enemyMotion_L_combo1;
							if (_enemyMotion->isPlay() == false)
							{
								_enemyMotion->start();
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;
						case 2:
							_direction = ENEMY_LEFT_COMBO2;
							_enemyMotion = _enemyMotion_L_combo2;
							if (_enemyMotion->isPlay() == false)
							{
								_enemyMotion->start();
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;
						case 3:
							_direction = ENEMY_LEFT_SUBMOTION;
							_enemyMotion = _enemyMotion_L_submotion;
						case 4:
							_direction = ENEMY_LEFT_BLOCK;
							_enemyMotion = _enemyMotion_L_block;
							if (_enemyMotion->isPlay() == false)
							{
								_enemyMotion->start();
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;
						case 5:
							_direction = ENEMY_LEFT_BACK_MOVE;
							_enemyMotion = _enemyMotion_L_back;
							if (_enemyMotion->isPlay() == false)
							{
								_enemyMotion->start();
								_random = RND->getInt(6);
								_isAttackCount = 0;
							}
							break;

						}
					}

				}
				else
				{
					if (_enemyMotion->isPlay() == false)	_enemyMotion->start();
				}
			}
		}

		if (_direction == ENEMY_LEFT_SUBMOTION || _direction == ENEMY_RIGHT_SUBMOTION)
		{
			if (_enemyMotion->isPlay() == false)
			{
				_enemyMotion->start();
				_random = RND->getInt(5);
				_isAttackCount = 0;

				if (_direction == ENEMY_LEFT_SUBMOTION)
				{
					_enemyMotion = _enemyMotion_L_idle;
					_direction = ENEMY_LEFT_IDLE;
				}
				else
				{
					_enemyMotion = _enemyMotion_R_idle;
					_direction = ENEMY_RIGHT_IDLE;
				}
			}
		}
	}

	if (0 < _hp &&  _hp <= 30 && _isStunCount <= 120)				//에너미 스턴
	{
		_isStun = true;
		_isStunCount++;

		if (_x < _playerX)
		{
			_enemyMotion = _enemyMotion_R_stun;
			_direction = ENEMY_RIGHT_STUN;
			if (_isStunCount >= 120)
			{
				_enemyMotion = _enemyMotion_R;
				_direction = ENEMY_RIGHT_MOVE;
			}
			if (_isStun == true)
			{
				ZORDER->pushObject(getMemDC(), _stunImg, _ani_stunImg, 1, _x + 10, _rc.getHeight() - 50, _rc.bottom + 0.1f);
				if (_ani_stunImg->isPlay() == false)
				{
					_ani_stunImg->start();
				}
			}
		}
		else
		{
			_enemyMotion = _enemyMotion_L_stun;
			_direction = ENEMY_LEFT_STUN;
			if (_isStunCount >= 120)
			{
				_enemyMotion = _enemyMotion_L;
				_direction = ENEMY_LEFT_MOVE;
			}
			if (_isStun == true)
			{
				ZORDER->pushObject(getMemDC(), _stunImg, _ani_stunImg, 1, _x - 10, _rc.getHeight() - 50, _rc.bottom + 0.1f);
				if (_ani_stunImg->isPlay() == false)
				{
					_ani_stunImg->start();
				}
			}
		}
		_ani_stunImg->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	}

	if (_hp == 0)
	{
		if (_x < _playerX)
		{
			_enemyMotion = _enemyMotion_L_dead;
			_direction = ENEMY_LEFT_DEAD;
		}
		else
		{
			_enemyMotion = _enemyMotion_R_dead;
			_direction = ENEMY_RIGHT_DEAD;
		}
		
	}
	
	// ==============================		에너미 움직임 및 공격      ==============================//
	
	switch (_stageNum)
	{
	case 0:
		pixel("stage1_pixel");
		break;
	case 1:
		pixel("stage2_pixel");
		break;
	case 2:
		pixel("stage3_pixel");
		break;
	case 3:
		pixel("stage4_pixel");
		break;
	case 4:
		pixel("boss_stage_pixel");
		break;
	}
	cout << _stageNum << endl;
	_rc.setCenterPos(_x, _y);
}

void enemy::render()
{

}

void enemy::pixel(string stageName)
{
	// ====================에너미 스테이지1 픽셀충돌==================== //

	for (int i = _rc.bottom + 3; i > _rc.bottom - 3; --i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(),_rc.getCenterX(),i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 255 && b == 255)
		{
			//cout << r << "," << g << "," << b << endl;
			_y = i - _rc.getHeight() / 2 - 4;		
			break;
		}
	}

	for (int i = _rc.bottom - 3; i < _rc.bottom + 3; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _rc.getCenterX(), i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			_y = i - _rc.getHeight() / 2 + 4;
			break;
		}
	}
	for (int i = _rc.left - 3; i < _rc.left + 3; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _rc.bottom);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 255) || (r == 255 && g == 0 && b == 0))
		{
			_x = i + _rc.getWidth() / 2 + 4;
			break;
		}
	}

	for (int i = _rc.right + 3; i > _rc.right - 3; --i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _rc.bottom);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 255) || (r == 255 && g == 0 && b == 0))
		{
			_x = i - _rc.getWidth() / 2 - 4;
			break;
		}
	}

}

void enemy::setPlayerPos(float x, float y)
{
	_playerX = x;
	_playerY = y;
}

