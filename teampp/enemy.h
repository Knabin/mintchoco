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
	RIGHT_MOVE
};

class enemy : public gameNode
{
protected:
	image* _enemyImg;	//���ʹ� �̹���

	animation* _enemyMotion;

	animation* _enemyMotionL;
	animation* _enemyMotionR;
	string _imageName;
	float _x, _y;		//���ʹ� x�� y��
	float _speed;
	int _count, _index;
	int _width, _height;
	MYRECT _rc;			//���ʹ� ��Ʈ
	bool _leftMove, _rightMove;

	//float _hp;		//���ʹ�ü��
	//float _Maxhp;		//���ʹ̸ƽ�ü��

	ENEMYDIRECTION _direction;
private:
	RECT _player;
	float _xp, _yp;
public:
	enemy();
	~enemy();

	virtual HRESULT init(string imageName, float x, float y, float speed);
	virtual void release();
	virtual void update();
	virtual void render();

	void enemyDirection();
};

