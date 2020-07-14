#pragma once
#include "gameNode.h"
#include "minion.h"
#include "bullets.h"
#include <vector>

//������� ���ӹ����� ���� Ŭ���� ���漱��
class spaceShip;

class enemyManager : public gameNode
{
private:
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	bullet* _bullet;

	spaceShip* _ship;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setMinion();

	void minionBulletFire();

	void removeMinion(int arrNum);

	//�浹�Լ�
	void collision();

	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _ship = ship; }

	vector<enemy*> getVMinion() { return _vMinion; }
	vector<enemy*>::iterator getVIMinion() { return _viMinion; }

};

