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
	ENEMY_LEFT_SUBMOTION,
	ENEMY_RIGHT_SUBMOTION,
	ENEMY_LEFT_GETHIT,
	ENEMY_RIGHT_GETHIT
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
	image* _submotion;	//치어리더는 백덤블링, 남학생은 어퍼컷, 여학생은 어택
	image* _gethit;
	

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
	animation* _enemyMotion_L_submotion;
	animation* _enemyMotion_R_submotion;
	animation* _enemyMotion_L_hit;
	animation* _enemyMotion_R_hit;


	string _imageName;	//에너미 이미지 받을 것
	float _x, _y;		//에너미 x축 y축
	float _speed;		//에너미 스피드
	float _jumpPower, _gravity;
	int _isAttackCount;	//에너미 공격 딜레이속도
	bool _isJump;
	MYRECT _rc;			//에너미 렉트

	int _aniTime;	//치어리더 백플립 잔상
	float _playerX, _playerY;	//플레이어 위치 값 받으려는 변수
	float angle;
	float distance;
	//float _hp;		//에너미체력
	//float _Maxhp;		//에너미맥스체력

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

