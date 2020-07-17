#pragma once
#include "gameNode.h"

class stage3 : public gameNode
{
private:
	image* _pixelCollision;
public:

	stage3() {}
	~stage3(){}

	HRESULT init();
	void release();
	void update();
	void render();

	image* getPixel() { return _pixelCollision; }  
};

