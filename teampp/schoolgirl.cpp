#include "stdafx.h"
#include "schoolgirl.h"

schoolgirl::schoolgirl()
{
}

schoolgirl::~schoolgirl()
{
}

HRESULT schoolgirl::init(string imageName, float x, float y, float speed)
{
	_idle = IMAGEMANAGER->addFrameImage("schoolgirl_idle", "images/enemys/SchoolGirl_Idle.bmp", 1170, 354, 10, 2, true, RGB(255, 0, 255));
	_move = IMAGEMANAGER->addFrameImage("schoolgirl_move", "images/enemys/SchoolGirl_Walk.bmp", 1296, 372, 12, 2, true, RGB(255, 0, 255));
	_attack = IMAGEMANAGER->addFrameImage("schoolgirl_attack", "images/enemys/SchoolGirl_ComboAttack1.bmp", 1239, 354, 7, 2, true, RGB(255, 0, 255));
	_combo1 = IMAGEMANAGER->addFrameImage("schoolgirl_combo1", "images/enemys/SchoolGirl_ComboAttack2.bmp", 1197, 354, 7, 2, true, RGB(255, 0, 255));
	_combo2 = IMAGEMANAGER->addFrameImage("schoolgirl_combo2", "images/enemys/SchoolGirl_ComboAttack3.bmp", 2412, 414, 12, 2, true, RGB(255, 0, 255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + y;
	_y = _y + y;
	_random = RND->getInt(3);

	// ============================	여학우 아이들 ============================ //
	_enemyMotion_L_IDLE = new animation;
	_enemyMotion_L_IDLE->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_L_IDLE->setPlayFrame(0, 9, false, true);
	_enemyMotion_L_IDLE->setFPS(1);
	_enemyMotion_L_IDLE->start();
	_enemyMotion_R_IDLE = new animation;
	_enemyMotion_R_IDLE->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_R_IDLE->setPlayFrame(19, 10, false, true);
	_enemyMotion_R_IDLE->setFPS(1);
	_enemyMotion_R_IDLE->start();
	// ============================	여학우 아이들 ============================ //

	// ============================	여학우 무브 ============================ //
	_enemyMotion_L = new animation;
	_enemyMotion_L->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_L->setPlayFrame(0, 11, false, true);
	_enemyMotion_L->setFPS(1);
	_enemyMotion_L->start();
	_enemyMotion_R = new animation;
	_enemyMotion_R->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_R->setPlayFrame(23, 12, false, true);
	_enemyMotion_R->setFPS(1);
	_enemyMotion_R->start();
	// ============================	여학우 무브 ============================ //

	// ============================	여학우 공격 ============================ //
	_enemyMotion_L_A = new animation;
	_enemyMotion_L_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_L_A->setPlayFrame(0, 6, false, false);
	_enemyMotion_L_A->setFPS(1);
	_enemyMotion_L_A->start();
	_enemyMotion_R_A = new animation;
	_enemyMotion_R_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_R_A->setPlayFrame(13, 7, false, false);
	_enemyMotion_R_A->setFPS(1);
	_enemyMotion_R_A->start();
	// ============================	여학우 공격 ============================ //

	// ============================	여학우 콤보1 ============================ //
	_enemyMotion_L_COMBO1 = new animation;
	_enemyMotion_L_COMBO1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_L_COMBO1->setPlayFrame(0, 6, false, false);
	_enemyMotion_L_COMBO1->setFPS(1);
	_enemyMotion_L_COMBO1->start();
	_enemyMotion_R_COMBO1 = new animation;
	_enemyMotion_R_COMBO1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_R_COMBO1->setPlayFrame(13, 7, false, false);
	_enemyMotion_R_COMBO1->setFPS(1);
	_enemyMotion_R_COMBO1->start();
	// ============================	여학우 콤보1 ============================ //

	// ============================	여학우 콤보2 ============================ //
	_enemyMotion_L_COMBO2 = new animation;
	_enemyMotion_L_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_L_COMBO2->setPlayFrame(0, 11, false, false);
	_enemyMotion_L_COMBO2->setFPS(1);
	_enemyMotion_L_COMBO2->start();
	_enemyMotion_R_COMBO2 = new animation;
	_enemyMotion_R_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_R_COMBO2->setPlayFrame(23, 12, false, false);
	_enemyMotion_R_COMBO2->setFPS(1);
	_enemyMotion_R_COMBO2->start();
	// ============================	여학우 콤보2 ============================ //


	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_enemyMotion = _enemyMotion_L;
	return S_OK;
}

void schoolgirl::release()
{
}

void schoolgirl::render()
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
	}
	ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX(), 0, _rc.bottom);
}
