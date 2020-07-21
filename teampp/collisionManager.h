#pragma once
class player;
class enemyManager;
class stageManager2;

class collisionManager
{
private:
	player* _player;
	enemyManager* _enemyManager;
	stageManager2* _stageManager2;

	int _count;

public:
	collisionManager() {}
	~collisionManager() {}
	
	HRESULT init();
	void render();
	void update();
	void release();

	void stagedoor_collision(); //스테이지 이동
	void stagedoor_collision_image(); //스테이지 이동 이미지 변경
	void enemy_collision();//적이랑 플레이어 공격이랑 충돌시

	void setPlayerMemoryAddressLink(player* player) { _player = player; }
	void setEnemyManagerMemoryAddressLink(enemyManager* enemyManager) { _enemyManager = enemyManager; }
	void setStageManager2MemoryAddressLink(stageManager2* stageManager) { _stageManager2 = stageManager; }
};

