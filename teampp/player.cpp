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
	_idleImage = IMAGEMANAGER->addFrameImage("playerIdle", "image/Kyoko_Idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));//�÷��̾� �⺻ ������ �̹���
	_walkImage = IMAGEMANAGER->addFrameImage("playerWalk", "image/Kyoko_Walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));//�÷��̾� �ȴ� ������ �̹���
	_runImage = IMAGEMANAGER->addFrameImage("playerRun", "image/Kyoko_Run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));//�÷��̾� �޸��� ������ �̹���
	_jumpImage = IMAGEMANAGER->addFrameImage("playerJump", "image/Kyoko_Jump.bmp", 405, 414, 3, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ������ �̹���
	_attackImage = IMAGEMANAGER->addFrameImage("playerAttack", "image/Kyoko_Attack.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ������ �̹���
	_backGround1Pixel = IMAGEMANAGER->addImage("backGround1Pixel", "image/01_Detention_BG_x3_second.bmp", 2016, 672, true, RGB(255, 0, 255));//�ΰ��� ó�� ���۽� ���ȭ�� �ȼ��浹�� �̹���

	_playerDirection = PLAYERDIRECTION_LEFT_STOP;//�÷��̾� ������ ���� �ʱ�ȭ

	_x = WINSIZEX / 2 + 300;
	_y = WINSIZEY / 2 + 100;
	_speed = 3.0f;//�÷��̾� �ȴ� ���ǵ�
	_runSpeed = 6.0f;//�÷��̾� �޸��� ���ǵ�

	_rc.set(0, 0, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());
	//_rc = RectMakeCenter(_x, _y, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());//�÷��̾� ��Ʈ

	_idleImage->setFrameX(0);
	_idleImage->setFrameY(0);
	//�÷��̾� �⺻ �̹����� ���� ������ �ʱ�ȭ

	_walkImage->setFrameX(0);
	_walkImage->setFrameY(0);
	//�÷��̾� �ȴ� �̹����� ���� ������ �ʱ�ȭ

	_runImage->setFrameX(0);
	_runImage->setFrameY(0);
	//�÷��̾� �޸��� �̹����� ���� ������ �ʱ�ȭ

	_attackImage->setFrameX(0);
	_attackImage->setFrameY(0);
	//�÷��̾� ���� �̹����� ���� ������ �ʱ�ȭ

	_jump = new jump;
	_jump->init();
	//���� ����Ҵ�

	_r = 255;
	_g = 0;
	_b = 255;
	//�ȼ��浹�� ����� rgb��

	_count = _index = _time = _clickTime = 0;//�÷��̾� �����ӿ� ����� ����
	_jumpPower = 12.0f;//�÷��̾� ������
	_gravity = 0.4f;//�÷��̾� ������
	_key = false;//������ �ߺ� ����
	_jumPing = false;//�÷��̾ �������� ��Ʈ�� �ǽð����� ������Ʈ �����ֱ� ���� ����
	_attack = false;//������ ���������� ���� Ȯ��
	_probeX = _x + _walkImage->getFrameWidth() / 2;//x��ǥ �ȼ��浹
	_probeY = _y + _walkImage->getFrameHeight() / 2;//y��ǥ �ȼ��浹
	_startX = _startY = 0;//�÷��̾ ���������� ���� �����ߴ��� üũ�ϱ� ���� ����
	_jumpCount = 0;//���� ������ �ð�üũ

	return S_OK;
}

void player::render()
{
	_rc.render(getMemDC());//�÷��̾� ��Ʈ
	//Rectangle(getMemDC(), _rc);//������
	//_backGround1Pixel->render(getMemDC(), 0, 0);
	switch (_playerDirection)//�÷��̾��� ������ ���°��� ���� ����
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
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))//����Ű�� ������ ������
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
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))//����Ű�� ������ ������
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

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))//����Ű�� ������
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
	//��������� �������� �����϶�

	if (!_dash)//�޸��� ������ �޽���
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))//������Ű�� ������ ������
		{
			_key = true;
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_WALK;//�÷��̾ ���������� �ȴ� ������
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

	else//�޸��� ������ Ʈ���
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))//������Ű�� ������ ������
		{
			_key = true;
			if (!_jumPing)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_MOVE;//�÷��̾ ���������� �޸��� ������
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

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))//������Ű�� ������
	{
		_key = false;
		if (!_jumPing)
		{
			_playerDirection = PLAYERDIRECTION_RIGHT_STOP;//�÷��̾ �������� ���� �ִ� �⺻ ������
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
	//��������� ���������� �����϶�

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

	if (KEYMANAGER->isStayKeyDown(VK_UP))//����Ű�� ������ ������
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
	if (KEYMANAGER->isOnceKeyUp(VK_UP))//����Ű�� ������
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

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))//�Ʒ�Ű�� ������ ������
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
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))//�Ʒ�Ű�� ������
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

	if (KEYMANAGER->isOnceKeyDown('A'))//�ָ԰���
	{
		if (!_jumPing)//�������� �ƴҶ�
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)//�⺻, �ȱ��϶� ����
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_LEFT_ATTACK;
				_attackImage->setFrameX(_attackImage->getMaxFrameX());
				_attackImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)//�⺻, �ȱ��϶� ����
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

	if (KEYMANAGER->isOnceKeyDown('D'))//����
	{
		_startY = _y;
		_jumPing = true;
		_jump->jumping(&_x, &_y, _jumpPower, _gravity);
		if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK || _playerDirection == PLAYERDIRECTION_LEFT_MOVE)//�÷��̾ ������ ����������
		{
			_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
			_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
			_jumpImage->setFrameY(0);
		}
		if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK || _playerDirection == PLAYERDIRECTION_RIGHT_MOVE)//�÷��̾ �������� ����������
		{
			_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
			_jumpImage->setFrameX(0);
			_jumpImage->setFrameY(1);
		}
	}

	switch (_playerDirection)//�÷��̾� ������ ����
	{

	case PLAYERDIRECTION_RIGHT_STOP://������ �⺻
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

	case PLAYERDIRECTION_LEFT_STOP://���ʱ⺻
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

	case PLAYERDIRECTION_LEFT_JUMP://�������� ����
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

	if (_jumPing)//�������϶� ��Ʈ ������Ʈ
	{
		_rc.set(0, 0, _jumpImage->getFrameWidth(), _jumpImage->getFrameHeight());
		_rc.setCenterPos(_x, _y);
		//_rc = RectMakeCenter(_x, _y, _jumpImage->getFrameWidth(), _jumpImage->getFrameHeight());
	}

	_jump->update();//���� ������Ʈ
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
