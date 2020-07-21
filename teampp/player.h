#pragma once
#include "gameNode.h"
#include "jump.h"
#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

#define FRAMEPOSX 20
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
	PLAYERDIRECTION _playerDirection;//�÷��̾� ������

	image* _idleImage;//�÷��̾� �⺻ �̹���
	image* _walkImage;//�÷��̾� �ȴ� �̹���
	image* _runImage;//�÷��̾� �޸��� �̹���
	image* _jumpImage;//�÷��̾� ���� �̹���
	image* _comboAttackImage1;//�÷��̾� ���� �̹���
	image* _comboAttackImage2;//�÷��̾� ���� �̹���2
	image* _comboAttackImage3;//�÷��̾� ���� �̹���3
	image* _strongAttackImage;//�÷��̾� ������ �̹���
	image* _ultimateImage;//�÷��̾� �ñر� �̹���
	image* _ultimateAfterImage[ULTIMATECOUNT];//�÷��̾� �ñر� �ܻ� �̹���
	image* _shadow;//�׸��� �̹���
	image* _jumpAttackImage;//�÷��̾� ���� ���� �̹���
	image* _dashAttackImage;//�뽬 ���� �̹���

	MYRECT _rc;//�÷��̾� ��Ʈ
	MYRECT _attackRc;//���ݿ����� ����� ��Ʈ
	MYRECT _comboAttackRc1;//1�ܰ� �޺����� ��Ʈ
	MYRECT _comboAttackRc2;//2�ܰ� �޺����� ��Ʈ

	float _x, _y;//�÷��̾� ������ǥ
	float _walkSpeed;//�ȴ� ���ǵ�
	float _runSpeed;//�޸��� ���ǵ�
	float _jumpPower, _gravity;//�÷��̾� ������
	float _startY;//���� �����ߴ��� ���� Ȯ��

	int _count, _ultimateAfterCount, _index;//�����ӿ� ����� ī��Ʈ, �ε���
	int _time, _clickTime;//�޸��� ���ǹ� �ð�üũ
	int _hp;//�÷��̾� hp
	int _r, _g, _b;//�ȼ��浹�� rgb
	int _probeX, _probeY;//�ȼ��浹��

	jump* _jump;//���� ����Ҵ�

	bool _dash;//�÷��̾ �޸��⿡ ����� ��
	bool _jumping;//�����Լ��� ������ ���� ��Ʈ���� ��� ��������ֱ� ���� ��
	bool _attack;//������ ���������� �ƴ��� ����Ȯ�ο� ��
	bool _ultimate;//�ñر�
	bool _comboAttack;//�޺����� �����ӿ� ����� ����
	bool _comboAttack2;//�޺����� 3�ܰ� ���࿩�θ� Ȯ���ϱ� ���� ����

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

	bool keyUltimate()
	{
		if (KEYMANAGER->isOnceKeyDown('F')) return true;
		return false;
	}

	void setComboAttack(bool comboAttack) {  _comboAttack = comboAttack; }
	void setComboAttack2(bool comboAttack2) { _comboAttack2 = comboAttack2; }
	PLAYERDIRECTION getPlayerdirection() { return _playerDirection; }
	float getPlayerX() { return _x; }
	float getPlayerY() { return _y; }
	MYRECT getPlayerRect() { return _rc; }
	MYRECT getAttackRc() { return _attackRc; }
	MYRECT getComboAttackRc1() { return _comboAttackRc1; }
	MYRECT getComboAttackRc2() { return _comboAttackRc2; }
};

