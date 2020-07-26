#pragma once
#include "gameNode.h"

class item : public gameNode
{
private:

	image* _itemImage;		//아이템 이미지
	MYRECT _rc;				//아이템 충돌용 렉트
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

