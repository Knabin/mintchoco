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
	_move = IMAGEMANAGER->addFrameImage("schoolboy_move", "images/enemys/SchoolBoy_Walk.bmp", 1620, 444, 12, 2, true, RGB(255, 0, 255));
	_attack = IMAGEMANAGER->addFrameImage("schoolboy_attack", "images/enemys/SchoolBoy_ComboAttack1.bmp", 1764, 426, 7, 2, true, RGB(255, 0, 255));
	_combo1 = IMAGEMANAGER->addFrameImage("schoolboy_combo1", "images/enemys/SchoolBoy_ComboAttack2.bmp", 2364, 444, 7, 2, true, RGB(255, 0, 255));
	_combo2 = IMAGEMANAGER->addFrameImage("schoolboy_combo2", "images/enemys/SchoolBoy_ComboAttack3.bmp", 1863, 558, 9, 2, true, RGB(255, 0, 255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_random = RND->getInt(3);

	_direction = ENEMY_LEFT_MOVE;

	// ============================	½ºÄðº¸ÀÌ ¹«ºê ============================ //
	_enemyMotion_L = new animation;
	_enemyMotion_L->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_L->setPlayFrame(0, 11, false, true);
	_enemyMotion_L->setFPS(1);
	_enemyMotion_L->start();
	_enemyMotion_R = new animation;
	_enemyMotion_R->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_R->setPlayFrame(21, 12, false, true);
	_enemyMotion_R->setFPS(1);
	_enemyMotion_R->start();
	// ============================	½ºÄðº¸ÀÌ ¹«ºê ============================ //

	// ============================	½ºÄðº¸ÀÌ °ø°Ý ============================ //
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
	// ============================	½ºÄðº¸ÀÌ °ø°Ý ============================ //

	// ============================	½ºÄðº¸ÀÌ ÄÞº¸1 ============================ //
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
	// ============================	½ºÄðº¸ÀÌ ÄÞº¸1 ============================ //

	// ============================	½ºÄðº¸ÀÌ ÄÞº¸2 ============================ //
	_enemyMotion_L_COMBO2 = new animation;
	_enemyMotion_L_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_L_COMBO2->setPlayFrame(0, 8, false, false);
	_enemyMotion_L_COMBO2->setFPS(1);
	_enemyMotion_L_COMBO2->start();
	_enemyMotion_R_COMBO2 = new animation;
	_enemyMotion_R_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_R_COMBO2->setPlayFrame(17, 9, false, false);
	_enemyMotion_R_COMBO2->setFPS(1);
	_enemyMotion_R_COMBO2->start();
	// ============================	½ºÄðº¸ÀÌ ÄÞº¸2 ============================ //

	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_enemyMotion = _enemyMotion_L;

	return S_OK;
}

void schoolboy::release()
{
}


void schoolboy::render()
{
	//_enemyImg->aniRender(getMemDC(), _rc.left, _rc.top, _enemyMotion);
	ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX(), 0, _rc.bottom);

	switch (_direction)
	{
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
}


