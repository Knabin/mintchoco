#pragma once
#include "ship.h"

class battle : public ship
{
public:
	battle();
	~battle();

	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();

	
	virtual void keyControl();
};

