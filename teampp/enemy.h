#pragma once
#include "gameNode.h"

enum ENEMYDIRECTION
{
	SIDE,
	UPDOWN,
	FREE
};

class enemy : public gameNode
{
protected:
	image* _imageName;		//���� �̹����� ����Ҳ�
	RECT _rc;				//�浹�� ��Ʈ

	int _currentFrameX;		//������ �̹��� 1�� ������ ���� �ٸ� ������ �����Ϸ���
	int _currentFrameY;

	int _count;				//������ ī��Ʈ ��
	int _fireCount;			//�߻� ī��Ʈ ��
	int _rndFireCount;		//�߻�Ǵ� ������ ��

	ENEMYDIRECTION _direction;

public:
	enemy();
	~enemy();

	HRESULT init();											//�ʱ�ȭ��
	HRESULT init(const char* imageName, POINT position);	//�ʱ�ȭ too
	void release();
	void update();
	void render();

	void move();			//������
	void draw();			//�׷�����

	bool bulletCountFire();	//�Ѿ� Ŭ�������� �߻�Ƕ�� �������ּ���~

	void enemyDirection(int num) { _direction = (ENEMYDIRECTION)num; }
	//��Ʈ ������
	inline RECT getRect() { return _rc; }
};

