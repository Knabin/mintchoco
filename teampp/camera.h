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

	float _x;				// 카메라 center x
	float _y;				// 카메라 center y

	int _blackSize;			// 상하단 검은색 부분 크기

	int _backWidth;			// 백버퍼 가로 크기
	int _backHeight;		// 백버퍼 세로 크기

	int _width;				// 전체 영역 가로 크기
	int _height;			// 전체 영역 세로 크기

	int _viewWidth;			// 보여질 영역(stage) 가로 크기
	int _viewHeight;		// 보여질 영역(stage) 세로 크기

	bool _isShaking;		// 흔들리고 있는지
	float _shakeAmount;		// 흔들림 세기
	int _shakeCount;		// 흔들림 시간
	int _flag = -1;

	bool _isFixed;			// 카메라가 고정되었는지
	int _fixedLeft;			// 고정된 left
	int _fixedTop;			// 고정된 top

	bool _isReturn;

public:
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

	// TODO: 수정 필요합니다 사용하지 마세요 ㅠㅠ
	// 카메라 전체 사이즈 기준으로 생성된 RECT 반환
	inline RECT getRect() { return RectMakeCenter(_x, _y, _width, _height); }
	// 검은 부분 제외한 카메라 실제 View 영역 기준으로 생성된 RECT 반환
	inline RECT getViewRect() { return RectMake(getLeft(), getTop(), _viewWidth, _viewHeight); }

	// =======================================================
};

