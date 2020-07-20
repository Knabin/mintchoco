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
	_idleImage = IMAGEMANAGER->addFrameImage("playerIdle", "images/player/Kyoko_Idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));//�÷��̾� �⺻ ������ �̹���
	_walkImage = IMAGEMANAGER->addFrameImage("playerWalk", "images/player/Kyoko_Walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));//�÷��̾� �ȴ� ������ �̹���
	_runImage = IMAGEMANAGER->addFrameImage("playerRun", "images/player/Kyoko_Run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));//�÷��̾� �޸��� ������ �̹���
	_jumpImage = IMAGEMANAGER->addFrameImage("playerJump", "images/player/Kyoko_Jump.bmp", 405, 414, 3, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ������ �̹���
	_comboAttackImage1 = IMAGEMANAGER->addFrameImage("playerComboAttack1", "images/player/Kyoko_ComboAttack1.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ������ �̹���
	_jumpAttackImage = IMAGEMANAGER->addFrameImage("plyaerJumpAttack", "images/player/Kyoko_Jump_Attack.bmp", 1560, 432, 10, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ���� �̹���
	_dashAttackImage = IMAGEMANAGER->addFrameImage("playerDashAttack", "images/player/Kyoko_DashAttack.bmp", 2700, 600, 8, 2, true, RGB(255, 0, 255));//�÷��̾� �뽬 ���� �̹���
	_shadow = IMAGEMANAGER->addImage("shadow", "images/player/Kyoko_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));//�׸��� �̹���

	_playerDirection = PLAYERDIRECTION_LEFT_STOP;//�÷��̾� ������ ���� �ʱ�ȭ

	_x = WINSIZEX / 2 + 300;
	_y = WINSIZEY / 2 + 100;
	_walkSpeed = 3.0f;//�÷��̾� �ȴ� ���ǵ�
	_runSpeed = 6.0f;//�÷��̾� �޸��� ���ǵ�

	_rc.set(0, 0, 80, 180);//�÷��̾� ��Ʈ

	_idleImage->setFrameX(0);
	_idleImage->setFrameY(0);
	//�÷��̾� �⺻ �̹����� ���� ������ �ʱ�ȭ

	_walkImage->setFrameX(0);
	_walkImage->setFrameY(0);
	//�÷��̾� �ȴ� �̹����� ���� ������ �ʱ�ȭ

	_runImage->setFrameX(0);
	_runImage->setFrameY(0);
	//�÷��̾� �޸��� �̹����� ���� ������ �ʱ�ȭ

	_comboAttackImage1->setFrameX(0);
	_comboAttackImage1->setFrameY(0);
	//�÷��̾� ���� �̹����� ���� ������ �ʱ�ȭ

	_jumpAttackImage->setFrameX(0);
	_jumpAttackImage->setFrameY(0);
	//�÷��̾� ���� ���� �̹����� ���� ������ �ʱ�ȭ

	_dashAttackImage->setFrameX(0);
	_dashAttackImage->setFrameY(0);
	//�÷��̾� �뽬 ���� �̹����� ���� ������ �ʱ�ȭ

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
	_jumping = false;//�÷��̾ �������� ��Ʈ�� �ǽð����� ������Ʈ �����ֱ� ���� ����
	_attack = false;//������ ���������� ���� Ȯ��
	_dash = false;//�뽬
	_probeX = _x + _walkImage->getFrameWidth() / 2;//x��ǥ �ȼ��浹
	_probeY = _y + _walkImage->getFrameHeight() / 2;//y��ǥ �ȼ��浹

	return S_OK;
}



void player::update()
{
	attack();//�÷��̾� ����

	leftMove();//�����̵�

	rightMove();//������ �̵�

	runTime();//���� ����

	upMove();//���� �̵�

	downMove();//�Ʒ��� �̵�

	jumpMove();//����

	frameDraw();//������ ����

	_rc.setCenterPos(_x, _y);

	cout << "jumping : " << _jumping << endl;
}

void player::render()
{
	_rc.render(getMemDC());//�÷��̾� ��Ʈ
	_attackRc.render(getMemDC());//�÷��̾� ���� ��Ʈ
	_shadow->render(getMemDC(), _rc.left - FRAMEPOSX, _rc.bottom);//�׸���
	switch (_playerDirection)//�÷��̾��� ������ ���°��� ���� ����
	{
	case PLAYERDIRECTION_RIGHT_STOP:
		ZORDER->pushObject(getMemDC(), _idleImage, _idleImage->getFrameX(), _idleImage->getFrameY(), 0, _rc.getCenterX() , _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_STOP:
		ZORDER->pushObject(getMemDC(), _idleImage, _idleImage->getFrameX(), _idleImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_RIGHT_WALK:
		ZORDER->pushObject(getMemDC(), _walkImage, _walkImage->getFrameX(), _walkImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_WALK:
		ZORDER->pushObject(getMemDC(), _walkImage, _walkImage->getFrameX(), _walkImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_RIGHT_MOVE:
		ZORDER->pushObject(getMemDC(), _runImage, _runImage->getFrameX(), _runImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_MOVE:
		ZORDER->pushObject(getMemDC(), _runImage, _runImage->getFrameX(), _runImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK1:
		ZORDER->pushObject(getMemDC(), _comboAttackImage1, _comboAttackImage1->getFrameX(), _comboAttackImage1->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_COBMO_ATTACK1:
		ZORDER->pushObject(getMemDC(), _comboAttackImage1, _comboAttackImage1->getFrameX(), _comboAttackImage1->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_RIGHT_JUMP:
		ZORDER->pushObject(getMemDC(), _jumpImage, _jumpImage->getFrameX(), _jumpImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_JUMP:
		ZORDER->pushObject(getMemDC(), _jumpImage, _jumpImage->getFrameX(), _jumpImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_RIGHT_JUMP_ATTACK:
		ZORDER->pushObject(getMemDC(), _jumpAttackImage, _jumpAttackImage->getFrameX(), _jumpAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_JUMP_ATTACK:
		ZORDER->pushObject(getMemDC(), _jumpAttackImage, _jumpAttackImage->getFrameX(), _jumpAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_RIGHT_DASH_ATTACK:
		ZORDER->pushObject(getMemDC(), _dashAttackImage, _dashAttackImage->getFrameX(), _dashAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_DASH_ATTACK:
		ZORDER->pushObject(getMemDC(), _dashAttackImage, _dashAttackImage->getFrameX(), _dashAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	}
}

void player::release()
{
}

void player::attack()
{
	if (KEYMANAGER->isOnceKeyDown('A') && !keyJump())//�ָ԰���
	{
		if (!_jumping)//�������� �ƴҶ�
		{
			_attack = true;
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)//�⺻, �ȱ��϶� ����
			{
				_playerDirection = PLAYERDIRECTION_LEFT_COBMO_ATTACK1;
				_comboAttackImage1->setFrameX(_comboAttackImage1->getMaxFrameX());
				_comboAttackImage1->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)//�⺻, �ȱ��϶� ����
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_COMBO_ATTACK1;
				_comboAttackImage1->setFrameX(0);
				_comboAttackImage1->setFrameY(1);
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_MOVE)//�޸���
			{
				_playerDirection = PLAYERDIRECTION_LEFT_DASH_ATTACK;
				_dashAttackImage->setFrameX(_dashAttackImage->getMaxFrameX());
				_dashAttackImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_MOVE)//�޸���
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_DASH_ATTACK;
				_dashAttackImage->setFrameX(0);
				_dashAttackImage->setFrameY(1);
			}

		}
		else//�������϶�
		{
			_attack = true;
			if (_playerDirection == PLAYERDIRECTION_LEFT_JUMP)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_JUMP_ATTACK;
				_jumpAttackImage->setFrameX(_jumpAttackImage->getMaxFrameX());
				_jumpAttackImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_JUMP)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_JUMP_ATTACK;
				_jumpAttackImage->setFrameX(0);
				_jumpAttackImage->setFrameY(1);
			}

		}
	}
}

void player::jumpMove()
{
	if (KEYMANAGER->isOnceKeyDown('D') && !keyAttack())//����
	{
		if (!_attack && !keyJump())//�������� �ƴҶ� && �����ߺ�����
		{
			_jumping = true;
			_startY = _y;
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
	}

	_jump->update();//���� ������Ʈ
}

void player::leftMove()
{
	if (!_dash)//�ȱ�
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			if (!_jumping && !_attack && !keyRight())
			{
				_playerDirection = PLAYERDIRECTION_LEFT_WALK;
				_walkImage->setFrameY(0);
			}

			if (!_attack && !keyRight())//�����߿� �����̴°� ���
			{
				_x -= _walkSpeed;
			}

		}
	}

	else//�޸���
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			if (!_jumping && !_attack && !keyRight())
			{
				_playerDirection = PLAYERDIRECTION_LEFT_MOVE;
				_runImage->setFrameY(0);
			}

			if (!_attack && !keyRight())//�����߿� �����̴°� ���
			{
				_x -= _runSpeed;
			}

		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))//����Ű�� ������
	{
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
}

void player::rightMove()
{
	if (!_dash)//�ȱ�
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			if (!_jumping && !_attack && !keyLeft())
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_WALK;
				_walkImage->setFrameY(1);
			}

			if (!_attack && !keyLeft())//�����߿� �����̴°� ���
			{
				_x += _walkSpeed;
			}
		}
	}

	else//�޸���
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			if (!_jumping && !_attack && !keyLeft())
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_MOVE;
				_runImage->setFrameY(1);
			}

			if (!_attack && !keyLeft())//�����߿� �����̴°� ���
			{
				_x += _runSpeed;
			}
		}

	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))//������Ű�� ������
	{
		if (!_jumping && !_attack)
		{
			_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
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

}

void player::upMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (!_jumping && !_attack && !keyDown())
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_WALK;
				_walkImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_WALK;
				_walkImage->setFrameY(1);
			}
		}

		if (!_attack)
		{
			if (_jumping)
			{
				_startY -= _walkSpeed;
			}
			_y -= _walkSpeed;
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_UP))//����Ű�� ������
	{
		if (!_jumping && !_attack)
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_idleImage->setFrameX(0);
				_idleImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_idleImage->setFrameX(0);
				_idleImage->setFrameY(1);
			}
		}
	}
}

void player::downMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (!_jumping && !_attack && !keyUp())
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_WALK;
				_walkImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_WALK;
				_walkImage->setFrameY(1);
			}
		}

		if (!_attack)
		{
			if (_jumping)
			{
				_startY -= _walkSpeed;
			}
			_y += _walkSpeed;
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))//�Ʒ�Ű�� ������
	{
		if (!_jumping && !_attack)
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_idleImage->setFrameX(0);
				_idleImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_idleImage->setFrameX(0);
				_idleImage->setFrameY(1);
			}
		}
	}
}

void player::runTime()
{
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
		break;

	case PLAYERDIRECTION_RIGHT_WALK:
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
		break;

	case PLAYERDIRECTION_LEFT_WALK:
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
		break;

	case PLAYERDIRECTION_RIGHT_MOVE:
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
		break;

	case PLAYERDIRECTION_LEFT_MOVE:
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
		break;

	case PLAYERDIRECTION_LEFT_JUMP://�������� ����
		_count++;
		if (_count % 5 == 0)
		{
			if (_jumpImage->getFrameX() > 0)
			{
				_jumpImage->setFrameX(_jumpImage->getFrameX() - 1);
			}

			if (_startY <= _y)
			{
				_jumping = false;
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}

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

			if (_startY <= _y)
			{
				_jumping = false;
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}

			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_COBMO_ATTACK1:
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage1->setFrameX(_comboAttackImage1->getFrameX() - 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY());
			if (_comboAttackImage1->getFrameX() <= 0)
			{
				_comboAttackImage1->setFrameX(_comboAttackImage1->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK1:
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage1->setFrameX(_comboAttackImage1->getFrameX() + 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.right + 35, _rc.getCenterY());
			if (_comboAttackImage1->getFrameX() >= _comboAttackImage1->getMaxFrameX())
			{
				_comboAttackImage1->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_JUMP_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_jumpAttackImage->setFrameX(_jumpAttackImage->getFrameX() - 1);
			_attackRc.set(0, 0, 50, 100);
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY() + 40);
			if (_jumpAttackImage->getFrameX() <= 0)
			{
				_jumpAttackImage->setFrameX(_jumpAttackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_jumping = false;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_JUMP_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_jumpAttackImage->setFrameX(_jumpAttackImage->getFrameX() + 1);
			_attackRc.set(0, 0, 50, 100);
			_attackRc.setCenterPos(_rc.right + 20, _rc.getCenterY() + 40);
			if (_jumpAttackImage->getFrameX() >= _jumpAttackImage->getMaxFrameX())
			{
				_jumpAttackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_jumping = false;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;


	case PLAYERDIRECTION_LEFT_DASH_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_dashAttackImage->setFrameX(_dashAttackImage->getFrameX() - 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.left - 10, _rc.getCenterY() + 10);
			if (_dashAttackImage->getFrameX() <= 0)
			{
				_dashAttackImage->setFrameX(_dashAttackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_DASH_ATTACK:
		_count++;
		if (_count % 5 == 0)
		{
			_dashAttackImage->setFrameX(_dashAttackImage->getFrameX() + 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.right + 30, _rc.getCenterY() + 10);
			if (_dashAttackImage->getFrameX() >= _dashAttackImage->getMaxFrameX())
			{
				_dashAttackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;
	}
}
