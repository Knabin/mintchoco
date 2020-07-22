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
	_submotion = IMAGEMANAGER->addFrameImage("schoolgirl_attack1", "images/enemys/Schoolgirl_attack1.bmp", 2208, 354, 8, 2, true, RGB(255, 0, 255));
	//_gethit = IMAGEMANAGER->addFrameImage("schoolgirl_gethit", "images/enemys/SchoolGirl_gethit.bmp", 1431, 360, 9, 2, true, RGB(255, 0, 255));
	_stun = IMAGEMANAGER->addFrameImage("schoolgirl_stun", "images/enemys/SchoolGirl_Stun.bmp", 456, 324, 4, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("schoolgirl_shadow", "images/enemys/SchoolGirl_Shadow.bmp", 150, 44, true, RGB(255, 0, 255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_random = RND->getInt(4);

	_direction = ENEMY_LEFT_MOVE;

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
	_enemyMotion_L->setPlayFrame(11, 0, false, true);
	_enemyMotion_L->setFPS(1.5);
	_enemyMotion_L->start();
	_enemyMotion_R = new animation;
	_enemyMotion_R->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_R->setPlayFrame(12, 23, false, true);
	_enemyMotion_R->setFPS(1.5);
	_enemyMotion_R->start();
	// ============================	여학우 무브 ============================ //

	// ============================	여학우 공격 ============================ //
	_enemyMotion_L_A = new animation;
	_enemyMotion_L_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_L_A->setPlayFrame(6, 0, false, false);
	_enemyMotion_L_A->setFPS(1.5);
	_enemyMotion_L_A->start();
	_enemyMotion_R_A = new animation;
	_enemyMotion_R_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_R_A->setPlayFrame(7, 13, false, false);
	_enemyMotion_R_A->setFPS(1.5);
	_enemyMotion_R_A->start();
	// ============================	여학우 공격 ============================ //

	// ============================	여학우 콤보1 ============================ //
	_enemyMotion_L_COMBO1 = new animation;
	_enemyMotion_L_COMBO1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_L_COMBO1->setPlayFrame(6, 0, false, false);
	_enemyMotion_L_COMBO1->setFPS(1.5);
	_enemyMotion_L_COMBO1->start();
	_enemyMotion_R_COMBO1 = new animation;
	_enemyMotion_R_COMBO1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_R_COMBO1->setPlayFrame(7, 13, false, false);
	_enemyMotion_R_COMBO1->setFPS(1.5);
	_enemyMotion_R_COMBO1->start();
	// ============================	여학우 콤보1 ============================ //

	// ============================	여학우 콤보2 ============================ //
	_enemyMotion_L_COMBO2 = new animation;
	_enemyMotion_L_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_L_COMBO2->setPlayFrame(0, 11, false, false);
	_enemyMotion_L_COMBO2->setFPS(1.5);
	_enemyMotion_L_COMBO2->start();
	_enemyMotion_R_COMBO2 = new animation;
	_enemyMotion_R_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_R_COMBO2->setPlayFrame(23, 12, false, false);
	_enemyMotion_R_COMBO2->setFPS(1.5);
	_enemyMotion_R_COMBO2->start();
	// ============================	여학우 콤보2 ============================ //

	// ============================	여학우 서브모션 ============================ //
	_enemyMotion_L_submotion = new animation;
	_enemyMotion_L_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_L_submotion->setPlayFrame(15, 8, false, false);
	_enemyMotion_L_submotion->setFPS(1.5);
	_enemyMotion_L_submotion->start();
	_enemyMotion_R_submotion = new animation;
	_enemyMotion_R_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_R_submotion->setPlayFrame(0, 7, false, false);
	_enemyMotion_R_submotion->setFPS(1.5);
	_enemyMotion_R_submotion->start();
	// ============================	여학우 서브모션 ============================ //

	// ============================	여학우 히트 ============================ //
	//_enemyMotion_L_hit = new animation;
	//_enemyMotion_L_hit->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	//_enemyMotion_L_hit->setPlayFrame(0, 7, false, false);
	//_enemyMotion_L_hit->setFPS(1);
	//_enemyMotion_L_hit->start();
	//_enemyMotion_R_hit = new animation;
	//_enemyMotion_R_hit->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	//_enemyMotion_R_hit->setPlayFrame(15, 8, false, false);
	//_enemyMotion_R_hit->setFPS(1);
	//_enemyMotion_R_hit->start();
	// ============================	여학우 히트 ============================ //

	// ============================	여학우 스턴 ============================ //
	_enemyMotion_L_stun = new animation;
	_enemyMotion_L_stun->init(_stun->getWidth(), _stun->getHeight(), _stun->getFrameWidth(), _stun->getFrameHeight());
	_enemyMotion_L_stun->setPlayFrame(4, 7, false, false);
	_enemyMotion_L_stun->setFPS(1);
	_enemyMotion_L_stun->start();
	_enemyMotion_R_stun = new animation;
	_enemyMotion_R_stun->init(_stun->getWidth(), _stun->getHeight(), _stun->getFrameWidth(), _stun->getFrameHeight());
	_enemyMotion_R_stun->setPlayFrame(0, 4, false, false);
	_enemyMotion_R_stun->setFPS(1);
	_enemyMotion_R_stun->start();
	// ============================	여학우 스턴 ============================ //


	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_attackRC.set(0, 0, 0, 0);
	_attackRC.setCenterPos(0, 0);

	_enemyMotion = _enemyMotion_L;
	return S_OK;
}

void schoolgirl::release()
{
}

void schoolgirl::render()
{
	_attackRC.set(0, 0, 0, 0);
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
		_attackRC.set(0, 0, 200, 100);
		_attackRC.setCenterPos(_rc.left, _rc.getCenterY());
		break;
	case ENEMY_RIGHT_ATTACK:
		_enemyImg = _attack;
		_attackRC.set(0, 0, 200, 100);
		_attackRC.setCenterPos(_rc.right, _rc.getCenterY());
		break;
	case ENEMY_LEFT_COMBO1:
		_enemyImg = _combo1;
		_attackRC.set(0, 0, 200, 100);
		_attackRC.setCenterPos(_rc.left, _rc.getCenterY());
		break;
	case ENEMY_RIGHT_COMBO1:
		_enemyImg = _combo1;
		_attackRC.set(0, 0, 200, 100);
		_attackRC.setCenterPos(_rc.right, _rc.getCenterY());
		break;
	case ENEMY_LEFT_COMBO2:
		_enemyImg = _combo2;
		_attackRC.set(0, 0, 200, 100);
		_attackRC.setCenterPos(_rc.left, _rc.getCenterY());
		break;
	case ENEMY_RIGHT_COMBO2:
		_enemyImg = _combo2;
		_attackRC.set(0, 0, 200, 100);
		_attackRC.setCenterPos(_rc.right, _rc.getCenterY());
		break;
	case ENEMY_LEFT_SUBMOTION:
		_enemyImg = _submotion;
		_attackRC.set(0, 0, 200, 100);
		_attackRC.setCenterPos(_rc.left, _rc.getCenterY());
		break;
	case ENEMY_RIGHT_SUBMOTION:
		_enemyImg = _submotion;
		_attackRC.set(0, 0, 200, 100);
		_attackRC.setCenterPos(_rc.right, _rc.getCenterY());
		break;
	//case ENEMY_LEFT_GETHIT:
	//	_enemyImg = _gethit;
	//	break;
	//case ENEMY_RIGHT_GETHIT:
	//	_enemyImg = _gethit;
	//	break;
	case ENEMY_LEFT_STUN:
		_enemyImg = _stun;
		break;
	case ENEMY_RIGHT_STUN:
		_enemyImg = _stun;
		break;
	}
	_rc.render(getMemDC());
	_attackRC.render(getMemDC());
	IMAGEMANAGER->findImage("schoolgirl_shadow")->alphaRender(getMemDC(), _rc.left - 19, _rc.bottom - 25, 100);
	ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX(), 0, _rc.bottom);
}
