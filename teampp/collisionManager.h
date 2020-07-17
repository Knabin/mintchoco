#pragma once
class player;
class enemyManager;

class collisionManager
{
private:
	player* _player;
	enemyManager* _enemyManager;

	

public:
	collisionManager() {}
	~collisionManager() {}
	
	HRESULT init();
	void render();
	void update();
	void release();

	void setPlayerMemoryAddressLink(player* player) { _player = player; }
	void setEnemyManagerMemoryAddressLink(enemyManager* enemyManager) { _enemyManager = enemyManager; }
};

