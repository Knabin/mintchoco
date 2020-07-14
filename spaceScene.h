#pragma once
#include "gameNode.h"
#include "ship.h"

class battle;

class spaceScene : public gameNode
{
private:
	ship* _battle;

public:
	spaceScene();
	~spaceScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

