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
	_move = IMAGEMANAGER->addFrameImage("cheer_move", "images/enemys/CheerLeader_Walk.bmp", 2736, 438, 12, 2, true, RGB(255, 0, 255));
	_attack = IMAGEMANAGER->addFrameImage("cheer_attack", "images/enemys/CheerLeader_ComboAttack3.bmp", 1827, 426, 7, 2, true, RGB(255, 0, 255));
	_combo1 = IMAGEMANAGER->addFrameImage("cheer_combo1", "images/enemys/CheerLeader_ComboAttack1.bmp", 1332, 468, 6, 2, true, RGB(255, 0, 255));
	_combo2 = IMAGEMANAGER->addFrameImage("cheer_combo2", "images/enemys/CheerLeader_ComboAttack2.bmp", 540,474,3,2,true,RGB(255,0,255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_random = RND->getInt(3);
	_direction = ENEMY_LEFT_MOVE;

	// ============================	치어리더 무브 ============================ //
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
	// ============================	치어리더 무브 ============================ //

	// ============================	치어리더 공격 ============================ //
	_enemyMotion_L_A = new animation;
	_enemyMotion_L_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_L_A->setPlayFrame(13, 7, false, false);
	_enemyMotion_L_A->setFPS(1);
	_enemyMotion_L_A->start();
	_enemyMotion_R_A = new animation;
	_enemyMotion_R_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_R_A->setPlayFrame(0, 6, false, false);
	_enemyMotion_R_A->setFPS(1);
	_enemyMotion_R_A->start();
	// ============================	치어리더 공격 ============================ //

	// ============================	치어리더 콤보1 ============================ //
	_enemyMotion_L_COMBO1 = new animation;
	_enemyMotion_L_COMBO1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_L_COMBO1->setPlayFrame(11, 6, false, false);
	_enemyMotion_L_COMBO1->setFPS(1);
	_enemyMotion_L_COMBO1->start();
	_enemyMotion_R_COMBO1 = new animation;
	_enemyMotion_R_COMBO1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_R_COMBO1->setPlayFrame(0, 5, false, false);
	_enemyMotion_R_COMBO1->setFPS(1);
	_enemyMotion_R_COMBO1->start();
	// ============================	치어리더 콤보1 ============================ //

	// ============================	치어리더 콤보2 ============================ //
	_enemyMotion_L_COMBO2 = new animation;
	_enemyMotion_L_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_L_COMBO2->setPlayFrame(0, 2, false, false);
	_enemyMotion_L_COMBO2->setFPS(1);
	_enemyMotion_L_COMBO2->start();
	_enemyMotion_R_COMBO2 = new animation;
	_enemyMotion_R_COMBO2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_R_COMBO2->setPlayFrame(5, 3, false, false);
	_enemyMotion_R_COMBO2->setFPS(1);
	_enemyMotion_R_COMBO2->start();
	// ============================	치어리더 콤보2 ============================ //

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
	_enemyImg->aniRender(getMemDC(), _rc.left, _rc.top, _enemyMotion);

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

