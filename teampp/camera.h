#pragma once
#include "singletonBase.h"

class camera : public singletonBase<camera>
{
	typedef struct tagCameraInfo
	{
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;

		float x;		// 카메라 center x
		float y;		// 카메라 center y

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


	bool _isShaking;		// 흔들리고 있는지
	float _shakeAmount;		// 흔들림 세기
	int _shakeCount;		// 흔들림 시간
	int _flag = -1;

	bool _isFixed;			// 카메라가 고정되었는지
	int _fixedLeft;			// 고정된 left
	int _fixedTop;			// 고정된 top

	bool _isReturn;

public:
	camera();
	~camera();

	// 카메라 초기화 함수(카메라 width(윈도우 X), 카메라 height(윈도우 Y), 배경 width, 배경 height)
	HRESULT init(int width, int height, int backWidth, int backHeight);

	void release();
	void render(HDC hdc);

	// 카메라 X축을 체크해야 하는지
	bool checkCameraX();
	// 카메라 Y축을 체크해야 하는지
	bool checkCameraY();

	// 흔들 때 필요한 값을 설정함, 카메라 흔들어야 할 때 해당 함수를 호출하세요
	void cameraShake();
	// 흔들 때 필요한 값이 설정되어 있다면 해당 값에 따라서 화면이 흔들림
	void shakeStart();

	// 현재 카메라 위치 기준으로 카메라 고정
	void cameraFixed();
	// 특정 좌표 기준으로 카메라 고정(left, top)
	void cameraFixed(float x, float y);

	// 자연스럽게 따라오는 카메라(centerX, centerY)
	void changePosition(float x, float y);
	void cameraFixedEnd(float x, float y);


	// =======================================================
	// ##				카메라 getter / setter				##

	inline HDC getMemDC() { return _cameraInfo->hMemDC; }

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

	inline int getOriginalLeft() 
	{
		if (!checkCameraX()) return (_cameraInfo->x <= _cameraInfo->backWidth / 2) ? 0 : _cameraInfo->backWidth - _cameraInfo->viewWidth;
		return _cameraInfo->x - _cameraInfo->viewWidth / 2;
	}

	inline int getOriginalTop()
	{
		if (!checkCameraY()) return (_cameraInfo->y <= _cameraInfo->backHeight / 2) ? 0 : _cameraInfo->backHeight - _cameraInfo->viewHeight;
		return _cameraInfo->y - _cameraInfo->viewHeight / 2;
	}

	inline void setIsShaking(bool isShaking) { _isShaking = isShaking; _shakeAmount = _isShaking ? 6.0f : 0; }
	inline bool getIsShaking() { return _isShaking; }

	inline void setIsFixed(bool isFixed) { _isFixed = isFixed; }
	inline bool getIsFixed() { return _isFixed; }

	inline void setIsReturn(bool isReturn) { _isReturn = isReturn; }
	inline bool getIsReturn() { return _isReturn; }

	// TODO: 수정 필요합니다 사용하지 마세요 ㅠㅠ
	// 카메라 전체 사이즈 기준으로 생성된 RECT 반환
	inline RECT getRect() { return RectMakeCenter(_cameraInfo->x, _cameraInfo->y, _cameraInfo->width, _cameraInfo->height); }
	// 검은 부분 제외한 카메라 실제 View 영역 기준으로 생성된 RECT 반환
	inline RECT getViewRect() { return RectMake(getLeft(), getTop(), _cameraInfo->viewWidth, _cameraInfo->viewHeight); }

	// =======================================================
};

