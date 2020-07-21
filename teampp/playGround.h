#pragma once
#include "gameNode.h"
#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")
#include "stageManager2.h"
#include "collisionManager.h"
#include "player.h"
#include "enemyManager.h"
#include "UiManager.h"
#include "itemManager.h"

class playGround : public gameNode
{
private:
	stageManager2* _stageManager2;
	player* _player;
	enemyManager* _enemyManager;
	collisionManager* _collisionManager;
	UiManager* _uiManager;
	itemManager* _itemManager;


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

