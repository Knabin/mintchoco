#pragma once

enum OBJECTTYPE
{
	PLAYER,
	ENEMY,
	OBJECT,
	SHADOW
};

struct tagObject
{
	image* image;	// �̹��� ������
	animation* ani;
	HDC hdc;

	int type;

	float x;	// X��ǥ(left)
	float jumpPower;	// jumpPower
	float z;	// Z��ǥ

	int frameX;
	int frameY;
};

class zOrder
{
public:
	static zOrder* getInstance()
	{
		static zOrder instance;
		return &instance;
	}

private:
	zOrder();
	~zOrder();

private:
	vector<tagObject> _vObject;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	// z-order�� ������Ʈ �߰�(�̹���, Ÿ��(0: �÷��̾�, 1: ��, 2: ������Ʈ), ���� x��ǥ, jumpPower��ǥ, z��ǥ(bottom))
	void pushObject(HDC hdc, image* img, int type, float x, float jumpPower, float z);
	// z-order�� ������Ʈ �߰�(�̹��� �̸�, Ÿ��(0: �÷��̾�, 1: ��, 2: ������Ʈ), ���� x��ǥ, y��ǥ, z��ǥ(bottom))
	void pushObject(HDC hdc, const char* imageName, int type, float x, float jumpPower, float z);

	// z-order�� ������Ʈ �߰�(�̹���, ���� ������X, ���� ������Y, Ÿ��(0: �÷��̾�, 1: ��, 2: ������Ʈ), ���� x��ǥ, y��ǥ, z��ǥ(bottom))
	void pushObject(HDC hdc, image* img, float frameX, float frameY, int type, float x, float jumpPower, float z);
	// z-order�� ������Ʈ �߰�(�̹��� �̸�, ���� ������X, ���� ������Y, Ÿ��(0: �÷��̾�, 1: ��, 2: ������Ʈ), ���� x��ǥ, y��ǥ, z��ǥ(bottom))
	void pushObject(HDC hdc, const char* imageName, float frameX, float frameY, int type, float x, float jumpPower, float z);

	// z-order�� ������Ʈ �߰�(�̹���, �ִϸ��̼�, Ÿ��(0: �÷��̾�, 1: ��, 2: ������Ʈ), ���� x��ǥ, y��ǥ, z��ǥ(bottom))
	void pushObject(HDC hdc, image* img, animation* ani, int type, float x, float jumpPower, float z);
	// z-order�� ������Ʈ �߰�(�̹��� �̸�, �ִϸ��̼�, Ÿ��(0: �÷��̾�, 1: ��, 2: ������Ʈ), ���� x��ǥ, y��ǥ, z��ǥ(bottom))
	void pushObject(HDC hdc, const char* imageName, animation* ani, int type, float x, float jumpPower, float z);

	void pushShadowObject(HDC hdc, image* img, int type, float x, float jumpPower, float z);

	void sortVector(int start, int end);
};

