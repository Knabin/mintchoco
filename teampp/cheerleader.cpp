#include "stdafx.h"
#include "cheerleader.h"

cheerleader::cheerleader()
{
}

cheerleader::~cheerleader()
{
}

HRESULT cheerleader::init(string imageName, float x, float y, float speed)
{
	_idle = IMAGEMANAGER->addFrameImage("cheer_idle", "images/enemys/CheerLeader_Idle.bmp", 2304, 432, 12, 2, true, RGB(255, 0, 255));
	_move = IMAGEMANAGER->addFrameImage("cheer_move", "images/enemys/CheerLeader_Walk.bmp", 2736, 438, 12, 2, true, RGB(255, 0, 255));
	_attack = IMAGEMANAGER->addFrameImage("cheer_attack", "images/enemys/CheerLeader_ComboAttack3.bmp", 1827, 426, 7, 2, true, RGB(255, 0, 255));
	_combo1 = IMAGEMANAGER->addFrameImage("cheer_combo1", "images/enemys/CheerLeader_ComboAttack1.bmp", 1332, 468, 6, 2, true, RGB(255, 0, 255));
	_combo2 = IMAGEMANAGER->addFrameImage("cheer_combo2", "images/enemys/CheerLeader_backflip.bmp", 3060, 1836, 10, 6, true, RGB(255, 0, 255));
	_submotion = IMAGEMANAGER->addFrameImage("cheer_back", "images/enemys/CheerLeader_cartwheel.bmp", 2817, 978, 11, 4, true, RGB(255, 0, 255));
	//_gethit = IMAGEMANAGER->addFrameImage("cheer_gethit", "images/enemys/CheerLeader_gethit.bmp", 1539, 426, 9, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("cheer_shadow", "images/enemys/CheerLeader_Shadow.bmp", 150, 44, true, RGB(255, 0, 255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_random = RND->getInt(4);
	_direction = ENEMY_LEFT_MOVE;
	_aniTime = 0;

	// ============================	치어리더 아이들 ============================ //
	_enemyMotion_L_IDLE = new animation;
	_enemyMotion_L_IDLE->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_L_IDLE->setPlayFrame(0, 11, false, true);
	_enemyMotion_L_IDLE->setFPS(1);
	_enemyMotion_L_IDLE->start();
	_enemyMotion_R_IDLE = new animation;
	_enemyMotion_R_IDLE->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_R_IDLE->setPlayFrame(23, 12, false, true);
	_enemyMotion_R_IDLE->setFPS(1);
	_enemyMotion_R_IDLE->start();
	// ============================	치어리더 아이들 ============================ //

	// ============================	치어리더 무브 ============================ //
	_enemyMotion_L = new animation;
	_enemyMotion_L->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_L->setPlayFrame(0, 11, false, true);
	_enemyMotion_L->setFPS(1.5);
	_enemyMotion_L->start();
	_enemyMotion_R = new animation;
	_enemyMotion_R->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_R->setPlayFrame(23, 12, false, true);
	_enemyMotion_R->setFPS(1.5);
	_enemyMotion_R->start();
	// ============================	치어리더 무브 ============================ //

	// ============================	치어리더 공격 ============================ //
	_enemyMotion_L_A = new animation;
	_enemyMotion_L_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_L_A->setPlayFrame(13, 7, false, false);
	_enemyMotion_L_A->setFPS(1.5);
	_enemyMotion_L_A->start();
	_enemyMotion_R_A = new animation;
	_enemyMotion_R_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_R_A->setPlayFrame(0, 6, false, false);
	_enemyMotion_R_A->setFPS(1.5);
	_enemyMotion_R_A->start();
	// ============================	치어리더 공격 ============================ //

	// ============================	치어리더 콤보1 ============================ //
	_enemyMotion_L_COMBO1 = new animation;
	_enemyMotion_L_COMBO1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_L_COMBO1->setPlayFrame(11, 6, false, false);
	_enemyMotion_L_COMBO1->setFPS(1.5);
	_enemyMotion_L_COMBO1->start();
	_enemyMotion_R_COMBO1 = new animation;
	_enemyMotion_R_COMBO1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_R_COMBO1->setPlayFrame(0, 5, false, false);
	_enemyMotion_R_COMBO1->setFPS(1.5);
	_enemyMotion_R_COMBO1->start();
	// ============================	치어리더 콤보1 ============================ //

	// ============================	치어리더 콤보2 ============================ //
	_enemyMotion_L_COMBO2 = new animation;
	_enemyMotion_L_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_L_COMBO2->setPlayFrame(59, 39, false, false);
	_enemyMotion_L_COMBO2->setFPS(1.5);
	_enemyMotion_L_COMBO2->start();
	_enemyMotion_R_COMBO2 = new animation;
	_enemyMotion_R_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_R_COMBO2->setPlayFrame(0, 21, false, false);
	_enemyMotion_R_COMBO2->setFPS(1.5);
	_enemyMotion_R_COMBO2->start();
	// ============================	치어리더 콤보2 ============================ //

	// ============================	치어리더 백플립 ============================ //
	_enemyMotion_L_submotion = new animation;
	_enemyMotion_L_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_L_submotion->setPlayFrame(43, 29, false, false);
	_enemyMotion_L_submotion->setFPS(2);
	_enemyMotion_L_submotion->start();
	_enemyMotion_R_submotion = new animation;
	_enemyMotion_R_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_R_submotion->setPlayFrame(0, 14, false, false);
	_enemyMotion_R_submotion->setFPS(2);
	_enemyMotion_R_submotion->start();
	// ============================	치어리더 백플립 ============================ //

	// ============================	치어리더 히트 ============================ //
	//_enemyMotion_L_hit = new animation;
	//_enemyMotion_L_hit->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	//_enemyMotion_L_hit->setPlayFrame(0, 2, false, false);
	//_enemyMotion_L_hit->setFPS(1);
	//_enemyMotion_L_hit->start();
	//_enemyMotion_R_hit = new animation;
	//_enemyMotion_R_hit->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	//_enemyMotion_R_hit->setPlayFrame(5, 3, false, false);
	//_enemyMotion_R_hit->setFPS(1);
	//_enemyMotion_R_hit->start();
	// ============================	치어리더 히트 ============================ //


	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_enemyMotion = _enemyMotion_L;


	return S_OK;
}

void cheerleader::release()
{
}




void cheerleader::render()
{
	switch (_direction)
	{
	case ENEMY_LEFT_IDLE:
		_enemyImg = _idle;
		break;
	case ENEMY_RIGHT_IDLE:
		_enemyImg = _idle;
		break;
	case ENEMY_LEFT_MOVE:
		_enemyImg = _move;
		break;
	case ENEMY_RIGHT_MOVE:
		_enemyImg = _move;
		break;
	case ENEMY_LEFT_ATTACK:
		_enemyImg = _attack;
		break;
	case ENEMY_RIGHT_ATTACK:
		_enemyImg = _attack;
		break;
	case ENEMY_LEFT_COMBO1:
		_enemyImg = _combo1;
		break;
	case ENEMY_RIGHT_COMBO1:
		_enemyImg = _combo1;
		break;
	case ENEMY_LEFT_COMBO2:
		_enemyImg = _combo2;
		break;
	case ENEMY_RIGHT_COMBO2:
		_enemyImg = _combo2;
		break;
	case ENEMY_LEFT_SUBMOTION:
		_enemyImg = _submotion;
		_x -= 5.f;
		break;
	case ENEMY_RIGHT_SUBMOTION:
		_enemyImg = _submotion;
		_x += 5.f;
			break;
	//case ENEMY_LEFT_GETHIT:
	//	_enemyImg = _gethit;
	//	break;
	//case ENEMY_RIGHT_GETHIT:
	//	_enemyImg = _gethit;
	//	break;

	}
	/*
	if(_direction == ENEMY_LEFT_SUBMOTION)
	{
		_aniTime++;
		if (_aniTime > 10)
		{
			for (int i = 0; i < 3; i++)
			{
				ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX() + 20*i, 0, _rc.bottom - 0.01);
			}
		}
	}
	else if (_direction == ENEMY_RIGHT_SUBMOTION)
	{
		_aniTime++;
		if (_aniTime > 10)
		{
			for (int i = 0; i < 3; i++)
			{
				ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX() - 20*i, 0, _rc.bottom - 0.01);
			}
		}
	}*/
	IMAGEMANAGER->findImage("cheer_shadow")->render(getMemDC(), _rc.left + 35, _rc.bottom-25);
	ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX(), 0, _rc.bottom);
}

