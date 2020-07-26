#pragma once
#include "gameNode.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

enum ENEMYDIRECTION
{
	ENEMY_LEFT_IDLE,			ENEMY_RIGHT_IDLE,
	ENEMY_LEFT_MOVE,			ENEMY_RIGHT_MOVE,
	ENEMY_LEFT_BACK_MOVE,		ENEMY_RIGHT_BACK_MOVE,
	ENEMY_LEFT_ATTACK,			//���ʹ� ���ݸ��
	ENEMY_RIGHT_ATTACK,			//���ʹ� ���ݸ��
	ENEMY_LEFT_COMBO1,			//���ʹ� ���ݸ�� 
	ENEMY_RIGHT_COMBO1,			//���ʹ� ���ݸ�� 
	ENEMY_LEFT_COMBO2,			//���ʹ� ���ݸ�� 
	ENEMY_RIGHT_COMBO2,			//���ʹ� ���ݸ�� 
	ENEMY_LEFT_SUBMOTION,		//���ʹ� ������ ġ����� �����, ���л��� ������, ���л��� ��ű
	ENEMY_RIGHT_SUBMOTION,		//���ʹ� ������ ġ����� �����, ���л��� ������, ���л��� ��ű
	ENEMY_LEFT_GETHIT_1,		ENEMY_RIGHT_GETHIT_1,
	ENEMY_LEFT_GETHIT_2,		ENEMY_RIGHT_GETHIT_2,
	ENEMY_LEFT_GETHIT_3,		ENEMY_RIGHT_GETHIT_3,
	ENEMY_LEFT_STUN,			ENEMY_RIGHT_STUN,
	ENEMY_POINT,
	ENEMY_LEFT_DEAD,			ENEMY_RIGHT_DEAD,
	ENEMY_LEFT_BLOCK,			ENEMY_RIGHT_BLOCK,
	ENEMY_STUNIMG,
	ENEMY_LEFT_RUN,				ENEMY_RIGHT_RUN,
	ENEMY_LEFT_BACKDOWN,		ENEMY_RIGHT_BACKDOWN,
};

class enemy : public gameNode
{
protected:
	image* _enemyImg;
	image* _idle;
	image* _move;
	image* _attack;		//���ʹ� ���ݸ��
	image* _combo1;		//���ʹ� ���ݸ��
	image* _combo2;		//���ʹ� ���ݸ��
	image* _submotion;	//ġ����� �����, ���л��� ������, ���л��� ����
	image* _gethit;
	image* _stun;
	image* _dead;
	image* _block;
	image* _run;
	image* _backdown;
	
	image* _point;
	image* _stunImg;

	//image* _ehit;

	animation* _enemyMotion;
	animation* _enemyMotion_L_idle;
	animation* _enemyMotion_R_idle;
	animation* _enemyMotion_L;
	animation* _enemyMotion_R;
	animation* _enemyMotion_L_back;
	animation* _enemyMotion_R_back;
	animation* _enemyMotion_L_A;
	animation* _enemyMotion_R_A;
	animation* _enemyMotion_L_combo1;
	animation* _enemyMotion_R_combo1;
	animation* _enemyMotion_L_combo2;
	animation* _enemyMotion_R_combo2;
	animation* _enemyMotion_L_submotion;
	animation* _enemyMotion_R_submotion;
	animation* _enemyMotion_L_hit_1;
	animation* _enemyMotion_R_hit_1;
	animation* _enemyMotion_L_hit_2;
	animation* _enemyMotion_R_hit_2;
	animation* _enemyMotion_L_hit_3;
	animation* _enemyMotion_R_hit_3;
	animation* _enemyMotion_L_stun;
	animation* _enemyMotion_R_stun;
	animation* _enemyMotion_L_dead;
	animation* _enemyMotion_R_dead;
	animation* _enemyMotion_L_block;
	animation* _enemyMotion_R_block;
	animation* _enemyMotion_L_run;
	animation* _enemyMotion_R_run;
	animation* _enemyMotion_L_backdown;
	animation* _enemyMotion_R_backdown;

	animation* _ani_point;
	animation* _ani_stunImg;


	string _imageName;	//���ʹ� �̹��� ���� ��
	float _x, _y;		//���ʹ� x�� y��
	float _speed;		//���ʹ� ���ǵ�
	float _jumpPower, _gravity;
	float _playerX, _playerY;	//�÷��̾� ��ġ �� �������� ����
	float angle;
	float distance;
	int _hp;		//���ʹ�ü��

	int _isAttackCount;	//���ʹ� ���� �����̼ӵ�
	int _isStunCount;	//���ʹ� ���� �ð�
	int _attackPower;

	bool _isJump;
	bool _isStart;
	bool _isPoint;
	bool _isStun;
	bool _enemyDead;
	bool _isDown;
	
	MYRECT _rc;			//���ʹ� ��Ʈ
	MYRECT _attackRC;	//���ʹ� ���ݷ�Ʈ

	ENEMYDIRECTION _direction;

	int _random;
	int _stageNum;

private:


public:
	enemy();
	~enemy();

	virtual HRESULT init(string imageName, float x, float y, float speed);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void pixel(string stageName);
	//virtual void hit();

	float getHP() { return _hp; }
	inline bool getEnemyDead() { return _enemyDead; }
	ENEMYDIRECTION getEnemyDirection() { return _direction; }
	animation* getEnemyMotion_L_hit_1() { return _enemyMotion_L_hit_1; }
	animation* getEnemyMotion_R_hit_1() { return _enemyMotion_R_hit_1; }
	animation* getEnemyMotion_L_hit_2() { return _enemyMotion_L_hit_2; }
	animation* getEnemyMotion_R_hit_2() { return _enemyMotion_R_hit_2; }
	animation* getEnemyMotion_L_hit_3() { return _enemyMotion_L_hit_3; }
	animation* getEnemyMotion_R_hit_3() { return _enemyMotion_R_hit_3; }
	animation* getEnemyMotion_L_backdown() { return _enemyMotion_L_backdown; }
	animation* getEnemyMotion_R_backdown() { return _enemyMotion_R_backdown; }
	
	void setHitEnemyHP(int hp) { _hp -= hp; }
	void setPlayerPos(float x, float y);
	void setStageNum(int num) { _stageNum = num; }
	void setEnemyDead(bool enemyDead) { _enemyDead = enemyDead; }
	void setEnemyDirection(ENEMYDIRECTION enemyDirection) { _direction = enemyDirection; }
	void setEnemyMotion(animation* enemyMotion) { _enemyMotion = enemyMotion; }
	void setEnemyPosition(float x, float y) { _x = x; _y = y; }

	MYRECT& getEnemyRect() { return _rc; }
	void setEnemyRect(MYRECT rc) { _rc = rc; }
	
	MYRECT& getEnemyAttackRect() { return _attackRC; }
	void setEnemyAttackRect(int a,int b,int c,int d) { _attackRC.set(a, b, c, d); }

	
};

