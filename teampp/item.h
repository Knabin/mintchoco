#pragma once
#include "gameNode.h"

class item : public gameNode
{
protected:

	image* ItemImage;
	RECT _rc;
	float _x, _y;

public:

	item();
	~item();

	HRESULT init();
	void release();
	void update();
	void render();

	inline RECT getRect() { return _rc; }

};