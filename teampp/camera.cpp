#include "stdafx.h"
#include "camera.h"


camera::camera()
	: _cameraInfo(NULL)
{
}


camera::~camera()
{
}


HRESULT camera::init(int width, int height, int backWidth, int backHeight)
{
	if (_cameraInfo != NULL) release();
	HDC hdc = GetDC(_hWnd);

	_cameraInfo = new CAMERA_INFO;
	_cameraInfo->hMemDC = CreateCompatibleDC(hdc);
	_cameraInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, backWidth, backHeight);
	_cameraInfo->hOBit = (HBITMAP)SelectObject(_cameraInfo->hMemDC, _cameraInfo->hBit);
	_cameraInfo->blackSize = 200;
	_cameraInfo->width = width;
	_cameraInfo->height = height;
	_cameraInfo->backWidth = backWidth;
	_cameraInfo->backHeight = backHeight;
	_cameraInfo->viewWidth = width;
	_cameraInfo->viewHeight = height - _cameraInfo->blackSize;

	_isShaking = false;
	_shakeAmount = 0.f;
	_shakeCount = 0;

	_isFixed = false;
	_fixedLeft = 0;
	_fixedTop = 0;


	if (_cameraInfo == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

void camera::release()
{
	if (_cameraInfo)
	{
		SelectObject(_cameraInfo->hMemDC, _cameraInfo->hOBit);
		DeleteObject(_cameraInfo->hBit);
		DeleteDC(_cameraInfo->hMemDC);

		SAFE_DELETE(_cameraInfo);
	}
}

void camera::render(HDC hdc)
{
	BitBlt(hdc,
		0,
		0,
		_cameraInfo->width,
		_cameraInfo->height,
		_cameraInfo->hMemDC,
		0, 0,
		SRCCOPY);
}

bool camera::checkCameraX()
{
	if (_cameraInfo->x - _cameraInfo->viewWidth / 2 <= 0 ||
		_cameraInfo->x + _cameraInfo->viewWidth / 2 >= _cameraInfo->backWidth)
		return false;
	return true;
}

bool camera::checkCameraY()
{
	if (_cameraInfo->y - _cameraInfo->viewHeight / 2 <= 0 ||
		_cameraInfo->y + _cameraInfo->viewHeight / 2 >= _cameraInfo->backHeight)
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

void camera::cameraFixed(float x, float y)
{
}

void camera::FixedStart()
{
}

void camera::changePosition(float x, float y)
{
	int d = getDistance(x, y, _cameraInfo->x, _cameraInfo->y);
	float angle = getAngle(_cameraInfo->x, _cameraInfo->y, x, y);

	if (d > 50)
	{
		_cameraInfo->x += cosf(angle) * 5;
		_cameraInfo->y -= sinf(angle) * 5;
	}
}
