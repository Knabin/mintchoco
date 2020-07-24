#pragma once
#include "gameNode.h"
#include "enemy.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

enum BOSSDIRECTION
{
	BOSS_RIGHT_IDLE,
	BOSS_LEFT_IDLE,

	BOSS_RIGHT_WALK,
	BOSS_LEFT_WALK,

	BOSS_RIGHT_HIT,
	BOSS_LEFT_HIT,

	BOSS_RIGHT_SLAP,
	BOSS_LEFT_SLAP,

	BOSS_RIGHT_ELBOW,
	BOSS_LEFT_ELBOW,

	BOSS_RIGHT_BLOCK,
	BOSS_LEFT_BLOCK,

	BOSS_RIGHT_ROAR,
	BOSS_LEFT_ROAR,

	BOSS_RIGHT_ROAR_U,
	BOSS_LEFT_ROAR_U,

	BOSS_RIGHT_TACKLE,
	BOSS_LEFT_TACKLE,

	BOSS_RIGHT_TACKLE_L,
	BOSS_LEFT_TACKLE_L,

	BOSS_RIGHT_TAUNT,
	BOSS_LEFT_TAUNT,

	BOSS_RIGHT_METEOR,
	BOSS_LEFT_METEOR,

	BOSS_RIGHT_METEOR_G,
	BOSS_LEFT_METEOR_G,

	BOSS_RIGHT_METEOR_C,
	BOSS_LEFT_METEOR_C,

	BOSS_RIGHT_METEOR_M,
	BOSS_LEFT_METEOR_M,

	BOSS_RIGHT_METEOR_J,
	BOSS_LEFT_METEOR_J,

	BOSS_RIGHT_METEOR_A,
	BOSS_LEFT_METEOR_A,

	BOSS_RIGHT_WUPUNCH,
	BOSS_LEFT_WUPUNCH
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

	BOSSDIRECTION _bossDirection;

	animation* _bossMotion;
	animation* _boss_R_IDLE;
	animation* _boss_L_IDLE;
	animation* _boss_R_WALK;
	animation* _boss_L_WALK;
	animation* _boss_R_HIT;
	animation* _boss_L_HIT;
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

public:

	boss();
	~boss();


	virtual HRESULT init(string imageName, float x, float z, float speed);
	virtual void release();
	virtual void update();
	virtual void render();

};

