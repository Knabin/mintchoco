#pragma once
#include "gameNode.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

enum ENEMYDIRECTION
{
	LEFT_IDLE,
	RIGHT_IDLE,
	LEFT_MOVE,
	RIGHT_MOVE,
	LEFT_ATTACK,
	RIGHT_ATTACK,
	LEFT_HIT,
	RIGHT_HIT
};

class enemy : public gameNode
{
protected:
	image* _enemyImg;	//���ʹ� �̹���
	image* _eA;
	image* _eW;
	image* _ehit;

	animation* _enemyMotion;

	animation* _enemyMotionL;
	animation* _enemyMotionR;
	animation* _enemyMotionL_A;
	animation* _enemyMotionR_A;
	animation* _enemyMotionL_H;
	animation* _enemyMotionR_H;

	string _imageName;
	float _x, _y;		//���ʹ� x�� y��
	float _speed;
	int _count, _index;
	int _width, _height;
	MYRECT _rc;			//���ʹ� ��Ʈ
	bool _leftMove, _rightMove;

	float _playerX, _playerY;
	float angle;
	float distance;
	//float _hp;		//���ʹ�ü��
	//float _Maxhp;		//���ʹ̸ƽ�ü��

	ENEMYDIRECTION _direction;
private:


public:
	enemy();
	~enemy();

	virtual HRESULT init(string imageName, float x, float y, float speed);
	virtual void release();
	virtual void update();
	virtual void render();

	void enemyDirection();

	void setPlayerPos(float x, float y);
};

