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
	PLAYERDIRECTION_LEFT_DASH_ATTACK,

	PLAYERDIRECTION_RIGHT_DEAD,
	PLAYERDIRECTION_LEFT_DEAD,

	PLAYERDIRECTION_RIGHT_HIT,
	PLAYERDIRECTION_LEFT_HIT,
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
	image* _guardImage;//�÷��̾� ��� �̹���
	image* _downImage;//�÷��̾ �ǰ� �������� �ٿ� �̹���
	image* _deadImage;//�÷��̾� ��� �̹���
	image* _hitImage;//�÷��̾� �ǰ� �̹���
	image* _runEffect;//�÷��̾ �޸��� ����� ���� ����Ʈ �̹���


	MYRECT _rc;//�÷��̾� ��Ʈ
	MYRECT _attackRc;//���ݿ����� ����� ��Ʈ
	MYRECT _comboAttackRc1;//1�ܰ� �޺����� ��Ʈ
	MYRECT _comboAttackRc2;//2�ܰ� �޺����� ��Ʈ
	MYRECT _comboAttackRc3;//2�ܰ� �޺����� ��Ʈ

	float _x, _z;//�÷��̾� ������ǥ
	float _walkSpeed;//�ȴ� ���ǵ�
	float _runSpeed;//�޸��� ���ǵ�
	float _jumpPower, _gravity;//�÷��̾� ������

	int _count, _ultimateAfterCount, _index;//�����ӿ� ����� ī��Ʈ, �ε���
	int _time, _clickTime;//�޸��� ���ǹ� �ð�üũ
	int _hp;//�÷��̾� hp
	int _coin;//��

	jump* _jump;//���� ����Ҵ�
	stageManager* _stageManager;//�������� �Ŵ��� ����Ҵ�

	bool _dash;//�÷��̾ �޸��⿡ ����� ��
	bool _jumping;//�����Լ��� ������ ���� ��Ʈ���� ��� ��������ֱ� ���� ��
	bool _attack;//������ ���������� �ƴ��� ����Ȯ�ο� ��
	bool _guard;//�÷��̾� ���
	bool _ultimate;//�ñر�
	bool _comboAttack;//�޺����� �����ӿ� ����� ����
	bool _comboAttack2;//�޺����� 3�ܰ� ���࿩�θ� Ȯ���ϱ� ���� ����
	bool _pixelCollision;//��ֹ� �ȼ��浹 ����
	bool _oneFramePlay;//��Ʈ, �ٿ� �������� set���¸� �ѹ����� �ʱ�ȭ�� �ǰ� �ϱ����� ����� ����
	bool _deadOneFramePlay;//�÷��̾ �׾����� �������� �ʱ�ȭ�� �ѹ��� �ϱ����� �ʿ��� ����
	bool _jumpingHit;//�����߿� ������ �÷��̾��� ��Ʈ��ġ�� �����Ŀ���ŭ ���� �÷��ֱ� ���� �ʿ��� ����

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
	void runTime();//Ű���� ���� �ð�
	void guard();//�÷��̾� ���
	void pixelCollision(string stageName);//�÷��̾� �ȼ��浹

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

	void setComboAttack(bool comboAttack) { _comboAttack = comboAttack; }
	void setComboAttack2(bool comboAttack2) { _comboAttack2 = comboAttack2; }
	void setHitPlayerHP(int hp) { _hp -= hp; }
	void setPlusPlayerHP(int hp) { _hp += hp; }
	void setPlayerAttackRectRemove(int a, int b, int c, int d) { _attackRc.set(0, 0, 0, 0); }
	void setPlayerAttackRectRemove1(int a, int b, int c, int d) { _comboAttackRc1.set(0, 0, 0, 0); }
	void setPlayerAttackRectRemove2(int a, int b, int c, int d) { _comboAttackRc2.set(0, 0, 0, 0); }
	void setPlayerAttackRectRemove3(int a, int b, int c, int d) { _comboAttackRc3.set(0, 0, 0, 0); }
	void setCoin(int coin) { _coin += coin; }//��
	void setPlayerHP(int hp) { _hp = hp; }
	void setPlayerDirection(PLAYERDIRECTION playerDirection) { _playerDirection = playerDirection; }

	PLAYERDIRECTION getPlayerdirection() { return _playerDirection; }
	float getPlayerX() { return _x; }
	float getPlayerZ() { return _z; }
	int getCoin() { return _coin; }//��
	int getPlayerHP() { return _hp; }//hp
	MYRECT getPlayerRect() { return _rc; }
	MYRECT getAttackRc() { return _attackRc; }
	MYRECT getComboAttackRc1() { return _comboAttackRc1; }
	MYRECT getComboAttackRc2() { return _comboAttackRc2; }
	MYRECT getComboAttackRc3() { return _comboAttackRc3; }
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
	bool getIsDead() 
	{
		if (_deadOneFramePlay && (_playerDirection == PLAYERDIRECTION_LEFT_DEAD && _deadImage->getFrameX() == 0 || _playerDirection == PLAYERDIRECTION_RIGHT_DEAD && _deadImage->getFrameX() == _deadImage->getMaxFrameX()))
			return true;
		return false;
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
	void playerPosition_BossStart();
};

