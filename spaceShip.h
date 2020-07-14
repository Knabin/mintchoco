#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

#pragma warning(disable:4996)

//������� ���ӹ����� ���� Ŭ���� ���漱��
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	jumo* _jumo;

	enemyManager* _em;

	progressBar* _hpBar;
	float _currentHP, _maxHP;

	int _alphaValue;

public:
	spaceShip();
	~spaceShip();

	//��Ʈ + ���� -> C -> C -> ����
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//�浹�� �Լ�
	void collision();

	//�ܺο��� �������ִ� �Լ�
	void hitDamage(float damage);

	//���漱�� �� �󲮵��⿡ ������ ã���ֱ����� �޸� ��ũ ������
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	image* getShipImage() { return _ship; }

	//�ָ� �̻��� ������
	jumo* getJumo() { return _jumo; }
};

