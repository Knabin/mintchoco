#pragma once
#include "gameNode.h"

class stage2 : public gameNode
{
private:
	image* _pixelCollision;
public:

	stage2() {}
	~stage2() {}

	HRESULT init();
	void release();
	void update();
	void render();

	image* getPixel() { return _pixelCollision; }
};

