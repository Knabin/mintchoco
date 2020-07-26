#pragma once
#include "gameNode.h"

class money : public gameNode
{

private:

	image* _moneyImage;		//�� �̹���
	MYRECT _rc;				//������ �浹�� ��Ʈ
	float _x, _y;

public:

	money();
	~money();

	HRESULT init(const char * imageName, float x, float y);
	void release();
	void update();
	void render();

	inline MYRECT getRect() { return _rc; }

};