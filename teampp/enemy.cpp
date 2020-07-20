#include "stdafx.h"
#include "enemy.h"

enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init(string imageName, float x, float y, float speed)
{
	_eA = IMAGEMANAGER->addFrameImage("attack", "images/CheerLeader_ComboAttack3.bmp", 1827, 426, 7, 2, true, RGB(255, 0, 255));
	_eW = IMAGEMANAGER->addFrameImage("move", "images/CheerLeader_Walk.bmp", 2736, 438, 12, 2, true, RGB(255, 0, 255));

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_direction = LEFT_MOVE;
	_enemyMotionL = new animation;
	_enemyMotionL->init(_eW->getWidth(), _eW->getHeight(), _eW->getFrameWidth(), _eW->getFrameHeight());
	_enemyMotionL->setPlayFrame(0,11,false, true);
	_enemyMotionL->setFPS(1);
	_enemyMotionL->start();

	_enemyMotionR = new animation;
	_enemyMotionR->init(_eW->getWidth(), _eW->getHeight(), _eW->getFrameWidth(), _eW->getFrameHeight());
	_enemyMotionR->setPlayFrame(21, 12, false, true);
	_enemyMotionR->setFPS(1);
	_enemyMotionR->start();

	_enemyMotionL_A = new animation;
	_enemyMotionL_A->init(_eA->getWidth(), _eA->getHeight(), _eA->getFrameWidth(), _eA->getFrameHeight());
	_enemyMotionL_A->setPlayFrame(13, 7, false, true);
	_enemyMotionL_A->setFPS(1);
	_enemyMotionL_A->start();
	
	_enemyMotionR_A = new animation;
	_enemyMotionR_A->init(_eA->getWidth(), _eA->getHeight(), _eA->getFrameWidth(), _eA->getFrameHeight());
	_enemyMotionR_A->setPlayFrame(0, 6, false, true);
	_enemyMotionR_A->setFPS(1);
	_enemyMotionR_A->start();


	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_enemyMotion = _enemyMotionL;

	//CAMERA->setPosition(_rc.getCenterX(), _rc.getCenterY());
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{		
	_enemyMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	
	distance = getDistance(_x, _y, _playerX, _playerY);
	angle = getAngle(_x, _y, _playerX, _playerY);

	if (distance > 165)
	{
		_x += cosf(angle) * _speed;
		_y -= sinf(angle) * _speed;
	}

	if (_x < _playerX)
	{
		_direction = RIGHT_MOVE;
		_enemyMotion = _enemyMotionR;
		if (_enemyMotion->isPlay() == false)	_enemyMotionR->start();

		else if (distance < 220)
		{
			_direction = RIGHT_ATTACK;
			_enemyMotion = _enemyMotionR_A;
			if (_enemyMotion->isPlay() == false) _enemyMotionR_A->start();
		}
	}
	else if (_x > _playerX + 150)
	{
		_direction = LEFT_MOVE;
		_enemyMotion = _enemyMotionL;
		if (_enemyMotion->isPlay() == false)	_enemyMotion->start();

		else if (distance < 220)
		{
			_direction = LEFT_ATTACK;
			_enemyMotion = _enemyMotionL_A;
			if (_enemyMotion->isPlay() == false) _enemyMotion->start();
		}
	}

	//if (_x < _playerX)
	//{
	//	if (distance < 220)
	//	{
	//		_direction = RIGHT_ATTACK;
	//		_enemyMotion = _enemyMotionR_A;
	//		if (_enemyMotion->isPlay() == false) _enemyMotionR_A->start();
	//	}
	//	else
	//	{
	//		_direction = RIGHT_MOVE;
	//		_enemyMotion = _enemyMotionR;
	//		if (_enemyMotion->isPlay() == false)	_enemyMotionR->start();
	//	}	
	//}
	//else if (_x > _playerX + 150)
	//{
	//	_direction = LEFT_MOVE;
	//	_enemyMotion = _enemyMotionL;
	//	if (_enemyMotion->isPlay() == false)	_enemyMotion->start();
	//
	//	else if (distance < 200)
	//	{
	//		_direction = LEFT_ATTACK;
	//		_enemyMotion = _enemyMotionL_A;
	//		if (_enemyMotion->isPlay() == false)		_enemyMotion->start();
	//
	//	}
	//}
	_rc.setCenterPos(_x, _y);

	enemyDirection();

}

void enemy::render()
{
	_rc.render(getMemDC());//·ºÆ®
	_enemyImg->aniRender(getMemDC(),_rc.left,_rc.top,_enemyMotion);
}

void enemy::enemyDirection()
{

	switch (_direction)
	{
	case LEFT_MOVE:
		_enemyImg = _eW;
		break;
	case RIGHT_MOVE:
		_enemyImg = _eW;
		break;
	case LEFT_ATTACK:
		_enemyImg = _eA;
		break;
	case RIGHT_ATTACK:
		_enemyImg = _eA;
		break;
	}
}

void enemy::setPlayerPos(float x, float y)
{
	_playerX = x;
	_playerY = y;
}

