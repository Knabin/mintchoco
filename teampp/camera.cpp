#include "stdafx.h"
#include "camera.h"


camera::camera()
	: _hMemDC(NULL), _hBit(NULL), _hOBit(NULL), _blackSize(0), _width(WINSIZEX), _height(WINSIZEY),
	_backWidth(WINSIZEX), _backHeight(WINSIZEY), _viewWidth(WINSIZEX), _viewHeight(WINSIZEY),
	_isShaking(false), _shakeAmount(0.f), _shakeCount(0), _isFixed(false), _fixedLeft(0), _fixedTop(0)
{
}


camera::~camera()
{
}


HRESULT camera::init(int width, int height, int backWidth, int backHeight)
{
	HDC hdc = GetDC(_hWnd);

	_hMemDC = CreateCompatibleDC(hdc);
	_hBit = (HBITMAP)CreateCompatibleBitmap(hdc, backWidth, backHeight);
	_hOBit = (HBITMAP)SelectObject(_hMemDC, _hBit);
	_blackSize = 160;
	_width = width;
	_height = height;
	_backWidth = backWidth;
	_backHeight = backHeight;
	_viewWidth = width;
	_viewHeight = height - _blackSize;

	_isShaking = false;
	_shakeAmount = 0.f;
	_shakeCount = 0;

	_isFixed = false;
	_fixedLeft = 0;
	_fixedTop = 0;


	if (_hMemDC == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

void camera::release()
{
	if (_hMemDC)
	{
		SelectObject(_hMemDC, _hOBit);
		DeleteObject(_hBit);
		DeleteDC(_hMemDC);
	}
}

void camera::render(HDC hdc)
{
	BitBlt(hdc,
		0,
		0,
		_width,
		_height,
		_hMemDC,
		0, 0,
		SRCCOPY);
}

bool camera::checkCameraX()
{
	if (_x - _viewWidth / 2 <= 0 ||
		_x + _viewWidth / 2 >= _backWidth)
		return false;
	return true;
}

bool camera::checkCameraY()
{
	if (_y - _viewHeight / 2 <= 0 ||
		_y + _viewHeight / 2 >= _backHeight)
		return false;
	return true;
}


void camera::cameraShake()
{
	_isShaking = true;
	_shakeAmount = 2.0f;
	_shakeCount = 0;
}

void camera::shakeStart()
{
	if (_isShaking)
	{
		++_shakeCount;
		if (_shakeCount > 10)
		{
			_shakeCount = 0;
			_shakeAmount = 0;
			_isShaking = false;
		}
		else
		{
			_flag *= -1;
		}
	}

}

void camera::cameraFixed()
{
	_fixedLeft = getLeft();
	_fixedTop = getTop();
	_isFixed = true;
}

void camera::cameraFixed(float x, float y)
{
	_fixedLeft = x;
	_fixedTop = y;
	_isFixed = true;
}

void camera::changePosition(float x, float y)
{
	int d = getDistance(x, y, _x, _y);
	float angle = getAngle(_x, _y, x, y);

	if (d > 50)
	{
		_x += cosf(angle) * 5;
		_y -= sinf(angle) * 5;
	}
}

void camera::cameraFixedEnd(float x, float y)
{
	int d = getDistance(_fixedLeft, _fixedTop, x, y);
	float angle = getAngle(_fixedLeft, _fixedTop, x, y);

	if (d > 5)
	{
		_fixedLeft += cosf(angle) * 5;
		_fixedTop -= sinf(angle) * 5;
	}
	else
	{
		_isFixed = false;
		_isReturn = false;
	}
}
