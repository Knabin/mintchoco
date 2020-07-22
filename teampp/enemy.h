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
	ENEMY_LEFT_ATTACK,			//에너미 공격모션
	ENEMY_RIGHT_ATTACK,			//에너미 공격모션
	ENEMY_LEFT_COMBO1,			//에너미 공격모션 
	ENEMY_RIGHT_COMBO1,			//에너미 공격모션 
	ENEMY_LEFT_COMBO2,			//에너미 공격모션 
	ENEMY_RIGHT_COMBO2,			//에너미 공격모션 
	ENEMY_LEFT_SUBMOTION,		//치어리더는 백덤블링, 남학생은 어퍼컷, 여학생은 어택
	ENEMY_RIGHT_SUBMOTION,		//치어리더는 백덤블링, 남학생은 어퍼컷, 여학생은 어택
	ENEMY_LEFT_GETHIT,
	ENEMY_RIGHT_GETHIT,
	ENEMY_LEFT_STUN,
	ENEMY_RIGHT_STUN
};

class enemy : public gameNode
{
protected:
	image* _enemyImg;
	image* _idle;
	image* _move;
	image* _attack;		//에너미 공격모션
	image* _combo1;		//에너미 공격모션
	image* _combo2;		//에너미 공격모션
	image* _submotion;	//치어리더는 백덤블링, 남학생은 어퍼컷, 여학생은 어택
	image* _gethit;
	image* _stun;	

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
	animation* _enemyMotion_L_stun;
	animation* _enemyMotion_R_stun;


	string _imageName;	//에너미 이미지 받을 것
	float _x, _y;		//에너미 x축 y축
	float _speed;		//에너미 스피드
	float _jumpPower, _gravity;
	int _isAttackCount;	//에너미 공격 딜레이속도
	int _isStunCount;	//에너미 스턴 시간
	bool _isJump;
	MYRECT _rc;			//에너미 렉트
	MYRECT _attackRC;	//에너미 공격렉트

	float _playerX, _playerY;	//플레이어 위치 값 받으려는 변수
	float angle;
	float distance;
	float _hp;		//에너미체력

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

