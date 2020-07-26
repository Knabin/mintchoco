#pragma once
#include "gameNode.h"
#include "enemy.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

enum BOSSDIRECTION
{
	BOSS_RIGHT_IDLE, BOSS_LEFT_IDLE,	//���̵�

	BOSS_RIGHT_WALK, BOSS_LEFT_WALK,	//�ȱ�

	BOSS_RIGHT_HIT1, BOSS_LEFT_HIT1,	// �´¸�� 1Ÿ

	BOSS_RIGHT_HIT2, BOSS_LEFT_HIT2,	// �´¸�� 2Ÿ

	BOSS_RIGHT_HIT3, BOSS_LEFT_HIT3,	// �´¸�� 3Ÿ

	BOSS_RIGHT_SLAP, BOSS_LEFT_SLAP,	//�չٴ�ġ��

	BOSS_RIGHT_ELBOW, BOSS_LEFT_ELBOW,	//�Ȳ�ġ���

	BOSS_RIGHT_BLOCK, BOSS_LEFT_BLOCK,	//����

	BOSS_RIGHT_ROAR, BOSS_LEFT_ROAR,	//�Լ�

	BOSS_RIGHT_ROAR_U, BOSS_LEFT_ROAR_U,	//�Ѿ����� �Ͼ�鼭 �Լ� �������� ���

	BOSS_RIGHT_TACKLE, BOSS_LEFT_TACKLE,	// ���ġ�� �غ���

	BOSS_RIGHT_TACKLE_L, BOSS_LEFT_TACKLE_L,	//���ġ�� ���� ���

	BOSS_RIGHT_TAUNT, BOSS_LEFT_TAUNT,	// ��� ���

	BOSS_RIGHT_METEOR, BOSS_LEFT_METEOR,	//���׿� �������µ���

	BOSS_RIGHT_METEOR_G, BOSS_LEFT_METEOR_G,	//���׿� �������� ���ν���

	BOSS_RIGHT_METEOR_C, BOSS_LEFT_METEOR_C,	//���׿� ���ӵ���

	BOSS_RIGHT_METEOR_M, BOSS_LEFT_METEOR_M,	//���׿� ��� ����

	BOSS_RIGHT_METEOR_J, BOSS_LEFT_METEOR_J,	//���׿� �������

	BOSS_RIGHT_METEOR_A, BOSS_LEFT_METEOR_A,	//���׿� ������ ���

	BOSS_RIGHT_WUPUNCH, BOSS_LEFT_WUPUNCH,	//��������ġ

	BOSS_RIGHT_HIT_A, BOSS_LEFT_HIT_A,	// 3Ÿ �°� ���󰥶�

	BOSS_RIGHT_HIT_K, BOSS_LEFT_HIT_K,	// �׳� ���󰥶�

	BOSS_RIGHT_G_HIT, BOSS_LEFT_G_HIT,	// �Ѿ������� ��Ʈ

	BOSS_RIGHT_GETUP_S, BOSS_LEFT_GETUP_S,	//�Ѿ����� �Ͼ�� �����

	BOSS_RIGHT_GETUP_SS, BOSS_LEFT_GETUP_SS,	//�Ѿ����� ����� �Ͼ��

	BOSS_RIGHT_DIZZY, BOSS_LEFT_DIZZY,	//�Ѿ�������

	BOSS_RIGHT_GETUP_C, BOSS_LEFT_GETUP_C, // ����� �Ͼ��

	BOSS_RIGHT_DEFEAT, BOSS_LEFT_DEFEAT // ������ �й�������

};

enum BOSSPHASE //ü�¿� ���� ���� ������ ���п�
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

	BOSSPHASE _bossPhase;	//ü�¿� ���� ���� ������ ���п�

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



	MYRECT _rc; //������ ��Ʈ
	MYRECT _rcA; //���� ������ ��Ʈ

	float _x, _y, _z; //���� ��ǥ��
	float _speed; //���� �̵��ӵ�

	string _imageName; // �����̹����ޱ�

	int _end;
	bool _isAttack;		//���ݽ����ߴ��� üũ
	int _attackCount;	//����ī��Ʈ
	int _attackTime;	//���ݽð�
	int _count;			//������ ī��Ʈ��
	int _index;
	int _loopCount;		//���� ���� ī��Ʈ

	float _angle;
	float _distance;

	float _jumpPower;
	float _gravity;
	bool _isJumping;

	int _random;	//�ٰŸ���
	int _random1;	//���Ÿ���

	float _ys;		//���� ������ ��ġ �����
	int _hp; // ���� HP

public:

	boss();
	~boss();


	virtual HRESULT init(string imageName, float x, float z, float speed);
	virtual void release();
	virtual void update();
	virtual void render();


	BOSSDIRECTION getBossDirection() { return _bossDirection; }
	void setBossDirection(BOSSDIRECTION bossDirection) { _bossDirection = bossDirection; }

	void setBossMotion(animation* bossMotion) { _bossMotion = bossMotion; }

	MYRECT& getBossRect() { return _rc; }
	void setBossRect(MYRECT rc) { _rc = rc; }

	MYRECT& getBossAttackRect() { return _rcA; }
	void setBossAttackRect(int a, int b, int c, int d) { _rcA.set(a, b, c, d); }

	float getBossHP() { return _hp; }
	void setHitBossHP(int hp) { _hp -= hp; }


	// ==========GET �� �´� ��� (�浹ó����)=============

	animation* getBossMotion_R_HIT1() { return _boss_R_HIT1; }
	animation* getBossMotion_L_HIT1() { return _boss_L_HIT1; }
	animation* getBossMotion_R_HIT2() { return _boss_R_HIT2; }
	animation* getBossMotion_L_HIT2() { return _boss_L_HIT2; }
	animation* getBossMotion_R_HIT3() { return _boss_R_HIT3; }
	animation* getBossMotion_L_HIT3() { return _boss_L_HIT3; }
	animation* getBossMotion_R_HIT_A() { return _boss_R_HIT_A; }
	animation* getBossMotion_L_HIT_A() { return _boss_L_HIT_A; }

	animation* getBossMotion_R_G_HIT1() { return _boss_R_G_HIT1; }
	animation* getBossMotion_L_G_HIT1() { return _boss_L_G_HIT1; }



	// ====== ���� ���� =========
	void attackSlap();
	void attackElbow();
	void block();
	void attackWupnch();

	void roar();			// ������ 10
	void tackle();			// ������ 11
	void tackle_loop();		// ������ Ÿ�ݽ� 15 , �ȸ����� 16
	void taunt();

	void meteor_j();		// ������ 12
	void meteor_a();		// ������ 13
	void meteor();			// ������ 14
	void meteor_m();


};