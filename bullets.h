#pragma once
#include "gameNode.h"
#include <vector>

//FULL_OOP(������ü����) �� �����ϴ� �÷�������
//����ü ������ Ŭ������ �ϴ°� �ξ� ���ϳ�...
//�츰 �ƴϾ�...

//�Ѿ˿� ����� ����ü
struct tagBullet
{
	image* bulletImage;		//�Ѿ˿� �� �̹���
	RECT rc;				//�Ѿ˿� �� ��Ʈ
	float x, y;				//���� x, y
	float angle;			//�Ѿ� ����
	float radius;			//�Ѿ� ������
	float speed;			//���ǵ�
	float fireX, fireY;		//�Ѿ� �߻�� ��ġ XY
	bool isFire;			//�߻��ߴ�?
	int count;				//������ �̹����� �� ī��Ʈ
};

//���������δ� �� �� �� �ִ� �Ѿ�
class bullet : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;
public:
	bullet() {};
	~bullet() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);

	void move();
	
	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }

};


//1. �����صΰ� �߻��ϴ� �̜X~ �̜X
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;	//��Ÿ�
public:
	missile() {};
	~missile() {};

	//�ʱ�ȭ �Լ� (�ִ� ���, ��Ÿ��� ��)
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);

	void move();
};


//2. �߻��Ҷ� �����ؼ� ��� �̜X~ �̜X~
class jumo : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	int _bulletMax;
	float _range;
public:
	jumo() {};
	~jumo() {};

	virtual HRESULT init(int missileMax, float range);
	virtual void release();
	virtual void update();
	virtual void render();

	void fire(float x, float y);

	void move();

	void removeJumo(int arrNum);

	vector<tagBullet> getVJumo() { return _vBullet; }
	vector<tagBullet>::iterator getVIJumo() { return _viBullet; }
};