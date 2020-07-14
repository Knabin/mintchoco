#pragma once
#include "gameNode.h"
#include "knight.h"

class ghostNGoblinScene : public gameNode
{
private:
	knight* _knight;

public:
	ghostNGoblinScene();
	~ghostNGoblinScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

