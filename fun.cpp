#include "stdafx.h"
#include "fun.h"


fun::fun()
{
}


fun::~fun()
{
}

HRESULT fun::init()
{
	_worldTimeCount = 0;
	_isMoving = false;

	return S_OK;
}

void fun::release()
{
}

void fun::update()
{
	moving();
}

void fun::render()
{
}

void fun::moveTo(image * image, float endX, float endY, float time)
{
	if (!_isMoving)
	{
		_image = image;

		_startX = _image->getX();
		_startY = _image->getY();

		_endX = endX;
		_endY = endY;

		_travelRange = getDistance(_startX, _startY, _endX, _endY);

		_angle = getAngle(_startX, _startY, _endX, _endY);

		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_time = time;

		_isMoving = true;
	}

}

void fun::moving()
{
	if (!_isMoving) return;

	float elapsedTime = TIMEMANAGER->getElapsedTime();

	//보간속도
	float moveSpeed = (elapsedTime / _time) * _travelRange;

	_image->setX(_image->getX() + cosf(_angle) * moveSpeed);
	_image->setY(_image->getY() + -sinf(_angle) * moveSpeed);

	if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_image->setX(_endX);
		_image->setY(_endY);

		_isMoving = false;

		
	}

}
