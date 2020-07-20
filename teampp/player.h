#pragma once
#include "gameNode.h"
#include "jump.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

#define FRAMEPOSX 20

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
	PLAYERDIRECTION_LEFT_COBMO_ATTACK1,

	PLAYERDIRECTION_RIGHT_COMBO_ATTACK2,
	PLAYERDIRECTION_LEFT_COMBO_ATTACK2,

	PLAYERDIRECTION_RIGHT_COMBO_ATTACK3,
	PLAYERDIRECTION_LEFT_COMBO_ATTACK3,

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
	PLAYERDIRECTION _playerDirection;//�÷��̾� ������

	image* _idleImage;//�÷��̾� �⺻ �̹���
	image* _walkImage;//�÷��̾� �ȴ� �̹���
	image* _runImage;//�÷��̾� �޸��� �̹���
	image* _jumpImage;//�÷��̾� ���� �̹���
	image* _comboAttackImage1;//�÷��̾� ���� �̹���
	image* _strongAttackImage;//�÷��̾� ������ �̹���
	image* _shadow;//�׸��� �̹���
	image* _jumpAttackImage;//�÷��̾� ���� ���� �̹���
	image* _dashAttackImage;//�뽬 ���� �̹���

	MYRECT _rc;//�÷��̾� ��Ʈ
	MYRECT _attackRc;//���ݿ����� ����� ��Ʈ

	float _x, _y;//�÷��̾� ������ǥ
	float _walkSpeed;//�ȴ� ���ǵ�
	float _runSpeed;//�޸��� ���ǵ�
	float _jumpPower, _gravity;//�÷��̾� ������
	float _startY;//���� �����ߴ��� ���� Ȯ��

	int _count, _index;//�����ӿ� ����� ī��Ʈ, �ε���
	int _time, _clickTime;//�޸��� ���ǹ� �ð�üũ
	int _hp;//�÷��̾� hp
	int _r, _g, _b;//�ȼ��浹�� rgb
	int _probeX, _probeY;//�ȼ��浹��

	jump* _jump;//���� ����Ҵ�

	bool _dash;//�÷��̾ �޸��⿡ ����� ��
	bool _jumping;//�����Լ��� ������ ���� ��Ʈ���� ��� ��������ֱ� ���� ��
	bool _attack;//������ ���������� �ƴ��� ����Ȯ�ο� ��

public:
	player();
	~player();

	HRESULT init();
	void render();
	void update();
	void release();

	void attack();

	void jumpMove();

	void leftMove();
	void rightMove();
	void upMove();
	void downMove();
	void runTime();//Ű���� ���� �ð�

	void frameDraw();//������ ���
	void hitDamage(int hitDamage) { _hp -= hitDamage; }//�÷��̾ ���� ������

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

	float getPlayerX() { return _x; }
	float getPlayerY() { return _y; }
	MYRECT getPlayerRect() { return _rc; }

};

