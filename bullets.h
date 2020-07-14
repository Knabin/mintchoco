#pragma once
#include "gameNode.h"
#include <vector>

//FULL_OOP(완전객체지향) 이 제공하는 플랫폼에선
//구조체 쓸빠야 클래스로 하는게 훨씬 편하나...
//우린 아니야...

//총알에 사용할 구조체
struct tagBullet
{
	image* bulletImage;		//총알에 쓸 이미지
	RECT rc;				//총알에 쓸 렉트
	float x, y;				//중점 x, y
	float angle;			//총알 각도
	float radius;			//총알 반지름
	float speed;			//스피드
	float fireX, fireY;		//총알 발사된 위치 XY
	bool isFire;			//발사했누?
	int count;				//프레임 이미지에 쓸 카운트
};

//공용적으로다 다 쓸 수 있는 총알
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


//1. 생성해두고 발사하는 미쏼~ 미쏼
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;	//사거리
public:
	missile() {};
	~missile() {};

	//초기화 함수 (최대 몇발, 사거리는 얼마)
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y);

	void move();
};


//2. 발사할때 생성해서 쏘는 미쏼~ 미쏼~
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