#pragma once
#include "gameNode.h"
#include "jump.h"
#include "stageManager.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

#define ULTIMATECOUNT 19

enum PLAYERDIRECTION
{
	PLAYERDIRECTION_RIGHT_STOP,
	PLAYERDIRECTION_LEFT_STOP,

	PLAYERDIRECTION_RIGHT_WALK,
	PLAYERDIRECTION_LEFT_WALK,

	PLAYERDIRECTION_RIGHT_MOVE,
	PLAYERDIRECTION_LEFT_MOVE,

	PLAYERDIRECTION_RIGHT_JUMP,
	PLAYERDIRECTION_LEFT_JUMP,

	PLAYERDIRECTION_RIGHT_COMBO_ATTACK1,
	PLAYERDIRECTION_LEFT_COMBO_ATTACK1,

	PLAYERDIRECTION_RIGHT_COMBO_ATTACK2,
	PLAYERDIRECTION_LEFT_COMBO_ATTACK2,

	PLAYERDIRECTION_RIGHT_COMBO_ATTACK3,
	PLAYERDIRECTION_LEFT_COMBO_ATTACK3,

	PLAYERDIRECTION_RIGHT_GUARD,
	PLAYERDIRECTION_LEFT_GUARD,

	PLAYERDIRECTION_RIGHT_DOWN,
	PLAYERDIRECTION_LEFT_DOWN,

	PLAYERDIRECTION_RIGHT_ULTIMATE,
	PLAYERDIRECTION_LEFT_ULTIMATE,

	PLAYERDIRECTION_RIGHT_STRONG_ATTACK,
	PLAYERDIRECTION_LEFT_STRONG_ATTACK,

	PLAYERDIRECTION_RIGHT_JUMP_ATTACK,
	PLAYERDIRECTION_LEFT_JUMP_ATTACK,

	PLAYERDIRECTION_RIGHT_DASH_ATTACK,
	PLAYERDIRECTION_LEFT_DASH_ATTACK
};

class player : public gameNode
{
private:
	PLAYERDIRECTION _playerDirection;//플레이어 프레임

	image* _idleImage;//플레이어 기본 이미지
	image* _walkImage;//플레이어 걷는 이미지
	image* _runImage;//플레이어 달리는 이미지
	image* _jumpImage;//플레이어 점프 이미지
	image* _comboAttackImage1;//플레이어 공격 이미지
	image* _comboAttackImage2;//플레이어 공격 이미지2
	image* _comboAttackImage3;//플레이어 공격 이미지3
	image* _strongAttackImage;//플레이어 강공격 이미지
	image* _ultimateImage;//플레이어 궁극기 이미지
	image* _ultimateAfterImage[ULTIMATECOUNT];//플레이어 궁극기 잔상 이미지
	image* _shadow;//그림자 이미지
	image* _jumpAttackImage;//플레이어 점프 공격 이미지
	image* _dashAttackImage;//대쉬 공격 이미지
	image* _guardImage;//플레이어 방어 이미지
	image* _downImage;//플레이어가 피격 당했을때 다운 이미지
	image* _stage01Pixel;//스테이지1의 배경픽셀 이미지
	image* _stage02Pixel;//스테이지1의 배경픽셀 이미지

	MYRECT _rc;//플레이어 렉트
	MYRECT _attackRc;//공격용으로 사용할 렉트
	MYRECT _comboAttackRc1;//1단계 콤보공격 렉트
	MYRECT _comboAttackRc2;//2단계 콤보공격 렉트

	float _x, _z;//플레이어 중점좌표
	float _walkSpeed;//걷는 스피드
	float _runSpeed;//달리는 스피드
	float _jumpPower, _gravity;//플레이어 점프값

	int _count, _ultimateAfterCount, _index;//프레임에 사용할 카운트, 인덱스
	int _time, _clickTime;//달리기 조건문 시간체크
	int _hp;//플레이어 hp
	int _coin;//돈

	jump* _jump;//점프 상속할당
	stageManager* _stageManager;//스테이지 매니저 상속할당

	bool _dash;//플레이어가 달리기에 사용할 값
	bool _jumping;//점프함수를 실행한 이후 렉트값을 계속 변경시켜주기 위한 값
	bool _attack;//공격이 실행중인지 아닌지 여부확인용 값
	bool _guard;//플레이어 방어
	bool _ultimate;//궁극기
	bool _comboAttack;//콤보공격 프레임에 사용할 변수
	bool _comboAttack2;//콤보공격 3단계 실행여부를 확인하기 위한 변수
	bool _pixelCollision;//장애물 픽셀충돌 조건
	bool _pixelCollisionDown;//픽셀충돌이 트루면 플레이어 위치 아래로 조정

	image* _playerImage;
	float _yPlayerY;


public:
	player();
	~player();

	HRESULT init();
	void render();
	void update();
	void release();

	void setStageManagerMemoryAddressLink(stageManager* stageManager) { _stageManager = stageManager; }

	void attack();

	void jumpMove();

	void leftMove();
	void rightMove();
	void upMove();
	void downMove();
	void runTime();//키보드 따닥 시간
	void guard();//플레이어 방어
	void pixelCollision(string stageName);//플레이어 픽셀충돌

	void frameDraw();//프레임 재생
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

	bool keyAttack()
	{
		if (KEYMANAGER->isOnceKeyDown('A')) return true;
		return false;
	}

	bool keyJump()
	{
		if (KEYMANAGER->isOnceKeyDown('D')) return true;
		return false;
	}

	bool keyUltimate()
	{
		if (KEYMANAGER->isOnceKeyDown('F')) return true;
		return false;
	}

	void setComboAttack(bool comboAttack) {  _comboAttack = comboAttack; }
	void setComboAttack2(bool comboAttack2) { _comboAttack2 = comboAttack2; }
	void setCoin(int coin) { _coin += coin; }//돈
	PLAYERDIRECTION getPlayerdirection() { return _playerDirection; }
	float getPlayerX() { return _x; }
	float getPlayerZ() { return _z; }
	int getCoin() { return _coin; }//돈
	MYRECT getPlayerRect() { return _rc; }
	MYRECT getAttackRc() { return _attackRc; }
	MYRECT getComboAttackRc1() { return _comboAttackRc1; }
	MYRECT getComboAttackRc2() { return _comboAttackRc2; }
	bool getIsAttacking() { 
		switch (_playerDirection)
		{
		case PLAYERDIRECTION_RIGHT_COMBO_ATTACK1:
		case PLAYERDIRECTION_LEFT_COMBO_ATTACK1:
		case PLAYERDIRECTION_RIGHT_COMBO_ATTACK2:
		case PLAYERDIRECTION_LEFT_COMBO_ATTACK2:
		case PLAYERDIRECTION_RIGHT_COMBO_ATTACK3:
		case PLAYERDIRECTION_LEFT_COMBO_ATTACK3:
		case PLAYERDIRECTION_RIGHT_ULTIMATE:
		case PLAYERDIRECTION_LEFT_ULTIMATE:
		case PLAYERDIRECTION_RIGHT_STRONG_ATTACK:
		case PLAYERDIRECTION_LEFT_STRONG_ATTACK:
		case PLAYERDIRECTION_RIGHT_JUMP_ATTACK:
		case PLAYERDIRECTION_LEFT_JUMP_ATTACK:
		case PLAYERDIRECTION_RIGHT_DASH_ATTACK:
		case PLAYERDIRECTION_LEFT_DASH_ATTACK:
			return true;
		default:
			return false;
		}
	}

	void playerPosition_1();
	void playerPosition_1at2();
	void playerPosition_2at3();
	void playerPosition_2at1();
	void playerPosition_3at2();
	void playerPosition_3at4();
	void playerPosition_4atBoss();
	void playerPosition_4at3();
	void playerPosition_Bossat4();
};

