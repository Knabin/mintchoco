#pragma once
#include "gameNode.h"

//콜백함수 == 함수 포인터
typedef void(*CALLBACK_FUNCTION)(void);

//콜백함수와 델리게이트(delegate) 조사해보면 좋습니다

//<Functional> 라이브러리를 사용하면 전역에 선언한 콜백함수
//매개변수로 지역변수 사용 가능해 집니다
//std::bind, std::move, std::Function

//Lambda식과 사용해서 콜백함수를 써보는 연습하면 더 좋겠죠

//강제아닙니다 권유에요

enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;

	const char* _imageName;
	image* _image;
	RECT _rc;

	float _x, _y;
	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	CALLBACK_FUNCTION _callbackFunction;	//콜백함수 선언

public:
	button();
	~button();

	HRESULT init(const char* imageName, float x, float y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION cbFunction);

	void release();
	void update();
	void render();
};

