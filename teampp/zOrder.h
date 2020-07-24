#pragma once
#include "singletonBase.h"


enum OBJECTTYPE
{
	PLAYER,
	ENEMY,
	OBJECT,
	SHADOW
};

struct tagObject
{
	image* image;	// 이미지 포인터
	animation* ani;
	HDC hdc;

	int type;

	float x;	// X좌표(left)
	float jumpPower;	// jumpPower
	float z;	// Z좌표

	int frameX;
	int frameY;
};

class zOrder : public singletonBase<zOrder>
{

private:
	vector<tagObject> _vObject;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	// z-order할 오브젝트 추가(이미지, 타입(0: 플레이어, 1: 적, 2: 오브젝트), 중점 x좌표, jumpPower좌표, z좌표(bottom))
	void pushObject(HDC hdc, image* img, int type, float x, float jumpPower, float z);
	// z-order할 오브젝트 추가(이미지 이름, 타입(0: 플레이어, 1: 적, 2: 오브젝트), 중점 x좌표, y좌표, z좌표(bottom))
	void pushObject(HDC hdc, const char* imageName, int type, float x, float jumpPower, float z);

	// z-order할 오브젝트 추가(이미지, 현재 프레임X, 현재 프레임Y, 타입(0: 플레이어, 1: 적, 2: 오브젝트), 중점 x좌표, y좌표, z좌표(bottom))
	void pushObject(HDC hdc, image* img, float frameX, float frameY, int type, float x, float jumpPower, float z);
	// z-order할 오브젝트 추가(이미지 이름, 현재 프레임X, 현재 프레임Y, 타입(0: 플레이어, 1: 적, 2: 오브젝트), 중점 x좌표, y좌표, z좌표(bottom))
	void pushObject(HDC hdc, const char* imageName, float frameX, float frameY, int type, float x, float jumpPower, float z);

	// z-order할 오브젝트 추가(이미지, 애니메이션, 타입(0: 플레이어, 1: 적, 2: 오브젝트), 중점 x좌표, y좌표, z좌표(bottom))
	void pushObject(HDC hdc, image* img, animation* ani, int type, float x, float jumpPower, float z);
	// z-order할 오브젝트 추가(이미지 이름, 애니메이션, 타입(0: 플레이어, 1: 적, 2: 오브젝트), 중점 x좌표, y좌표, z좌표(bottom))
	void pushObject(HDC hdc, const char* imageName, animation* ani, int type, float x, float jumpPower, float z);

	void pushShadowObject(HDC hdc, image* img, int type, float x, float jumpPower, float z);

	void sortVector(int start, int end);
};

