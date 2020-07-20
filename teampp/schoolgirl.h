#pragma once
#include "enemy.h"
class schoolgirl : public enemy
{
public:
	schoolgirl();
	~schoolgirl();

	HRESULT init(string imageName, float x, float y, float speed);
	void release();
	void render();
};

