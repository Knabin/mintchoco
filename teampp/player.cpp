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
	_idleImage = IMAGEMANAGER->addFrameImage("playerIdle", "images/player/Kyoko_Idle.bmp", 1440, 450, 12, 2, true, RGB(255, 0, 255));//플레이어 기본 프레임 이미지
	_walkImage = IMAGEMANAGER->addFrameImage("playerWalk", "images/player/Kyoko_Walk.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255));//플레이어 걷는 프레임 이미지
	_runImage = IMAGEMANAGER->addFrameImage("playerRun", "images/player/Kyoko_Run.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255));//플레이어 달리는 프레임 이미지
	_jumpImage = IMAGEMANAGER->addFrameImage("playerJump", "images/player/Kyoko_Jump.bmp", 405, 414, 3, 2, true, RGB(255, 0, 255));//플레이어 점프 프레임 이미지
	_comboAttackImage1 = IMAGEMANAGER->addFrameImage("playerComboAttack1", "images/player/Kyoko_ComboAttack1.bmp", 1548, 390, 6, 2, true, RGB(255, 0, 255));//플레이어 공격 프레임 이미지
	_strongAttackImage = IMAGEMANAGER->addFrameImage("playerStrongAttack", "images/player/Kyoko_StrongAttack.bmp", 3030, 474, 10, 2, true, RGB(255, 0, 255));//플레이어 강공격 프레임 이미지
	_jumpAttackImage = IMAGEMANAGER->addFrameImage("plyaerJumpAttack", "images/player/Kyoko_Jump_Attack.bmp", 1560, 432, 10, 2, true, RGB(255, 0, 255));//플레이어 점프 공격 이미지
	_dashAttackImage = IMAGEMANAGER->addFrameImage("playerDashAttack", "images/player/Kyoko_DashAttack.bmp", 2700, 436, 8, 2, true, RGB(255, 0, 255));//플레이어 대쉬 공격 이미지
	_ultimateImage = IMAGEMANAGER->addFrameImage("playerUltimate", "images/player/Kyoko_Ultimate.bmp", 3675, 384, 25, 2, true, RGB(255, 0, 255));//플레이어 궁극기 이미지

	
	_ultimateAfterImage[0] = IMAGEMANAGER->addFrameImage("playerUltimateAfter", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[1] = IMAGEMANAGER->addFrameImage("playerUltimateAfter2", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[2] = IMAGEMANAGER->addFrameImage("playerUltimateAfter3", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[3] = IMAGEMANAGER->addFrameImage("playerUltimateAfter4", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[4] = IMAGEMANAGER->addFrameImage("playerUltimateAfter5", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[5] = IMAGEMANAGER->addFrameImage("playerUltimateAfter6", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[6] = IMAGEMANAGER->addFrameImage("playerUltimateAfter7", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[7] = IMAGEMANAGER->addFrameImage("playerUltimateAfter8", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[8] = IMAGEMANAGER->addFrameImage("playerUltimateAfter9", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[9] = IMAGEMANAGER->addFrameImage("playerUltimateAfter10", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[10] = IMAGEMANAGER->addFrameImage("playerUltimateAfter11", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[11] = IMAGEMANAGER->addFrameImage("playerUltimateAfter12", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[12] = IMAGEMANAGER->addFrameImage("playerUltimateAfter13", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[13] = IMAGEMANAGER->addFrameImage("playerUltimateAfter14", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[14] = IMAGEMANAGER->addFrameImage("playerUltimateAfter15", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[15] = IMAGEMANAGER->addFrameImage("playerUltimateAfter16", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[16] = IMAGEMANAGER->addFrameImage("playerUltimateAfter17", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[17] = IMAGEMANAGER->addFrameImage("playerUltimateAfter18", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[18] = IMAGEMANAGER->addFrameImage("playerUltimateAfter19", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	_ultimateAfterImage[19] = IMAGEMANAGER->addFrameImage("playerUltimateAfter20", "images/player/Kyoko_Ultimate_Afterimage.bmp", 2793, 352, 19, 2, true, RGB(255, 0, 255));//플레이어 궁극기 잔상 이미지
	
	_shadow = IMAGEMANAGER->addImage("shadow", "images/player/Kyoko_Shadow.bmp", 128, 38, true, RGB(255, 0, 255));//그림자 이미지

	_playerDirection = PLAYERDIRECTION_LEFT_STOP;//플레이어 프레임 상태 초기화

	_x = WINSIZEX / 2 + 300;
	_y = WINSIZEY / 2 + 100;
	_walkSpeed = 3.0f;//플레이어 걷는 스피드
	_runSpeed = 6.0f;//플레이어 달리는 스피드

	_rc.set(0, 0, 80, 180);//플레이어 렉트

	_idleImage->setFrameX(0);
	_idleImage->setFrameY(0);
	//플레이어 기본 이미지의 현재 프레임 초기화

	_walkImage->setFrameX(0);
	_walkImage->setFrameY(0);
	//플레이어 걷는 이미지의 현재 프레임 초기화

	_runImage->setFrameX(0);
	_runImage->setFrameY(0);
	//플레이어 달리는 이미지의 현재 프레임 초기화

	_comboAttackImage1->setFrameX(0);
	_comboAttackImage1->setFrameY(0);
	//플레이어 공격 이미지의 현재 프레임 초기화

	_jumpAttackImage->setFrameX(0);
	_jumpAttackImage->setFrameY(0);
	//플레이어 점프 공격 이미지의 현재 프레임 초기화

	_dashAttackImage->setFrameX(0);
	_dashAttackImage->setFrameY(0);
	//플레이어 대쉬 공격 이미지의 현재 프레임 초기화

	_strongAttackImage->setFrameX(0);
	_strongAttackImage->setFrameY(0);
	//플레이어 강공격 이미지의 현재 프레임 초기화

	_ultimateImage->setFrameX(0);
	_ultimateImage->setFrameY(0);
	//플레이어 궁극기 이미지의 현재 프레임 초기화

	_jump = new jump;
	_jump->init();
	//점프 상속할당

	_r = 255;
	_g = 0;
	_b = 255;
	//픽셀충돌에 사용할 rgb값

	_ultimateAfterCount = _count = _index = _time = _clickTime = 0;//플레이어 프레임에 사용할 변수
	_jumpPower = 12.0f;//플레이어 점프값
	_gravity = 0.4f;//플레이어 점프값
	_jumping = false;//플레이어가 점프이후 렉트를 실시간으로 업데이트 시켜주기 위한 변수
	_attack = false;//공격이 실행중인지 여부 확인
	_dash = false;//대쉬
	_ultimate = false;//궁극기
	_probeX = _x + _walkImage->getFrameWidth() / 2;//x좌표 픽셀충돌
	_probeY = _y + _walkImage->getFrameHeight() / 2;//y좌표 픽셀충돌

	return S_OK;
}



void player::update()
{
	attack();//플레이어 공격

	leftMove();//왼쪽이동

	rightMove();//오른쪽 이동

	runTime();//따닥 감지

	upMove();//위쪽 이동

	downMove();//아래쪽 이동

	jumpMove();//점프

	frameDraw();//프레임 관리

	_rc.setCenterPos(_x, _y);

	cout << "_playerDirection : " << _playerDirection << endl;

}

void player::render()
{
	_rc.render(getMemDC());//플레이어 렉트
	//_attackRc.render(getMemDC());//플레이어 공격 렉트
	if (!_jumping)
	{
		_shadow->render(getMemDC(), _rc.left - FRAMEPOSX, _rc.bottom - 20);//그림자
	}
	else
	{
		_shadow->render(getMemDC(), _rc.left - FRAMEPOSX, _startY + 60);//그림자
	}
	if (_ultimate)
	{
		for (int i = 0; i < ULTIMATECOUNT; i++)
		{
			_ultimateAfterCount++;
			if (_ultimateAfterCount % 5 == 0)
			{
				if (_playerDirection == PLAYERDIRECTION_RIGHT_ULTIMATE)
				{
					_ultimateAfterImage[i]->frameRender(getMemDC(), _rc.left - 40 - ((i + 1) * 5), _rc.top);
				}

				if (_playerDirection == PLAYERDIRECTION_LEFT_ULTIMATE)
				{
					_ultimateAfterImage[i]->frameRender(getMemDC(), _rc.left + ((i + 1) * 5), _rc.top + 10);
				}
				
				_ultimateAfterCount = 0;
			}
		}
	}
	switch (_playerDirection)//플레이어의 프레임 상태값에 따른 렌더
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
	case PLAYERDIRECTION_RIGHT_STRONG_ATTACK:
		ZORDER->pushObject(getMemDC(), _strongAttackImage, _strongAttackImage->getFrameX(), _strongAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_STRONG_ATTACK:
		ZORDER->pushObject(getMemDC(), _strongAttackImage, _strongAttackImage->getFrameX(), _strongAttackImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_RIGHT_ULTIMATE:
		ZORDER->pushObject(getMemDC(), _ultimateImage, _ultimateImage->getFrameX(), _ultimateImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	case PLAYERDIRECTION_LEFT_ULTIMATE:
		ZORDER->pushObject(getMemDC(), _ultimateImage, _ultimateImage->getFrameX(), _ultimateImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _rc.bottom);
		break;
	}
}

void player::release()
{
}

void player::attack()
{
	if (KEYMANAGER->isOnceKeyDown('A') && !keyJump())//약공격
	{
		if (!_jumping)//점프중이 아닐때
		{
			_attack = true;
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)//기본, 걷기일때 공격
			{
				_playerDirection = PLAYERDIRECTION_LEFT_COBMO_ATTACK1;
				_comboAttackImage1->setFrameX(_comboAttackImage1->getMaxFrameX());
				_comboAttackImage1->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)//기본, 걷기일때 공격
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_COMBO_ATTACK1;
				_comboAttackImage1->setFrameX(0);
				_comboAttackImage1->setFrameY(1);
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_MOVE)//달리기
			{
				_playerDirection = PLAYERDIRECTION_LEFT_DASH_ATTACK;
				_dashAttackImage->setFrameX(_dashAttackImage->getMaxFrameX());
				_dashAttackImage->setFrameY(0);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_MOVE)//달리기
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_DASH_ATTACK;
				_dashAttackImage->setFrameX(0);
				_dashAttackImage->setFrameY(1);
			}

		}
		else//점프중일때
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

	if (KEYMANAGER->isOnceKeyDown('S') && !keyJump())//강공격
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

	if (KEYMANAGER->isOnceKeyDown('F') && !keyJump())//궁극기
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
	if (KEYMANAGER->isOnceKeyDown('D') && !keyAttack())//점프
	{
		if (!_attack && !_jumping)//공격중이 아닐때 && 점프중복방지
		{
			_jumping = true;
			_startY = _y;
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
	}
	_jump->update();//점프 업데이트
}

void player::leftMove()
{
	if (!_dash)//걷기
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

			if (_jumping && !_attack)//점프중에 프레임 변경
			{
				_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
				_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
				_jumpImage->setFrameY(0);
			}

			if (!_attack && !keyRight())//점프중에 움직이는거 허용
			{
				_x -= _walkSpeed;
			}

		}
	}

	else//달리기
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

			if (!_attack && !keyRight())//점프중에 움직이는거 허용
			{
				_x -= _runSpeed;
			}

		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))//왼쪽키를 뗏으면
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
	if (!_dash)//걷기
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

			if (_jumping && !_attack)//점프중에 프레임 변경
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
				_jumpImage->setFrameX(0);
				_jumpImage->setFrameY(1);
			}

			if (!_attack && !keyLeft())//점프중에 움직이는거 허용
			{
				_x += _walkSpeed;
			}
		}
	}

	else//달리기
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

			if (!_attack && !keyLeft())//점프중에 움직이는거 허용
			{
				_x += _runSpeed;
			}
		}

	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))//오른쪽키를 뗏으면
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
				_startY -= _walkSpeed;//점프한 상태에서 위쪽으로 움직일경우 점프의 시작점을 옮겨주기 위한 코드
			}
			_y -= _walkSpeed;
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_UP))//위쪽키를 뗏으면
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
				_startY -= _walkSpeed;//점프한 상태에서 위쪽으로 움직일경우 점프의 시작점을 옮겨주기 위한 코드
			}
			_y += _walkSpeed;
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))//아래키를 뗏으면
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

	case PLAYERDIRECTION_LEFT_JUMP://왼쪽으로 점프
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
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY() - 10);
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
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY() - 10);
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

	case PLAYERDIRECTION_LEFT_STRONG_ATTACK:
		_count++;
		_jumping = true;
		_jump->jumping(&_x, &_y, 5.0f, 0.25f);
		if (_count % 4 == 0)
		{
			_strongAttackImage->setFrameX(_strongAttackImage->getFrameX() + 1);
			_attackRc.set(0, 0, 100, 200);
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY());
			if (_strongAttackImage->getFrameX() >= _strongAttackImage->getMaxFrameX())
			{
				_strongAttackImage->setFrameX(_strongAttackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_jumping = false;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_STRONG_ATTACK:
		_count++;
		_jumping = true;
		_jump->jumping(&_x, &_y, 5.0f, 0.25f);
		if (_count % 4 == 0)
		{
			_strongAttackImage->setFrameX(_strongAttackImage->getFrameX() - 1);
			_attackRc.set(0, 0, 100, 200);
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY());
			if (_strongAttackImage->getFrameX() <= 0)
			{
				_strongAttackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_jumping = false;
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
		_jumping = true;
		_jump->jumping(&_x, &_y, 2.0f, 0.16f);
		if (_count % 5 == 0)
		{
			_dashAttackImage->setFrameX(_dashAttackImage->getFrameX() - 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY() - 30);
			if (_dashAttackImage->getFrameX() <= 0)
			{
				_dashAttackImage->setFrameX(_dashAttackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_jumping = false;
				_attack = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_DASH_ATTACK:
		_count++;
		_x += _runSpeed;
		_jumping = true;
		_jump->jumping(&_x, &_y, 2.0f, 0.16f);
		if (_count % 5 == 0)
		{
			_dashAttackImage->setFrameX(_dashAttackImage->getFrameX() + 1);
			_attackRc.set(0, 0, 100, 50);
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY() - 30);
			if (_dashAttackImage->getFrameX() >= _dashAttackImage->getMaxFrameX())
			{
				_dashAttackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_jumping = false;
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
