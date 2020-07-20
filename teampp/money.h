#pragma once
#include "gameNode.h"

class money : public gameNode
{

private:


public:

	money();
	~money();

	HRESULT init();
	void release();
	void update();
	void render();

};