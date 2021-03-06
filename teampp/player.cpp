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
	_comboAttackImage2 = IMAGEMANAGER->addFrameImage("playerComboAttack2", "images/player/Kyoko_ComboAttack2.bmp", 1869, 402, 7, 2, true, RGB(255, 0, 255));//플레이어 공격 프레임 이미지2
	_comboAttackImage3 = IMAGEMANAGER->addFrameImage("playerComboAttack3", "images/player/Kyoko_ComboAttack3.bmp", 2970, 462, 9, 2, true, RGB(255, 0, 255));//플레이어 공격 프레임 이미지3
	_strongAttackImage = IMAGEMANAGER->addFrameImage("playerStrongAttack", "images/player/Kyoko_StrongAttack.bmp", 3030, 474, 10, 2, true, RGB(255, 0, 255));//플레이어 강공격 프레임 이미지
	_jumpAttackImage = IMAGEMANAGER->addFrameImage("plyaerJumpAttack", "images/player/Kyoko_Jump_Attack.bmp", 1560, 432, 10, 2, true, RGB(255, 0, 255));//플레이어 점프 공격 이미지
	_dashAttackImage = IMAGEMANAGER->addFrameImage("playerDashAttack", "images/player/Kyoko_DashAttack.bmp", 2700, 436, 8, 2, true, RGB(255, 0, 255));//플레이어 대쉬 공격 이미지
	_ultimateImage = IMAGEMANAGER->addFrameImage("playerUltimate", "images/player/Kyoko_Ultimate.bmp", 3675, 384, 25, 2, true, RGB(255, 0, 255));//플레이어 궁극기 이미지
	_guardImage = IMAGEMANAGER->addFrameImage("playerGuard", "images/player/Kyoko_Guard.bmp", 351, 378, 3, 2, true, RGB(255, 0, 255));//플레이어 방어 이미지
	_downImage = IMAGEMANAGER->addFrameImage("playerDown", "images/player/Kyoko_Down.bmp", 4896, 366, 24, 2, true, RGB(255, 0, 255));//플레이어 피격당했을때 다운 이미지
	_deadImage = IMAGEMANAGER->addFrameImage("playerDead", "images/player/Kyoko_GameOver.bmp", 6240, 282, 26, 2, true, RGB(255, 0, 255));//플레이어 사망 이미지
	_hitImage = IMAGEMANAGER->addFrameImage("playerHit", "images/player/Kyoko_Hit.bmp", 236, 348, 2, 2, true, RGB(255, 0, 255));//플레이어 피격 당할때 이미지
	_runEffect = IMAGEMANAGER->addFrameImage("playerRunEffect", "images/player/Kyoko_Run_Effect.bmp", 2544, 246, 12, 2, true, RGB(255, 0, 255));//플레이어가 달릴때 생기는 먼지 이펙트 이미지

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

	_x = WINSIZEX / 2 + 500;
	_z = WINSIZEY / 2 + 300;
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

	_comboAttackImage2->setFrameX(0);
	_comboAttackImage2->setFrameY(0);
	//플레이어 공격 이미지2의 현재 프레임 초기화

	_comboAttackImage3->setFrameX(0);
	_comboAttackImage3->setFrameY(0);
	//플레이어 공격 이미지3의 현재 프레임 초기화

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

	_guardImage->setFrameX(0);
	_guardImage->setFrameY(0);
	//플레이어 방어 이미지의 현재 프레임 초기화

	_downImage->setFrameX(0);
	_downImage->setFrameY(0);
	//플레이어가 피격 당했을때 다운당하는 이미지의 현재 프레임 초기화

	_deadImage->setFrameX(0);
	_deadImage->setFrameY(0);
	//플레이어가 보스에게 강공격을 당했을때 다운당할 이미지의 현재 프레임 초기화

	_hitImage->setFrameX(0);
	_hitImage->setFrameY(0);
	//플레이어가 공격 당했을때 생길 이미지의 현재 프레임 초기화

	_runEffect->setFrameX(0);
	_runEffect->setFrameY(0);
	//플레이어가 달릴때 생기는 먼지 이펙트 이미지의 현재 프레임 초기화

	_jump = new jump;
	_jump->init();
	//점프 상속할당

	_ultimateAfterCount = _count = _index = _time = _clickTime = 0;//플레이어 프레임에 사용할 변수
	_jumpPower = 15.0f;//플레이어 점프값
	_gravity = 15.0f;//플레이어 점프값
	_jumping = false;//플레이어가 점프이후 렉트를 실시간으로 업데이트 시켜주기 위한 변수
	_attack = false;//공격이 실행중인지 여부 확인
	_dash = false;//대쉬
	_ultimate = false;//궁극기
	_comboAttack = false;//콤보공격 프레임에 사용할 변수
	_comboAttack2 = false;//콤보공격 3단계 실행여부를 확인하기 위한 변수
	_guard = false;//플레이어 방어
	_pixelCollision = false;//장애물 픽셀 충돌 조건 확인용
	_oneFramePlay = false;//히트, 다운 프레임의 set상태를 한번씩만 초기화가 되게 하기위해 사용할 변수
	_jumpingHit = false;//점프중에 맞으면 플레이어의 렉트위치를 점프파워만큼 위로 올려주기 위해 필요한 변수
	_deadOneFramePlay = false;//점프중에 맞으면 플레이어의 렉트위치를 점프파워만큼 위로 올려주기 위해 필요한 변수

	_yPlayerY = 0;
	_playerImage = _idleImage;
	_hp = 26;
	_coin = 0;

	{
		SOUNDMANAGER->addSound("attack1", "sounds/effect/player_punch_01.wav", false, false);
		SOUNDMANAGER->addSound("attack2", "sounds/effect/player_punch_02.wav", false, false);
		SOUNDMANAGER->addSound("attack3", "sounds/effect/player_punch_03.wav", false, false);
		SOUNDMANAGER->addSound("attack1 v1", "sounds/effect/vo_kyoko_effort_15.wav", false, false);
		SOUNDMANAGER->addSound("attack1 v2", "sounds/effect/vo_kyoko_effort_16.wav", false, false);
		SOUNDMANAGER->addSound("attack3 v", "sounds/effect/vo_kyoko_effort_08.wav", false, false);
		SOUNDMANAGER->addSound("attack dash", "sounds/effect/player_kyoko_dropkick.wav", false, false);
		SOUNDMANAGER->addSound("attack dash v", "sounds/effect/vo_kyoko_effort_44.wav", false, false);
		SOUNDMANAGER->addSound("attack str", "sounds/effect/player_kyoko_axe_kick.wav", false, false);
		SOUNDMANAGER->addSound("attack str v1", "sounds/effect/vo_kyoko_effort_02.wav", false, false);
		SOUNDMANAGER->addSound("attack str v2", "sounds/effect/vo_kyoko_effort_03.wav", false, false);

		SOUNDMANAGER->addSound("jump", "sounds/effect/player_jump.wav", false, false);
		SOUNDMANAGER->addSound("land", "sounds/effect/player_land.wav", false, false);
		SOUNDMANAGER->addSound("dab", "sounds/effect/player_kyoko_dab_slam.wav", false, false);

		SOUNDMANAGER->addSound("gameover", "sounds/menu/interface_game_over.wav", false, false);
	}

	return S_OK;
}



void player::update()
{
	if (_hp >= 27)
	{
		_hp = 26;
	}


	if (_hp >= 1)
	{
		attack();//플레이어 공격

		leftMove();//왼쪽이동

		rightMove();//오른쪽 이동

		runTime();//따닥 감지

		upMove();//위쪽 이동

		downMove();//아래쪽 이동

		guard();//플레이어 방어
	}
		jumpMove();//점프

		
	

	frameDraw();//프레임 관리

	

	if (_jumping && !_pixelCollision && !_jumpingHit)
	{
		_rc.setCenterPos(_x, _z - _jump->getJumpPower() - _rc.getHeight() / 2);
	}
	else if (!_jumping && !_pixelCollision && !_jumpingHit)
	{
		_rc.setCenterPos(_x, _z - _rc.getHeight() / 2);
	}
	else if (_jumpingHit)
	{
		_rc.setCenterPos(_x, _z - _jump->getJumpPower() - _rc.getHeight() / 2);
	}

	if (_comboAttack)
	{
		_comboAttackRc1.set(0, 0, 0, 0);
	}
	if (_comboAttack2)
	{
		_comboAttackRc2.set(0, 0, 0, 0);
	}

	if (_z <= _z - _jump->getJumpPower())
	{
		_jumpingHit = false;
	}

	if (_hp <= 0)
	{
		if (_playerDirection == PLAYERDIRECTION_LEFT_COMBO_ATTACK1 || _playerDirection == PLAYERDIRECTION_LEFT_COMBO_ATTACK2 || _playerDirection == PLAYERDIRECTION_LEFT_COMBO_ATTACK3 ||
			_playerDirection == PLAYERDIRECTION_LEFT_DASH_ATTACK || _playerDirection == PLAYERDIRECTION_LEFT_GUARD || _playerDirection == PLAYERDIRECTION_LEFT_HIT ||
			_playerDirection == PLAYERDIRECTION_LEFT_JUMP || _playerDirection == PLAYERDIRECTION_LEFT_JUMP_ATTACK || _playerDirection == PLAYERDIRECTION_LEFT_MOVE ||
			_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_STRONG_ATTACK || _playerDirection == PLAYERDIRECTION_LEFT_ULTIMATE ||
			_playerDirection == PLAYERDIRECTION_LEFT_WALK)
		{
			_playerDirection = PLAYERDIRECTION_LEFT_DEAD;
		}
		else if (_playerDirection == PLAYERDIRECTION_RIGHT_COMBO_ATTACK1 || _playerDirection == PLAYERDIRECTION_RIGHT_COMBO_ATTACK2 || _playerDirection == PLAYERDIRECTION_RIGHT_COMBO_ATTACK3 ||
			_playerDirection == PLAYERDIRECTION_RIGHT_DASH_ATTACK || _playerDirection == PLAYERDIRECTION_RIGHT_GUARD || _playerDirection == PLAYERDIRECTION_RIGHT_HIT ||
			_playerDirection == PLAYERDIRECTION_RIGHT_JUMP || _playerDirection == PLAYERDIRECTION_RIGHT_JUMP_ATTACK || _playerDirection == PLAYERDIRECTION_RIGHT_MOVE ||
			_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_STRONG_ATTACK || _playerDirection == PLAYERDIRECTION_RIGHT_ULTIMATE ||
			_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
		{
			_playerDirection = PLAYERDIRECTION_RIGHT_DEAD;
		}
	}

	switch (_stageManager->getNowStage())
	{
	case 0:
		pixelCollision("stage1_pixel");
		break;
	case 1:
		pixelCollision("stage2_pixel");
		break;
	case 2:
		pixelCollision("stage3_pixel");
		break;
	case 3:
		pixelCollision("stage4_pixel");
		break;
	case 4:
		pixelCollision("boss_stage_pixel");
		break;
	}

	//cout << _hp << endl;
}

void player::render()
{

	//_rc.render(getMemDC());//플레이어 렉트
	//_attackRc.render(getMemDC());//플레이어 공격 렉트
	//_comboAttackRc1.render(getMemDC());//1단계 콤보공격 렉트
	//_comboAttackRc2.render(getMemDC());//2단계 콤보공격 렉트

	if (!_pixelCollision)
		ZORDER->pushShadowObject(getMemDC(), _shadow, 3, _rc.getCenterX(), 0, _z + 15);
	else if (_pixelCollision)
	{
		ZORDER->pushShadowObject(getMemDC(), _shadow, 3, _rc.getCenterX(), _z - _yPlayerY, _z + 15);
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
					_ultimateAfterImage[i]->frameRender(getMemDC(), _rc.left - 40 - ((i + 1) * 5), _rc.bottom - _ultimateAfterImage[i]->getFrameHeight());
				}

				if (_playerDirection == PLAYERDIRECTION_LEFT_ULTIMATE)
				{
					_ultimateAfterImage[i]->frameRender(getMemDC(), _rc.left + ((i + 1) * 5), _rc.bottom - _ultimateAfterImage[i]->getFrameHeight() + 15);
				}

				_ultimateAfterCount = 0;
			}
		}
	}

	switch (_playerDirection)//플레이어의 프레임 상태값에 따른 렌더
	{
		if (_hp >= 1)
		{
	case PLAYERDIRECTION_RIGHT_STOP:
	case PLAYERDIRECTION_LEFT_STOP:
		_playerImage = _idleImage;
		break;
	case PLAYERDIRECTION_RIGHT_WALK:
	case PLAYERDIRECTION_LEFT_WALK:
		_playerImage = _walkImage;
		break;
	case PLAYERDIRECTION_RIGHT_MOVE:
		_playerImage = _runImage;
		_runEffect->frameRender(getMemDC(), _rc.left - 180, _rc.getCenterY() - 30, _runEffect->getFrameX(), _runEffect->getFrameY());
		break;
	case PLAYERDIRECTION_LEFT_MOVE:
		_playerImage = _runImage;
		_runEffect->frameRender(getMemDC(), _rc.getCenterX(), _rc.getCenterY() - 30, _runEffect->getFrameX(), _runEffect->getFrameY());
		break;
	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK1:
	case PLAYERDIRECTION_LEFT_COMBO_ATTACK1:
		_playerImage = _comboAttackImage1;
		break;
	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK2:
	case PLAYERDIRECTION_LEFT_COMBO_ATTACK2:
		_playerImage = _comboAttackImage2;
		break;
	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK3:
	case PLAYERDIRECTION_LEFT_COMBO_ATTACK3:
		_playerImage = _comboAttackImage3;
		break;
	case PLAYERDIRECTION_RIGHT_JUMP:
	case PLAYERDIRECTION_LEFT_JUMP:
		_playerImage = _jumpImage;
		break;
	case PLAYERDIRECTION_RIGHT_JUMP_ATTACK:
	case PLAYERDIRECTION_LEFT_JUMP_ATTACK:
		_playerImage = _jumpAttackImage;
		break;
	case PLAYERDIRECTION_RIGHT_DASH_ATTACK:
	case PLAYERDIRECTION_LEFT_DASH_ATTACK:
		_playerImage = _dashAttackImage;
		break;
	case PLAYERDIRECTION_RIGHT_STRONG_ATTACK:
	case PLAYERDIRECTION_LEFT_STRONG_ATTACK:
		_playerImage = _strongAttackImage;
		break;
	case PLAYERDIRECTION_RIGHT_ULTIMATE:
	case PLAYERDIRECTION_LEFT_ULTIMATE:
		_playerImage = _ultimateImage;
		break;
	case PLAYERDIRECTION_RIGHT_GUARD:
	case PLAYERDIRECTION_LEFT_GUARD:
		_playerImage = _guardImage;
		break;
	case PLAYERDIRECTION_RIGHT_DOWN:
	case PLAYERDIRECTION_LEFT_DOWN:
		_playerImage = _downImage;
		break;
	case PLAYERDIRECTION_RIGHT_HIT:
	case PLAYERDIRECTION_LEFT_HIT:
		_playerImage = _hitImage;
		break;
		}
	case PLAYERDIRECTION_RIGHT_DEAD:
	case PLAYERDIRECTION_LEFT_DEAD:
		_playerImage = _deadImage;
		break;
	}

	if (!_pixelCollision)
		ZORDER->pushObject(getMemDC(), _playerImage, _playerImage->getFrameX(), _playerImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower(), _z);
	else
	{
		ZORDER->pushObject(getMemDC(), _playerImage, _playerImage->getFrameX(), _playerImage->getFrameY(), 0, _rc.getCenterX(), _jump->getJumpPower() + _z - _yPlayerY, _z);
	}


	RectangleMakeCenter(getMemDC(), _x, _rc.bottom, 10, 10);
	RectangleMakeCenter(getMemDC(), _rc.left, _rc.getCenterY(), 10, 10);
	RectangleMakeCenter(getMemDC(), _rc.right, _rc.getCenterY(), 10, 10);
	RectangleMakeCenter(getMemDC(), _rc.getCenterX(), _rc.top - 30, 10, 10);
}

void player::release()
{
}

void player::guard()
{
	if (_playerDirection != PLAYERDIRECTION_LEFT_DEAD && _playerDirection != PLAYERDIRECTION_LEFT_DOWN && _playerDirection != PLAYERDIRECTION_LEFT_HIT &&
		_playerDirection != PLAYERDIRECTION_RIGHT_DEAD && _playerDirection != PLAYERDIRECTION_RIGHT_DOWN && _playerDirection != PLAYERDIRECTION_RIGHT_HIT)
	{
		if (KEYMANAGER->isStayKeyDown(VK_SPACE) && !keyAttack())
		{
			if (!_jumping && !_attack)
			{
				if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK || _playerDirection == PLAYERDIRECTION_LEFT_MOVE)
				{
					_guard = true;
					_playerDirection = PLAYERDIRECTION_LEFT_GUARD;
					_guardImage->setFrameX(_guardImage->getMaxFrameX());
					_guardImage->setFrameY(0);
				}

				if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK || _playerDirection == PLAYERDIRECTION_RIGHT_MOVE)
				{
					_guard = true;
					_playerDirection = PLAYERDIRECTION_RIGHT_GUARD;
					_guardImage->setFrameX(0);
					_guardImage->setFrameY(1);
				}
			}
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_SPACE))
	{
		_guard = false;
		if (_playerDirection == PLAYERDIRECTION_LEFT_GUARD)
		{
			_playerDirection = PLAYERDIRECTION_LEFT_STOP;
		}
		if (_playerDirection == PLAYERDIRECTION_RIGHT_GUARD)
		{
			_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
		}
	}

}

void player::pixelCollision(string stageName)
{
	if (_jump->getGravity() < 0 && _jumping)
	{
		_pixelCollision = false;
	}


	if (!_pixelCollision)
	{
		for (int i = _rc.right - 100 + 3; i > _rc.right - 100 - 3; i--)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _z);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);


			if ((r == 255 && g == 0 && b == 0) || (!_jumping && (r == 0 && g == 255 && b == 0)))
			{
				_x = i + 103 - (_rc.getWidth() / 2);
				break;
			}
		}

		for (int i = _rc.left + 100 - 3; i < _rc.left + 100 + 3; i++)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _z);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 255 && g == 0 && b == 0) || (!_jumping && (r == 0 && g == 255 && b == 0)))
			{
				_x = i - 103 + (_rc.getWidth() / 2);
				break;
			}
		}

		for (int i = _z - 30 + 3; i > _z - 30 - 3; i--)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 255 && g == 0 && b == 0) || (!_jumping && (r == 0 && g == 255 && b == 0)))
			{
				_z = i + 30;
				break;
			}
		}

		for (int i = _z + 10 - 3; i < _z + 10 + 3; i++)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 255 && g == 255 && b == 255))
			{
				_z = i - 10;
				break;
			}
		}

		for (int i = _z - 40 - 3; i < _z - 40 + 3; i++)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 255 && g == 255 && b == 0) && !_jumping)
			{
				_z = i + 40;
				break;
			}
		}

		for (int i = _rc.right + 3; i > _rc.right - 3; i--)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _z - 30);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);



			if ((r == 0 && g == 0 && b == 255) && !_jumping)
			{
				if (_playerDirection == PLAYERDIRECTION_RIGHT_WALK)
					_x = i - 6 - (_rc.getWidth() / 2);
				else
				{
					_x = i - 9 - (_rc.getWidth() / 2);
				}
				break;
			}
		}



		for (int i = _rc.left - 3; i < _rc.left + 3; i++)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _z - 30);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);



			if ((r == 0 && g == 0 && b == 255) && !_jumping)
			{

				if (_playerDirection == PLAYERDIRECTION_LEFT_WALK)
					_x = i + 6 + (_rc.getWidth() / 2);
				else
				{
					_x = i + 9 + (_rc.getWidth() / 2);
				}
				break;
			}
		}
	}


	if (stageName == "stage1_pixel")
	{
		if (_jumping && _jump->getGravity() < 0 && _z < 560.f)
		{
			for (int i = _rc.bottom - 3; i < _rc.bottom + 3; i++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _x, i);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 255 && g == 255 && b == 0))
				{
					_pixelCollision = true;
					_jumping = false;
					_jump->setJumpPower(0);

					_rc.setCenterPos(_x, i + 70);

					_yPlayerY = i + 70;
					if (_playerDirection == PLAYERDIRECTION_LEFT_JUMP)
					{
						_playerDirection = PLAYERDIRECTION_LEFT_STOP;
					}
					if (_playerDirection == PLAYERDIRECTION_RIGHT_JUMP)
					{
						_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
					}
					SOUNDMANAGER->play("land");

					break;
				}
			}
		}
	}

	if (stageName == "stage4_pixel")
	{
		if (_jumping && _jump->getGravity() < 0 && _z < 560.f)
		{
			for (int i = _rc.bottom - 3; i < _rc.bottom + 3; i++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _x, i);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 255 && g == 255 && b == 0))
				{
					_pixelCollision = true;
					_jumping = false;
					_jump->setJumpPower(0);

					_rc.setCenterPos(_x, i + 10);

					_yPlayerY = i + 10;
					if (_playerDirection == PLAYERDIRECTION_LEFT_JUMP)
					{
						_playerDirection = PLAYERDIRECTION_LEFT_STOP;
					}
					if (_playerDirection == PLAYERDIRECTION_RIGHT_JUMP)
					{
						_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
					}
					SOUNDMANAGER->play("land");

					break;
				}
			}
		}
	}


	if (_pixelCollision && !_jumping)
	{
		if (_stageManager->getNowstage1())
		{
			for (int i = _x - 10; i < _x + 10; i++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _yPlayerY);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 255 && g == 0 && b == 255) || (r == 255 && g == 0 && b == 0) || (r == 0 && g == 255 && b == 0))
				{
					if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK || _playerDirection == PLAYERDIRECTION_LEFT_MOVE)
					{
						_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
						_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
						_jumpImage->setFrameY(0);
					}
					else
					{
						_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
						_jumpImage->setFrameX(0);
						_jumpImage->setFrameY(1);
					}


					_jump->jumping(&_x, &_z, 180, 10);
					_jumping = true;

					_z = _yPlayerY + 100;
					_pixelCollision = false;

					break;
				}
			}




			_rc.setCenterPos(_x, _yPlayerY - _rc.getHeight() / 2);
		}
		else if (_stageManager->getNowstage4())
		{


			if (_x > 700)
			{
				for (int i = _rc.right + 3; i > _rc.right - 3; i--)
				{
					COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _yPlayerY);

					int r = GetRValue(color);
					int g = GetGValue(color);
					int b = GetBValue(color);


					if ((r == 255 && g == 0 && b == 0))
					{
						_x = i - 4 - (_rc.getWidth() / 2);
						break;
					}
				}

				for (int i = _x - 10; i < _x + 10; i++)
				{
					COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _yPlayerY);

					int r = GetRValue(color);
					int g = GetGValue(color);
					int b = GetBValue(color);

					if ((r == 255 && g == 0 && b == 0) || (r == 0 && g == 255 && b == 0))
					{
						if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK || _playerDirection == PLAYERDIRECTION_LEFT_MOVE)
						{
							_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
							_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
							_jumpImage->setFrameY(0);
						}
						else
						{
							_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
							_jumpImage->setFrameX(0);
							_jumpImage->setFrameY(1);
						}
						if (KEYMANAGER->isStayKeyDown(VK_DOWN))
							_z = 560;
						if (KEYMANAGER->isStayKeyDown(VK_UP))
							_z = 520;

						_jumping = true;
						_jump->jumping(&_x, &_z, 180, 10);
						_pixelCollision = false;
						break;
					}
				}


			}


			if (_x < 700)
			{
				for (int i = _x - 10; i < _x + 10; i++)
				{
					COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _yPlayerY);

					int r = GetRValue(color);
					int g = GetGValue(color);
					int b = GetBValue(color);

					if ((r == 255 && g == 0 && b == 0) || (r == 0 && g == 255 && b == 0))
					{
						if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK || _playerDirection == PLAYERDIRECTION_LEFT_MOVE)
						{
							_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
							_jumpImage->setFrameX(_jumpImage->getMaxFrameX());
							_jumpImage->setFrameY(0);
						}
						else
						{
							_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
							_jumpImage->setFrameX(0);
							_jumpImage->setFrameY(1);
						}
						if (KEYMANAGER->isStayKeyDown(VK_DOWN))
							_z = 560;
						if (KEYMANAGER->isStayKeyDown(VK_UP))
							_z = 520;

						_jumping = true;
						_jump->jumping(&_x, &_z, 180, 10);
						_pixelCollision = false;
						break;
					}
				}


				if (_pixelCollision)
					for (int i = _rc.left - 3; i < _rc.left + 3; i++)
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), i, _yPlayerY);

						int r = GetRValue(color);
						int g = GetGValue(color);
						int b = GetBValue(color);

						if ((r == 255 && g == 0 && b == 0))
						{
							_x = i + 4 + (_rc.getWidth() / 2);
							break;
						}
					}
			}

			for (int i = _yPlayerY - 15; i < _yPlayerY - 10; i++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _x, i);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 0 && g == 255 && b == 0))
				{
					_yPlayerY = i + 18;
					break;
				}
			}


			for (int i = _yPlayerY - 1; i < _yPlayerY + 1; i++)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _x, i);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if ((r == 255 && g == 0 && b == 255))
				{
					_pixelCollision = false;
					break;
				}
			}

		}


	}
	if (_pixelCollision)
	{
		_rc.setCenterPos(_x, _yPlayerY - _rc.getHeight() / 2 - _jump->getJumpPower());
	}

	if (_pixelCollision && !_jumping)
	{

		for (int i = _z - 3; i < _z + 3; i++)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage(stageName)->getMemDC(), _x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);



			if (!(r == 255 && g == 0 && b == 255))
			{
				_z = i + 5;
				break;
			}
		}

	}



}

void player::attack()
{
	if (KEYMANAGER->isOnceKeyDown('A') && !keyJump())//약공격
	{
		if (!_jumping && !_guard)//점프중이 아닐때
		{
			_attack = true;
			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP && !_comboAttack || _playerDirection == PLAYERDIRECTION_LEFT_WALK && !_comboAttack)//기본, 걷기일때 공격
			{
				_playerDirection = PLAYERDIRECTION_LEFT_COMBO_ATTACK1;
				_comboAttackImage1->setFrameX(_comboAttackImage1->getMaxFrameX());
				_comboAttackImage1->setFrameY(0);
				SOUNDMANAGER->play("attack1");
				int r = RND->getInt(4);
				if (r == 0) SOUNDMANAGER->play("attack1 v1", 0.7f);
				else if (r == 1) SOUNDMANAGER->play("attack1 v2", 0.7f);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP && !_comboAttack || _playerDirection == PLAYERDIRECTION_RIGHT_WALK && !_comboAttack)//기본, 걷기일때 공격
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_COMBO_ATTACK1;
				_comboAttackImage1->setFrameX(0);
				_comboAttackImage1->setFrameY(1);
				SOUNDMANAGER->play("attack1");
				int r = RND->getInt(4);
				if (r == 0) SOUNDMANAGER->play("attack1 v1", 0.7f);
				else if (r == 1) SOUNDMANAGER->play("attack1 v2", 0.7f);
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_COMBO_ATTACK1 && _comboAttack && _comboAttackImage1->getFrameX() <= 2)//2단콤보
			{
				_playerDirection = PLAYERDIRECTION_LEFT_COMBO_ATTACK2;
				_comboAttackImage2->setFrameX(_comboAttackImage2->getMaxFrameX());
				_comboAttackImage2->setFrameY(0);
				SOUNDMANAGER->play("attack2");
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_COMBO_ATTACK1 && _comboAttack && _comboAttackImage1->getFrameX() >= _comboAttackImage1->getMaxFrameX() - 2)//2단콤보
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_COMBO_ATTACK2;
				_comboAttackImage2->setFrameX(0);
				_comboAttackImage2->setFrameY(1);
				SOUNDMANAGER->play("attack2");
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_COMBO_ATTACK2 && _comboAttack2 && _comboAttackImage2->getFrameX() <= 2)//3단콤보
			{
				_playerDirection = PLAYERDIRECTION_LEFT_COMBO_ATTACK3;
				_comboAttackImage3->setFrameX(_comboAttackImage3->getMaxFrameX());
				_comboAttackImage3->setFrameY(0);
				SOUNDMANAGER->play("attack3");
				SOUNDMANAGER->play("attack3 v", 0.7f);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_COMBO_ATTACK2 && _comboAttack2 && _comboAttackImage2->getFrameX() >= _comboAttackImage2->getMaxFrameX() - 2)//3단콤보
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_COMBO_ATTACK3;
				_comboAttackImage3->setFrameX(0);
				_comboAttackImage3->setFrameY(1);
				SOUNDMANAGER->play("attack3");
				SOUNDMANAGER->play("attack3 v", 0.7f);
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_MOVE)//달리기
			{
				_playerDirection = PLAYERDIRECTION_LEFT_DASH_ATTACK;
				_dashAttackImage->setFrameX(_dashAttackImage->getMaxFrameX());
				_dashAttackImage->setFrameY(0);
				SOUNDMANAGER->play("attack dash");
				if (RND->getInt(2) == 0) SOUNDMANAGER->play("attack dash v", 0.7f);
			}

			if (_playerDirection == PLAYERDIRECTION_RIGHT_MOVE)//달리기
			{
				_playerDirection = PLAYERDIRECTION_RIGHT_DASH_ATTACK;
				_dashAttackImage->setFrameX(0);
				_dashAttackImage->setFrameY(1);
				SOUNDMANAGER->play("attack dash");
				if (RND->getInt(2) == 0) SOUNDMANAGER->play("attack dash v", 0.7f);
			}

		}
		else if (_jumping && !_guard)//점프중일때
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
		if (!_jumping && !_guard)
		{
			if (_playerDirection == PLAYERDIRECTION_RIGHT_STOP || _playerDirection == PLAYERDIRECTION_RIGHT_WALK)
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_RIGHT_STRONG_ATTACK;
				_strongAttackImage->setFrameX(_strongAttackImage->getMaxFrameX());
				_strongAttackImage->setFrameY(1);
				SOUNDMANAGER->play("attack str");

				int r = RND->getInt(4);
				if (r == 0) SOUNDMANAGER->play("attack str v1", 0.7f);
				else if (r == 1) SOUNDMANAGER->play("attack str v2", 0.7f);
			}

			if (_playerDirection == PLAYERDIRECTION_LEFT_STOP || _playerDirection == PLAYERDIRECTION_LEFT_WALK)
			{
				_attack = true;
				_playerDirection = PLAYERDIRECTION_LEFT_STRONG_ATTACK;
				_strongAttackImage->setFrameX(0);
				_strongAttackImage->setFrameY(0);
				SOUNDMANAGER->play("attack str");

				int r = RND->getInt(4);
				if (r == 0) SOUNDMANAGER->play("attack str v1", 0.7f);
				else if (r == 1) SOUNDMANAGER->play("attack str v2", 0.7f);
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('F') && !keyJump())//궁극기
	{
		if (!_jumping && !_guard)
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
				SOUNDMANAGER->play("dab");
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
				SOUNDMANAGER->play("dab");
			}

		}
	}
}

void player::jumpMove()
{
	if (_playerDirection != PLAYERDIRECTION_LEFT_DEAD && _playerDirection != PLAYERDIRECTION_LEFT_DOWN && _playerDirection != PLAYERDIRECTION_LEFT_HIT &&
		_playerDirection != PLAYERDIRECTION_RIGHT_DEAD && _playerDirection != PLAYERDIRECTION_RIGHT_DOWN && _playerDirection != PLAYERDIRECTION_RIGHT_HIT)
	{
		if (KEYMANAGER->isOnceKeyDown('D') && !keyAttack())//점프
		{
			if (!_attack && !_jumping && !_guard)//공격중이 아닐때 && 점프중복방지
			{
				_jumping = true;
				_jump->jumping(&_x, &_z, _jumpPower, _gravity);
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
				SOUNDMANAGER->play("jump");
			}
		}
	}
	_jump->update();//점프 업데이트
}

void player::leftMove()
{
	if (_playerDirection != PLAYERDIRECTION_LEFT_HIT && _playerDirection != PLAYERDIRECTION_RIGHT_HIT &&
		_playerDirection != PLAYERDIRECTION_LEFT_DOWN && _playerDirection != PLAYERDIRECTION_RIGHT_DOWN &&
		_playerDirection != PLAYERDIRECTION_LEFT_DEAD && _playerDirection != PLAYERDIRECTION_RIGHT_DEAD)
	{
		if (!_dash)//걷기
		{
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				if (!_jumping && !_attack && !_guard && !keyRight())
				{
					_playerDirection = PLAYERDIRECTION_LEFT_WALK;
					_walkImage->setFrameY(0);
				}

				if (!_jumping && !_attack && !_guard && keyRight())
				{
					_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				}

				if (!_attack && !keyRight() && !_guard)//점프중에 움직이는거 허용
				{
					if (CAMERA->getLeft() < _rc.left)
						_x -= _walkSpeed;
				}

			}
		}

		else//달리기
		{
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				if (!_jumping && !_attack && !_guard && !keyRight())
				{
					_playerDirection = PLAYERDIRECTION_LEFT_MOVE;
					_runImage->setFrameY(0);
					//_runEffect->setFrameX(_runEffect->getMaxFrameX());
					_runEffect->setFrameY(0);
				}
				if (!_jumping && !_attack && !_guard && keyRight())
				{
					_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				}

				if (!_attack && !keyRight() && !_guard)//점프중에 움직이는거 허용
				{
					if (CAMERA->getLeft() < _rc.left)
						_x -= _runSpeed;
				}

			}
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))//왼쪽키를 뗏으면
	{
		if (!_jumping && !_attack && !_guard)
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
		if (_jumping && !_attack && !_guard)//점프중에 프레임 변경
		{
			_jumpImage->setFrameX(_jumpImage->getFrameX());
			_jumpImage->setFrameY(0);
			_playerDirection = PLAYERDIRECTION_LEFT_JUMP;

		}
		_clickTime++;
	}
}

void player::rightMove()
{
	if (_playerDirection != PLAYERDIRECTION_LEFT_HIT && _playerDirection != PLAYERDIRECTION_RIGHT_HIT &&
		_playerDirection != PLAYERDIRECTION_LEFT_DOWN && _playerDirection != PLAYERDIRECTION_RIGHT_DOWN &&
		_playerDirection != PLAYERDIRECTION_LEFT_DEAD && _playerDirection != PLAYERDIRECTION_RIGHT_DEAD)
	{
		if (!_dash)//걷기
		{
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				if (!_jumping && !_attack && !_guard && !keyLeft())
				{
					_playerDirection = PLAYERDIRECTION_RIGHT_WALK;
					_walkImage->setFrameY(1);
				}

				if (!_jumping && !_attack && !_guard && keyLeft())
				{
					_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				}

				if (!_attack && !keyLeft() && !_guard)//점프중에 움직이는거 허용
				{
					if (CAMERA->getLeft() + CAMERA->getWidth() > _rc.right)
						_x += _walkSpeed;
				}
			}
		}

		else//달리기
		{
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				if (!_jumping && !_attack && !_guard && !keyLeft())
				{
					_playerDirection = PLAYERDIRECTION_RIGHT_MOVE;
					_runImage->setFrameY(1);
					//_runEffect->setFrameX(0);
					_runEffect->setFrameY(1);
				}

				if (!_jumping && !_attack && !_guard && keyLeft())
				{
					_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				}

				if (!_attack && !keyLeft() && !_guard)//점프중에 움직이는거 허용
				{
					if (CAMERA->getLeft() + CAMERA->getWidth() > _rc.right)
						_x += _runSpeed;
				}
			}

		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))//오른쪽키를 뗏으면
	{
		if (!_jumping && !_attack && !_guard)
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
		if (_jumping && !_attack && !_guard)//점프중에 프레임 변경
		{
			_jumpImage->setFrameX(0);
			_jumpImage->setFrameY(1);
			_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;

		}
		_clickTime++;
	}

}

void player::upMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_playerDirection != PLAYERDIRECTION_LEFT_HIT && _playerDirection != PLAYERDIRECTION_RIGHT_HIT &&
			_playerDirection != PLAYERDIRECTION_LEFT_DOWN && _playerDirection != PLAYERDIRECTION_RIGHT_DOWN &&
			_playerDirection != PLAYERDIRECTION_LEFT_DEAD && _playerDirection != PLAYERDIRECTION_RIGHT_DEAD)
		{
			if (!_jumping && !_attack && !_guard && !keyDown())
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

			if (!_jumping && !_attack && !_guard && keyDown())
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

			if (!_attack && !_guard)
			{
				if (_jumping)
				{
					_jump->setStartZmin(_walkSpeed);
				}
				if (!_pixelCollision)
					_z -= _walkSpeed;
				else if (_pixelCollision)
				{
					_yPlayerY -= _walkSpeed;
				}
			}
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_UP))//위쪽키를 뗏으면
	{
		if (!_jumping && !_attack && !_guard)
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
		if (_playerDirection != PLAYERDIRECTION_LEFT_HIT && _playerDirection != PLAYERDIRECTION_RIGHT_HIT &&
			_playerDirection != PLAYERDIRECTION_LEFT_DOWN && _playerDirection != PLAYERDIRECTION_RIGHT_DOWN &&
			_playerDirection != PLAYERDIRECTION_LEFT_DEAD && _playerDirection != PLAYERDIRECTION_RIGHT_DEAD)
		{
			if (!_jumping && !_attack && !_guard && !keyUp())
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

			if (!_jumping && !_attack && !_guard && keyUp())
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

			if (!_attack && !_guard)
			{
				if (_jumping)
				{
					_jump->setStartZpls(_walkSpeed);
				}

				if (!_pixelCollision)
					_z += _walkSpeed;
				else if (_pixelCollision)
				{
					_yPlayerY += _walkSpeed;
				}
			}
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))//아래키를 뗏으면
	{
		if (!_jumping && !_attack && !_guard)
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
		_attack = false;
		_comboAttack = false;
		_comboAttack2 = false;
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
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
		_attack = false;
		_comboAttack = false;
		_comboAttack2 = false;
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
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
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
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
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
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
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);

		_count++;
		if (_count % 5 == 0)
		{
			_runImage->setFrameX(_runImage->getFrameX() + 1);
			if (_runImage->getFrameX() >= _runImage->getMaxFrameX())
			{
				_runImage->setFrameX(0);
			}

			_runEffect->setFrameX(_runEffect->getFrameX() - 1);
			if (_runEffect->getFrameX() <= 0)
			{
				_runEffect->setFrameX(_runEffect->getMaxFrameX());
			}

			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_MOVE:
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);

		_count++;
		if (_count % 5 == 0)
		{
			_runImage->setFrameX(_runImage->getFrameX() - 1);
			if (_runImage->getFrameX() <= 0)
			{
				_runImage->setFrameX(_runImage->getMaxFrameX());
			}

			_runEffect->setFrameX(_runEffect->getFrameX() + 1);
			if (_runEffect->getFrameX() >= _runEffect->getMaxFrameX())
			{
				_runEffect->setFrameX(0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_JUMP://왼쪽으로 점프
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
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
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
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
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage1->setFrameX(_comboAttackImage1->getFrameX() - 1);
			_comboAttackRc1.set(0, 0, 150, 50);
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
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage1->setFrameX(_comboAttackImage1->getFrameX() + 1);
			_comboAttackRc1.set(0, 0, 150, 50);
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
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage2->setFrameX(_comboAttackImage2->getFrameX() - 1);
			_comboAttackRc2.set(0, 0, 180, 100);
			_comboAttackRc2.setCenterPos(_rc.left, _rc.getCenterY());
			if (_comboAttackImage2->getFrameX() <= 0)
			{
				_comboAttackImage2->setFrameX(_comboAttackImage2->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_comboAttackRc2.set(0, 0, 0, 0);
				_comboAttack = false;//2단콤보 실행조건 펄스
				_comboAttack2 = false;//3단콤보 실행조건 펄스
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK2:
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage2->setFrameX(_comboAttackImage2->getFrameX() + 1);
			_comboAttackRc2.set(0, 0, 180, 100);
			_comboAttackRc2.setCenterPos(_rc.right, _rc.getCenterY());
			if (_comboAttackImage2->getFrameX() >= _comboAttackImage2->getMaxFrameX())
			{
				_comboAttackImage2->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_comboAttackRc2.set(0, 0, 0, 0);
				_comboAttack = false;//2단콤보 실행조건 펄스
				_comboAttack2 = false;//3단콤보 실행조건 펄스
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_COMBO_ATTACK3:
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage3->setFrameX(_comboAttackImage3->getFrameX() - 1);
			if (_comboAttackImage3->getFrameX() >= _comboAttackImage3->getMaxFrameX() - 3)
			{
				_comboAttackRc3.set(0, 0, 200, 200);
			}
			_comboAttackRc3.setCenterPos(_rc.left, _rc.getCenterY());
			if (_comboAttackImage3->getFrameX() <= _comboAttackImage3->getMaxFrameX() - 3)
			{
				_comboAttackRc3.set(0, 0, 0, 0);
			}
			if (_comboAttackImage3->getFrameX() <= 0)
			{
				_comboAttackImage3->setFrameX(_comboAttackImage3->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_comboAttack = false;//2단콤보 실행조건 펄스
				_comboAttack2 = false;//3단콤보 실행조건 펄스
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_COMBO_ATTACK3:
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
		_count++;
		if (_count % 5 == 0)
		{
			_comboAttackImage3->setFrameX(_comboAttackImage3->getFrameX() + 1);
			if (_comboAttackImage3->getFrameX() <= 3)
			{
				_comboAttackRc3.set(0, 0, 200, 200);
			}
			_comboAttackRc3.setCenterPos(_rc.right, _rc.getCenterY());
			if (_comboAttackImage3->getFrameX() >= 3)
			{
				_comboAttackRc3.set(0, 0, 0, 0);
			}
			if (_comboAttackImage3->getFrameX() >= _comboAttackImage3->getMaxFrameX())
			{
				_comboAttackImage3->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_comboAttack = false;//2단콤보 실행조건 펄스
				_comboAttack2 = false;//3단콤보 실행조건 펄스
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_STRONG_ATTACK:
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
		_count++;
		_jump->jumping(&_x, &_z, 7.0f, 7.0f);
		if (_count % 4 == 0)
		{
			_strongAttackImage->setFrameX(_strongAttackImage->getFrameX() + 1);
			if (_strongAttackImage->getFrameX() <= 3)
			{
				_attackRc.set(0, 0, 150, 200);
			}
			_attackRc.setCenterPos(_rc.left - 50, _rc.getCenterY() - _jump->getJumpPower());
			if (_strongAttackImage->getFrameX() >= 3)
			{
				_attackRc.set(0, 0, 0, 0);
			}
			if (_strongAttackImage->getFrameX() >= _strongAttackImage->getMaxFrameX())
			{
				_strongAttackImage->setFrameX(_strongAttackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_STRONG_ATTACK:
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
		_count++;
		_jump->jumping(&_x, &_z, 7.0f, 7.0f);
		if (_count % 4 == 0)
		{
			_strongAttackImage->setFrameX(_strongAttackImage->getFrameX() - 1);
			if (_strongAttackImage->getFrameX() >= _strongAttackImage->getMaxFrameX() - 3)
			{
				_attackRc.set(0, 0, 150, 200);
			}
			_attackRc.setCenterPos(_rc.right + 50, _rc.getCenterY() - _jump->getJumpPower());
			if (_strongAttackImage->getFrameX() <= _strongAttackImage->getMaxFrameX() - 3)
			{
				_attackRc.set(0, 0, 0, 0);
			}
			if (_strongAttackImage->getFrameX() <= 0)
			{
				_strongAttackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_JUMP_ATTACK:
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
		_count++;
		if (_count % 5 == 0)
		{
			if (_jumpAttackImage->getFrameX() > 0)
			{
				_jumpAttackImage->setFrameX(_jumpAttackImage->getFrameX() - 1);
			}
			if (_jumpAttackImage->getFrameX() >= _jumpAttackImage->getMaxFrameX() - 3)
			{
				_attackRc.set(0, 0, 50, 100);
			}
			_attackRc.setCenterPos(_rc.left, _rc.getCenterY());
			if (_jumpAttackImage->getFrameX() <= _jumpAttackImage->getMaxFrameX() - 3)
			{
				_attackRc.set(0, 0, 0, 0);
			}
			if (_jumpAttackImage->getFrameX() <= 0)
			{
				if (_z <= _z - _jump->getJumpPower())
				{
					_jumpAttackImage->setFrameX(_jumpAttackImage->getMaxFrameX());
					_playerDirection = PLAYERDIRECTION_LEFT_STOP;
					_jumping = false;
					_attack = false;
				}
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_JUMP_ATTACK:
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
		_count++;
		if (_count % 5 == 0)
		{
			if (_jumpAttackImage->getFrameX() < _jumpAttackImage->getMaxFrameX())
			{
				_jumpAttackImage->setFrameX(_jumpAttackImage->getFrameX() + 1);
			}
			if (_jumpAttackImage->getFrameX() <= 3)
			{
				_attackRc.set(0, 0, 50, 100);
			}
			_attackRc.setCenterPos(_rc.right, _rc.getCenterY());
			if (_jumpAttackImage->getFrameX() >= 3)
			{
				_attackRc.set(0, 0, 0, 0);
			}
			if (_jumpAttackImage->getFrameX() >= _jumpAttackImage->getMaxFrameX())
			{
				if (_z <= _z - _jump->getJumpPower())
				{
					_jumpAttackImage->setFrameX(0);
					_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
					_jumping = false;
					_attack = false;
				}
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_DASH_ATTACK:
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
		_count++;
		_x -= _runSpeed;
		_jump->jumping(&_x, &_z, 2.0f, 0.16f);
		if (_count % 5 == 0)
		{
			_dashAttackImage->setFrameX(_dashAttackImage->getFrameX() - 1);
			if (_dashAttackImage->getFrameX() >= _dashAttackImage->getMaxFrameX() - 3)
			{
				_attackRc.set(0, 0, 120, 100);
			}
			_attackRc.setCenterPos(_rc.left - 50, _rc.getCenterY() - 30);
			if (_dashAttackImage->getFrameX() <= _dashAttackImage->getMaxFrameX() - 3)
			{
				_attackRc.set(0, 0, 0, 0);
			}
			if (_dashAttackImage->getFrameX() <= 0)
			{
				_dashAttackImage->setFrameX(_dashAttackImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_DASH_ATTACK:
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
		_count++;
		_x += _runSpeed;
		_jump->jumping(&_x, &_z, 2.0f, 0.16f);
		if (_count % 5 == 0)
		{
			_dashAttackImage->setFrameX(_dashAttackImage->getFrameX() + 1);
			if (_dashAttackImage->getFrameX() <= 3)
			{
				_attackRc.set(0, 0, 120, 100);
			}
			_attackRc.setCenterPos(_rc.right + 50, _rc.getCenterY() - 30);
			if (_dashAttackImage->getFrameX() >= 3)
			{
				_attackRc.set(0, 0, 0, 0);
			}
			if (_dashAttackImage->getFrameX() >= _dashAttackImage->getMaxFrameX())
			{
				_dashAttackImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_ULTIMATE:
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
		_count++;
		if (_count % 3 == 0)
		{
			_ultimateImage->setFrameX(_ultimateImage->getFrameX() - 1);
			if (_ultimateImage->getFrameX() <= 20)
			{
				_ultimate = true;
			}
			if (_ultimateImage->getFrameX() >= _ultimateImage->getMaxFrameX() - 4)
			{
				_attackRc.set(0, 0, 250, 300);
			}
			_attackRc.setCenterPos(_rc.left - 50, _rc.getCenterY());
			if (_ultimateImage->getFrameX() <= _ultimateImage->getMaxFrameX() - 4)
			{
				_attackRc.set(0, 0, 0, 0);
			}
			if (_ultimateImage->getFrameX() <= 0)
			{
				_ultimateImage->setFrameX(_ultimateImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				_attack = false;
				_ultimate = false;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_ULTIMATE:
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
		_count++;
		if (_count % 3 == 0)
		{
			_ultimateImage->setFrameX(_ultimateImage->getFrameX() + 1);
			if (_ultimateImage->getFrameX() >= 5)
			{
				_ultimate = true;
			}
			if (_ultimateImage->getFrameX() <= 4)
			{
				_attackRc.set(0, 0, 250, 300);
			}
			_attackRc.setCenterPos(_rc.right + 50, _rc.getCenterY());
			if (_ultimateImage->getFrameX() >= 4)
			{
				_attackRc.set(0, 0, 0, 0);
			}
			if (_ultimateImage->getFrameX() >= _ultimateImage->getMaxFrameX())
			{
				_ultimateImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				_attack = false;
				_ultimate = false;
			}
		}
		break;

	case PLAYERDIRECTION_LEFT_GUARD:
		_downImage->setFrameX(_downImage->getMaxFrameX());
		_downImage->setFrameY(0);
		_count++;
		if (_count % 5 == 0)
		{
			_guardImage->setFrameX(_guardImage->getFrameX() - 1);
			if (_guardImage->getFrameX() <= 0)
			{
				_guardImage->setFrameX(_guardImage->getMaxFrameX());
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_GUARD:
		_downImage->setFrameX(0);
		_downImage->setFrameY(1);
		_count++;
		if (_count % 5 == 0)
		{
			_guardImage->setFrameX(_guardImage->getFrameX() + 1);
			if (_guardImage->getFrameX() >= _guardImage->getMaxFrameX())
			{
				_guardImage->setFrameX(0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_DOWN:
		_count++;
		if (_count % 5 == 0)
		{
			_downImage->setFrameX(_downImage->getFrameX() - 1);
			if (_downImage->getFrameX() <= 0)
			{
				_downImage->setFrameX(_downImage->getMaxFrameX());
				_playerDirection = PLAYERDIRECTION_LEFT_STOP;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_DOWN:
		_count++;
		if (_count % 5 == 0)
		{
			_downImage->setFrameX(_downImage->getFrameX() + 1);
			if (_downImage->getFrameX() >= _downImage->getMaxFrameX())
			{
				_downImage->setFrameX(0);
				_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_HIT:
		_attack = false;
		if (_jumping)
		{
			_jumpingHit = true;
		}
		_jumping = false;
		_comboAttack = false;
		_comboAttack2 = false;
		if (!_oneFramePlay)
		{
			_hitImage->setFrameX(_hitImage->getMaxFrameX());
			_hitImage->setFrameY(0);
			_oneFramePlay = true;
		}
		_count++;
		if (_count % 15 == 0)
		{
			_hitImage->setFrameX(_hitImage->getFrameX() - 1);
			if (_hitImage->getFrameX() <= 0)
			{
				_hitImage->setFrameX(_hitImage->getMaxFrameX());
				if (_jumpingHit)//점프중에 맞았으면 점프프레임
				{
					_playerDirection = PLAYERDIRECTION_LEFT_JUMP;
				}
				else
				{
					_playerDirection = PLAYERDIRECTION_LEFT_STOP;
				}
				_comboAttack = false;
				_comboAttack2 = false;
				_attack = false;
				_oneFramePlay = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count == 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_HIT:
		_attack = false;
		if (_jumping)
		{
			_jumpingHit = true;
		}
		_jumping = false;
		_comboAttack = false;
		_comboAttack2 = false;
		if (!_oneFramePlay)
		{
			_hitImage->setFrameX(0);
			_hitImage->setFrameY(1);
			_oneFramePlay = true;
		}
		_count++;
		if (_count % 15 == 0)
		{
			_hitImage->setFrameX(_hitImage->getFrameX() + 1);
			if (_hitImage->getFrameX() >= _hitImage->getMaxFrameX())
			{
				_hitImage->setFrameX(0);
				if (_jumpingHit)//점프중에 맞았으면 점프프레임
				{
					_playerDirection = PLAYERDIRECTION_RIGHT_JUMP;
				}
				else
				{
					_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
				}
				_comboAttack = false;
				_comboAttack2 = false;
				_attack = false;
				_oneFramePlay = false;
				_attackRc.set(0, 0, 0, 0);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_LEFT_DEAD:
		if (!_deadOneFramePlay)
		{
			SOUNDMANAGER->stopAll("");
			SOUNDMANAGER->play("gameover");
			_deadImage->setFrameX(_deadImage->getMaxFrameX());
			_deadImage->setFrameY(0);
			_deadOneFramePlay = true;
		}
		_count++;
		if (_count % 10 == 0)
		{
			if (_deadImage->getFrameX() > 0 && _deadImage->getFrameX() != 0)
			{
				_deadImage->setFrameX(_deadImage->getFrameX() - 1);
			}
			_count = 0;
		}
		break;

	case PLAYERDIRECTION_RIGHT_DEAD:
		if (!_deadOneFramePlay)
		{
			SOUNDMANAGER->stopAll("");
			SOUNDMANAGER->play("gameover");
			_deadImage->setFrameX(0);
			_deadImage->setFrameY(1);
			_deadOneFramePlay = true;
		}
		_count++;
		if (_count % 10 == 0)
		{
			if (_deadImage->getFrameX() < _deadImage->getMaxFrameX() && _deadImage->getFrameX() != _deadImage->getMaxFrameX())
			{
				_deadImage->setFrameX(_deadImage->getFrameX() + 1);
			}
			_count = 0;
		}
		break;
	}
}

//player가 stage 이동 시 player 위치 리셋
//stageOpenDoor 좌표를 기준으로 player x,y 중점을 변경 해주는 함수입니다.
//원하는 좌표로 바꿀 시 정수만 바꿔주세요

void player::playerPosition_1()
{
	_x = 450;
	_z = 400;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_1at2()
{
	_x = 350;
	_z = WINSIZEY / 2 + 250;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_2at3()
{
	_x = WINSIZEX / 2 + 625;
	_z = WINSIZEY / 2 + 190;
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

void player::playerPosition_Bossat4()
{
	_x = WINSIZEX + 500;
	_z = WINSIZEY / 2 + 300;
	CAMERA->setPosition(_x, _z);
}

void player::playerPosition_BossStart()
{
	_playerDirection = PLAYERDIRECTION_RIGHT_STOP;
	_idleImage->setFrameY(1);
	_x = WINSIZEX - 100;
	_z = WINSIZEY / 2 + 400;
	_rc.setCenterPos(_x, _z - _rc.getHeight() / 2);

	CAMERA->setPosition(_x + 200, _z - 130);
}
