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
	_bossIdle = IMAGEMANAGER->addFrameImage("BOSSIDLE", "images/boss/boss_idle.bmp", 3189, 634, 12, 2, true, RGB(255, 0, 255));
	_bossWalk = IMAGEMANAGER->addFrameImage("BOSSWALK", "images/boss/boss_walk.bmp", 2113, 589, 10, 2, true, RGB(255, 0, 255));
	_bossHit = IMAGEMANAGER->addFrameImage("BOSSHIT", "images/boss/boss_gethit.bmp", 692, 186, 9, 2, true, RGB(255, 0, 255));
	_bossSlap = IMAGEMANAGER->addFrameImage("BOSSSLAP", "images/boss/boss_slap.bmp", 5283, 582, 14, 2, true, RGB(255, 0, 255));
	_bossElbow = IMAGEMANAGER->addFrameImage("BOSSELBOW", "images/boss/boss_elbow.bmp", 2922, 653, 11, 2, true, RGB(255, 0, 255));
	_bossBlock = IMAGEMANAGER->addFrameImage("BOSSBLOCK", "images/boss/boss_block1.bmp", 1688, 576, 8, 2, true, RGB(255, 0, 255));
	_bossRoar = IMAGEMANAGER->addFrameImage("BOSSROAR", "images/boss/boss_roar.bmp", 2918, 576, 12, 2, true, RGB(255, 0, 255));
	_bossRoar_u = IMAGEMANAGER->addFrameImage("BOSSROAR_U", "images/boss/boss_roar_U.bmp", 999, 474, 4, 2, true, RGB(255, 0, 255));
	_bossTackle = IMAGEMANAGER->addFrameImage("BOSSTACKLE", "images/boss/boss_tackle.bmp", 1120, 576, 5, 2, true, RGB(255, 0, 255));
	_bossTackle_l = IMAGEMANAGER->addFrameImage("BOSSTACKLE_L", "images/boss/boss_tackle_L.bmp", 2886, 576, 11, 2, true, RGB(255, 0, 255));
	_bossTaunt = IMAGEMANAGER->addFrameImage("BOSSTAUNT", "images/boss/boss_taunt.bmp", 5669, 749, 23, 2, true, RGB(255, 0, 255));
	_bossMeteor = IMAGEMANAGER->addFrameImage("BOSSMETEOR", "images/boss/boss_meteor.bmp", 480, 461, 2, 2, true, RGB(255, 0, 255));
	_bossMeteor_g = IMAGEMANAGER->addFrameImage("BOSSMETEOR_G", "images/boss/boss_meteor_G.bmp", 1228, 422, 6, 2, true, RGB(255, 0, 255));
	_bossMeteor_c = IMAGEMANAGER->addFrameImage("BOSSMETEOR_C", "images/boss/boss_meteor_C.bmp", 2995, 576, 12, 2, true, RGB(255, 0, 255));
	_bossMeteor_m = IMAGEMANAGER->addFrameImage("BOSSMETEOR_M", "images/boss/boss_meteor_M.bmp", 4682, 576, 19, 2, true, RGB(255, 0, 255));
	_bossMeteor_j = IMAGEMANAGER->addFrameImage("BOSSMETEOR_J", "images/boss/boss_meteor_J.bmp", 1894, 672, 8, 2, true, RGB(255, 0, 255));
	_bossMeteor_a = IMAGEMANAGER->addFrameImage("BOSSMETEOR_A", "images/boss/boss_meteor_A.bmp", 409, 659, 2, 2, true, RGB(255, 0, 255));
	_bossWupunch = IMAGEMANAGER->addFrameImage("BOSSWUPUNCH", "images/boss/boss_wupunch.bmp", 11919, 595, 27, 2, true, RGB(255, 0, 255));


	_bossImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;


	_x = _x + x;
	_y = 0;
	_z = _z + z;


	_speed = speed;
	_random = RND->getInt(4);
	_random1 = RND->getInt(2);

	_bossDirection = BOSS_LEFT_IDLE;

	//_isAttack = _attackCount = _attackTime = _count = _index = 0;

	//_rc.set(0, 0, _bossIdle->getFrameWidth(), _bossIdle->getFrameHeight());
	//_rc.setCenterPos(_x, _y);

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

	_boss_L_METEOR_M = new animation;
	_boss_L_METEOR_M->init(_bossMeteor_m->getWidth(), _bossMeteor_m->getHeight(), _bossMeteor_m->getFrameWidth(), _bossMeteor_m->getFrameHeight());
	_boss_L_METEOR_M->setPlayFrame(37, 19, false, false);
	_boss_L_METEOR_M->setFPS(1);
	_boss_R_METEOR_M = new animation;
	_boss_R_METEOR_M->init(_bossMeteor_m->getWidth(), _bossMeteor_m->getHeight(), _bossMeteor_m->getFrameWidth(), _bossMeteor_m->getFrameHeight());
	_boss_R_METEOR_M->setPlayFrame(0, 18, false, false);
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


	_jumpPower = _gravity = _isJumping = _attackTime = 0;


	_rc.set(0, 0, _bossIdle->getFrameWidth(), _bossIdle->getFrameHeight());
	_rc.setCenterPos(_x, _z);

	_rcA.set(0, 0, 0, 0);
	_rcA.setCenterPos(0, 0);

	_bossMotion = _boss_L_IDLE;
	_hp = 1;


	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	_attackCount++;
	if (_bossDirection == BOSS_LEFT_BLOCK || _bossDirection == BOSS_RIGHT_BLOCK)	 //애니메이션 재생속도오?
		_bossMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	else if (_bossDirection == BOSS_LEFT_WUPUNCH || _bossDirection == BOSS_RIGHT_WUPUNCH)
		_bossMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 15);
	else if (_bossDirection == BOSS_LEFT_METEOR_J || _bossDirection == BOSS_RIGHT_METEOR_J)
		_bossMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 6);
	else _bossMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 12);



	if (_isJumping)
	{
		_jumpPower += _gravity;
		//_attackTime++;
		//_gravity -= 0.1f;

		//if (_jumpPower < 0)
		//{
		//	_jumpPower = 0;
		//	//_attackCount = 0;
		//	//_bossMotion->start();
		//	//_random1 = RND->getInt(2);
		//	//_isJumping = false;
		//
		//}
	}

	//cout << _playerX << endl;
	//cout << _playerY << endl;
	//cout << _distance << endl;
	//cout << "어택카운트" << _attackCount << endl;
	//cout << "어택타임" << _attackTime << endl;
	//cout << "근거리랜던값" << _random << endl;
	//cout << "원거리랜덤값" << _random1 << endl;
	//cout << "_y 값" << _y << endl;
	//cout << "중력값" << _gravity << endl;
	cout << "점프값" << _jumpPower << endl;

	_distance = getDistance(_x, _z, _playerX, _playerY);
	_angle = getAngle(_x, _z, _playerX, _playerY);


	if (_distance > 165 && (_bossDirection == BOSS_RIGHT_IDLE || _bossDirection == BOSS_LEFT_IDLE))
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
	// 공격 패턴
	if (_attackCount > 150)
	{
		if (_distance < 170)
		{
			switch (_random)
			{
			case 0:
				if (_x < _playerX)
				{
					_bossDirection = BOSS_RIGHT_SLAP;
					_bossMotion = _boss_R_SLAP;
					if (_bossMotion->isPlay() == false)
					{
						_attackCount = 0;
						_bossMotion->start();
						_random = RND->getInt(4);

					}
					break;
				}
				else
				{
					_bossDirection = BOSS_LEFT_SLAP;
					_bossMotion = _boss_L_SLAP;
					if (_bossMotion->isPlay() == false)
					{
						_attackCount = 0;
						_bossMotion->start();
						_random = RND->getInt(4);

					}
					break;
				}
			case 1:
				if (_x < _playerX)
				{
					_bossDirection = BOSS_RIGHT_ELBOW;
					_bossMotion = _boss_R_ELBOW;
					if (_bossMotion->isPlay() == false)
					{
						_attackCount = 0;
						_bossMotion->start();
						_random = RND->getInt(4);

					}
					break;
				}
				else
				{
					_bossDirection = BOSS_LEFT_ELBOW;
					_bossMotion = _boss_L_ELBOW;
					if (_bossMotion->isPlay() == false)
					{
						_attackCount = 0;
						_bossMotion->start();
						_random = RND->getInt(4);

					}
					break;
				}
			case 2:
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
					break;
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
					break;
				}
			case 3:
				if (_x < _playerX)
				{
					_bossDirection = BOSS_RIGHT_WUPUNCH;
					_bossMotion = _boss_R_WUPUNCH;
					if (_bossMotion->isPlay() == false)
					{
						_attackCount = 0;
						_bossMotion->start();
						_random = RND->getInt(4);

					}
					break;
				}
				else
				{
					_bossDirection = BOSS_LEFT_WUPUNCH;
					_bossMotion = _boss_L_WUPUNCH;
					if (_bossMotion->isPlay() == false)
					{
						_attackCount = 0;
						_bossMotion->start();
						_random = RND->getInt(4);

					}
					break;
				}
			}
		}
		if (_distance >= 175 && _distance < 800 || _isJumping)
			//if (_distance > 175 || _isJumping)
		{
			switch (_random1)
			{

			case 0:
				if (_x < _playerX)
				{
					_bossDirection = BOSS_RIGHT_ROAR;
					_bossMotion = _boss_R_ROAR;
					if (_bossMotion->isPlay() == false)
					{
						_bossMotion->start();
						_random1 = 10;
					}
					break;
				}
				else
				{
					_bossDirection = BOSS_LEFT_ROAR;
					_bossMotion = _boss_L_ROAR;
					if (_bossMotion->isPlay() == false)
					{
						_bossMotion->start();
						_random1 = 10;
					}
					break;
				}

			case 1:
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
					break;
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
					break;

				}

			case 10:
				if (_x < _playerX)
				{
					_bossDirection = BOSS_RIGHT_TACKLE;
					_bossMotion = _boss_R_TACKLE;
					if (_bossMotion->isPlay() == false)
					{
						_bossMotion->start();
						_random1 = 11;
					}
					break;
				}
				else
				{
					_bossDirection = BOSS_LEFT_TACKLE;
					_bossMotion = _boss_L_TACKLE;
					if (_bossMotion->isPlay() == false)
					{
						_bossMotion->start();
						_random1 = 11;
					}
					break;
				}


			case 11:

				if (_x < _playerX)
				{
					_bossDirection = BOSS_RIGHT_TACKLE_L;
					_bossMotion = _boss_R_TACKLE_L;
					if (_bossMotion->isPlay() == false)
					{
						_attackCount = 0;
						_bossMotion->start();
						_random1 = RND->getInt(2);


					}
					break;
				}
				else
				{
					_bossDirection = BOSS_LEFT_TACKLE_L;
					_bossMotion = _boss_L_TACKLE_L;
					if (_bossMotion->isPlay() == false)
					{
						_attackCount = 0;
						_bossMotion->start();
						_random1 = RND->getInt(2);

					}
					break;
				}
			case 12:

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
					break;
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
					break;
				}
			case 13:
				if (_x < _playerX)
				{
					_bossDirection = BOSS_RIGHT_METEOR;
					_bossMotion = _boss_R_METEOR;
					if (_isJumping = true)
					{
						_jumpPower -= 30.0f;
						if (_jumpPower <= 0)
						{
							_gravity = 0;
							_jumpPower = 0;
							_attackCount = 0;
							_bossMotion->start();
							_random1 = RND->getInt(2);
							_isJumping = false;

						}
					}
					break;
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
							_gravity = 0;
							_jumpPower = 0;
							_attackCount = 0;
							_bossMotion->start();
							_random1 = RND->getInt(2);
							_isJumping = false;

						}
					}
					break;

				}
			}
		}
	}
	_rc.setCenterPos(_x, _z);
}


void boss::render()
{
	_rcA.set(0, 0, 0, 0); // 렉트 초기화

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
		_rcA.set(0, 0, 90, 60);
		_rcA.setCenterPos(_rc.right, _rc.getCenterY());
		break;
	case BOSS_LEFT_SLAP:
		_bossImg = _bossSlap;
		_rcA.set(0, 0, 90, 60);
		_rcA.setCenterPos(_rc.left, _rc.getCenterY());
		break;
	case BOSS_RIGHT_ELBOW:
		_bossImg = _bossElbow;
		_rcA.set(0, 0, 60, 90);
		_rcA.setCenterPos(_rc.right, _rc.getCenterY());
		break;
	case BOSS_LEFT_ELBOW:
		_bossImg = _bossElbow;
		_rcA.set(0, 0, 60, 90);
		_rcA.setCenterPos(_rc.left, _rc.getCenterY());
		break;
	case BOSS_RIGHT_BLOCK:
		_bossImg = _bossBlock;
		break;
	case BOSS_LEFT_BLOCK:
		_bossImg = _bossBlock;
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

	}

	ZORDER->pushObject(getMemDC(), _bossImg, _bossMotion, 1, _rc.getCenterX(), _jumpPower, _rc.bottom);
	_rcA.render(getMemDC());
}