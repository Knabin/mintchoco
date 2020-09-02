#pragma once

class camera
{
public:
	static camera* getInstance()
	{
		static camera instance;
		return &instance;
	}
private:
	camera();
	~camera();

private:
	HDC _hMemDC;
	HBITMAP _hBit;
	HBITMAP _hOBit;

	float _x;				// ī�޶� center x
	float _y;				// ī�޶� center y

	int _blackSize;			// ���ϴ� ������ �κ� ũ��

	int _backWidth;			// ����� ���� ũ��
	int _backHeight;		// ����� ���� ũ��

	int _width;				// ��ü ���� ���� ũ��
	int _height;			// ��ü ���� ���� ũ��

	int _viewWidth;			// ������ ����(stage) ���� ũ��
	int _viewHeight;		// ������ ����(stage) ���� ũ��

	bool _isShaking;		// ��鸮�� �ִ���
	float _shakeAmount;		// ��鸲 ����
	int _shakeCount;		// ��鸲 �ð�
	int _flag = -1;

	bool _isFixed;			// ī�޶� �����Ǿ�����
	int _fixedLeft;			// ������ left
	int _fixedTop;			// ������ top

	bool _isReturn;

public:
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

	inline HDC getMemDC() { return _hMemDC; }

	inline float getShakeNumber() { return _shakeAmount * _flag; }

	inline void setPosition(float x, float y) { _x = x; _y = y; }

	inline void setX(int x) { _x = x; }
	inline float getX() { return _x; }

	inline void setY(int y) { _y = y; }
	inline float getY() { return _y; }

	inline void setBlackSize(int size) { _blackSize = size; }
	inline int getBlackSize() { return _blackSize; }

	inline void setWidth(int width) { _width = width; }
	inline int getWidth() { return _width; }

	inline void setHeight(int height) { _height = height; }
	inline int getHeight() { return _height; }

	inline void setBackWidth(int width) { _backWidth = width; }
	inline void setBackHeight(int height) { _backHeight = height; }

	inline void setViewWidth(int width) { _viewWidth = width; }
	inline int getViewWidth() { return _viewWidth; }

	inline void setViewHeight(int height) { _viewHeight = height; }
	inline int getViewHeight() { return _viewHeight; }

	inline int getLeft() {
		if (_isFixed) return _fixedLeft;
		if (!checkCameraX()) return (_x <= _backWidth / 2) ? 0 : _backWidth - _viewWidth;
		return _x - _viewWidth / 2;
	}
	inline int getTop() {
		if (_isFixed) return _fixedTop;
		if (!checkCameraY()) return (_y <= _backHeight / 2) ? 0 : _backHeight - _viewHeight;
		return _y - _viewHeight / 2;
	}

	inline int getOriginalLeft() 
	{
		if (!checkCameraX()) return (_x <= _backWidth / 2) ? 0 : _backWidth - _viewWidth;
		return _x - _viewWidth / 2;
	}

	inline int getOriginalTop()
	{
		if (!checkCameraY()) return (_y <= _backHeight / 2) ? 0 : _backHeight - _viewHeight;
		return _y - _viewHeight / 2;
	}

	inline void setIsShaking(bool isShaking) { _isShaking = isShaking; _shakeAmount = _isShaking ? 6.0f : 0; }
	inline bool getIsShaking() { return _isShaking; }

	inline void setIsFixed(bool isFixed) { _isFixed = isFixed; }
	inline bool getIsFixed() { return _isFixed; }

	inline void setIsReturn(bool isReturn) { _isReturn = isReturn; }
	inline bool getIsReturn() { return _isReturn; }

	// TODO: ���� �ʿ��մϴ� ������� ������ �Ф�
	// ī�޶� ��ü ������ �������� ������ RECT ��ȯ
	inline RECT getRect() { return RectMakeCenter(_x, _y, _width, _height); }
	// ���� �κ� ������ ī�޶� ���� View ���� �������� ������ RECT ��ȯ
	inline RECT getViewRect() { return RectMake(getLeft(), getTop(), _viewWidth, _viewHeight); }

	// =======================================================
};

