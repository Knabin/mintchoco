#pragma once
#include "gameNode.h"
#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

class playGround : public gameNode
{
private:

	
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

