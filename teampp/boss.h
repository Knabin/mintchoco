#pragma once
#include "gameNode.h"

class boss : public  gameNode
{
private:


public:

	HRESULT init();
	void release();
	void update();
	void render();

};

