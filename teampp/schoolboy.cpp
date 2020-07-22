#include "stdafx.h"
#include "schoolboy.h"

schoolboy::schoolboy()
{
}

schoolboy::~schoolboy()
{
}

HRESULT schoolboy::init(string imageName, float x, float y, float speed)
{
	_idle = IMAGEMANAGER->addFrameImage("schoolboy_idle", "images/enemys/SchoolBoy_Idle.bmp", 1224, 432, 8, 2, true, RGB(255, 0, 255));
	_move = IMAGEMANAGER->addFrameImage("schoolboy_move", "images/enemys/SchoolBoy_Walk.bmp", 1620, 444, 12, 2, true, RGB(255, 0, 255));
	_attack = IMAGEMANAGER->addFrameImage("schoolboy_attack", "images/enemys/SchoolBoy_ComboAttack1.bmp", 2352, 426, 7, 2, true, RGB(255, 0, 255));
	_combo1 = IMAGEMANAGER->addFrameImage("schoolboy_combo1", "images/enemys/SchoolBoy_ComboAttack2.bmp", 1757, 444, 7, 2, true, RGB(255, 0, 255));
	_combo2 = IMAGEMANAGER->addFrameImage("schoolboy_combo2", "images/enemys/SchoolBoy_ComboAttack3.bmp", 1890, 558, 9, 2, true, RGB(255, 0, 255));
	_submotion = IMAGEMANAGER->addFrameImage("schoolboy_upercut", "images/enemys/SchoolBoy_upercut.bmp", 1386, 510, 7, 2, true, RGB(255, 0, 255));
	_gethit = IMAGEMANAGER->addFrameImage("schoolboy_gethit", "images/enemys/SchoolBoy_gethit.bmp", 1728, 450, 9, 2, true, RGB(255, 0, 255));
	_stun = IMAGEMANAGER->addFrameImage("schoolboy_stun", "images/enemys/SchoolBoy_Stun.bmp", 633, 408, 4, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("schoolboy_shadow", "images/enemys/SchoolBoy_Shadow.bmp", 180, 53, true, RGB(255, 0, 255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_random = RND->getInt(4);

	_direction = ENEMY_LEFT_MOVE;

	// ============================	½ºÄðº¸ÀÌ ¾ÆÀÌµé ============================ //
	_enemyMotion_L_IDLE = new animation;
	_enemyMotion_L_IDLE->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_L_IDLE->setPlayFrame(0, 7, false, true);
	_enemyMotion_L_IDLE->setFPS(1);
	_enemyMotion_L_IDLE->start();
	_enemyMotion_R_IDLE = new animation;
	_enemyMotion_R_IDLE->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_R_IDLE->setPlayFrame(15, 8, false, true);
	_enemyMotion_R_IDLE->setFPS(1);
	_enemyMotion_R_IDLE->start();
	// ============================	½ºÄðº¸ÀÌ ¾ÆÀÌµé ============================ //

	// ============================	½ºÄðº¸ÀÌ ¹«ºê ============================ //
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
	// ============================	½ºÄðº¸ÀÌ ¹«ºê ============================ //

	// ============================	½ºÄðº¸ÀÌ °ø°Ý ============================ //
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
	// ============================	½ºÄðº¸ÀÌ °ø°Ý ============================ //

	// ============================	½ºÄðº¸ÀÌ ÄÞº¸1 ============================ //
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
	// ============================	½ºÄðº¸ÀÌ ÄÞº¸1 ============================ //

	// ============================	½ºÄðº¸ÀÌ ÄÞº¸2 ============================ //
	_enemyMotion_L_COMBO2 = new animation;
	_enemyMotion_L_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_L_COMBO2->setPlayFrame(8, 0, false, false);
	_enemyMotion_L_COMBO2->setFPS(1.5);
	_enemyMotion_L_COMBO2->start();
	_enemyMotion_R_COMBO2 = new animation;
	_enemyMotion_R_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_R_COMBO2->setPlayFrame(9, 17, false, false);
	_enemyMotion_R_COMBO2->setFPS(1.5);
	_enemyMotion_R_COMBO2->start();
	// ============================	½ºÄðº¸ÀÌ ÄÞº¸2 ============================ //

	// ============================	½ºÄðº¸ÀÌ ¾îÆÛÄÆ ============================ //
	_enemyMotion_L_submotion = new animation;
	_enemyMotion_L_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_L_submotion->setPlayFrame(13, 7, false, false);
	_enemyMotion_L_submotion->setFPS(1.5);
	_enemyMotion_L_submotion->start();
	_enemyMotion_R_submotion = new animation;
	_enemyMotion_R_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_R_submotion->setPlayFrame(0, 6, false, false);
	_enemyMotion_R_submotion->setFPS(1.5);
	_enemyMotion_R_submotion->start();
	// ============================	½ºÄðº¸ÀÌ ¾îÆÛÄÆ ============================ //

	// ============================	½ºÄðº¸ÀÌ È÷Æ® ============================ //
	//_enemyMotion_L_hit = new animation;
	//_enemyMotion_L_hit->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	//_enemyMotion_L_hit->setPlayFrame(0, 8, false, false);
	//_enemyMotion_L_hit->setFPS(1);
	//_enemyMotion_L_hit->start();
	//_enemyMotion_R_hit = new animation;
	//_enemyMotion_R_hit->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	//_enemyMotion_R_hit->setPlayFrame(17, 9, false, false);
	//_enemyMotion_R_hit->setFPS(1);
	//_enemyMotion_R_hit->start();
	// ============================	½ºÄðº¸ÀÌ È÷Æ® ============================ //

	// ============================	½ºÄðº¸ÀÌ ½ºÅÏ ============================ //
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
	// ============================	½ºÄðº¸ÀÌ ½ºÅÏ ============================ //

	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_attackRC.set(0, 0, 0, 0);
	_rc.setCenterPos(0, 0);

	_enemyMotion = _enemyMotion_L;

	return S_OK;
}

void schoolboy::release()
{
}


void schoolboy::render()
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
	IMAGEMANAGER->findImage("schoolboy_shadow")->alphaRender(getMemDC(), _rc.left - 20, _rc.bottom - 30, 100);
	ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX(), 0, _rc.bottom);
}


