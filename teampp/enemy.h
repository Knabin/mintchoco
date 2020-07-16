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
	image* _enemyImg;	//���ʹ� �̹���
	float _x, _y;		//���ʹ� x�� y��
	RECT _rc;			//���ʹ� ��Ʈ

	ENEMYDIRECTION _enemyDirection;	//���ʹ� ��������
	CHEELEADER _cheerleaderDirection;			//���ʹ� ����
	animation* _enemyMotion;		//���ʹ� �ִϸ��̼�
public:
	enemy();
	~enemy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

