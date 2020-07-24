#pragma once
#include "gameNode.h"
#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")
#include "stageManager.h"
#include "collisionManager.h"
#include "player.h"
#include "enemyManager.h"
#include "UiManager.h"
#include "itemManager.h"
#include "scene.h"

class playGround : public gameNode
{
private:
	stageManager* _stageManager;
	player* _player;
	enemyManager* _enemyManager;
	collisionManager* _collisionManager;
	UiManager* _uiManager;
	itemManager* _itemManager;
	scene* _scene;

	// 비디오 관련 변수들
	HWND LogoVideo;
	char movie[20] = "videos/boss.mp4";
	bool _playVideo;


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

