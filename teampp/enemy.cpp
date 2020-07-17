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

	_xp = 500;
	_yp = WINSIZEY - 200;

	_player = RectMakeCenter(_xp, _yp, 100, 100);

	_enemyImg = IMAGEMANAGER->findImage(imageName);
	_imageName = imageName;
	_speed = speed;
	_x = _x + x;
	_y = _y + y;
	_direction = LEFT_MOVE;
	_enemyMotionL = new animation;
	_enemyMotionL->init(_enemyImg->getWidth(), _enemyImg->getHeight(), _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_enemyMotionL->setPlayFrame(0,11,false, true);
	_enemyMotionL->setFPS(1);
	_enemyMotionL->start();

	_enemyMotionR = new animation;
	_enemyMotionR->init(_enemyImg->getWidth(), _enemyImg->getHeight(), _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_enemyMotionR->setPlayFrame(21, 12, false, true);
	_enemyMotionR->setFPS(1);
	_enemyMotionR->start();

	_rc.set(0, 0, _enemyImg->getFrameWidth(), _enemyImg->getFrameHeight());
	_rc.setCenterPos(_x, _y);

	_enemyMotion = _enemyMotionL;
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{		

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.left += 5;
		_player.right += 5;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.left -= 5;
		_player.right -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_player.top -= 5;
		_player.bottom -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.top += 5;
		_player.bottom += 5;
	}

	_enemyMotion->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

	if ((_rc.left + _rc.right) / 2 < 100)
	{
		_direction = RIGHT_MOVE;

		_enemyMotion = _enemyMotionR;
		_enemyMotion->start();
	}

	if ((_rc.left + _rc.right) / 2 > 800)
	{
		_direction = LEFT_MOVE;

		_enemyMotion = _enemyMotionL;
		_enemyMotion->start();
	}

	enemyDirection();
}

void enemy::render()
{
	Rectangle(getMemDC(), _player);//플레이어 렉트
	_rc.render(getMemDC());//렉트
	_enemyImg->aniRender(getMemDC(),_rc.left,_rc.top,_enemyMotion);
}

void enemy::enemyDirection()
{

	switch (_direction)
	{
	case LEFT_MOVE:

		_rc.move(-5, 0);
	
		break;
	case RIGHT_MOVE:

		_rc.move(5, 0);
		break;
	}
}

