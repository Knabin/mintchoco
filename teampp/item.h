#pragma once
#include "gameNode.h"

class item : public gameNode
{
protected:

	image* ItemImage;
	MYRECT _rc;
	float _x, _y;

public:

	item();
	~item();

	HRESULT init();
	void release();
	void update();
	void render();

	inline MYRECT getRect() { return _rc; }

};