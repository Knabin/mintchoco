#pragma once
#include "gameNode.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

#define ENEMYSPEED 3.0f;

enum ENEMYDIRECTION
{
	ENEMY_RIGHT_IDLE,
	ENEMY_LEFT_IDLE,
	ENEMY_RIGHT_MOVE,
	ENEMY_LEFT_MOVE
};

enum CHEELEADER
{
	IDLE,
	WALK
};


class enemy : public gameNode
{
private:
	image* _enemyImg;	//에너미 이미지
	float _x, _y;		//에너미 x축 y축
	RECT _rc;			//에너미 렉트

	ENEMYDIRECTION _enemyDirection;	//에너미 상태정의
	CHEELEADER _cheerleaderDirection;			//에너미 정의
	animation* _enemyMotion;		//에너미 애니메이션
public:
	enemy();
	~enemy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

