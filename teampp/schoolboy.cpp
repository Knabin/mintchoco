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
	enemy::init(imageName, x, y, speed);
	_idle = IMAGEMANAGER->addFrameImage("schoolboy_idle", "images/enemys/SchoolBoy_Idle.bmp", 1224, 432, 8, 2, true, RGB(255, 0, 255));
	_move = IMAGEMANAGER->addFrameImage("schoolboy_move", "images/enemys/SchoolBoy_Walk.bmp", 1620, 444, 12, 2, true, RGB(255, 0, 255));
	_attack = IMAGEMANAGER->addFrameImage("schoolboy_attack", "images/enemys/SchoolBoy_ComboAttack1.bmp", 2352, 426, 7, 2, true, RGB(255, 0, 255));
	_combo1 = IMAGEMANAGER->addFrameImage("schoolboy_combo1", "images/enemys/SchoolBoy_ComboAttack2.bmp", 1757, 444, 7, 2, true, RGB(255, 0, 255));
	_combo2 = IMAGEMANAGER->addFrameImage("schoolboy_combo2", "images/enemys/SchoolBoy_ComboAttack3.bmp", 1890, 558, 9, 2, true, RGB(255, 0, 255));
	_submotion = IMAGEMANAGER->addFrameImage("schoolboy_upercut", "images/enemys/SchoolBoy_upercut.bmp", 1386, 502, 7, 2, true, RGB(255, 0, 255));
	_gethit = IMAGEMANAGER->addFrameImage("schoolboy_gethit", "images/enemys/SchoolBoy_gethit.bmp", 1728, 450, 9, 2, true, RGB(255, 0, 255));
	_stun = IMAGEMANAGER->addFrameImage("schoolboy_stun", "images/enemys/SchoolBoy_Stun.bmp", 633, 408, 4, 2, true, RGB(255, 0, 255));
	_dead = IMAGEMANAGER->addFrameImage("schoolboy_dead", "images/enemys/SchoolBoy_weapon_swing.bmp", 5415, 438, 19, 2, true, RGB(255, 0, 255));
	_block = IMAGEMANAGER->addFrameImage("schoolboy_block", "images/enemys/SchoolBoy_block.bmp", 459, 438, 3, 2, true, RGB(255, 0, 255));
	_run = IMAGEMANAGER->addFrameImage("schoolboy_run", "images/enemys/SchoolBoy_run.bmp", 1920, 390, 10, 2, true, RGB(255, 0, 255));
	_backdown = IMAGEMANAGER->addFrameImage("schoolboy_backdown", "images/enemys/SchoolBoy_backdown.bmp", 7695, 438, 27, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("schoolboy_shadow", "images/enemys/SchoolBoy_Shadow.bmp", 180, 53, true, RGB(255, 0, 255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_random = RND->getInt(6);


	// ============================	½ºÄðº¸ÀÌ ¾ÆÀÌµé ============================ //
	_enemyMotion_L_idle = new animation;
	_enemyMotion_L_idle->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_L_idle->setPlayFrame(0, 7, false, true);
	_enemyMotion_L_idle->setFPS(1);
	_enemyMotion_R_idle = new animation;
	_enemyMotion_R_idle->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_R_idle->setPlayFrame(15, 8, false, true);
	_enemyMotion_R_idle->setFPS(1);
	// ============================	½ºÄðº¸ÀÌ ¾ÆÀÌµé ============================ //

	// ============================	½ºÄðº¸ÀÌ ¹«ºê ============================ //
	_enemyMotion_L = new animation;
	_enemyMotion_L->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_L->setPlayFrame(11, 0, false, true);
	_enemyMotion_L->setFPS(1.5);
	_enemyMotion_R = new animation;
	_enemyMotion_R->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_R->setPlayFrame(12, 23, false, true);
	_enemyMotion_R->setFPS(1.5);
	// ============================	½ºÄðº¸ÀÌ ¹«ºê ============================ //

	// ============================	½ºÄðº¸ÀÌ ¹é¹«ºê ============================ //
	_enemyMotion_L_back = new animation;
	_enemyMotion_L_back->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_L_back->setPlayFrame(0, 11, false, false);
	_enemyMotion_L_back->setFPS(1.5);
	_enemyMotion_R_back = new animation;
	_enemyMotion_R_back->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_R_back->setPlayFrame(23, 12, false, false);
	_enemyMotion_R_back->setFPS(1.5);
	// ============================	½ºÄðº¸ÀÌ ¹é¹«ºê ============================ //

	// ============================	½ºÄðº¸ÀÌ °ø°Ý ============================ //
	_enemyMotion_L_A = new animation;
	_enemyMotion_L_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_L_A->setPlayFrame(6, 0, false, false);
	_enemyMotion_L_A->setFPS(1.5);
	_enemyMotion_R_A = new animation;
	_enemyMotion_R_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_R_A->setPlayFrame(7, 13, false, false);
	_enemyMotion_R_A->setFPS(1.5);
	// ============================	½ºÄðº¸ÀÌ °ø°Ý ============================ //

	// ============================	½ºÄðº¸ÀÌ ÄÞº¸1 ============================ //
	_enemyMotion_L_combo1 = new animation;
	_enemyMotion_L_combo1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_L_combo1->setPlayFrame(6, 0, false, false);
	_enemyMotion_L_combo1->setFPS(1.5);
	_enemyMotion_R_combo1 = new animation;
	_enemyMotion_R_combo1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_R_combo1->setPlayFrame(7, 13, false, false);
	_enemyMotion_R_combo1->setFPS(1.5);
	// ============================	½ºÄðº¸ÀÌ ÄÞº¸1 ============================ //

	// ============================	½ºÄðº¸ÀÌ ÄÞº¸2 ============================ //
	_enemyMotion_L_combo2 = new animation;
	_enemyMotion_L_combo2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_L_combo2->setPlayFrame(8, 0, false, false);
	_enemyMotion_L_combo2->setFPS(1.5);
	_enemyMotion_R_combo2 = new animation;
	_enemyMotion_R_combo2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_R_combo2->setPlayFrame(9, 17, false, false);
	_enemyMotion_R_combo2->setFPS(1.5);
	// ============================	½ºÄðº¸ÀÌ ÄÞº¸2 ============================ //

	// ============================	½ºÄðº¸ÀÌ ¾îÆÛÄÆ ============================ //
	_enemyMotion_L_submotion = new animation;
	_enemyMotion_L_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_L_submotion->setPlayFrame(13, 7, false, false);
	_enemyMotion_L_submotion->setFPS(1.5);
	_enemyMotion_R_submotion = new animation;
	_enemyMotion_R_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_R_submotion->setPlayFrame(0, 6, false, false);
	_enemyMotion_R_submotion->setFPS(1.5);
	// ============================	½ºÄðº¸ÀÌ ¾îÆÛÄÆ ============================ //

	// ============================	½ºÄðº¸ÀÌ È÷Æ®1 ============================ //
	_enemyMotion_L_hit_1 = new animation;
	_enemyMotion_L_hit_1->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	_enemyMotion_L_hit_1->setPlayFrame(17, 15, false, false);
	_enemyMotion_L_hit_1->setFPS(0.3);
	//_enemyMotion_L_hit_1->start();
	_enemyMotion_R_hit_1 = new animation;
	_enemyMotion_R_hit_1->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	_enemyMotion_R_hit_1->setPlayFrame(0, 2, false, false);
	_enemyMotion_R_hit_1->setFPS(0.3);
	//_enemyMotion_R_hit_1->start();
	// ============================	½ºÄðº¸ÀÌ È÷Æ®1 ============================ //

	// ============================	½ºÄðº¸ÀÌ È÷Æ®2 ============================ //
	_enemyMotion_L_hit_2 = new animation;
	_enemyMotion_L_hit_2->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	_enemyMotion_L_hit_2->setPlayFrame(14, 12, false, false);
	_enemyMotion_L_hit_2->setFPS(0.3);
	_enemyMotion_R_hit_2 = new animation;
	_enemyMotion_R_hit_2->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	_enemyMotion_R_hit_2->setPlayFrame(3, 5, false, false);
	_enemyMotion_R_hit_2->setFPS(0.3);
	// ============================	½ºÄðº¸ÀÌ È÷Æ®2 ============================ //

	// ============================	½ºÄðº¸ÀÌ È÷Æ®3 ============================ //
	_enemyMotion_L_hit_3 = new animation;
	_enemyMotion_L_hit_3->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	_enemyMotion_L_hit_3->setPlayFrame(11, 9, false, false);
	_enemyMotion_L_hit_3->setFPS(0.3);
	//_enemyMotion_L_hit_3->start();
	_enemyMotion_R_hit_3 = new animation;
	_enemyMotion_R_hit_3->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	_enemyMotion_R_hit_3->setPlayFrame(6, 8, false, false);
	_enemyMotion_R_hit_3->setFPS(0.3);
	//_enemyMotion_R_hit_3->start();
	// ============================	½ºÄðº¸ÀÌ È÷Æ®3 ============================ //

	// ============================	½ºÄðº¸ÀÌ ½ºÅÏ ============================ //
	_enemyMotion_L_stun = new animation;
	_enemyMotion_L_stun->init(_stun->getWidth(), _stun->getHeight(), _stun->getFrameWidth(), _stun->getFrameHeight());
	_enemyMotion_L_stun->setPlayFrame(0, 3, false, false);
	_enemyMotion_L_stun->setFPS(0.7);
	_enemyMotion_R_stun = new animation;
	_enemyMotion_R_stun->init(_stun->getWidth(), _stun->getHeight(), _stun->getFrameWidth(), _stun->getFrameHeight());
	_enemyMotion_R_stun->setPlayFrame(7, 4, false, false);
	_enemyMotion_R_stun->setFPS(0.7);
	// ============================	½ºÄðº¸ÀÌ ½ºÅÏ ============================ //

	// ============================	½ºÄðº¸ÀÌ Á×À½ ============================ //
	_enemyMotion_L_dead = new animation;
	_enemyMotion_L_dead->init(_dead->getWidth(), _dead->getHeight(), _dead->getFrameWidth(), _dead->getFrameHeight());
	_enemyMotion_L_dead->setPlayFrame(0, 18, false, false);
	_enemyMotion_L_dead->setFPS(1);
	_enemyMotion_L_dead->start();
	_enemyMotion_R_dead = new animation;
	_enemyMotion_R_dead->init(_dead->getWidth(), _dead->getHeight(), _dead->getFrameWidth(), _dead->getFrameHeight());
	_enemyMotion_R_dead->setPlayFrame(37, 19, false, false);
	_enemyMotion_R_dead->setFPS(1);
	_enemyMotion_R_dead->start();
	// ============================	½ºÄðº¸ÀÌ Á×À½ ============================ //

	// ============================	½ºÄðº¸ÀÌ ¸·±â ============================ //
	_enemyMotion_L_block = new animation;
	_enemyMotion_L_block->init(_block->getWidth(), _block->getHeight(), _block->getFrameWidth(), _block->getFrameHeight());
	_enemyMotion_L_block->setPlayFrame(5, 3, false, false);
	_enemyMotion_L_block->setFPS(0.5);
	_enemyMotion_R_block = new animation;
	_enemyMotion_R_block->init(_block->getWidth(), _block->getHeight(), _block->getFrameWidth(), _block->getFrameHeight());
	_enemyMotion_R_block->setPlayFrame(0, 2, false, false);
	_enemyMotion_R_block->setFPS(0.5);
	// ============================	½ºÄðº¸ÀÌ ¸·±â ============================ //

	// ============================	½ºÄðº¸ÀÌ ·± ============================ //
	_enemyMotion_L_run = new animation;
	_enemyMotion_L_run->init(_run->getWidth(), _run->getHeight(), _run->getFrameWidth(), _run->getFrameHeight());
	_enemyMotion_L_run->setPlayFrame(19, 10, false, false);
	_enemyMotion_L_run->setFPS(1.5);
	_enemyMotion_R_run = new animation;
	_enemyMotion_R_run->init(_run->getWidth(), _run->getHeight(), _run->getFrameWidth(), _run->getFrameHeight());
	_enemyMotion_R_run->setPlayFrame(0, 9, false, false);
	_enemyMotion_R_run->setFPS(1.5);
	// ============================	½ºÄðº¸ÀÌ ·± ============================ //

	// ============================	½ºÄðº¸ÀÌ ¹é´Ù¿î ============================ //
	_enemyMotion_L_backdown = new animation;
	_enemyMotion_L_backdown->init(_backdown->getWidth(), _backdown->getHeight(), _backdown->getFrameWidth(), _backdown->getFrameHeight());
	_enemyMotion_L_backdown->setPlayFrame(0, 26, false, false);
	_enemyMotion_L_backdown->setFPS(2);
	_enemyMotion_R_backdown = new animation;
	_enemyMotion_R_backdown->init(_backdown->getWidth(), _backdown->getHeight(), _backdown->getFrameWidth(), _backdown->getFrameHeight());
	_enemyMotion_R_backdown->setPlayFrame(53, 27, false, false);
	_enemyMotion_R_backdown->setFPS(2);
	// ============================	½ºÄðº¸ÀÌ ¹é´Ù¿î ============================ //

	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_attackRC.set(0, 0, 0, 0);
	_attackRC.setCenterPos(0, 0);

	_enemyMotion = _enemyMotion_R;
	_direction = ENEMY_RIGHT_MOVE;

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
	case ENEMY_LEFT_BACK_MOVE:
		_x += 3;
		_enemyImg = _move;
		break;
	case ENEMY_RIGHT_BACK_MOVE:
		_x -= 3;
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
	case ENEMY_LEFT_GETHIT_1:
		_enemyImg = _gethit;
		break;
	case ENEMY_RIGHT_GETHIT_1:
		_enemyImg = _gethit;
		break;
	case ENEMY_LEFT_GETHIT_2:
		_enemyImg = _gethit;
		break;
	case ENEMY_RIGHT_GETHIT_2:
		_enemyImg = _gethit;
		break;
	case ENEMY_LEFT_GETHIT_3:
		_enemyImg = _gethit;
		break;
	case ENEMY_RIGHT_GETHIT_3:
		_enemyImg = _gethit;
		break;
	case ENEMY_LEFT_STUN:
		_enemyImg = _stun;
		break;
	case ENEMY_RIGHT_STUN:
		_enemyImg = _stun;
		break;
	case ENEMY_LEFT_DEAD:
		_enemyImg = _dead;
		break;
	case ENEMY_RIGHT_DEAD:
		_enemyImg = _dead;
		break;
	case ENEMY_LEFT_BLOCK:
		_enemyImg = _block;
		break;
	case ENEMY_RIGHT_BLOCK:
		_enemyImg = _block;
		break;
	case ENEMY_LEFT_RUN:
		_x -= 4.5f;
		_enemyImg = _run;
		break;
	case ENEMY_RIGHT_RUN:
		_x += 4.5f;
		_enemyImg = _run;
		break;
	case ENEMY_LEFT_BACKDOWN:
		if (_enemyMotion->getFramePos().x < 19 * _enemyMotion->getFrameWidth())
			_x -= 10.f;
		_enemyImg = _backdown;
		break;
	case ENEMY_RIGHT_BACKDOWN:
		if (_enemyMotion->getFramePos().x > 10 * _enemyMotion->getFrameWidth())
			_x += 10.f;
		_enemyImg = _backdown;
		break;
	}
	//_rc.render(getMemDC());
	//_attackRC.render(getMemDC());
	IMAGEMANAGER->findImage("schoolboy_shadow")->alphaRender(getMemDC(), _rc.left - 20, _rc.bottom - 30, 100);
	ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX(), 0, _rc.bottom);
}


