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
	enemy::init(imageName, x, y, speed);
	_idle = IMAGEMANAGER->addFrameImage("schoolgirl_idle", "images/enemys/SchoolGirl_Idle.bmp", 1170, 354, 10, 2, true, RGB(255, 0, 255));
	_move = IMAGEMANAGER->addFrameImage("schoolgirl_move", "images/enemys/SchoolGirl_Walk.bmp", 1296, 372, 12, 2, true, RGB(255, 0, 255));
	_attack = IMAGEMANAGER->addFrameImage("schoolgirl_attack", "images/enemys/SchoolGirl_ComboAttack1.bmp", 1239, 354, 7, 2, true, RGB(255, 0, 255));
	_combo1 = IMAGEMANAGER->addFrameImage("schoolgirl_combo1", "images/enemys/SchoolGirl_ComboAttack2.bmp", 1197, 354, 7, 2, true, RGB(255, 0, 255));
	_combo2 = IMAGEMANAGER->addFrameImage("schoolgirl_combo2", "images/enemys/SchoolGirl_ComboAttack3.bmp", 2412, 414, 12, 2, true, RGB(255, 0, 255));
	_submotion = IMAGEMANAGER->addFrameImage("schoolgirl_attack1", "images/enemys/Schoolgirl_attack1.bmp", 2208, 354, 8, 2, true, RGB(255, 0, 255));
	_gethit = IMAGEMANAGER->addFrameImage("schoolgirl_gethit", "images/enemys/SchoolGirl_gethit.bmp", 1431, 360, 9, 2, true, RGB(255, 0, 255));
	_stun = IMAGEMANAGER->addFrameImage("schoolgirl_stun", "images/enemys/SchoolGirl_Stun.bmp", 456, 324, 4, 2, true, RGB(255, 0, 255));
	_dead = IMAGEMANAGER->addFrameImage("schoolgirl_dead", "images/enemys/SchoolGirl_weapon_swing.bmp", 4369, 336, 17, 2, true, RGB(255, 0, 255));
	_block = IMAGEMANAGER->addFrameImage("schoolgirl_block", "images/enemys/SchoolGirl_block.bmp", 351, 337, 3, 2, true, RGB(255, 0, 255));
	_run = IMAGEMANAGER->addFrameImage("schoolgirl_run", "images/enemys/SchoolGirl_run.bmp", 1470, 330, 10, 2, true, RGB(255, 0, 255));
	_backdown = IMAGEMANAGER->addFrameImage("schoolgirl_backdown", "images/enemys/SchoolGirl_backdown.bmp", 6939, 376, 27, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("schoolgirl_shadow", "images/enemys/SchoolGirl_Shadow.bmp", 150, 44, true, RGB(255, 0, 255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_random = RND->getInt(6);


	// ============================	여학우 아이들 ============================ //
	_enemyMotion_L_idle = new animation;
	_enemyMotion_L_idle->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_L_idle->setPlayFrame(0, 9, false, true);
	_enemyMotion_L_idle->setFPS(1);
	_enemyMotion_R_idle = new animation;
	_enemyMotion_R_idle->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_enemyMotion_R_idle->setPlayFrame(19, 10, false, true);
	_enemyMotion_R_idle->setFPS(1);
	// ============================	여학우 아이들 ============================ //

	// ============================	여학우 무브 ============================ //
	_enemyMotion_L = new animation;
	_enemyMotion_L->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_L->setPlayFrame(11, 0, false, true);
	_enemyMotion_L->setFPS(1.5);
	_enemyMotion_R = new animation;
	_enemyMotion_R->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_R->setPlayFrame(12, 23, false, true);
	_enemyMotion_R->setFPS(1.5);
	// ============================	여학우 무브 ============================ //

	// ============================	여학우 백무브 ============================ //
	_enemyMotion_L_back = new animation;
	_enemyMotion_L_back->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_L_back->setPlayFrame(0, 11, false, false);
	_enemyMotion_L_back->setFPS(1.5);
	_enemyMotion_R_back = new animation;
	_enemyMotion_R_back->init(_move->getWidth(), _move->getHeight(), _move->getFrameWidth(), _move->getFrameHeight());
	_enemyMotion_R_back->setPlayFrame(23, 12, false, false);
	_enemyMotion_R_back->setFPS(1.5);
	// ============================	여학우 백무브 ============================ //

	// ============================	여학우 공격 ============================ //
	_enemyMotion_L_A = new animation;
	_enemyMotion_L_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_L_A->setPlayFrame(6, 0, false, false);
	_enemyMotion_L_A->setFPS(1.5);
	_enemyMotion_R_A = new animation;
	_enemyMotion_R_A->init(_attack->getWidth(), _attack->getHeight(), _attack->getFrameWidth(), _attack->getFrameHeight());
	_enemyMotion_R_A->setPlayFrame(7, 13, false, false);
	_enemyMotion_R_A->setFPS(1.5);
	// ============================	여학우 공격 ============================ //

	// ============================	여학우 콤보1 ============================ //
	_enemyMotion_L_combo1 = new animation;
	_enemyMotion_L_combo1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_L_combo1->setPlayFrame(6, 0, false, false);
	_enemyMotion_L_combo1->setFPS(1.5);
	_enemyMotion_R_combo1 = new animation;
	_enemyMotion_R_combo1->init(_combo1->getWidth(), _combo1->getHeight(), _combo1->getFrameWidth(), _combo1->getFrameHeight());
	_enemyMotion_R_combo1->setPlayFrame(7, 13, false, false);
	_enemyMotion_R_combo1->setFPS(1.5);
	// ============================	여학우 콤보1 ============================ //

	// ============================	여학우 콤보2 ============================ //
	_enemyMotion_L_combo2 = new animation;
	_enemyMotion_L_combo2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_L_combo2->setPlayFrame(0, 11, false, false);
	_enemyMotion_L_combo2->setFPS(1.5);
	_enemyMotion_R_combo2 = new animation;
	_enemyMotion_R_combo2->init(_combo2->getWidth(), _combo2->getHeight(), _combo2->getFrameWidth(), _combo2->getFrameHeight());
	_enemyMotion_R_combo2->setPlayFrame(23, 12, false, false);
	_enemyMotion_R_combo2->setFPS(1.5);
	// ============================	여학우 콤보2 ============================ //

	// ============================	여학우 서브모션 ============================ //
	_enemyMotion_L_submotion = new animation;
	_enemyMotion_L_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_L_submotion->setPlayFrame(15, 8, false, false);
	_enemyMotion_L_submotion->setFPS(1.5);
	_enemyMotion_R_submotion = new animation;
	_enemyMotion_R_submotion->init(_submotion->getWidth(), _submotion->getHeight(), _submotion->getFrameWidth(), _submotion->getFrameHeight());
	_enemyMotion_R_submotion->setPlayFrame(0, 7, false, false);
	_enemyMotion_R_submotion->setFPS(1.5);
	// ============================	여학우 서브모션 ============================ //

	// ============================	여학우 히트1 ============================ //
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
	// ============================	여학우 히트1 ============================ //

	// ============================	여학우 히트2 ============================ //
	_enemyMotion_L_hit_2 = new animation;
	_enemyMotion_L_hit_2->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	_enemyMotion_L_hit_2->setPlayFrame(14, 12, false, false);
	_enemyMotion_L_hit_2->setFPS(0.3);
	//_enemyMotion_L_hit_2->start();
	_enemyMotion_R_hit_2 = new animation;
	_enemyMotion_R_hit_2->init(_gethit->getWidth(), _gethit->getHeight(), _gethit->getFrameWidth(), _gethit->getFrameHeight());
	_enemyMotion_R_hit_2->setPlayFrame(3, 5, false, false);
	_enemyMotion_R_hit_2->setFPS(0.3);
	//_enemyMotion_R_hit_2->start();
	// ============================	여학우 히트2 ============================ //

	// ============================	여학우 히트3 ============================ //
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
	// ============================	여학우 히트3 ============================ //

	// ============================	여학우 스턴 ============================ //
	_enemyMotion_L_stun = new animation;
	_enemyMotion_L_stun->init(_stun->getWidth(), _stun->getHeight(), _stun->getFrameWidth(), _stun->getFrameHeight());
	_enemyMotion_L_stun->setPlayFrame(0, 3, false, false);
	_enemyMotion_L_stun->setFPS(0.7);
	_enemyMotion_R_stun = new animation;
	_enemyMotion_R_stun->init(_stun->getWidth(), _stun->getHeight(), _stun->getFrameWidth(), _stun->getFrameHeight());
	_enemyMotion_R_stun->setPlayFrame(7, 4, false, false);
	_enemyMotion_R_stun->setFPS(0.7);
	// ============================	여학우 스턴 ============================ //

	// ============================	여학우 죽음 ============================ //
	_enemyMotion_L_dead = new animation;
	_enemyMotion_L_dead->init(_dead->getWidth(), _dead->getHeight(), _dead->getFrameWidth(), _dead->getFrameHeight());
	_enemyMotion_L_dead->setPlayFrame(0, 17, false, false);
	_enemyMotion_L_dead->setFPS(1);
	_enemyMotion_L_dead->start();
	_enemyMotion_R_dead = new animation;
	_enemyMotion_R_dead->init(_dead->getWidth(), _dead->getHeight(), _dead->getFrameWidth(), _dead->getFrameHeight());
	_enemyMotion_R_dead->setPlayFrame(33, 17, false, false);
	_enemyMotion_R_dead->setFPS(1);
	_enemyMotion_R_dead->start();
	// ============================	여학우 죽음 ============================ //

	// ============================	여학우 막기 ============================ //
	_enemyMotion_L_block = new animation;
	_enemyMotion_L_block->init(_block->getWidth(), _block->getHeight(), _block->getFrameWidth(), _block->getFrameHeight());
	_enemyMotion_L_block->setPlayFrame(5, 3, false, false);
	_enemyMotion_L_block->setFPS(0.5);
	_enemyMotion_R_block = new animation;
	_enemyMotion_R_block->init(_block->getWidth(), _block->getHeight(), _block->getFrameWidth(), _block->getFrameHeight());
	_enemyMotion_R_block->setPlayFrame(0, 2, false, false);
	_enemyMotion_R_block->setFPS(0.5);
	// ============================	여학우 막기 ============================ //

	// ============================	여학우 런 ============================ //
	_enemyMotion_L_run = new animation;
	_enemyMotion_L_run->init(_run->getWidth(), _run->getHeight(), _run->getFrameWidth(), _run->getFrameHeight());
	_enemyMotion_L_run->setPlayFrame(19, 10, false, false);
	_enemyMotion_L_run->setFPS(1.5);
	_enemyMotion_R_run = new animation;
	_enemyMotion_R_run->init(_run->getWidth(), _run->getHeight(), _run->getFrameWidth(), _run->getFrameHeight());
	_enemyMotion_R_run->setPlayFrame(0, 9, false, false);
	_enemyMotion_R_run->setFPS(1.5);
	// ============================	여학우 런 ============================ //

	// ============================	여학우 백다운 ============================ //
	_enemyMotion_L_backdown = new animation;
	_enemyMotion_L_backdown->init(_backdown->getWidth(), _backdown->getHeight(), _backdown->getFrameWidth(), _backdown->getFrameHeight());
	_enemyMotion_L_backdown->setPlayFrame(0, 26, false, false);
	_enemyMotion_L_backdown->setFPS(1);
	_enemyMotion_R_backdown = new animation;
	_enemyMotion_R_backdown->init(_backdown->getWidth(), _backdown->getHeight(), _backdown->getFrameWidth(), _backdown->getFrameHeight());
	_enemyMotion_R_backdown->setPlayFrame(53, 27, false, false);
	_enemyMotion_R_backdown->setFPS(1);
	// ============================	여학우 백다운 ============================ //

	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_attackRC.set(0, 0, 0, 0);
	_attackRC.setCenterPos(0, 0);

	_enemyMotion = _enemyMotion_R;
	_direction = ENEMY_RIGHT_MOVE;
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
		_x -= 3.f;
		_enemyImg = _backdown;
		break;
	case ENEMY_RIGHT_BACKDOWN:
		_x += 3.f;
		_enemyImg = _backdown;
		break;
	}
	//_rc.render(getMemDC());
	_attackRC.render(getMemDC());
	IMAGEMANAGER->findImage("schoolgirl_shadow")->alphaRender(getMemDC(), _rc.left - 19, _rc.bottom - 25, 100);
	ZORDER->pushObject(getMemDC(), _enemyImg, _enemyMotion, 1, _rc.getCenterX(), 0, _rc.bottom);
}
