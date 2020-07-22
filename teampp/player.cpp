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
	_comboAttackImage2 = IMAGEMANAGER->addFrameImage("playerComboAttack2", "images/player/Kyoko_ComboAttack2.bmp", 1869, 402, 7, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ������ �̹���2
	_comboAttackImage3 = IMAGEMANAGER->addFrameImage("playerComboAttack3", "images/player/Kyoko_ComboAttack3.bmp", 2970, 462, 9, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ������ �̹���3
	_strongAttackImage = IMAGEMANAGER->addFrameImage("playerStrongAttack", "images/player/Kyoko_StrongAttack.bmp", 3030, 474, 10, 2, true, RGB(255, 0, 255));//�÷��̾� ������ ������ �̹���
	_jumpAttackImage = IMAGEMANAGER->addFrameImage("plyaerJumpAttack", "images/player/Kyoko_Jump_Attack.bmp", 1560, 432, 10, 2, true, RGB(255, 0, 255));//�÷��̾� ���� ���� �̹���
	_dashAttackImage = IMAGEMANAGER->addFrameImage("playerDashAttack", "images/player/Kyoko_DashAttack.bmp", 2700, 436, 8, 2, true, RGB(255, 0, 255));//�÷��̾� �뽬 ���� �̹���
	_ultimateImage = IMAGEMANAGER->addFrameImage("playerUltimate", "images/player/Kyoko_Ultimate.bmp", 3675, 384, 25, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �̹���
	_guardImage = IMAGEMANAGER->addFrameImage("playerGuard", "images/player/Kyoko_Guard.bmp", 351, 378, 3, 2, true, RGB(255, 0, 255));//�÷��̾� ��� �̹���
	
	_ultimateAfterImage[0] = IMAGEMANAGER->addFrameImage("playerUltimateAfter", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[1] = IMAGEMANAGER->addFrameImage("playerUltimateAfter2", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[2] = IMAGEMANAGER->addFrameImage("playerUltimateAfter3", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[3] = IMAGEMANAGER->addFrameImage("playerUltimateAfter4", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[4] = IMAGEMANAGER->addFrameImage("playerUltimateAfter5", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[5] = IMAGEMANAGER->addFrameImage("playerUltimateAfter6", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[6] = IMAGEMANAGER->addFrameImage("playerUltimateAfter7", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[7] = IMAGEMANAGER->addFrameImage("playerUltimateAfter8", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[8] = IMAGEMANAGER->addFrameImage("playerUltimateAfter9", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[9] = IMAGEMANAGER->addFrameImage("playerUltimateAfter10", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[10] = IMAGEMANAGER->addFrameImage("playerUltimateAfter11", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[11] = IMAGEMANAGER->addFrameImage("playerUltimateAfter12", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[12] = IMAGEMANAGER->addFrameImage("playerUltimateAfter13", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[13] = IMAGEMANAGER->addFrameImage("playerUltimateAfter14", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[14] = IMAGEMANAGER->addFrameImage("playerUltimateAfter15", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[15] = IMAGEMANAGER->addFrameImage("playerUltimateAfter16", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[16] = IMAGEMANAGER->addFrameImage("playerUltimateAfter17", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[17] = IMAGEMANAGER->addFrameImage("playerUltimateAfter18", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[18] = IMAGEMANAGER->addFrameImage("playerUltimateAfter19", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	_ultimateAfterImage[19] = IMAGEMANAGER->addFrameImage("playerUltimateAfter20", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//�÷��̾� �ñر� �ܻ� �̹���
	
	_shadow = IMAGEMANAGER->addImage("shadow", "images/player/Kyoko_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));//�׸��� �̹���

	_playerDirection = PLAYERDIRECTION_LEFT_STOP;//�÷��̾� ������ ���� �ʱ�ȭ

	_x = WINSIZEX / 2 + 300;
	_z = WINSIZEY / 2 + 100;
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

	_comboAttackImage2->setFrameX(0);
	_comboAttackImage2->setFrameY(0);
	//�÷��̾� ���� �̹���2�� ���� ������ �ʱ�ȭ

	_comboAttackImage3->setFrameX(0);
	_comboAttackImage3->setFrameY(0);
	//�÷��̾� ���� �̹���3�� ���� ������ �ʱ�ȭ

	_jumpAttackImage->setFrameX(0);
	_jumpAttackImage->setFrameY(0);
	//�÷��̾� ���� ���� �̹����� ���� ������ �ʱ�ȭ

	_dashAttackImage->setFrameX(0);
	_dashAttackImage->setFrameY(0);
	//�÷��̾� �뽬 ���� �̹����� ���� ������ �ʱ�ȭ

	_strongAttackImage->setFrameX(0);
	_strongAttackImage->setFrameY(0);
	//�÷��̾� ������ �̹����� ���� ������ �ʱ�ȭ

	_ultimateImage->setFrameX(0);
	_ultimateImage->setFrameY(0);
	//�÷��̾� �ñر� �̹����� ���� ������ �ʱ�ȭ

	_guardImage->setFrameX(0);
	_guardImage->setFrameY(0);
	//�÷��̾� ��� �̹����� ���� ������ �ʱ�ȭ

	_jump = new jump;
	_jump->init();
	//���� ����Ҵ�

	_r = 255;
	_g = 0;
	_b = 255;
	//�ȼ��浹�� ����� rgb��

	_ultimateAfterCount = _count = _index = _time = _clickTime = 0;//�÷��̾� �����ӿ� ����� ����
	_jumpPower = 10.0f;//�÷��̾� ������
	_gravity = 10.0f;//�÷��̾� ������
	_jumping = false;//�÷��̾ �������� ��Ʈ�� �ǽð����� ������Ʈ �����ֱ� ���� ����
	_attack = false;//������ ���������� ���� Ȯ��
	_dash = false;//�뽬
	_ultimate = false;//�ñر�
	_comboAttack = false;//�޺����� �����ӿ� ����� ����
	_comboAttack2 = false;//�޺����� 3�ܰ� ���࿩�θ� Ȯ���ϱ� ���� ����
	_probeX = _x + _walkImage->getFrameWidth() / 2;//x��ǥ �ȼ��浹
	_probeY = _z + _walkImage->getFrameHeight() / 2;//y��ǥ �ȼ��浹

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

	guard();//�÷��̾� ���

	frameDraw();//������ ����

	//cout << _playerDirection << endl;

	if (!_jumping)
	{
		_rc.setCenterPos(_x, _z - (_rc.bottom - _rc.top) / 2);
	}
	else
	{
		_rc.setCenterPos(_x, _z - _jump->getJumpPower() - (_rc.bottom - _rc.top) / 2);
	}

	if (_comboAttack)
	{
		_comboAttackRc1.set(0, 0, 0, 0);
	}
	if (_comboAttack2)
	{
		_comboAttackRc2.set(0, 0, 0, 0);
	}
}

void player::render()
{
	_rc.render(getMemDC());//�÷��̾� ��Ʈ
	_attackRc.render(getMemDC());//�÷��̾� ���� ��Ʈ
	_comboAttackRc1.render(getMemDC());//1�ܰ� �޺����� ��Ʈ
	_comboAttackRc2.render(getMemDC());//2�ܰ� �޺����� ��Ʈ

	_shadow->alphaRender(getMemDC(), _rc.left - 20, _z, 100);//�׸���

	if (_ultimate)
	{
		for (int i = 0; i < ULTIMATECOUNT; i++)
		{
			_ultimateAfterCount++;
			if (_ultimateAfterCount % 5 == 0)
			{
				if (_playerDirection == PLAYERDIRECTION_RIGHT_ULTIMATE)
				{
					_ultimateAfterImage[i]->frameRender(getMemDC(), _rc.left - 40 - ((i + 1) * 5), _rc.bottom - _ultimateAfterImage[i]->getFrameHeight());
				}

				if (_playerDirection == PLAYERDIRECTION_LEFT_ULTIMATE)
				{
					_ultimateAfterImage[i]->frameRender(getMemDC(), _rc.left + ((i + 1) * 5), _rc.bottom - _ultimateAfterImage[i]->getFrameHeight() +15);
				}
				
				_ultimateAfterCount = 0;
			}
		}
	}

	switch (_playerDirection)//�÷��̾��� ������ ���°��� ���� ����
	{
	case PLAYERDIRECTION_RIGHT_STOP:
	case PLAYERDIRECTION_LEFT_STOP:
		//_playerIMg = idleimage;
		ZORDER->pushObject(getMemDC(), _idleImage, _idleImage->getFrameX(), _idleImage->getFrameY(), 0, _rc.getCenterX() , _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_WALK:
	case PLAYERDIRECTION_LEFT_WALK:
		ZORDER->pushObject(getMemDC(), _walkImage, _walkImage->getFrameX(), _walkImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_MOVE:
	case PLAYERDIRECTION_LEFT_MOVE:
		ZORDER->pushObject(getMemDC(), _runImage, _runImage->getFrameX(), _runImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK1:
	case PLAYERDIRECTION_LEFT_COMBO_ATTACK1:
		ZORDER->pushObject(getMemDC(), _comboAttackImage1, _comboAttackImage1->getFrameX(), _comboAttackImage1->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK2:
	case PLAYERDIRECTION_LEFT_COMBO_ATTACK2:
		ZORDER->pushObject(getMemDC(), _comboAttackImage2, _comboAttackImage2->getFrameX(), _comboAttackImage2->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK3:
	case PLAYERDIRECTION_LEFT_COMBO_ATTACK3:
		ZORDER->pushObject(getMemDC(), _comboAttackImage3, _comboAttackImage3->getFrameX(), _comboAttackImage3->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_JUMP:
	case PLAYERDIRECTION_LEFT_JUMP:
		ZORDER->pushObject(getMemDC(), _jumpImage, _jumpImage->getFrameX(), _jumpImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_JUMP_ATTACK:
	case PLAYERDIRECTION_LEFT_JUMP_ATTACK:
		ZORDER->pushObject(getMemDC(), _jumpAttackImage, _jumpAttackImage->getFrameX(), _jumpAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_DASH_ATTACK:
	case PLAYERDIRECTION_LEFT_DASH_ATTACK:
		ZORDER->pushObject(getMemDC(), _dashAttackImage, _dashAttackImage->getFrameX(), _dashAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_STRONG_ATTACK:
	case PLAYERDIRECTION_LEFT_STRONG_ATTACK:
		ZORDER->pushObject(getMemDC(), _strongAttackImage, _strongAttackImage->getFrameX(), _strongAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_ULTIMATE:
	case PLAYERDIRECTION_LEFT_ULTIMATE:
		ZORDER->pushObject(getMemDC(), _ultimateImage, _ultimateImage->getFrameX(), _ultimateImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	case PLAYERDIRECTION_RIGHT_GUARD:
	case PLAYERDIRECTION_LEFT_GUARD:
		ZORDER->pushObject(getMemDC(), _guardImage, _guardImage->getFrameX(), _guardImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
		break;
	}

	//ZORDER->pushObject(getMemDC(), _playerIMg, _playerIMg->getFrameX(), _playerIMg->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
}

void player::release()
{
}

void player::attack()
{
	if (KEYMANAGER->isOnceKeyDown('A') && !keyJump())//�����
	{
		if (!_jumping)//�������� �ƴҶ�
		{
			_attack = true;
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP && !_comboAttack || _playerDirection == PLAYERDIRECTION_LEFT_WALK && !_comboAttack)//�⺻, �ȱ��϶� ����
			{
				_playerDirection = PLAYERDIRECTION_LEFT_COMBO_ATTACK1;
				_comboAttackImage1->setFrameX(_comboAttackImage1->getMaxFrameX());
				_comboAttackImage1->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP && !_comboAttack || _playerDirection == PLAYERDIRECTION_RIGHT_WALK && !_comboAttack)//�⺻, �ȱ��϶� ����
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_COMBO_ATTACK1;
				_comboAttackImage1->setFrameX(0);
				_comboAttackImage1->setFrameY(1);
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_COMBO_ATTACK1 && _comboAttack && _comboAttackImage1->getFrameX() <= 2)//2���޺�
			{
				_playerDirection = PLAYERDIRECTION_LEFT_COMBO_ATTACK2;
				_comboAttackImage2->setFrameX(_comboAttackImage2->getMaxFrameX());
				_comboAttackImage2->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_COMBO_ATTACK1 && _comboAttack && _comboAttackImage1->getFrameX() >= _comboAttackImage1->getMaxFrameX() - 2)//2���޺�
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_COMBO_ATTACK2;
				_comboAttackImage2->setFrameX(0);
				_comboAttackImage2->setFrameY(1);
			}
			
			if (_playerDirection == PLAYERDIRECTION_LEFT_COMBO_ATTACK2 && _comboAttack2 && _comboAttackImage2->getFrameX() <= 2)//3���޺�
			{
				_playerDirection = PLAYERDIRECTION_LEFT_COMBO_ATTACK3;
				_comboAttackImage3->setFrameX(_comboAttackImage3->getMaxFrameX());
				_comboAttackImage3->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_COMBO_ATTACK2 && _comboAttack2 && _comboAttackImage2->getFrameX() >= _comboAttackImage2->getMaxFrameX() - 2)//3���޺�
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_COMBO_ATTACK3;
				_comboAttackImage3->setFrameX(0);
				_comboAttackImage3->setFrameY(1);
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

	if (KEYMANAGER->isOnceKeyDown('S') && !keyJump())//������
	{
		if (!_jumping)
		{
			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_RIGHT_STRONG_ATTACK;
				_strongAttackImage->setFrameX(_strongAttackImage->getMaxFrameX());
				_strongAttackImage->setFrameY(1);
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_LEFT_STRONG_ATTACK;
				_strongAttackImage->setFrameX(0);
				_strongAttackImage->setFrameY(0);
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('F') && !keyJump())//�ñر�
	{
		if (!_jumping)
		{
			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_RIGHT_ULTIMATE;
				_ultimateImage->setFrameX(0);
				_ultimateImage->setFrameY(1);
				for (int i = 0; i < ULTIMATECOUNT; i++)
				{
					_ultimateAfterImage[i]->setFrameX(i);
					_ultimateAfterImage[i]->setFrameY(1);
				}	
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_LEFT_ULTIMATE;
				_ultimateImage->setFrameX(_ultimateImage->getMaxFrameX());
				_ultimateImage->setFrameY(0);

				for (int i = 0; i < ULTIMATECOUNT; i++)
				{
					_ultimateAfterImage[i]->setFrameX(i);
					_ultimateAfterImage[i]->setFrameY(0);
				}
			}
		}
	}
}

void player::jumpMove()
{
	if (KEYMANAGER->isOnceKeyDown('D') && !keyAttack())//����
	{
		if (!_attack && !_jumping)//�������� �ƴҶ� && �����ߺ�����
		{
			_jumping = true;
			_jump->jumping(&_x, &_z, _jumpPower, _gravity);
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

			if (!_jumping && !_attack && keyRight())
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
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

			if (!_jumping && !_attack && keyRight())
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
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
		if (_jumping && !_attack)//�����߿� ������ ����
		{
			_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
			_jumpImage->setFrameX(_jumpImage->getFrameX());
			_jumpImage->setFrameY(0);
		}
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

			if (!_jumping && !_attack && keyLeft())
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
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

			if (!_jumping && !_attack && keyLeft())
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
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
		if (_jumping && !_attack)//�����߿� ������ ����
		{
			_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
			_jumpImage->setFrameX(_jumpImage->getFrameX());
			_jumpImage->setFrameY(1);
		}
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

		if (!_jumping && !_attack && keyDown())
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}
		}

		if (!_attack)
		{
			if (_jumping)
			{
				_jump->setStartYmin(_walkSpeed);
			}
			
			_z -= _walkSpeed;
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

		if (!_jumping && !_attack && keyUp())
		{
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}
		}

		if (!_attack)
		{
			if (_jumping)
			{
				_jump->setStartYpls(_walkSpeed);
			}

			_z += _walkSpeed;
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

void player::guard()
{
	
}

void player::frameDraw()
{
	switch (_playerDirection)//�÷��̾� ������ ����
	{

	case PLAYERDIRECTION_RIGHT_STOP://������ �⺻
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

			if (_z <= _z - _jump->getJumpPower())
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

			if (_z <= _z - _jump->getJumpPower())
			{
				_jumping = false;
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}

			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_COMBO_ATTACK1:
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage1->setFrameX(_comboAttackImage1->getFrameX() - 1);
			_comboAttackRc1.set(0, 0, 100, 50);
			_comboAttackRc1.setCenterPos(_rc.left, _rc.getCenterY() - 10);
			if (_comboAttackImage1->getFrameX() <= 0)
			{
				_comboAttackImage1->setFrameX(_comboAttackImage1->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_comboAttackRc1.set(0, 0, 0, 0);
				_comboAttack = false;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK1:
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage1->setFrameX(_comboAttackImage1->getFrameX() + 1);
			_comboAttackRc1.set(0, 0, 100, 50);
			_comboAttackRc1.setCenterPos(_rc.right, _rc.getCenterY() - 10);
			if (_comboAttackImage1->getFrameX() >= _comboAttackImage1->getMaxFrameX())
			{
				_comboAttackImage1->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_comboAttackRc1.set(0, 0, 0, 0);
				_comboAttack = false;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_COMBO_ATTACK2:
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage2->setFrameX(_comboAttackImage2->getFrameX() - 1);
			_comboAttackRc2.set(0, 0, 100, 50);
			_comboAttackRc2.setCenterPos(_rc.left, _rc.getCenterY());
			if (_comboAttackImage2->getFrameX() <= 0)
			{
				_comboAttackImage2->setFrameX(_comboAttackImage2->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_comboAttackRc2.set(0, 0, 0, 0);
				_comboAttack = false;//2���޺� �������� �޽�
				_comboAttack2 = false;//3���޺� �������� �޽�
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK2:
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage2->setFrameX(_comboAttackImage2->getFrameX() + 1);
			_comboAttackRc2.set(0, 0, 100, 50);
			_comboAttackRc2.setCenterPos(_rc.right, _rc.getCenterY());
			if (_comboAttackImage2->getFrameX() >= _comboAttackImage2->getMaxFrameX())
			{
				_comboAttackImage2->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_comboAttackRc2.set(0, 0, 0, 0);
				_comboAttack = false;//2���޺� �������� �޽�
				_comboAttack2 = false;//3���޺� �������� �޽�
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_COMBO_ATTACK3:
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage3->setFrameX(_comboAttackImage3->getFrameX() - 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY());
			if (_comboAttackImage3->getFrameX() <= 0)
			{
				_comboAttackImage3->setFrameX(_comboAttackImage3->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
				_comboAttack = false;//2���޺� �������� �޽�
				_comboAttack2 = false;//3���޺� �������� �޽�
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK3:
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage3->setFrameX(_comboAttackImage3->getFrameX() + 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY());
			if (_comboAttackImage3->getFrameX() >= _comboAttackImage3->getMaxFrameX())
			{
				_comboAttackImage3->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
				_comboAttack = false;//2���޺� �������� �޽�
				_comboAttack2 = false;//3���޺� �������� �޽�
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_STRONG_ATTACK:
		_count++;
		_jump->jumping(&_x, &_z, 5.0f, 0.25f);
		if (_count % 4 == 0)
		{
			_strongAttackImage->setFrameX(_strongAttackImage->getFrameX() + 1);
			_attackRc.set(0, 0, 100, 200);
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY());
			if (_strongAttackImage->getFrameX() >= _strongAttackImage->getMaxFrameX())
			{
				_strongAttackImage->setFrameX(_strongAttackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_STRONG_ATTACK:
		_count++;
		_jump->jumping(&_x, &_z, 5.0f, 0.25f);
		if (_count % 4 == 0)
		{
			_strongAttackImage->setFrameX(_strongAttackImage->getFrameX() - 1);
			_attackRc.set(0, 0, 100, 200);
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY());
			if (_strongAttackImage->getFrameX() <= 0)
			{
				_strongAttackImage->setFrameX(0);
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
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY());
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
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY());
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
		_x -= _runSpeed;
		_jump->jumping(&_x, &_z, 2.0f, 0.16f);
		if (_count % 5 == 0)
		{
			_dashAttackImage->setFrameX(_dashAttackImage->getFrameX() - 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY() - 30);
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
		_x += _runSpeed;
		_jump->jumping(&_x, &_z, 2.0f, 0.16f);
		if (_count % 5 == 0)
		{
			_dashAttackImage->setFrameX(_dashAttackImage->getFrameX() + 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY() - 30);
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

	case PLAYERDIRECTION_LEFT_ULTIMATE:
		_count++;
		if (_count % 5 == 0)
		{
			_ultimateImage->setFrameX(_ultimateImage->getFrameX() - 1);
			if (_ultimateImage->getFrameX() <= 20)
			{
				_ultimate = true;
			}
			_attackRc.set(0, 0, 300, 300);
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY());
			if (_ultimateImage->getFrameX() <= 0)
			{
				_ultimateImage->setFrameX(_ultimateImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_ultimate = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_ULTIMATE:
		_count++;
		if (_count % 5 == 0)
		{
			_ultimateImage->setFrameX(_ultimateImage->getFrameX() + 1);
			if (_ultimateImage->getFrameX() >= 5)
			{
				_ultimate = true;
			}
			_attackRc.set(0, 0, 300, 300);
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY());
			if (_ultimateImage->getFrameX() >= _ultimateImage->getMaxFrameX())
			{
				_ultimateImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_ultimate = false;
				_attackRc.set(0, 0, 0, 0);
			}
		}
		break;
	}
}

//player�� stage �̵� �� player ��ġ ����
//stageOpenDoor ��ǥ�� �������� player x,y ������ ���� ���ִ� �Լ��Դϴ�.
//���ϴ� ��ǥ�� �ٲ� �� ������ �ٲ��ּ���

void player::playerPosition_1at2()
{
	_x = 350;
	_z = WINSIZEY / 2 + 250;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_2at3()
{
	_x = WINSIZEX / 2 + 625;
	_z = WINSIZEY / 2 + 165;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_2at1()
{
	_x = WINSIZEX + 155;
	_z = WINSIZEY / 2 + 100;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_3at2()
{
	_x = WINSIZEX - 245;
	_z = WINSIZEY / 2 + 150;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_3at4()
{
	_x = 350;
	_z = WINSIZEY / 2 + 325;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_4atBoss()
{
	_x = 400;
	_z = WINSIZEY / 2 + 425;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_4at3()
{
	_x = WINSIZEX + 800;
	_z = WINSIZEY / 2 + 300;
	CAMERA->setPosition(_x, _z);
}
