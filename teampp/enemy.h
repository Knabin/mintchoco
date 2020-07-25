#pragma once
#include "gameNode.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

enum ENEMYDIRECTION
{
	ENEMY_LEFT_IDLE,
	ENEMY_RIGHT_IDLE,
	ENEMY_LEFT_MOVE,
	ENEMY_RIGHT_MOVE,
	ENEMY_LEFT_ATTACK,
	ENEMY_RIGHT_ATTACK,
	ENEMY_LEFT_COMBO1,
	ENEMY_RIGHT_COMBO1,
	ENEMY_LEFT_COMBO2,
	ENEMY_RIGHT_COMBO2,
};

class enemy : public gameNode
{
protected:
	image* _enemyImg;
	image* _idle;
	image* _move;
	image* _attack;
	image* _combo1;
	image* _combo2;


	//image* _ehit;

	animation* _enemyMotion;
	animation* _enemyMotion_L_IDLE;
	animation* _enemyMotion_R_IDLE;
	animation* _enemyMotion_L;
	animation* _enemyMotion_R;
	animation* _enemyMotion_L_A;
	animation* _enemyMotion_R_A;
	animation* _enemyMotion_L_COMBO1;
	animation* _enemyMotion_R_COMBO1;
	animation* _enemyMotion_L_COMBO2;
	animation* _enemyMotion_R_COMBO2;


	string _imageName;	//���ʹ� �̹��� ���� ��
	float _x, _y;		//���ʹ� x�� y��
	float _speed;		//���ʹ� ���ǵ�
	float _jumpPower, _gravity;
	int _isAttackCount;	//���ʹ� ���� �����̼ӵ�
	bool _isJump;
	MYRECT _rc;			//���ʹ� ��Ʈ

	float _playerX, _playerY;	//�÷��̾� ��ġ �� �������� ����
	float angle;
	float distance;
	//float _hp;		//���ʹ�ü��
	//float _Maxhp;		//���ʹ̸ƽ�ü��

	ENEMYDIRECTION _direction;

	int _random;

private:


public:
	enemy();
	~enemy();

	virtual HRESULT init(string imageName, float x, float y, float speed);
	virtual void release();
	virtual void update();
	virtual void render();

	void setPlayerPos(float x, float y);
};

