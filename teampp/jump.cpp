#include "stdafx.h"
#include "jump.h"


jump::jump()
{
}


jump::~jump()
{
}

HRESULT jump::init()
{
	_isJumping = _jumpPower = _gravity = _angle = _speed = 0;

	return S_OK;
}

void jump::render()
{
}

void jump::update()
{
	
}

void jump::release()
{
}

void jump::jumping(float * x, float * y, float jumpPower, float gravity)
{
	if (_isJumping) return;

	_isJumping = true;

	_x = x;
	_y = y;

	_startX = *x;
	_startY = *y;
	_gravity = gravity;
	_jumpPower = jumpPower;
}

void jump::jumpingUpdate()
{
	if (!_isJumping) return;

	*_y -= _jumpPower;
	_jumpPower -= _gravity;

	if (_startY < *_y)
	{
		_isJumping = false;
		*_y = _startY;
	}
}

void jump::walkJumping(float * x, float * y, float jumpPower, float gravity, float angle, float speed, bool leftOrRight)
{
	if (_isWalkJumping) return;

	_isWalkJumping = true;

	_x = x;
	_y = y;

	_startX = *x;
	_startY = *y;
	_gravity = gravity;
	_jumpPower = jumpPower;
	_angle = angle;
	_leftOrRight = leftOrRight;
}

void jump::walkJumpingUpdate()
{
	if (!_isWalkJumping) return;

	if (!_leftOrRight)
	{
		*_x -= cos(_angle) * _speed;
		*_y -= -sin(_angle) * _jumpPower;

		if (_startY < *_y)
		{
			_isWalkJumping = false;
			*_y = _startY;
		}
	}
	else
	{
		*_x += cos(_angle) * _speed;
		*_y -= -sin(_angle) * _speed;

		if (_startY < *_y)
		{
			_isWalkJumping = false;
			*_y = _startY;
		}
	}
}

void jump::runJumping(float * x, float * y, float jumpPower, float gravity, float angle, float speed, bool leftOrRight)
{
	if (_isRunJumping) return;

	_isRunJumping = true;

	_x = x;
	_y = y;

	_startX = *x;
	_startY = *y;
	_gravity = gravity;
	_jumpPower = jumpPower;
	_angle = angle;
	_leftOrRight = leftOrRight;
}

void jump::runJumpingUpdate()
{
	if (!_isRunJumping) return;

	if (!_leftOrRight)
	{
		*_x -= cos(_angle) * _speed;
		*_y -= -sin(_angle) * _jumpPower;

		if (_startY < *_y)
		{
			_isRunJumping = false;
			*_y = _startY;
		}
	}
	else
	{
		*_x += cos(_angle) * _speed;
		*_y -= -sin(_angle) * _speed;

		if (_startY < *_y)
		{
			_isRunJumping = false;
			*_y = _startY;
		}
	}
}
