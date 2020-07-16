#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_idleImage = IMAGEMANAGER->addFrameImage("playerIdle", "image/Kyoko_Idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));//플레이어 기본 프레임 이미지
	_walkImage = IMAGEMANAGER->addFrameImage("playerWalk", "image/Kyoko_Walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));//플레이어 걷는 프레임 이미지
	_runImage = IMAGEMANAGER->addFrameImage("playerRun", "image/Kyoko_Run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));//플레이어 달리는 프레임 이미지
	_jumpImage = IMAGEMANAGER->addFrameImage("playerJump", "image/Kyoko_Jump.bmp", 405, 414, 3, 2, true, RGB(255, 0, 255));//플레이어 점프 프레임 이미지
	_attackImage = IMAGEMANAGER->addFrameImage("playerAttack", "image/Kyoko_Attack.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));//플레이어 공격 프레임 이미지
	_backGround1Pixel = IMAGEMANAGER->addImage("backGround1Pixel", "image/01_Detention_BG_x3_second.bmp", 2016, 672, true, RGB(255, 0, 255));//인게임 처음 시작시 배경화면 픽셀충돌용 이미지

	_playerDirection = PLAYERDIRECTION_LEFT_STOP;//플레이어 프레임 상태 초기화

	_x = WINSIZEX / 2 + 300;
	_y = WINSIZEY / 2 + 100;
	_speed = 3.0f;//플레이어 걷는 스피드
	_runSpeed = 6.0f;//플레이어 달리는 스피드

	_rc.set(0, 0, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());
	//_rc = RectMakeCenter(_x, _y, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());//플레이어 렉트

	_idleImage->setFrameX(0);
	_idleImage->setFrameY(0);
	//플레이어 기본 이미지의 현재 프레임 초기화

	_walkImage->setFrameX(0);
	_walkImage->setFrameY(0);
	//플레이어 걷는 이미지의 현재 프레임 초기화

	_runImage->setFrameX(0);
	_runImage->setFrameY(0);
	//플레이어 달리는 이미지의 현재 프레임 초기화

	_attackImage->setFrameX(0);
	_attackImage->setFrameY(0);
	//플레이어 공격 이미지의 현재 프레임 초기화

	_jump = new jump;
	_jump->init();
	//점프 상속할당

	_r = 255;
	_g = 0;
	_b = 255;
	//픽셀충돌에 사용할 rgb값

	_count = _index = _time = _clickTime = 0;//플레이어 프레임에 사용할 변수
	_jumpPower = 12.0f;//플레이어 점프값
	_gravity = 0.4f;//플레이어 점프값
	_key = false;//프레임 중복 방지
	_jumPing = false;//플레이어가 점프이후 렉트를 실시간으로 업데이트 시켜주기 위한 변수
	_attack = false;//공격이 실행중인지 여부 확인
	_probeX = _x + _walkImage->getFrameWidth() / 2;//x좌표 픽셀충돌
	_probeY = _y + _walkImage->getFrameHeight() / 2;//y좌표 픽셀충돌
	_startX = _startY = 0;//플레이어가 점프했을때 땅에 착지했는지 체크하기 위한 변수
	_jumpCount = 0;//점프 프레임 시간체크

	return S_OK;
}

void player::render()
{
	_rc.render(getMemDC());//플레이어 렉트
	//Rectangle(getMemDC(), _rc);//디버깅용
	//_backGround1Pixel->render(getMemDC(), 0, 0);
	switch (_playerDirection)//플레이어의 프레임 상태값에 따른 렌더
	{
	case PLAYERDIRECTION_RIGHT_STOP:
		//_idleImage->frameRender(getMemDC(), _rc.left, _rc.top, _idleImage->getFrameX(), _idleImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _idleImage, _idleImage->getFrameX(), _idleImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_LEFT_STOP:
		//_idleImage->frameRender(getMemDC(), _rc.left, _rc.top, _idleImage->getFrameX(), _idleImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _idleImage, _idleImage->getFrameX(), _idleImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_RIGHT_WALK:
		//_walkImage->frameRender(getMemDC(), _rc.left, _rc.top, _walkImage->getFrameX(), _walkImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _walkImage, _walkImage->getFrameX(), _walkImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_LEFT_WALK:
		//_walkImage->frameRender(getMemDC(), _rc.left, _rc.top, _walkImage->getFrameX(), _walkImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _walkImage, _walkImage->getFrameX(), _walkImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_RIGHT_MOVE:
		//_runImage->frameRender(getMemDC(), _rc.left, _rc.top, _runImage->getFrameX(), _runImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _runImage, _runImage->getFrameX(), _runImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_LEFT_MOVE:
		//_runImage->frameRender(getMemDC(), _rc.left, _rc.top, _runImage->getFrameX(), _runImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _runImage, _runImage->getFrameX(), _runImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_RIGHT_ATTACK:
		ZORDER->pushObject(getMemDC(), _attackImage, _attackImage->getFrameX(), _attackImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_LEFT_ATTACK:
		ZORDER->pushObject(getMemDC(), _attackImage, _attackImage->getFrameX(), _attackImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_RIGHT_JUMP:
		//_jumpImage->frameRender(getMemDC(), _rc.left, _rc.top, _jumpImage->getFrameX(), _jumpImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _jumpImage, _jumpImage->getFrameX(), _jumpImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_LEFT_JUMP:
		//_jumpImage->frameRender(getMemDC(), _rc.left, _rc.top, _jumpImage->getFrameX(), _jumpImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _jumpImage, _jumpImage->getFrameX(), _jumpImage->getFrameY(), 0, _rc.left, _jump->getJumpPower(), _rc.top);
		break;
	case PLAYERDIRECTION_RIGHT_MOVE_JUMP:
		break;
	}
}

void player::update()
{

	if (!_dash)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))//왼쪽키를 누르고 있으면
		{
			_key = true;
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_WALK;

				_walkImage->setFrameY(0);
				_count++;
				if (_count % 5 == 0)
				{
					_walkImage->setFrameX(_walkImage->getFrameX() - 1);
					if (_walkImage->getFrameX() <= 0)
					{
						_walkImage->setFrameX(_walkImage->getMaxFrameX());
					}
					_count = 0;
				}
			}
			_rc.set(0, 0, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
			_rc.setCenterPos(_x, _y);
			//_rc = RectMakeCenter(_x, _y, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
			_x -= _speed;
		}
	}

	else
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))//왼쪽키를 누르고 있으면
		{
			_key = true;
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_MOVE;
				_runImage->setFrameY(0);
				_count++;
				if (_count % 5 == 0)
				{
					_runImage->setFrameX(_runImage->getFrameX() - 1);
					if (_runImage->getFrameX() <= 0)
					{
						_runImage->setFrameX(_runImage->getMaxFrameX());
					}
					_count = 0;
				}
			}
			_rc.set(0, 0, _runImage->getFrameWidth(), _runImage->getFrameHeight());
			_rc.setCenterPos(_x, _y);
			//_rc = RectMakeCenter(_x, _y, _runImage->getFrameWidth(), _runImage->getFrameHeight());
			_x -= _runSpeed;
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))//왼쪽키를 뗏으면
	{
		_key = false;
		if (!_jumPing)
		{
			_playerDirection = PLAYERDIRECTION_LEFT_STOP;
		}
		_idleImage->setFrameX(0);
		_idleImage->setFrameY(0);
		_clickTime++;
		_dash = false;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_clickTime++;
	}
	//여기까지는 왼쪽으로 움직일때

	if (!_dash)//달리기 조건이 펄스면
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))//오른쪽키를 누르고 있으면
		{
			_key = true;
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_WALK;//플레이어가 오른쪽으로 걷는 프레임
				_walkImage->setFrameY(1);
				_count++;
				if (_count % 5 == 0)
				{
					_walkImage->setFrameX(_walkImage->getFrameX() + 1);
					if (_walkImage->getFrameX() >= _walkImage->getMaxFrameX())
					{
						_walkImage->setFrameX(0);
					}
					_count = 0;
				}
			}
			_rc.set(0, 0, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
			_rc.setCenterPos(_x, _y);
			//_rc = RectMakeCenter(_x, _y, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
			_x += _speed;
		}
	}

	else//달리기 조건이 트루면
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))//오른쪽키를 누르고 있으면
		{
			_key = true;
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_MOVE;//플레이어가 오른쪽으로 달리는 프레임
				_runImage->setFrameY(1);
				_count++;
				if (_count % 5 == 0)
				{
					_runImage->setFrameX(_runImage->getFrameX() + 1);
					if (_runImage->getFrameX() >= _runImage->getMaxFrameX())
					{
						_runImage->setFrameX(0);
					}
					_count = 0;
				}
			}
			_rc.set(0, 0, _runImage->getFrameWidth(), _runImage->getFrameHeight());
			_rc.setCenterPos(_x, _y);
			//_rc = RectMakeCenter(_x, _y, _runImage->getFrameWidth(), _runImage->getFrameHeight());
			_x += _runSpeed;
		}

	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))//오른쪽키를 뗏으면
	{
		_key = false;
		if (!_jumPing)
		{
			_playerDirection = PLAYERDIRECTION_RIGHT_STOP;//플레이어가 오른쪽을 보고 있는 기본 프레임
		}
		_idleImage->setFrameX(0);
		_idleImage->setFrameY(1);
		_clickTime++;
		_dash = false;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_clickTime++;
	}
	//여기까지는 오른쪽으로 움직일때

	if (_clickTime >= 3)
	{
		_dash = true;
	}

	_time++;
	if (_time > 30)
	{
		_time = 0;
		_clickTime = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))//위쪽키를 누르고 있으면
	{
		if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK && !_key)
		{
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_WALK;
				_walkImage->setFrameY(0);
				_count++;
				if (_count % 5 == 0)
				{
					_walkImage->setFrameX(_walkImage->getFrameX() - 1);
					if (_walkImage->getFrameX() <= 0)
					{
						_walkImage->setFrameX(_walkImage->getMaxFrameX());
					}
					_count = 0;
				}
			}
		}

		if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK && !_key)
		{
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_WALK;
				_walkImage->setFrameY(1);
				_count++;
				if (_count % 5 == 0)
				{
					_walkImage->setFrameX(_walkImage->getFrameX() + 1);
					if (_walkImage->getFrameX() >= _walkImage->getMaxFrameX())
					{
						_walkImage->setFrameX(0);
					}
					_count = 0;
				}
			}
		}
		_rc.set(0, 0, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
		_rc.setCenterPos(_x, _y);
		//_rc = RectMakeCenter(_x, _y, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
		_y -= _speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))//위쪽키를 뗏으면
	{
		_key = false;
		if (_playerDirection == PLAYERDIRECTION_LEFT_WALK)
		{
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}
			_idleImage->setFrameX(0);
			_idleImage->setFrameY(0);
		}

		if (_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
		{
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}
			_idleImage->setFrameX(0);
			_idleImage->setFrameY(1);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))//아래키를 누르고 있으면
	{
		if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK && !_key)
		{
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_WALK;
				_walkImage->setFrameY(0);
				_count++;
				if (_count % 5 == 0)
				{
					_walkImage->setFrameX(_walkImage->getFrameX() - 1);
					if (_walkImage->getFrameX() <= 0)
					{
						_walkImage->setFrameX(_walkImage->getMaxFrameX());
					}
					_count = 0;
				}
			}
		}

		if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP && !_key || _playerDirection == PLAYERDIRECTION_RIGHT_WALK && !_key)
		{
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_WALK;
				_walkImage->setFrameY(1);
				_count++;
				if (_count % 5 == 0)
				{
					_walkImage->setFrameX(_walkImage->getFrameX() + 1);
					if (_walkImage->getFrameX() >= _walkImage->getMaxFrameX())
					{
						_walkImage->setFrameX(0);
					}
					_count = 0;
				}
			}
		}
		_rc.set(0, 0, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
		_rc.setCenterPos(_x, _y);
		//_rc = RectMakeCenter(_x, _y, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
		_y += _speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))//아래키를 뗏으면
	{
		_key = false;
		if (_playerDirection == PLAYERDIRECTION_LEFT_WALK)
		{
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}
			_idleImage->setFrameX(0);
			_idleImage->setFrameY(0);
		}

		if (_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
		{
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}
			_idleImage->setFrameX(0);
			_idleImage->setFrameY(1);
		}
	}

	if (KEYMANAGER->isOnceKeyDown('A'))//주먹공격
	{
		if (!_jumPing)//점프중이 아닐때
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)//기본, 걷기일때 공격
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_LEFT_ATTACK;
				_attackImage->setFrameX(_attackImage->getMaxFrameX());
				_attackImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)//기본, 걷기일때 공격
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_RIGHT_ATTACK;
				_attackImage->setFrameX(0);
				_attackImage->setFrameY(1);
			}
			_rc.set(0, 0, _attackImage->getFrameWidth(), _attackImage->getFrameHeight());
			_rc.setCenterPos(_x, _y);
		}
	}

	if (KEYMANAGER->isOnceKeyDown('D'))//점프
	{
		_startY = _y;
		_jumPing = true;
		_jump->jumping(&_x, &_y, _jumpPower, _gravity);
		if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK || _playerDirection == PLAYERDIRECTION_LEFT_MOVE)//플레이어가 왼쪽을 보고있으면
		{
			_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
			_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
			_jumpImage->setFrameY(0);
		}
		if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK || _playerDirection == PLAYERDIRECTION_RIGHT_MOVE)//플레이어가 오른쪽을 보고있으면
		{
			_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
			_jumpImage->setFrameX(0);
			_jumpImage->setFrameY(1);
		}
	}

	switch (_playerDirection)//플레이어 프레임 변경
	{

	case PLAYERDIRECTION_RIGHT_STOP://오른쪽 기본
		_count++;
		if (_count % 5 == 0)
		{
			_idleImage->setFrameX(_idleImage->getFrameX() + 1);
			if (_idleImage->getFrameX() >= _idleImage->getMaxFrameX())
			{
				_idleImage->setFrameX(0);
			}
			_count = 0;
		}
		_rc.set(0, 0, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());
		_rc.setCenterPos(_x, _y);
		//_rc = RectMakeCenter(_x, _y, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());
		break;

	case PLAYERDIRECTION_LEFT_STOP://왼쪽기본
		_count++;
		if (_count % 5 == 0)
		{
			_idleImage->setFrameX(_idleImage->getFrameX() + 1);
			if (_idleImage->getFrameX() >= _idleImage->getMaxFrameX())
			{
				_idleImage->setFrameX(0);
			}
			_count = 0;
		}
		_rc.set(0, 0, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());
		_rc.setCenterPos(_x, _y);
		//_rc = RectMakeCenter(_x, _y, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());
		break;

	case PLAYERDIRECTION_LEFT_JUMP://왼쪽으로 점프
		_count++;
		if (_count % 5 == 0)
		{
			if (_jumpImage->getFrameX() > 0)
			{
				_jumpImage->setFrameX(_jumpImage->getFrameX() - 1);
			}
			
			_jumpCount++;
			if (_jumpCount % 12 == 0)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_jumPing = false;
				_jumpCount = 0;
			}

			/*
			if (_startY <= _y)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_jumPing = false;
			}
			*/
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_JUMP:
		_count++;
		if (_count % 5 == 0)
		{
			if (_jumpImage->getFrameX() < _jumpImage->getMaxFrameX())
			{
				_jumpImage->setFrameX(_jumpImage->getFrameX() + 1);
			}
			
			_jumpCount++;
			if (_jumpCount % 12 == 0)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_jumPing = false;
				_jumpCount = 0;
			}

			/*
			if (_startY <= _y)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_jumPing = false;
			}
			*/
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_attackImage->setFrameX(_attackImage->getFrameX() - 1);
			if (_attackImage->getFrameX() <= 0)
			{
				_attackImage->setFrameX(_attackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_attackImage->setFrameX(_attackImage->getFrameX() + 1);
			if (_attackImage->getFrameX() >= _attackImage->getMaxFrameX())
			{
				_attackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}
			_count = 0;
		}
	}
	/*
	_probeX = _x + _walkImage->getFrameWidth() / 2;
	_probeY = _y + _walkImage->getFrameHeight() / 2;

	for (int i = _probeX - 5; i < _probeX + 5; i++)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("backGround1")->getMemDC(), i, _y);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_x = i - _walkImage->getFrameWidth() / 2;
			break;
		}
	}

	for (int i = _probeY - 5; i < _probeY + 5; i++)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("backGround1")->getMemDC(), _x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - _walkImage->getFrameHeight() / 2;
			break;
		}
	}
	*/
	cout << _time << endl;

	if (_jumPing)//점프중일때 렉트 업데이트
	{
		_rc.set(0, 0, _jumpImage->getFrameWidth(), _jumpImage->getFrameHeight());
		_rc.setCenterPos(_x, _y);
		//_rc = RectMakeCenter(_x, _y, _jumpImage->getFrameWidth(), _jumpImage->getFrameHeight());
	}

	_jump->update();//점프 업데이트
}

void player::release()
{
}

void player::attack()
{
}

void player::move()
{
}
