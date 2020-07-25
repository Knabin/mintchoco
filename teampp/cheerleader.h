#pragma once
#include "enemy.h"

class cheerleader :public enemy
{
private:

public:
	cheerleader();
	~cheerleader();

	HRESULT init(string imageName, float x, float y, float speed);
	void release();
	void render();
};

