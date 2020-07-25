#pragma once
#include "gameNode.h"


enum PointerState //포인터 렉트 현위치
{
	START = 0,
	QUIT
};
struct tagScene
{
	image* SceneImage;
	RECT _rc;			//포인터 렉트
	float _x, _y;
	PointerState _PointerState;
};

class scene : public gameNode
{

private:

	tagScene _MainTitle;		//타이틀 배경
	tagScene _StartQuit;		//타이틀 버튼
	tagScene _Pointer;			//타이틀 포인터

	bool _GameStart;			//게임 시작할것인가?
	bool _Loading;				//로딩 시작할것 인가?

	int _LoadingCount;			//로딩 카운트

public:

	scene();
	~scene();

	HRESULT init();
	void release();
	void update();
	void render();

	void PointerMove();		//포인터 이동 함수
	void Draw();			//배경씬, 로딩씬 그리기

};

