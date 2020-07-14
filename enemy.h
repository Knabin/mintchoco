#pragma once
#include "gameNode.h"

enum ENEMYDIRECTION
{
	SIDE,
	UPDOWN,
	FREE
};

class enemy : public gameNode
{
protected:
	image* _imageName;		//적의 이미지에 사용할꺼
	RECT _rc;				//충돌용 렉트

	int _currentFrameX;		//프레임 이미지 1개 가지고 각각 다른 프레임 유지하려고
	int _currentFrameY;

	int _count;				//프레임 카운트 용
	int _fireCount;			//발사 카운트 용
	int _rndFireCount;		//발사되는 딜레이 용

	ENEMYDIRECTION _direction;

public:
	enemy();
	~enemy();

	HRESULT init();											//초기화용
	HRESULT init(const char* imageName, POINT position);	//초기화 too
	void release();
	void update();
	void render();

	void move();			//움직임
	void draw();			//그려주자

	bool bulletCountFire();	//총알 클래스에게 발사되라고 전달해주세요~

	void enemyDirection(int num) { _direction = (ENEMYDIRECTION)num; }
	//렉트 접근자
	inline RECT getRect() { return _rc; }
};

