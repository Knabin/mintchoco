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
	_idleImage = IMAGEMANAGER->addFrameImage("playerIdle", "images/Kyoko_Idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));//�÷��̾� �⺻ ������ �̹���
	_walkImage = IMAGEMANAGER->addFrameImage("playerWalk", "images/Kyoko_Walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));//�÷��̾� �ȴ� ������ �̹���
	_runImage = IMAGEMANAGER->addFrameImage("playerRun", "images/Kyoko_Run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));//�÷��̾� �޸��� ������ �̹���
	_jumpImage = IMAGEMANAGER->addFrameImage("playerJump", "images/Kyoko_Jump.bmp", 405, 414, 3, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ������ �̹���
	_attackImage = IMAGEMANAGER->addFrameImage("playerAttack", "images/Kyoko_Attack.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ������ �̹���
	_jumpAttackImage = IMAGEMANAGER->addFrameImage("plyaerJumpAttack", "images/Kyoko_Jump_Attack.bmp", 1560, 432, 10, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ���� �̹���

	_playerDirection = PLAYERDIRECTION_LEFT_STOP;//�÷��̾� ������ ���� �ʱ�ȭ

	_x = WINSIZEX / 2 + 300;
	_y = WINSIZEY / 2 + 100;
	_speed = 3.0f;//�÷��̾� �ȴ� ���ǵ�
	_runSpeed = 6.0f;//�÷��̾� �޸��� ���ǵ�

	_rc.set(0, 0, 80, 200);//�÷��̾� ��Ʈ
	//_rc = RectMakeCenter(_x, _y, _idleImage->getFrameWidth(), _idleImage->getFrameHeight());//�÷��̾� ��Ʈ

	_attackRc.set(0, 0, 100, 50);//���� ��Ʈ
	_attackRc.setCenterPos(-100, -100);

	_jumpAttackRc.set(0, 0, 50, 100);//���� ���� ��Ʈ
	_jumpAttackRc.setCenterPos(-100, -100);

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

	_jumpAttackImage->setFrameX(0);
	_jumpAttackImage->setFrameY(0);
	//�÷��̾� ���� ���� �̹����� ���� ������ �ʱ�ȭ

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
	_diagonalKey = false;//������ �ߺ� ����
	_jumping = false;//�÷��̾ �������� ��Ʈ�� �ǽð����� ������Ʈ �����ֱ� ���� ����
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
	_attackRc.render(getMemDC());//�÷��̾� ���� ��Ʈ
	_jumpAttackRc.render(getMemDC());//�÷��̾� ���� ���� ��Ʈ
	//Rectangle(getMemDC(), _rc);//������
	//_backGround1Pixel->render(getMemDC(), 0, 0);
	switch (_playerDirection)//�÷��̾��� ������ ���°��� ���� ����
	{
	case PLAYERDIRECTION_RIGHT_STOP:
		//_idleImage->frameRender(getMemDC(), _rc.left, _rc.top, _idleImage->getFrameX(), _idleImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _idleImage, _idleImage->getFrameX(), _idleImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y);
		break;
	case PLAYERDIRECTION_LEFT_STOP:
		//_idleImage->frameRender(getMemDC(), _rc.left, _rc.top, _idleImage->getFrameX(), _idleImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _idleImage, _idleImage->getFrameX(), _idleImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y);
		break;
	case PLAYERDIRECTION_RIGHT_WALK:
		//_walkImage->frameRender(getMemDC(), _rc.left, _rc.top, _walkImage->getFrameX(), _walkImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _walkImage, _walkImage->getFrameX(), _walkImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y + 10);
		break;
	case PLAYERDIRECTION_LEFT_WALK:
		//_walkImage->frameRender(getMemDC(), _rc.left, _rc.top, _walkImage->getFrameX(), _walkImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _walkImage, _walkImage->getFrameX(), _walkImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y + 10);
		break;
	case PLAYERDIRECTION_RIGHT_MOVE:
		//_runImage->frameRender(getMemDC(), _rc.left, _rc.top, _runImage->getFrameX(), _runImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _runImage, _runImage->getFrameX(), _runImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y + 20);
		break;
	case PLAYERDIRECTION_LEFT_MOVE:
		//_runImage->frameRender(getMemDC(), _rc.left, _rc.top, _runImage->getFrameX(), _runImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _runImage, _runImage->getFrameX(), _runImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y + 20);
		break;
	case PLAYERDIRECTION_RIGHT_ATTACK:
		ZORDER->pushObject(getMemDC(), _attackImage, _attackImage->getFrameX(), _attackImage->getFrameY(), 0, _x - 60, _jump->getJumpPower(), _y + 20);
		break;
	case PLAYERDIRECTION_LEFT_ATTACK:
		ZORDER->pushObject(getMemDC(), _attackImage, _attackImage->getFrameX(), _attackImage->getFrameY(), 0, _x - 60, _jump->getJumpPower(), _y + 20);
		break;
	case PLAYERDIRECTION_RIGHT_JUMP:
		//_jumpImage->frameRender(getMemDC(), _rc.left, _rc.top, _jumpImage->getFrameX(), _jumpImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _jumpImage, _jumpImage->getFrameX(), _jumpImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y);
		break;
	case PLAYERDIRECTION_LEFT_JUMP:
		//_jumpImage->frameRender(getMemDC(), _rc.left, _rc.top, _jumpImage->getFrameX(), _jumpImage->getFrameY());
		ZORDER->pushObject(getMemDC(), _jumpImage, _jumpImage->getFrameX(), _jumpImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y);
		break;
	case PLAYERDIRECTION_RIGHT_JUMP_ATTACK:
		ZORDER->pushObject(getMemDC(), _jumpAttackImage, _jumpAttackImage->getFrameX(), _jumpAttackImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y);
		break;
	case PLAYERDIRECTION_LEFT_JUMP_ATTACK:
		ZORDER->pushObject(getMemDC(), _jumpAttackImage, _jumpAttackImage->getFrameX(), _jumpAttackImage->getFrameY(), 0, _x, _jump->getJumpPower(), _y);
		break;
	}
}

void player::update()
{
	attack();//�÷��̾� ����

	move();//�÷��̾� ����

	frameDraw();//������ ����
	
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
	cout << _time << endl;//������

	if (_jumping)//�������϶� ��Ʈ ������Ʈ
	{
		_rc.setCenterPos(_x + 65, _y + 120);
		//_rc = RectMakeCenter(_x, _y, _jumpImage->getFrameWidth(), _jumpImage->getFrameHeight());
	}


	//_jump->update();//���� ������Ʈ
}

void player::release()
{
}

void player::attack()
{
	if (KEYMANAGER->isOnceKeyDown('A'))//�ָ԰���
	{
		if (!_jumping)//�������� �ƴҶ�
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
			_rc.setCenterPos(_x + 55, _y + 120);
		}
		else//�������϶�
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_JUMP)
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_LEFT_JUMP_ATTACK;
				_jumpAttackImage->setFrameX(_jumpAttackImage->getMaxFrameX());
				_jumpAttackImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_JUMP)
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_RIGHT_JUMP_ATTACK;
				_jumpAttackImage->setFrameX(0);
				_jumpAttackImage->setFrameY(1);
			}
			_rc.setCenterPos(_x + 55, _y + 120);
		}
	}
}

void player::move()
{
	if (!_dash)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))//����Ű�� ������ ������
		{
			_diagonalKey = true;
			if (!_jumping && !_attack && !keyRight())
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
				_rc.setCenterPos(_x + 55, _y + 120);
				//_rc = RectMakeCenter(_x, _y, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
				_x -= _speed;
			}
		}
	}

	else
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))//����Ű�� ������ ������
		{
			_diagonalKey = true;
			if (!_jumping && !_attack && !keyRight())
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
				_rc.setCenterPos(_x + 55, _y + 120);
				//_rc = RectMakeCenter(_x, _y, _runImage->getFrameWidth(), _runImage->getFrameHeight());
				_x -= _runSpeed;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))//����Ű�� ������
	{
		_diagonalKey = false;
		if (!_jumping && !_attack)
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
			_diagonalKey = true;
			if (!_jumping && !_attack && !keyLeft())
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
				_rc.setCenterPos(_x + 55, _y + 120);
				//_rc = RectMakeCenter(_x, _y, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
				_x += _speed;
			}
		}
	}

	else//�޸��� ������ Ʈ���
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))//������Ű�� ������ ������
		{
			_diagonalKey = true;
			if (!_jumping && !_attack && !keyLeft())
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
				_rc.setCenterPos(_x + 110, _y + 120);
				//_rc = RectMakeCenter(_x, _y, _runImage->getFrameWidth(), _runImage->getFrameHeight());
				_x += _runSpeed;
			}
		}

	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))//������Ű�� ������
	{
		_diagonalKey = false;
		if (!_jumping && !_attack)
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
		if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK && !_diagonalKey)
		{
			if (!_jumping && !_attack && !keyDown())
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

		if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK && !_diagonalKey)
		{
			if (!_jumping && !_attack && !keyDown())
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
		if (!_attack)
		{
			if (!_diagonalKey)
			{
				_rc.setCenterPos(_x + 55, _y + 120);
			}
			//_rc = RectMakeCenter(_x, _y, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
			_y -= _speed;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))//����Ű�� ������
	{
		_diagonalKey = false;
		if (_playerDirection == PLAYERDIRECTION_LEFT_WALK)
		{
			if (!_jumping && !_attack)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}
			_idleImage->setFrameX(0);
			_idleImage->setFrameY(0);
		}

		if (_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
		{
			if (!_jumping && !_attack)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}
			_idleImage->setFrameX(0);
			_idleImage->setFrameY(1);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))//�Ʒ�Ű�� ������ ������
	{
		if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK && !_diagonalKey)
		{
			if (!_jumping && !_attack && !keyUp())
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

		if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP && !_diagonalKey || _playerDirection == PLAYERDIRECTION_RIGHT_WALK && !_diagonalKey)
		{
			if (!_jumping && !_attack && !keyUp())
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
		if (!_attack)
		{
			if (!_diagonalKey)
			{
				_rc.setCenterPos(_x + 55, _y + 120);
			}
			//_rc = RectMakeCenter(_x, _y, _walkImage->getFrameWidth(), _walkImage->getFrameHeight());
			_y += _speed;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))//�Ʒ�Ű�� ������
	{
		_diagonalKey = false;
		if (_playerDirection == PLAYERDIRECTION_LEFT_WALK)
		{
			if (!_jumping && !_attack)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}
			_idleImage->setFrameX(0);
			_idleImage->setFrameY(0);
		}

		if (_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
		{
			if (!_jumping && !_attack)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}
			_idleImage->setFrameX(0);
			_idleImage->setFrameY(1);
		}
	}

	if (KEYMANAGER->isOnceKeyDown('D'))//����
	{
		if (!_attack)//�������� �ƴҶ�
		{
			//_startY = _y;
			_jumping = true;
			//_jump->jumping(&_x, &_y, _jumpPower, _gravity);
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP)//�÷��̾ ������ ����������
			{
				_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
				_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
				_jumpImage->setFrameY(0);
			}
			if (_playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
				_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
				_jumpImage->setFrameY(0);
			}
			if (_playerDirection == PLAYERDIRECTION_LEFT_MOVE)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
				_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
				_jumpImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP)//�÷��̾ �������� ����������
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
				_jumpImage->setFrameX(0);
				_jumpImage->setFrameY(1);
			}
			if (_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
				_jumpImage->setFrameX(0);
				_jumpImage->setFrameY(1);
			}
			if (_playerDirection == PLAYERDIRECTION_RIGHT_MOVE)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
				_jumpImage->setFrameX(0);
				_jumpImage->setFrameY(1);
			}
		}
	}
}

void player::frameDraw()
{
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
		_rc.setCenterPos(_x + 55, _y + 120);
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
		_rc.setCenterPos(_x + 55, _y + 120);
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
				_jumping = false;
				_jumpCount = 0;
			}

			/*
			if (_startY <= _y)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_jumping = false;
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
				_jumping = false;
				_jumpCount = 0;
			}

			/*
			if (_startY <= _y)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_jumping = false;
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
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_x + 10, _y + 100);
			if (_attackImage->getFrameX() <= 0)
			{
				_attackImage->setFrameX(_attackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
				_attackRc.setCenterPos(_x, _y);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_attackImage->setFrameX(_attackImage->getFrameX() + 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_x + 130, _y + 100);
			if (_attackImage->getFrameX() >= _attackImage->getMaxFrameX())
			{
				_attackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
				_attackRc.setCenterPos(_x, _y);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_JUMP_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_jumpAttackImage->setFrameX(_jumpAttackImage->getFrameX() - 1);
			_jumpAttackRc.set(0, 0, 50, 100);
			_jumpAttackRc.setCenterPos(_x, _y + 150);
			if (_jumpAttackImage->getFrameX() <= 0)
			{
				_jumpAttackImage->setFrameX(_jumpAttackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_jumping = false;
				_attack = false;
				_jumpAttackRc.set(0, 0, 0, 0);
				_jumpAttackRc.setCenterPos(_x, _y + 150);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_JUMP_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_jumpAttackImage->setFrameX(_jumpAttackImage->getFrameX() + 1);
			_jumpAttackRc.set(0, 0, 50, 100);
			_jumpAttackRc.setCenterPos(_x + 130, _y + 150);
			if (_jumpAttackImage->getFrameX() >= _jumpAttackImage->getMaxFrameX())
			{
				_jumpAttackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_jumping = false;
				_attack = false;
				_jumpAttackRc.set(0, 0, 0, 0);
				_jumpAttackRc.setCenterPos(_x + 130, _y + 150);
			}
			_count = 0;
		}
		break;
	}
}
