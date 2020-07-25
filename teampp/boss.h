#pragma once
#include "gameNode.h"
#include "enemy.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

enum BOSSDIRECTION
{
	BOSS_RIGHT_IDLE, BOSS_LEFT_IDLE,	//아이들

	BOSS_RIGHT_WALK, BOSS_LEFT_WALK,	//걷기

	BOSS_RIGHT_HIT1, BOSS_LEFT_HIT1,	// 맞는모션 1타

	BOSS_RIGHT_HIT2, BOSS_LEFT_HIT2,	// 맞는모션 2타

	BOSS_RIGHT_HIT3, BOSS_LEFT_HIT3,	// 맞는모션 3타

	BOSS_RIGHT_SLAP, BOSS_LEFT_SLAP,	//손바닥치기

	BOSS_RIGHT_ELBOW, BOSS_LEFT_ELBOW,	//팔꿈치찍기

	BOSS_RIGHT_BLOCK, BOSS_LEFT_BLOCK,	//막기

	BOSS_RIGHT_ROAR, BOSS_LEFT_ROAR,	//함성

	BOSS_RIGHT_ROAR_U, BOSS_LEFT_ROAR_U,	//넘어지고 일어나면서 함성 지르기전 모션

	BOSS_RIGHT_TACKLE, BOSS_LEFT_TACKLE,	// 어깨치기 준비모션

	BOSS_RIGHT_TACKLE_L, BOSS_LEFT_TACKLE_L,	//어깨치기 루프 모션

	BOSS_RIGHT_TAUNT, BOSS_LEFT_TAUNT,	// 놀리는 모션

	BOSS_RIGHT_METEOR, BOSS_LEFT_METEOR,	//메테오 떨어지는동작

	BOSS_RIGHT_METEOR_G, BOSS_LEFT_METEOR_G,	//메테오 떨어지고 본인스턴

	BOSS_RIGHT_METEOR_C, BOSS_LEFT_METEOR_C,	//메테오 연속동작

	BOSS_RIGHT_METEOR_M, BOSS_LEFT_METEOR_M,	//메테오 찍고 스턴

	BOSS_RIGHT_METEOR_J, BOSS_LEFT_METEOR_J,	//메테오 점프모션

	BOSS_RIGHT_METEOR_A, BOSS_LEFT_METEOR_A,	//메테오 점프중 모션

	BOSS_RIGHT_WUPUNCH, BOSS_LEFT_WUPUNCH,	//존나쌘펀치

	BOSS_RIGHT_HIT_A, BOSS_LEFT_HIT_A,	// 3타 맞고 날라갈때

	BOSS_RIGHT_HIT_K, BOSS_LEFT_HIT_K,	// 그냥 날라갈때

	BOSS_RIGHT_G_HIT, BOSS_LEFT_G_HIT,	// 넘어졌을때 히트

	BOSS_RIGHT_GETUP_S, BOSS_LEFT_GETUP_S,	//넘어지고 일어날때 땅찍기

	BOSS_RIGHT_GETUP_SS, BOSS_LEFT_GETUP_SS,	//넘어지고 땅찍고 일어나기

	BOSS_RIGHT_DIZZY, BOSS_LEFT_DIZZY,	//넘어졌을때

	BOSS_RIGHT_GETUP_C, BOSS_LEFT_GETUP_C, // 땅찍고 일어날때

	BOSS_RIGHT_DEFEAT, BOSS_LEFT_DEFEAT // 보스가 패배했을때

};

enum BOSSPHASE //체력에 따른 보스 페이즈 구분용
{
	PHASE1,
	PHASE2,
	PHASE3
};

class boss : public enemy
{
private:

	image* _bossImg;
	image* _bossIdle;
	image* _bossWalk;
	image* _bossHit;
	image* _bossSlap;
	image* _bossElbow;
	image* _bossBlock;
	image* _bossRoar;
	image* _bossRoar_u;
	image* _bossTackle;
	image* _bossTackle_l;
	image* _bossTaunt;
	image* _bossMeteor;
	image* _bossMeteor_g;
	image* _bossMeteor_c;
	image* _bossMeteor_m;
	image* _bossMeteor_j;
	image* _bossMeteor_a;
	image* _bossWupunch;
	image* _bossHit_a;
	image* _bossHit_k;
	image* _bossG_hit;
	image* _bossGetup_s;
	image* _bossGetup_ss;
	image* _bossDizzy;
	image* _bossGetup_c;
	image* _bossDefeat;

	BOSSPHASE _bossPhase;	//체력에 따른 보스 페이즈 구분용

	BOSSDIRECTION _bossDirection;

	animation* _bossMotion;
	animation* _boss_R_IDLE;
	animation* _boss_L_IDLE;
	animation* _boss_R_WALK;
	animation* _boss_L_WALK;
	animation* _boss_R_HIT1;
	animation* _boss_L_HIT1;
	animation* _boss_R_HIT2;
	animation* _boss_L_HIT2;
	animation* _boss_R_HIT3;
	animation* _boss_L_HIT3;
	animation* _boss_R_SLAP;
	animation* _boss_L_SLAP;
	animation* _boss_R_ELBOW;
	animation* _boss_L_ELBOW;
	animation* _boss_R_BLOCK;
	animation* _boss_L_BLOCK;
	animation* _boss_R_ROAR;
	animation* _boss_L_ROAR;
	animation* _boss_R_ROAR_U;
	animation* _boss_L_ROAR_U;
	animation* _boss_R_TACKLE;
	animation* _boss_L_TACKLE;
	animation* _boss_R_TACKLE_L;
	animation* _boss_L_TACKLE_L;
	animation* _boss_R_TAUNT;
	animation* _boss_L_TAUNT;
	animation* _boss_R_METEOR;
	animation* _boss_L_METEOR;
	animation* _boss_R_METEOR_G;
	animation* _boss_L_METEOR_G;
	animation* _boss_R_METEOR_C;
	animation* _boss_L_METEOR_C;
	animation* _boss_R_METEOR_M;
	animation* _boss_L_METEOR_M;
	animation* _boss_R_METEOR_J;
	animation* _boss_L_METEOR_J;
	animation* _boss_R_METEOR_A;
	animation* _boss_L_METEOR_A;
	animation* _boss_R_WUPUNCH;
	animation* _boss_L_WUPUNCH;
	animation* _boss_R_HIT_A;
	animation* _boss_L_HIT_A;
	animation* _boss_R_HIT_K;
	animation* _boss_L_HIT_K;
	animation* _boss_R_G_HIT1;
	animation* _boss_L_G_HIT1;
	animation* _boss_R_G_HIT2;
	animation* _boss_L_G_HIT2;
	animation* _boss_R_GETUP_S;
	animation* _boss_L_GETUP_S;
	animation* _boss_R_GETUP_SS;
	animation* _boss_L_GETUP_SS;
	animation* _boss_R_DIZZY;
	animation* _boss_L_DIZZY;
	animation* _boss_R_GETUP_C;
	animation* _boss_L_GETUP_C;
	animation* _boss_R_DEFEAT;
	animation* _boss_L_DEFEAT;



	MYRECT _rc; //보스용 렉트
	MYRECT _rcA; //공격 범위용 렉트

	float _x, _y, _z; //보스 좌표용
	float _speed; //보스 이동속도

	string _imageName; // 보스이미지받기

	int _end;
	bool _isAttack;		//공격실행했는지 체크
	int _attackCount;	//공격카운트
	int _attackTime;	//공격시간
	int _count;			//프레임 카운트용
	int _index;
	int _loopCount;		//공격 루프 카운트

	float _angle;
	float _distance;

	float _jumpPower;
	float _gravity;
	bool _isJumping;

	int _random;	//근거리용
	int _random1;	//원거리용

	float _ys;		//보스 점프시 위치 저장용
	int _hp; // 보스 HP

public:

	boss();
	~boss();


	virtual HRESULT init(string imageName, float x, float z, float speed);
	virtual void release();
	virtual void update();
	virtual void render();


	BOSSDIRECTION getBossDirection() { return _bossDirection; }
	void setBossDirection(BOSSDIRECTION bossDirection) { _bossDirection = bossDirection; }

	MYRECT& getBossRect() { return _rc; }
	void setBossRect(MYRECT rc) { _rc = rc; }

	MYRECT& getBossAttackRect() { return _rcA; }
	void setBossAttackRect(int a, int b, int c, int d) { _rcA.set(a, b, c, d); }



	// ==========GET 쳐 맞는 모션 (충돌처리용)=============

	animation* getBossMotion_R_HIT1() { return _boss_R_HIT1; }
	animation* getBossMotion_L_HIT1() { return _boss_L_HIT1; }
	animation* getBossMotion_R_HIT2() { return _boss_R_HIT2; }
	animation* getBossMotion_L_HIT2() { return _boss_L_HIT2; }
	animation* getBossMotion_R_HIT3() { return _boss_R_HIT3; }
	animation* getBossMotion_L_HIT3() { return _boss_L_HIT3; }

	animation* getBossMotion_R_G_HIT1() { return _boss_R_G_HIT1; }
	animation* getBossMotion_L_G_HIT1() { return _boss_L_G_HIT1; }



	// ====== 공격 패턴 =========
	void attackSlap();
	void attackElbow();
	void block();
	void attackWupnch();

	void roar();			// 랜덤값 10
	void tackle();			// 랜덤값 11
	void tackle_loop();		// 랜덤값 타격시 15 , 안맞으면 16
	void taunt();

	void meteor_j();		// 랜덤값 12
	void meteor_a();		// 랜덤값 13
	void meteor();			// 랜덤값 14
	void meteor_m();


};

