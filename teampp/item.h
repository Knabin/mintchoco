#pragma once
#include "gameNode.h"

class item : public gameNode
{
private:

	image* _itemImage;		//������ �̹���
	MYRECT _rc;				//������ �浹�� ��Ʈ
	float _x, _y;

public:

	item();
	~item();

	HRESULT init(const char * imageName, float x, float y);
	void release();
	void update();
	void render();

	inline MYRECT getRect() { return _rc; }

};

