#include "stdafx.h"
#include "boss.h"

boss::boss()
{
}

boss::~boss()
{
}

HRESULT boss::init(string imageName, float x, float z, float speed)
{
	_bossIdle = IMAGEMANAGER->addFrameImage("BOSSIDLE", "images/boss/boss_idle.bmp", 3180, 634, 12, 2, true, RGB(255, 0, 255));
	_bossWalk = IMAGEMANAGER->addFrameImage("BOSSWALK", "images/boss/boss_walk.bmp", 2110, 588, 10, 2, true, RGB(255, 0, 255));
	_bossHit = IMAGEMANAGER->addFrameImage("BOSSHIT", "images/boss/boss_gethit.bmp", 2214, 594, 9, 2, true, RGB(255, 0, 255));
	_bossSlap = IMAGEMANAGER->addFrameImage("BOSSSLAP", "images/boss/boss_slap.bmp", 5278, 582, 14, 2, true, RGB(255, 0, 255));
	_bossElbow = IMAGEMANAGER->addFrameImage("BOSSELBOW", "images/boss/boss_elbow.bmp", 2915, 652, 11, 2, true, RGB(255, 0, 255));
	_bossBlock = IMAGEMANAGER->addFrameImage("BOSSBLOCK", "images/boss/boss_block1.bmp", 1688, 576, 8, 2, true, RGB(255, 0, 255));
	_bossRoar = IMAGEMANAGER->addFrameImage("BOSSROAR", "images/boss/boss_roar.bmp", 2916, 576, 12, 2, true, RGB(255, 0, 255));
	_bossRoar_u = IMAGEMANAGER->addFrameImage("BOSSROAR_U", "images/boss/boss_roar_U.bmp", 1000, 474, 4, 2, true, RGB(255, 0, 255));
	_bossTackle = IMAGEMANAGER->addFrameImage("BOSSTACKLE", "images/boss/boss_tackle.bmp", 1120, 576, 5, 2, true, RGB(255, 0, 255));
	_bossTackle_l = IMAGEMANAGER->addFrameImage("BOSSTACKLE_L", "images/boss/boss_tackle_L.bmp", 2882, 576, 11, 2, true, RGB(255, 0, 255));
	_bossTaunt = IMAGEMANAGER->addFrameImage("BOSSTAUNT", "images/boss/boss_taunt.bmp", 5658, 748, 23, 2, true, RGB(255, 0, 255));
	_bossMeteor = IMAGEMANAGER->addFrameImage("BOSSMETEOR", "images/boss/boss_meteor.bmp", 480, 460, 2, 2, true, RGB(255, 0, 255));
	_bossMeteor_g = IMAGEMANAGER->addFrameImage("BOSSMETEOR_G", "images/boss/boss_meteor_G.bmp", 1224, 422, 6, 2, true, RGB(255, 0, 255));
	_bossMeteor_c = IMAGEMANAGER->addFrameImage("BOSSMETEOR_C", "images/boss/boss_meteor_C.bmp", 2988, 576, 12, 2, true, RGB(255, 0, 255));
	_bossMeteor_m = IMAGEMANAGER->addFrameImage("BOSSMETEOR_M", "images/boss/boss_meteor_M.bmp", 4674, 576, 19, 2, true, RGB(255, 0, 255));
	_bossMeteor_j = IMAGEMANAGER->addFrameImage("BOSSMETEOR_J", "images/boss/boss_meteor_J.bmp", 1888, 672, 8, 2, true, RGB(255, 0, 255));
	_bossMeteor_a = IMAGEMANAGER->addFrameImage("BOSSMETEOR_A", "images/boss/boss_meteor_A.bmp", 410, 660, 2, 2, true, RGB(255, 0, 255));
	_bossWupunch = IMAGEMANAGER->addFrameImage("BOSSWUPUNCH", "images/boss/boss_wupunch.bmp", 11880, 594, 27, 2, true, RGB(255, 0, 255));

	_bossHit_a = IMAGEMANAGER->addFrameImage("BOSSHIT_A", "images/boss/boss_gethit_A.bmp", 5830, 510, 22, 2, true, RGB(255, 0, 255));
	_bossHit_k = IMAGEMANAGER->addFrameImage("BOSSHIT_K", "images/boss/boss_gethit_K.bmp", 2880, 594, 10, 2, true, RGB(255, 0, 255));
	_bossG_hit = IMAGEMANAGER->addFrameImage("BOSSG_HIT", "images/boss/boss_groundhit.bmp", 1036, 460, 4, 2, true, RGB(255, 0, 255));
	_bossGetup_s = IMAGEMANAGER->addFrameImage("BOSSGETUP_S", "images/boss/boss_getup_S.bmp", 2560, 466, 10, 2, true, RGB(255, 0, 255));
	_bossGetup_ss = IMAGEMANAGER->addFrameImage("BOSSGETUP_SS", "images/boss/boss_getup_SS.bmp", 3735, 580, 15, 2, true, RGB(255, 0, 255));
	_bossDizzy = IMAGEMANAGER->addFrameImage("BOSSDIZZY", "images/boss/boss_dizzy.bmp", 1024, 434, 4, 2, true, RGB(255, 0, 255));
	_bossGetup_c = IMAGEMANAGER->addFrameImage("BOSSGETUP_C", "images/boss/boss_getup_C.bmp", 2187, 576, 9, 2, true, RGB(255, 0, 255));
	_bossDefeat = IMAGEMANAGER->addFrameImage("BOSSDEFEAT", "images/boss/boss_defeat.bmp", 4576, 576, 13, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("boss_shadow", "images/boss/boss_Shadow.bmp", 200, 59, true, RGB(255, 0, 255));


	_bossImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;


	_x = _x + x;
	_y = 0;
	_z = _z + z;


	_speed = speed;
	_random = RND->getInt(4);
	_random1 = RND->getInt(2);

	_bossDirection = BOSS_LEFT_IDLE;
	_bossPhase = PHASE1;


	_boss_L_IDLE = new animation;
	_boss_L_IDLE->init(_bossIdle->getWidth(), _bossIdle->getHeight(), _bossIdle->getFrameWidth(), _bossIdle->getFrameHeight());
	_boss_L_IDLE->setPlayFrame(23, 12, false, true);
	_boss_L_IDLE->setFPS(1);
	_boss_R_IDLE = new animation;
	_boss_R_IDLE->init(_bossIdle->getWidth(), _bossIdle->getHeight(), _bossIdle->getFrameWidth(), _bossIdle->getFrameHeight());
	_boss_R_IDLE->setPlayFrame(0, 11, false, true);
	_boss_R_IDLE->setFPS(1);

	_boss_L_WALK = new animation;
	_boss_L_WALK->init(_bossWalk->getWidth(), _bossWalk->getHeight(), _bossWalk->getFrameWidth(), _bossWalk->getFrameHeight());
	_boss_L_WALK->setPlayFrame(19, 10, false, true);
	_boss_L_WALK->setFPS(1);
	_boss_R_WALK = new animation;
	_boss_R_WALK->init(_bossWalk->getWidth(), _bossWalk->getHeight(), _bossWalk->getFrameWidth(), _bossWalk->getFrameHeight());
	_boss_R_WALK->setPlayFrame(0, 9, false, true);
	_boss_R_WALK->setFPS(1);

	_boss_L_SLAP = new animation;
	_boss_L_SLAP->init(_bossSlap->getWidth(), _bossSlap->getHeight(), _bossSlap->getFrameWidth(), _bossSlap->getFrameHeight());
	_boss_L_SLAP->setPlayFrame(27, 14, false, false);
	_boss_L_SLAP->setFPS(1);
	_boss_R_SLAP = new animation;
	_boss_R_SLAP->init(_bossSlap->getWidth(), _bossSlap->getHeight(), _bossSlap->getFrameWidth(), _bossSlap->getFrameHeight());
	_boss_R_SLAP->setPlayFrame(0, 13, false, false);
	_boss_R_SLAP->setFPS(1);

	_boss_L_ELBOW = new animation;
	_boss_L_ELBOW->init(_bossElbow->getWidth(), _bossElbow->getHeight(), _bossElbow->getFrameWidth(), _bossElbow->getFrameHeight());
	_boss_L_ELBOW->setPlayFrame(21, 11, false, false);
	_boss_L_ELBOW->setFPS(1);
	_boss_R_ELBOW = new animation;
	_boss_R_ELBOW->init(_bossElbow->getWidth(), _bossElbow->getHeight(), _bossElbow->getFrameWidth(), _bossElbow->getFrameHeight());
	_boss_R_ELBOW->setPlayFrame(0, 10, false, false);
	_boss_R_ELBOW->setFPS(1);
	//---------------------------------------------------------------------------------------------------------------------------------
	_boss_L_BLOCK = new animation;
	_boss_L_BLOCK->init(_bossBlock->getWidth(), _bossBlock->getHeight(), _bossBlock->getFrameWidth(), _bossBlock->getFrameHeight());
	_boss_L_BLOCK->setPlayFrame(15, 8, false, false);
	_boss_L_BLOCK->setFPS(1);
	_boss_R_BLOCK = new animation;
	_boss_R_BLOCK->init(_bossBlock->getWidth(), _bossBlock->getHeight(), _bossBlock->getFrameWidth(), _bossBlock->getFrameHeight());
	_boss_R_BLOCK->setPlayFrame(0, 7, false, false);
	_boss_R_BLOCK->setFPS(1);

	_boss_L_ROAR = new animation;
	_boss_L_ROAR->init(_bossRoar->getWidth(), _bossRoar->getHeight(), _bossRoar->getFrameWidth(), _bossRoar->getFrameHeight());
	_boss_L_ROAR->setPlayFrame(23, 12, false, false);
	_boss_L_ROAR->setFPS(1);
	_boss_R_ROAR = new animation;
	_boss_R_ROAR->init(_bossRoar->getWidth(), _bossRoar->getHeight(), _bossRoar->getFrameWidth(), _bossRoar->getFrameHeight());
	_boss_R_ROAR->setPlayFrame(0, 11, false, false);
	_boss_R_ROAR->setFPS(1);

	_boss_L_ROAR_U = new animation;
	_boss_L_ROAR_U->init(_bossRoar_u->getWidth(), _bossRoar_u->getHeight(), _bossRoar_u->getFrameWidth(), _bossRoar_u->getFrameHeight());
	_boss_L_ROAR_U->setPlayFrame(7, 4, false, false);
	_boss_L_ROAR_U->setFPS(1);
	_boss_R_ROAR_U = new animation;
	_boss_R_ROAR_U->init(_bossRoar_u->getWidth(), _bossRoar_u->getHeight(), _bossRoar_u->getFrameWidth(), _bossRoar_u->getFrameHeight());
	_boss_R_ROAR_U->setPlayFrame(0, 3, false, false);
	_boss_R_ROAR_U->setFPS(1);

	_boss_L_TACKLE = new animation;
	_boss_L_TACKLE->init(_bossTackle->getWidth(), _bossTackle->getHeight(), _bossTackle->getFrameWidth(), _bossTackle->getFrameHeight());
	_boss_L_TACKLE->setPlayFrame(9, 5, false, false);
	_boss_L_TACKLE->setFPS(1);
	_boss_R_TACKLE = new animation;
	_boss_R_TACKLE->init(_bossTackle->getWidth(), _bossTackle->getHeight(), _bossTackle->getFrameWidth(), _bossTackle->getFrameHeight());
	_boss_R_TACKLE->setPlayFrame(0, 4, false, false);
	_boss_R_TACKLE->setFPS(1);

	_boss_L_TACKLE_L = new animation;
	_boss_L_TACKLE_L->init(_bossTackle_l->getWidth(), _bossTackle_l->getHeight(), _bossTackle_l->getFrameWidth(), _bossTackle_l->getFrameHeight());
	_boss_L_TACKLE_L->setPlayFrame(21, 11, false, false);
	_boss_L_TACKLE_L->setFPS(1);
	_boss_R_TACKLE_L = new animation;
	_boss_R_TACKLE_L->init(_bossTackle_l->getWidth(), _bossTackle_l->getHeight(), _bossTackle_l->getFrameWidth(), _bossTackle_l->getFrameHeight());
	_boss_R_TACKLE_L->setPlayFrame(0, 10, false, false);
	_boss_R_TACKLE_L->setFPS(1);

	_boss_L_TAUNT = new animation;
	_boss_L_TAUNT->init(_bossTaunt->getWidth(), _bossTaunt->getHeight(), _bossTaunt->getFrameWidth(), _bossTaunt->getFrameHeight());
	_boss_L_TAUNT->setPlayFrame(45, 23, false, false);
	_boss_L_TAUNT->setFPS(1);
	_boss_R_TAUNT = new animation;
	_boss_R_TAUNT->init(_bossTaunt->getWidth(), _bossTaunt->getHeight(), _bossTaunt->getFrameWidth(), _bossTaunt->getFrameHeight());
	_boss_R_TAUNT->setPlayFrame(0, 22, false, false);
	_boss_R_TAUNT->setFPS(1);

	_boss_L_METEOR = new animation;
	_boss_L_METEOR->init(_bossMeteor->getWidth(), _bossMeteor->getHeight(), _bossMeteor->getFrameWidth(), _bossMeteor->getFrameHeight());
	_boss_L_METEOR->setPlayFrame(3, 2, false, false);
	_boss_L_METEOR->setFPS(1);
	_boss_R_METEOR = new animation;
	_boss_R_METEOR->init(_bossMeteor->getWidth(), _bossMeteor->getHeight(), _bossMeteor->getFrameWidth(), _bossMeteor->getFrameHeight());
	_boss_R_METEOR->setPlayFrame(0, 1, false, false);
	_boss_R_METEOR->setFPS(1);

	_boss_L_METEOR_G = new animation;
	_boss_L_METEOR_G->init(_bossMeteor_g->getWidth(), _bossMeteor_g->getHeight(), _bossMeteor_g->getFrameWidth(), _bossMeteor_g->getFrameHeight());
	_boss_L_METEOR_G->setPlayFrame(11, 6, false, false);
	_boss_L_METEOR_G->setFPS(1);
	_boss_R_METEOR_G = new animation;
	_boss_R_METEOR_G->init(_bossMeteor_g->getWidth(), _bossMeteor_g->getHeight(), _bossMeteor_g->getFrameWidth(), _bossMeteor_g->getFrameHeight());
	_boss_R_METEOR_G->setPlayFrame(0, 5, false, false);
	_boss_R_METEOR_G->setFPS(1);

	_boss_L_METEOR_C = new animation;
	_boss_L_METEOR_C->init(_bossMeteor_c->getWidth(), _bossMeteor_c->getHeight(), _bossMeteor_c->getFrameWidth(), _bossMeteor_c->getFrameHeight());
	_boss_L_METEOR_C->setPlayFrame(23, 12, false, false);
	_boss_L_METEOR_C->setFPS(1);
	_boss_R_METEOR_C = new animation;
	_boss_R_METEOR_C->init(_bossMeteor_c->getWidth(), _bossMeteor_c->getHeight(), _bossMeteor_c->getFrameWidth(), _bossMeteor_c->getFrameHeight());
	_boss_R_METEOR_C->setPlayFrame(0, 11, false, false);
	_boss_R_METEOR_C->setFPS(1);

	int arr_L[30] = { 37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,22,22,22,22,22,21,21,21,21,21,21,21,20,19 };
	_boss_L_METEOR_M = new animation;
	_boss_L_METEOR_M->init(_bossMeteor_m->getWidth(), _bossMeteor_m->getHeight(), _bossMeteor_m->getFrameWidth(), _bossMeteor_m->getFrameHeight());
	//_boss_L_METEOR_M->setPlayFrame(37, 19, false, false);
	_boss_L_METEOR_M->setPlayFrame(arr_L, 30, false);
	_boss_L_METEOR_M->setFPS(1);
	int arr_R[30] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,15,15,15,15,15,16,16,16,16,16,16,16,17,18 };
	_boss_R_METEOR_M = new animation;
	_boss_R_METEOR_M->init(_bossMeteor_m->getWidth(), _bossMeteor_m->getHeight(), _bossMeteor_m->getFrameWidth(), _bossMeteor_m->getFrameHeight());
	//_boss_R_METEOR_M->setPlayFrame(0, 18, false, false);
	_boss_R_METEOR_M->setPlayFrame(arr_R, 30, false);
	_boss_R_METEOR_M->setFPS(1);

	_boss_L_METEOR_J = new animation;
	_boss_L_METEOR_J->init(_bossMeteor_j->getWidth(), _bossMeteor_j->getHeight(), _bossMeteor_j->getFrameWidth(), _bossMeteor_j->getFrameHeight());
	_boss_L_METEOR_J->setPlayFrame(15, 8, false, false);
	_boss_L_METEOR_J->setFPS(1);
	_boss_R_METEOR_J = new animation;
	_boss_R_METEOR_J->init(_bossMeteor_j->getWidth(), _bossMeteor_j->getHeight(), _bossMeteor_j->getFrameWidth(), _bossMeteor_j->getFrameHeight());
	_boss_R_METEOR_J->setPlayFrame(0, 7, false, false);
	_boss_R_METEOR_J->setFPS(1);

	_boss_L_METEOR_A = new animation;
	_boss_L_METEOR_A->init(_bossMeteor_a->getWidth(), _bossMeteor_a->getHeight(), _bossMeteor_a->getFrameWidth(), _bossMeteor_a->getFrameHeight());
	_boss_L_METEOR_A->setPlayFrame(3, 2, false, false);
	_boss_L_METEOR_A->setFPS(1);
	_boss_R_METEOR_A = new animation;
	_boss_R_METEOR_A->init(_bossMeteor_a->getWidth(), _bossMeteor_a->getHeight(), _bossMeteor_a->getFrameWidth(), _bossMeteor_a->getFrameHeight());
	_boss_R_METEOR_A->setPlayFrame(0, 1, false, false);
	_boss_R_METEOR_A->setFPS(1);

	_boss_L_WUPUNCH = new animation;
	_boss_L_WUPUNCH->init(_bossWupunch->getWidth(), _bossWupunch->getHeight(), _bossWupunch->getFrameWidth(), _bossWupunch->getFrameHeight());
	_boss_L_WUPUNCH->setPlayFrame(53, 27, false, false);
	_boss_L_WUPUNCH->setFPS(1);
	_boss_R_WUPUNCH = new animation;
	_boss_R_WUPUNCH->init(_bossWupunch->getWidth(), _bossWupunch->getHeight(), _bossWupunch->getFrameWidth(), _bossWupunch->getFrameHeight());
	_boss_R_WUPUNCH->setPlayFrame(0, 26, false, false);
	_boss_R_WUPUNCH->setFPS(1);

	_boss_L_HIT1 = new animation;
	_boss_L_HIT1->init(_bossHit->getWidth(), _bossHit->getHeight(), _bossHit->getFrameWidth(), _bossHit->getFrameHeight());
	_boss_L_HIT1->setPlayFrame(17, 15, false, false);
	_boss_L_HIT1->setFPS(1);
	_boss_R_HIT1 = new animation;
	_boss_R_HIT1->init(_bossHit->getWidth(), _bossHit->getHeight(), _bossHit->getFrameWidth(), _bossHit->getFrameHeight());
	_boss_R_HIT1->setPlayFrame(0, 2, false, false);
	_boss_R_HIT1->setFPS(1);

	_boss_L_HIT2 = new animation;
	_boss_L_HIT2->init(_bossHit->getWidth(), _bossHit->getHeight(), _bossHit->getFrameWidth(), _bossHit->getFrameHeight());
	_boss_L_HIT2->setPlayFrame(14, 12, false, false);
	_boss_L_HIT2->setFPS(1);
	_boss_R_HIT2 = new animation;
	_boss_R_HIT2->init(_bossHit->getWidth(), _bossHit->getHeight(), _bossHit->getFrameWidth(), _bossHit->getFrameHeight());
	_boss_R_HIT2->setPlayFrame(3, 5, false, false);
	_boss_R_HIT2->setFPS(1);

	_boss_L_HIT3 = new animation;
	_boss_L_HIT3->init(_bossHit->getWidth(), _bossHit->getHeight(), _bossHit->getFrameWidth(), _bossHit->getFrameHeight());
	_boss_L_HIT3->setPlayFrame(11, 9, false, false);
	_boss_L_HIT3->setFPS(1);
	_boss_R_HIT3 = new animation;
	_boss_R_HIT3->init(_bossHit->getWidth(), _bossHit->getHeight(), _bossHit->getFrameWidth(), _bossHit->getFrameHeight());
	_boss_R_HIT3->setPlayFrame(6, 8, false, false);
	_boss_R_HIT3->setFPS(1);

	_boss_L_G_HIT1 = new animation;
	_boss_L_G_HIT1->init(_bossG_hit->getWidth(), _bossG_hit->getHeight(), _bossG_hit->getFrameWidth(), _bossG_hit->getFrameHeight());
	_boss_L_G_HIT1->setPlayFrame(6, 5, false, false);
	_boss_L_G_HIT1->setFPS(1);
	_boss_R_G_HIT1 = new animation;
	_boss_R_G_HIT1->init(_bossG_hit->getWidth(), _bossG_hit->getHeight(), _bossG_hit->getFrameWidth(), _bossG_hit->getFrameHeight());
	_boss_R_G_HIT1->setPlayFrame(1, 2, false, false);
	_boss_R_G_HIT1->setFPS(1);

	_boss_L_HIT_A = new animation;
	_boss_L_HIT_A->init(_bossHit_a->getWidth(), _bossHit_a->getHeight(), _bossHit_a->getFrameWidth(), _bossHit_a->getFrameHeight());
	_boss_L_HIT_A->setPlayFrame(43, 22, false, false);
	_boss_L_HIT_A->setFPS(1);
	_boss_R_HIT_A = new animation;
	_boss_R_HIT_A->init(_bossHit_a->getWidth(), _bossHit_a->getHeight(), _bossHit_a->getFrameWidth(), _bossHit_a->getFrameHeight());
	_boss_R_HIT_A->setPlayFrame(0, 21, false, false);
	_boss_R_HIT_A->setFPS(1);

	_boss_L_DIZZY = new animation;
	_boss_L_DIZZY->init(_bossDizzy->getWidth(), _bossDizzy->getHeight(), _bossDizzy->getFrameWidth(), _bossDizzy->getFrameHeight());
	_boss_L_DIZZY->setPlayFrame(7, 4, false, false);
	_boss_L_DIZZY->setFPS(1);
	_boss_R_DIZZY = new animation;
	_boss_R_DIZZY->init(_bossDizzy->getWidth(), _bossDizzy->getHeight(), _bossDizzy->getFrameWidth(), _bossDizzy->getFrameHeight());
	_boss_R_DIZZY->setPlayFrame(0, 3, false, false);
	_boss_R_DIZZY->setFPS(1);

	_boss_L_GETUP_SS = new animation;
	_boss_L_GETUP_SS->init(_bossGetup_ss->getWidth(), _bossGetup_ss->getHeight(), _bossGetup_ss->getFrameWidth(), _bossGetup_ss->getFrameHeight());
	_boss_L_GETUP_SS->setPlayFrame(29, 15, false, false);
	_boss_L_GETUP_SS->setFPS(1);
	_boss_R_GETUP_SS = new animation;
	_boss_R_GETUP_SS->init(_bossGetup_ss->getWidth(), _bossGetup_ss->getHeight(), _bossGetup_ss->getFrameWidth(), _bossGetup_ss->getFrameHeight());
	_boss_R_GETUP_SS->setPlayFrame(0, 14, false, false);
	_boss_R_GETUP_SS->setFPS(1);

	_boss_L_DEFEAT = new animation;
	_boss_L_DEFEAT->init(_bossDefeat->getWidth(), _bossDefeat->getHeight(), _bossDefeat->getFrameWidth(), _bossDefeat->getFrameHeight());
	_boss_L_DEFEAT->setPlayFrame(25, 13, false, false);
	_boss_L_DEFEAT->setFPS(1);
	_boss_R_DEFEAT = new animation;
	_boss_R_DEFEAT->init(_bossDefeat->getWidth(), _bossDefeat->getHeight(), _bossDefeat->getFrameWidth(), _bossDefeat->getFrameHeight());
	_boss_R_DEFEAT->setPlayFrame(0, 12, false, false);
	_boss_R_DEFEAT->setFPS(1);


	_jumpPower = _gravity = _isJumping = _attackTime = 0;


	_rc.set(0, 0, _bossImg->getFrameWidth(), _bossImg->getFrameHeight());
	_rc.setCenterPos(_x, _z);

	_rcA.set(0, 0, 0, 0);
	_rcA.setCenterPos(0, 0);

	_bossMotion = _boss_L_IDLE;
	_hp = 66;


	return S_OK;
}

void boss::release()
{
}

void boss::update()
{

	if (_bossMotion->isPlay() == false || (_bossDirection == BOSS_RIGHT_IDLE || _bossDirection == BOSS_LEFT_IDLE || _bossDirection == BOSS_RIGHT_WALK || _bossDirection == BOSS_LEFT_WALK))
	{
		_attackCount++;
	}

	cout << "보스 HP" << _hp << endl;
	//cout << "어택카운트" << _attackCount << endl;
	cout << "랜덤1" << _random1 << endl;


	if (_bossDirection == BOSS_LEFT_BLOCK || _bossDirection == BOSS_RIGHT_BLOCK)	 //애니메이션 재생속도오?
		_bossMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	else if (_bossDirection == BOSS_LEFT_WUPUNCH || _bossDirection == BOSS_RIGHT_WUPUNCH)
		_bossMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 15);
	else if (_bossDirection == BOSS_LEFT_METEOR_J || _bossDirection == BOSS_RIGHT_METEOR_J)
		_bossMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 6);
	else _bossMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 12);

	if (_hp >= 45)
	{
		_bossPhase = PHASE1;
	}

	if (_hp < 45 && _hp > 23)	// HP가 45보다 작고 23보단 크면 페이즈 변화
	{
		_bossPhase = PHASE2;
	}

	if (_hp <= 23)				// HP가 23보다 작으면 페이즈 변화
	{
		_bossPhase = PHASE3;
	}

	if (_hp = 0)			// HP 0되면 죽는모션 게임 끝나는것도 연동 필요?
	{
		if (_x < _playerX)
		{
			_bossMotion = _boss_R_DEFEAT;
			_bossDirection = BOSS_RIGHT_DEFEAT;

		}
		else
		{
			_bossMotion = _boss_L_DEFEAT;
			_bossDirection = BOSS_LEFT_DEFEAT;
		}
		if (_bossMotion->isPlay() == false)	_bossMotion->start();
	}


	if (_isJumping)
	{
		_jumpPower += _gravity;
		_rc.setCenterPos(_x, _z-_jumpPower);

	}


	_distance = getDistance(_x, _z, _playerX, _playerY);
	_angle = getAngle(_x, _z, _playerX, _playerY);


	if (_distance > 165 && (_bossDirection == BOSS_RIGHT_IDLE || _bossDirection == BOSS_LEFT_IDLE || _bossDirection == BOSS_RIGHT_WALK || _bossDirection == BOSS_LEFT_WALK))
	{
		if (_x < _playerX)
		{
			_bossMotion = _boss_R_WALK;
			_bossDirection = BOSS_RIGHT_WALK;

		}
		else
		{
			_bossMotion = _boss_L_WALK;
			_bossDirection = BOSS_LEFT_WALK;
		}

		if (_bossMotion->isPlay() == false)	_bossMotion->start();
	}


	if (_distance > 165 && (_bossDirection == BOSS_RIGHT_WALK || _bossDirection == BOSS_LEFT_WALK))
	{
		_x += cosf(_angle) * _speed;
		_z -= sinf(_angle) * _speed;
	}

	if (_distance > 165 && (_bossDirection == BOSS_RIGHT_TACKLE || _bossDirection == BOSS_LEFT_TACKLE || _bossDirection == BOSS_RIGHT_TACKLE_L || _bossDirection == BOSS_LEFT_TACKLE_L || _bossDirection == BOSS_RIGHT_WUPUNCH || _bossDirection == BOSS_LEFT_WUPUNCH))
	{
		_x += cosf(_angle) * _speed;
		_z -= sinf(_angle) * _speed;
	}





	//if (_bossDirection == BOSS_LEFT_HIT1 || _bossDirection == BOSS_RIGHT_HIT1 ||
	//	_bossDirection == BOSS_LEFT_HIT2 || _bossDirection == BOSS_RIGHT_HIT2 ||
	//	_bossDirection == BOSS_LEFT_HIT3 || _bossDirection == BOSS_RIGHT_HIT3 ||
	//	_bossDirection == BOSS_LEFT_HIT_A || _bossDirection == BOSS_RIGHT_HIT_A)
	//{
	//	if (!_bossMotion->isPlay())
	//	{
	//		_bossMotion->start();
	//	}
	//}



	// 공격 패턴
	switch (_bossPhase == PHASE1)
	{
	case PHASE1:
		if (_attackCount > 150)
		{
			if (_distance < 170 && !_isJumping && (_bossDirection == BOSS_RIGHT_IDLE || _bossDirection == BOSS_LEFT_IDLE || _bossDirection == BOSS_RIGHT_WALK || _bossDirection == BOSS_LEFT_WALK))
			{
				switch (_random)
				{
				case 0:
					attackSlap();
					break;

				case 1:
					attackElbow();
					break;

				case 2:
					block();
					break;

				case 3:
					attackWupnch();
					break;
				}
			}

			//if (_distance >= 175 && _distance < 800 || _isJumping)
			else if ((_distance >= 170 && _distance < 800) || _isJumping)
			{
				switch (_random1)
				{
				case 0:
					roar();
					break;

				case 1:
					meteor_j();
					break;

				case 10:
					tackle();
					break;

				case 11:
					tackle_loop();
					break;

				case 12:
					meteor_a();
					break;

				case 13:
					meteor();
					break;

				case 14:
					meteor_m();
					break;

				case 15:
					taunt();
					break;
				}
			}
		}

	case PHASE2:
		if (_attackCount > 120)
		{
			if (_distance < 170 && !_isJumping && (_bossDirection == BOSS_RIGHT_IDLE || _bossDirection == BOSS_LEFT_IDLE || _bossDirection == BOSS_RIGHT_WALK || _bossDirection == BOSS_LEFT_WALK))
			{
				switch (_random)
				{
				case 0:
					attackSlap();
					break;

				case 1:
					attackElbow();
					break;

				case 2:
					block();
					break;

				case 3:
					attackWupnch();
					break;
				}
			}

			if ((_distance >= 170 && _distance < 800) || _isJumping)
			{
				switch (_random1)
				{

				case 0:
					roar();
					break;

				case 1:
					meteor_j();
					break;

				case 10:
					tackle();
					break;

				case 11:
					tackle_loop();
					break;

				case 12:
					meteor_a();
					break;

				case 13:
					meteor();
					break;
				}
			}
		}

	case PHASE3:
		if (_attackCount > 100)
		{
			if (_distance < 170 && !_isJumping && (_bossDirection == BOSS_RIGHT_IDLE || _bossDirection == BOSS_LEFT_IDLE || _bossDirection == BOSS_RIGHT_WALK || _bossDirection == BOSS_LEFT_WALK))
			{
				switch (_random)
				{
				case 0:
					attackSlap();
					break;

				case 1:
					attackElbow();
					break;

				case 2:
					block();
					break;

				case 3:
					attackWupnch();
					break;
				}
			}

			if ((_distance >= 170 && _distance < 800) || _isJumping)
			{
				switch (_random1)
				{

				case 0:
					roar();
					break;

				case 1:
					meteor_j();
					break;

				case 10:
					tackle();
					break;

				case 11:
					tackle_loop();
					break;

				case 12:
					meteor_a();
					break;

				case 13:
					meteor();
					break;
				}
			}
		}
	}
	if (_isJumping == false)
	{
		_rc.setCenterPos(_x, _z);
	}

	if (_bossMotion->isPlay() == false && _x < _playerX)
	{
		_bossMotion = _boss_R_IDLE;
		_bossDirection = BOSS_RIGHT_IDLE;
	
		if (_bossMotion->isPlay() == false)	_bossMotion->start();
	}
	if (_bossMotion->isPlay() == false && _x > _playerX)
	{
		_bossMotion = _boss_L_IDLE;
		_bossDirection = BOSS_LEFT_IDLE;
	
		if (_bossMotion->isPlay() == false)	_bossMotion->start();
	}
}


void boss::render()
{
	//_rcA.set(0, 0, 0, 0); // 렉트 초기화

	switch (_bossDirection)
	{
	case BOSS_RIGHT_IDLE:
		_bossImg = _bossIdle;
		break;
	case BOSS_LEFT_IDLE:
		_bossImg = _bossIdle;
		break;
	case BOSS_RIGHT_WALK:
		_bossImg = _bossWalk;
		_speed = 3.0f;
		break;
	case BOSS_LEFT_WALK:
		_bossImg = _bossWalk;
		_speed = 3.0f;
		break;
	case BOSS_RIGHT_SLAP:
		_bossImg = _bossSlap;
		
		break;
	case BOSS_LEFT_SLAP:
		_bossImg = _bossSlap;
		
		break;
	case BOSS_RIGHT_ELBOW:
		_bossImg = _bossElbow;
		
		break;
	case BOSS_LEFT_ELBOW:
		_bossImg = _bossElbow;
		
		break;
	case BOSS_RIGHT_BLOCK:
		_bossImg = _bossBlock;
		_rc.move(30, 0);
		break;
	case BOSS_LEFT_BLOCK:
		_bossImg = _bossBlock;
		_rc.move(30, 0);
		break;
	case BOSS_RIGHT_ROAR:
		_bossImg = _bossRoar;
		
		break;
	case BOSS_LEFT_ROAR:
		_bossImg = _bossRoar;
		
		break;
	case BOSS_RIGHT_ROAR_U:
		_bossImg = _bossRoar_u;
		break;
	case BOSS_LEFT_ROAR_U:
		_bossImg = _bossRoar_u;
		break;
	case BOSS_RIGHT_TACKLE:
		_bossImg = _bossTackle;
		
		_speed = 2.0f;
		break;
	case BOSS_LEFT_TACKLE:
		_bossImg = _bossTackle;
		_speed = 2.0f;
		break;
	case BOSS_RIGHT_TACKLE_L:
		_bossImg = _bossTackle_l;
		_speed = 10.0f;
		break;
	case BOSS_LEFT_TACKLE_L:
		_bossImg = _bossTackle_l;
		_speed = 10.0f;
		break;
	case BOSS_RIGHT_TAUNT:
		_bossImg = _bossTaunt;
		break;
	case BOSS_LEFT_TAUNT:
		_bossImg = _bossTaunt;
		break;
	case BOSS_RIGHT_METEOR:
		_bossImg = _bossMeteor;
		
		break;
	case BOSS_LEFT_METEOR:
		_bossImg = _bossMeteor;
		break;
	case BOSS_RIGHT_METEOR_G:
		_bossImg = _bossMeteor_g;
		break;
	case BOSS_LEFT_METEOR_G:
		_bossImg = _bossMeteor_g;
		break;
	case BOSS_RIGHT_METEOR_C:
		_bossImg = _bossMeteor_c;
		break;
	case BOSS_LEFT_METEOR_C:
		_bossImg = _bossMeteor_c;
		break;
	case BOSS_RIGHT_METEOR_M:
		_bossImg = _bossMeteor_m;
		break;
	case BOSS_LEFT_METEOR_M:
		_bossImg = _bossMeteor_m;
		break;
	case BOSS_RIGHT_METEOR_J:
		_bossImg = _bossMeteor_j;
		break;
	case BOSS_LEFT_METEOR_J:
		_bossImg = _bossMeteor_j;
		break;
	case BOSS_RIGHT_METEOR_A:
		_bossImg = _bossMeteor_a;
		_speed = 4.0f;
		break;
	case BOSS_LEFT_METEOR_A:
		_bossImg = _bossMeteor_a;
		_speed = 4.0f;
		break;
	case BOSS_RIGHT_WUPUNCH:
		_bossImg = _bossWupunch;
		
		_speed = 1.0f;
		break;
	case BOSS_LEFT_WUPUNCH:
		_bossImg = _bossWupunch;

		_speed = 1.0f;
		break;
	case BOSS_RIGHT_HIT1:
		_bossImg = _bossHit;
		//_boss_R_HIT1->start();
		break;
	case BOSS_RIGHT_HIT2:
		_bossImg = _bossHit;
		//_boss_R_HIT2->start();
		break;
	case BOSS_RIGHT_HIT3:
		_bossImg = _bossHit;
		//_boss_R_HIT3->start();
		break;
	case BOSS_LEFT_HIT1:
		_bossImg = _bossHit;
		//_boss_L_HIT1->start();
		break;
	case BOSS_LEFT_HIT2:
		_bossImg = _bossHit;
		//_boss_L_HIT2->start();
		break;
	case BOSS_LEFT_HIT3:
		_bossImg = _bossHit;
		//_boss_L_HIT3->start();
		break;
	case BOSS_RIGHT_HIT_A:
		_bossImg = _bossHit_a;
		//_boss_R_HIT_A->start();
		_rc.move(-50, 0);
		break;
	case BOSS_LEFT_HIT_A:
		_bossImg = _bossHit_a;
		//_boss_L_HIT_A->start();
		_rc.move(50, 0);
		break;
	case BOSS_RIGHT_G_HIT:
		_bossImg = _bossG_hit;
		break;
	case BOSS_LEFT_G_HIT:
		_bossImg = _bossG_hit;
		break;
	case BOSS_RIGHT_DEFEAT:
		_bossImg = _bossDefeat;
		break;
	case BOSS_LEFT_DEFEAT:
		_bossImg = _bossDefeat;
		break;

	}

	IMAGEMANAGER->findImage("boss_shadow")->alphaRender(getMemDC(), _rc.left + 35, _rc.bottom - 45, 100);
	ZORDER->pushObject(getMemDC(), _bossImg, _bossMotion, 1, _rc.getCenterX(), _jumpPower, _rc.bottom);
	//_rcA.render(getMemDC());
	//_rc.render(getMemDC());
}

void boss::attackSlap()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_SLAP;
		_bossMotion = _boss_R_SLAP;
		//_bossMotion->start();
		//_attackCount = 0;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 90, 60);
			_rcA.setCenterPos(_rc.right, _rc.getCenterY());
			_attackCount = 0;
			_bossMotion->start();
			_random = RND->getInt(4);

		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_SLAP;
		_bossMotion = _boss_L_SLAP;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 90, 60);
			_rcA.setCenterPos(_rc.left, _rc.getCenterY());
			_attackCount = 0;
			_bossMotion->start();
			_random = RND->getInt(4);

		}
	}
}

void boss::attackElbow()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_ELBOW;
		_bossMotion = _boss_R_ELBOW;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 60, 90);
			_rcA.setCenterPos(_rc.right, _rc.getCenterY());
			_attackCount = 0;
			_bossMotion->start();
			_random = RND->getInt(4);

		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_ELBOW;
		_bossMotion = _boss_L_ELBOW;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 60, 90);
			_rcA.setCenterPos(_rc.left, _rc.getCenterY());
			_attackCount = 0;
			_bossMotion->start();
			_random = RND->getInt(4);

		}
	}
}

void boss::block()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_BLOCK;
		_bossMotion = _boss_R_BLOCK;
		if (_bossMotion->isPlay() == false)
		{
			_attackCount = 0;
			_bossMotion->start();
			_random = RND->getInt(4);

		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_BLOCK;
		_bossMotion = _boss_L_BLOCK;
		if (_bossMotion->isPlay() == false)
		{
			_attackCount = 0;
			_bossMotion->start();
			_random = RND->getInt(4);

		}
	}
}

void boss::attackWupnch()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_WUPUNCH;
		_bossMotion = _boss_R_WUPUNCH;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 90, 60);
			_rcA.setCenterPos(_rc.right, _rc.getCenterY());
			_attackCount = 0;
			_bossMotion->start();
			_random = RND->getInt(4);

		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_WUPUNCH;
		_bossMotion = _boss_L_WUPUNCH;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 90, 60);
			_rcA.setCenterPos(_rc.left, _rc.getCenterY());
			_attackCount = 0;
			_bossMotion->start();
			_random = RND->getInt(4);

		}
	}

}

void boss::roar()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_ROAR;
		_bossMotion = _boss_R_ROAR;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 150, 150);
			_rcA.setCenterPos(_rc.right, _rc.getCenterY());
			_bossMotion->start();
			_random1 = 10;
		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_ROAR;
		_bossMotion = _boss_L_ROAR;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 150, 150);
			_rcA.setCenterPos(_rc.left, _rc.getCenterY());
			_bossMotion->start();
			_random1 = 10;
		}
	}
}

void boss::meteor_j()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_METEOR_J;
		_bossMotion = _boss_R_METEOR_J;
		if (_bossMotion->isPlay() == false)
		{
			_bossMotion->start();

			_ys = _z;
			_gravity = 20.0f;
			_random1 = 12;
			_isJumping = true;

		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_METEOR_J;
		_bossMotion = _boss_L_METEOR_J;
		if (_bossMotion->isPlay() == false)
		{
			_bossMotion->start();

			_ys = _z;
			_gravity = 20.0f;
			_random1 = 12;
			_isJumping = true;

		}
	}
}

void boss::tackle()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_TACKLE;
		_bossMotion = _boss_R_TACKLE;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 60, 90);
			_rcA.setCenterPos(_rc.right, _rc.getCenterY());
			_bossMotion->start();
			_random1 = 11;
		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_TACKLE;
		_bossMotion = _boss_L_TACKLE;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 60, 90);
			_rcA.setCenterPos(_rc.left, _rc.getCenterY());
			_bossMotion->start();
			_random1 = 11;
		}
	}
}

void boss::tackle_loop()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_TACKLE_L;
		_bossMotion = _boss_R_TACKLE_L;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 60, 90);
			_rcA.setCenterPos(_rc.right, _rc.getCenterY());
			_bossMotion->start();
			_random1 = 15;


		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_TACKLE_L;
		_bossMotion = _boss_L_TACKLE_L;
		if (_bossMotion->isPlay() == false)
		{
			_rcA.set(0, 0, 60, 90);
			_rcA.setCenterPos(_rc.left, _rc.getCenterY());
			_bossMotion->start();
			_random1 = 15;

		}
	}
}

void boss::taunt()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_TAUNT;
		_bossMotion = _boss_R_TAUNT;
		if (_bossMotion->isPlay() == false)
		{
			_attackCount = 0;
			_bossMotion->start();
			_random1 = RND->getInt(2);

		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_METEOR_M;
		_bossMotion = _boss_L_METEOR_M;
		if (_bossMotion->isPlay() == false)
		{
			_attackCount = 0;
			_bossMotion->start();
			_random1 = RND->getInt(2);

		}
	}
}

void boss::meteor_a()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_METEOR_A;
		_bossMotion = _boss_R_METEOR_A;
		if (_isJumping == true)
		{
			_x += cosf(_angle) * _speed;
			_z -= sinf(_angle) * _speed;
			if (_jumpPower > 1800)
			{
				_gravity = 0;
				_bossMotion->start();
				_random1 = 13;

			}
		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_METEOR_A;
		_bossMotion = _boss_L_METEOR_A;
		if (_isJumping == true)
		{
			_x += cosf(_angle) * _speed;
			_z -= sinf(_angle) * _speed;
			if (_jumpPower > 1800)
			{
				_gravity = 0;
				_bossMotion->start();
				_random1 = 13;
			}
		}
	}
}

void boss::meteor()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_METEOR;
		_bossMotion = _boss_R_METEOR;
		if (_isJumping = true)
		{
			_jumpPower -= 30.0f;
			if (_jumpPower <= 0)
			{
				_rcA.set(0, 0, 150, 150);
				_rcA.setCenterPos(_rc.right, _rc.getCenterY());
				_gravity = 0;
				_jumpPower = 0;
				_bossMotion->start();
				_random1 = 14;
				//_isJumping = false;

			}
		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_METEOR;
		_bossMotion = _boss_L_METEOR;
		if (_isJumping = true)
		{
			_jumpPower -= 30.0f;
			if (_jumpPower <= 0)
			{
				_rcA.set(0, 0, 150, 150);
				_rcA.setCenterPos(_rc.left, _rc.getCenterY());
				_gravity = 0;
				_jumpPower = 0;
				_bossMotion->start();
				_random1 = 14;
				//_isJumping = false;

			}
		}
	}
}

void boss::meteor_m()
{
	if (_x < _playerX)
	{
		_bossDirection = BOSS_RIGHT_METEOR_M;
		_bossMotion = _boss_R_METEOR_M;
		if (_bossMotion->isPlay() == false)
		{
			_isJumping = false;
			_bossMotion->start();
			_random1 = RND->getInt(2);
			_attackCount = 0;

		}
	}
	else
	{
		_bossDirection = BOSS_LEFT_METEOR_M;
		_bossMotion = _boss_L_METEOR_M;
		if (_bossMotion->isPlay() == false)
		{
			_isJumping = false;
			_bossMotion->start();
			_random1 = RND->getInt(2);
			_attackCount = 0;
		}
	}
}
