#pragma once
#include "enemy.h"

class schoolboy : public enemy
{
private:

public:
	schoolboy();
	~schoolboy();

	HRESULT init(string imageName, float x, float y, float speed);
	void release();
	void render();
};

