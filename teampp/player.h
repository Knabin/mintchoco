#pragma once
#include "gameNode.h"
#include "jump.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

enum PLAYERDIRECTION
{
	PLAYERDIRECTION_RIGHT_STOP,
	PLAYERDIRECTION_LEFT_STOP,
	PLAYERDIRECTION_RIGHT_WALK,
	PLAYERDIRECTION_LEFT_WALK,
	PLAYERDIRECTION_RIGHT_MOVE,
	PLAYERDIRECTION_LEFT_MOVE,
	PLAYERDIRECTION_RIGHT_ATTACK,
	PLAYERDIRECTION_LEFT_ATTACK,
	PLAYERDIRECTION_RIGHT_JUMP,
	PLAYERDIRECTION_LEFT_JUMP,
	PLAYERDIRECTION_LEFT_JUMP_ATTACK,
	PLAYERDIRECTION_RIGHT_JUMP_ATTACK
};

class player : public gameNode
{
private:
	PLAYERDIRECTION _playerDirection;//플레이어 프레임

	image* _idleImage;//플레이어 기본 이미지
	image* _walkImage;//플레이어 걷는 이미지
	image* _runImage;//플레이어 달리는 이미지
	image* _jumpImage;//플레이어 점프 이미지
	image* _attackImage;//플레이어 공격 이미지
	image* _jumpAttackImage;//플레이어 점프 공격 이미지
	image* _backGround1Pixel;//1번 스테이지 픽셀충돌용 이미지
	MYRECT _rc;//플레이어 렉트
	MYRECT _attackRc;//공격용으로 사용할 렉트
	MYRECT _jumpAttackRc;//점프 공격 렉트
	float _x, _y;//플레이어 중점좌표
	float _startX, _startY;//플레이어 점프했을때 땅에 착지한 상태인지 체크하기 위한값
	float _speed;//걷는 스피드
	float _runSpeed;//달리는 스피드
	float _jumpPower, _gravity;//플레이어 점프값
	int _count, _index;//프레임에 사용할 카운트, 인덱스
	int _jumpCount;
	int _time, _clickTime;//달리기 조건문 시간체크
	int _hp;//플레이어 hp
	int _r, _g, _b;//픽셀충돌용 rgb
	int _probeX, _probeY;//픽셀충돌용
	jump* _jump;//점프 상속할당

	bool _diagonalKey;//중복키를 방지해 프레임을 하나씩만 실행시키기 위한 값(대각선 중복키 방지)
	bool _dash;//플레이어가 달리기에 사용할 값
	bool _jumping;//점프함수를 실행한 이후 렉트값을 계속 변경시켜주기 위한 값
	bool _attack;//공격이 실행중인지 아닌지 여부확인용 값

public:
	player();
	~player();

	HRESULT init();
	void render();
	void update();
	void release();

	void attack();
	void move();
	void frameDraw();
	void hitDamage(int hitDamage) { _hp -= hitDamage; }//플레이어가 받을 데미지

	bool keyLeft()
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT)) return true;
		return false;
	}

	bool keyRight()
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) return true;
		return false;
	}

	bool keyUp()
	{
		if (KEYMANAGER->isStayKeyDown(VK_UP)) return true;
			return false;
	}

	bool keyDown()
	{
		if (KEYMANAGER->isStayKeyDown(VK_DOWN)) return true;
		return false;
	}

	float getPlayerX() { return _x; }
	float getPlayerY() { return _y; }
	
	MYRECT getPlayerRect() { return _rc; }
};

