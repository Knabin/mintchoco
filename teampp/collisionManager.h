#pragma once
class player;
class enemyManager;
class stageManager;
class itemManager;
class UiManager;


class collisionManager
{
private:
	player* _player;
	enemyManager* _enemyManager;
	stageManager* _stageManager;
	itemManager* _itemManager;
	UiManager* _uiManager;

	int _count;
	int _enemyCollisionCount;
	int _enemyCollisionCount1;
	int _enemyCollisionCount2;
	int _enemyCollisionCount3;

public:
	collisionManager() {}
	~collisionManager() {}

	HRESULT init();
	void render();
	void update();
	void release();

	void stagedoor_collision(); //스테이지 이동
	void stagedoor_collision_image(); //스테이지 이동 이미지 변경
	void enemy_collisionNoBlock();//적이랑 플레이어 공격이랑 충돌시
	void enemy_collisionLeftBlock();
	void enemy_collisionRightBlock();
	void npcCollision();
	void player_collision();//플레이어랑 적 공격이랑 충돌시
	void item_drop();		//에너미 사망 시 아이템 드랍
	void item_collision();	//아이템 먹을 경우 (체력 5씩 회복)
	void money_collision(); // 돈 먹을 경우	  (10원씩 획득)

	void setPlayerMemoryAddressLink(player* player) { _player = player; }
	void setEnemyManagerMemoryAddressLink(enemyManager* enemyManager) { _enemyManager = enemyManager; }
	void setStageManagerMemoryAddressLink(stageManager* stageManager) { _stageManager = stageManager; }
	void setItemManagerMemoryAddressLink(itemManager* itemManager) { _itemManager = itemManager; }
	void setUiManagerMemoryAddressLink(UiManager* uiManager) { _uiManager = uiManager; }
};

