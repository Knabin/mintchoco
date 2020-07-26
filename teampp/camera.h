#pragma once
#include "singletonBase.h"

class camera : public singletonBase<camera>
{
	typedef struct tagCameraInfo
	{
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;

		float x;		// ī�޶� center x
		float y;		// ī�޶� center y

		int blackSize;	// ���ϴ� ������ �κ� ũ��

		int backWidth;	// ����� ���� ũ��
		int backHeight;	// ����� ���� ũ��

		int width;		// ��ü ���� ���� ũ��
		int height;		// ��ü ���� ���� ũ��

		int viewWidth;	// ������ ����(stage) ���� ũ��
		int viewHeight;	// ������ ����(stage) ���� ũ��

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


	bool _isShaking;		// ��鸮�� �ִ���
	float _shakeAmount;		// ��鸲 ����
	int _shakeCount;		// ��鸲 �ð�
	int _flag = -1;

	bool _isFixed;			// ī�޶� �����Ǿ�����
	int _fixedLeft;			// ������ left
	int _fixedTop;			// ������ top

	bool _isReturn;

public:
	camera();
	~camera();

	// ī�޶� �ʱ�ȭ �Լ�(ī�޶� width(������ X), ī�޶� height(������ Y), ��� width, ��� height)
	HRESULT init(int width, int height, int backWidth, int backHeight);

	void release();
	void render(HDC hdc);

	// ī�޶� X���� üũ�ؾ� �ϴ���
	bool checkCameraX();
	// ī�޶� Y���� üũ�ؾ� �ϴ���
	bool checkCameraY();

	// ��� �� �ʿ��� ���� ������, ī�޶� ����� �� �� �ش� �Լ��� ȣ���ϼ���
	void cameraShake();
	// ��� �� �ʿ��� ���� �����Ǿ� �ִٸ� �ش� ���� ���� ȭ���� ��鸲
	void shakeStart();

	// ���� ī�޶� ��ġ �������� ī�޶� ����
	void cameraFixed();
	// Ư�� ��ǥ �������� ī�޶� ����(left, top)
	void cameraFixed(float x, float y);

	// �ڿ������� ������� ī�޶�(centerX, centerY)
	void changePosition(float x, float y);
	void cameraFixedEnd(float x, float y);


	// =======================================================
	// ##				ī�޶� getter / setter				##

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

	// TODO: ���� �ʿ��մϴ� ������� ������ �Ф�
	// ī�޶� ��ü ������ �������� ������ RECT ��ȯ
	inline RECT getRect() { return RectMakeCenter(_cameraInfo->x, _cameraInfo->y, _cameraInfo->width, _cameraInfo->height); }
	// ���� �κ� ������ ī�޶� ���� View ���� �������� ������ RECT ��ȯ
	inline RECT getViewRect() { return RectMake(getLeft(), getTop(), _cameraInfo->viewWidth, _cameraInfo->viewHeight); }

	// =======================================================
};

