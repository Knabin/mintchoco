#pragma once
#include "singletonBase.h"

class camera : public singletonBase<camera>
{
	typedef struct tagCameraInfo
	{
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;

		float x;
		float y;

		int blackSize;	// 상하단 검은색 부분 크기

		int backWidth;	// 백버퍼 가로 크기
		int backHeight;	// 백버퍼 세로 크기

		int width;		// 전체 영역 가로 크기
		int height;		// 전체 영역 세로 크기

		int viewWidth;	// 보여질 영역(stage) 가로 크기
		int viewHeight;	// 보여질 영역(stage) 세로 크기

		tagCameraInfo()
		{
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			x = 0.0f;
			y = 0.0f;
			blackSize = 0;
			backWidth = 0;
			backHeight = 0;
			width = 0;
			height = 0;
			viewWidth = 0;
			viewHeight = 0;
		}

	} CAMERA_INFO, *LPCAMERA_INFO;

private:
	LPCAMERA_INFO _cameraInfo;


	bool _isShaking;
	float _shakeAmount;
	int _shakeCount;
	int _flag = -1;

	bool _isFixed;
	int _fixedLeft;
	int _fixedTop;

public:
	camera();
	~camera();

	HRESULT init(int width, int height, int backWidth, int backHeight);

	void release();
	void render(HDC hdc);

	inline HDC getMemDC() { return _cameraInfo->hMemDC; }

	bool checkCameraX();
	bool checkCameraY();

	void cameraShake();
	void shakeStart();

	void cameraFixed();
	void cameraFixed(float x, float y);

	void changePosition(float x, float y);

	inline float getShakeNumber() { return _shakeAmount * _flag; }

	inline void setPosition(float x, float y) { _cameraInfo->x = x; _cameraInfo->y = y; }

	inline void setX(int x) { _cameraInfo->x = x; }
	inline float getX() { return _cameraInfo->x; }

	inline void setY(int y) { _cameraInfo->y = y; }
	inline float getY() { return _cameraInfo->y; }

	inline void setBlackSize(int size) { _cameraInfo->blackSize = size; }
	inline int getBlackSize() { return _cameraInfo->blackSize; }

	inline void setWidth(int width) { _cameraInfo->width = width; }
	inline int getWidth() { return _cameraInfo->width; }

	inline void setHeight(int height) { _cameraInfo->height = height; }
	inline int getHeight() { return _cameraInfo->height; }

	inline void setBackWidth(int width) { _cameraInfo->backWidth = width; }
	inline void setBackHeight(int height) { _cameraInfo->backHeight = height; }

	inline void setViewWidth(int width) { _cameraInfo->viewWidth = width; }
	inline int getViewWidth() { return _cameraInfo->viewWidth; }

	inline void setViewHeight(int height) { _cameraInfo->viewHeight = height; }
	inline int getViewHeight() { return _cameraInfo->viewHeight; }

	inline int getLeft() {
		if (_isFixed) return _fixedLeft;
		if (!checkCameraX()) return (_cameraInfo->x <= _cameraInfo->backWidth / 2) ? 0 : _cameraInfo->backWidth - _cameraInfo->viewWidth;
		return _cameraInfo->x - _cameraInfo->viewWidth / 2;
	}
	inline int getTop() {
		if (_isFixed) return _fixedTop;
		if (!checkCameraY()) return (_cameraInfo->y <= _cameraInfo->backHeight / 2) ? 0 : _cameraInfo->backHeight - _cameraInfo->viewHeight;
		return _cameraInfo->y - _cameraInfo->viewHeight / 2;
	}

	inline void setIsShaking(bool isShaking) { _isShaking = isShaking; _shakeAmount = _isShaking ? 6.0f : 0; }
	inline bool getIsShaking() { return _isShaking; }

	inline void setIsFixed(bool isFixed) { _isFixed = isFixed; }
	inline bool getIsFixed() { return _isFixed; }

	inline RECT getRect() { return RectMakeCenter(_cameraInfo->x, _cameraInfo->y, _cameraInfo->width, _cameraInfo->height); }
};

