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
	_isJumping = _jumpPower = _gravity = 0;

	return S_OK;
}

void jump::render()
{
}

void jump::update()
{
	if (!_isJumping) return;

	//*_y -= _jumpPower - _gravity;
	//_jumpPower -= _gravity;

	_jumpPower += _gravity;
	_gravity -= 0.4f;

	if (_jumpPower < 0)
	{
		_jumpPower = 0;
		_isJumping = false;
		//SOUNDMANAGER->play("land");
	}


	//if (_startY < *_y)
	//{
	//	_isJumping = false;
	//	*_y = _startY;
	//}
}

void jump::release()
{
}

void jump::jumping(float * x, float * z, float jumpPower, float gravity)
{
	if (_isJumping) return;

	_isJumping = true;

	_x = x;
	_z = z;

	_startX = *x;
	_startZ = *z;
	_gravity = gravity;
	_jumpPower = jumpPower;
}
