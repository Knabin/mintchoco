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
	ENEMY_LEFT_BACK_MOVE,
	ENEMY_RIGHT_BACK_MOVE,
	ENEMY_LEFT_ATTACK,			//���ʹ� ���ݸ��
	ENEMY_RIGHT_ATTACK,			//���ʹ� ���ݸ��
	ENEMY_LEFT_COMBO1,			//���ʹ� ���ݸ�� 
	ENEMY_RIGHT_COMBO1,			//���ʹ� ���ݸ�� 
	ENEMY_LEFT_COMBO2,			//���ʹ� ���ݸ�� 
	ENEMY_RIGHT_COMBO2,			//���ʹ� ���ݸ�� 
	ENEMY_LEFT_SUBMOTION,		//ġ����� �����, ���л��� ������, ���л��� ����
	ENEMY_RIGHT_SUBMOTION,		//ġ����� �����, ���л��� ������, ���л��� ����
	ENEMY_LEFT_GETHIT,
	ENEMY_RIGHT_GETHIT,
	ENEMY_LEFT_STUN,
	ENEMY_RIGHT_STUN,
	ENEMY_POINT,
	ENEMY_LEFT_DEAD,
	ENEMY_RIGHT_DEAD,
	ENEMY_LEFT_BLOCK,
	ENEMY_RIGHT_BLOCK,
	ENEMY_STUNIMG
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
	animation* _enemyMotion_L_hit;
	animation* _enemyMotion_R_hit;
	animation* _enemyMotion_L_stun;
	animation* _enemyMotion_R_stun;
	animation* _enemyMotion_L_dead;
	animation* _enemyMotion_R_dead;
	animation* _enemyMotion_L_block;
	animation* _enemyMotion_R_block;

	animation* _ani_point;
	animation* _ani_stunImg;


	string _imageName;	//���ʹ� �̹��� ���� ��
	float _x, _y;		//���ʹ� x�� y��
	float _speed;		//���ʹ� ���ǵ�
	float _jumpPower, _gravity;
	int _isAttackCount;	//���ʹ� ���� �����̼ӵ�
	int _isStunCount;	//���ʹ� ���� �ð�
	bool _isJump;
	bool _isStart;
	bool _isPoint;
	bool _isStun;

	MYRECT _rc;			//���ʹ� ��Ʈ
	MYRECT _attackRC;	//���ʹ� ���ݷ�Ʈ

	float _playerX, _playerY;	//�÷��̾� ��ġ �� �������� ����
	float angle;
	float distance;
	float _hp;		//���ʹ�ü��

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
	

	void setPlayerPos(float x, float y);
	void setStageNum(int num) { _stageNum = num; }

	MYRECT& getEnemyAttackRect() { return _attackRC; }
};

