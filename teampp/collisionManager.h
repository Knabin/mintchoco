#pragma once
#include "gameNode.h"
class player;
class enemyManager;
class stageManager;
class itemManager;
class UiManager;


class collisionManager : public gameNode
{
private:
	player* _player;
	enemyManager* _enemyManager;
	stageManager* _stageManager;
	itemManager* _itemManager;
	UiManager* _uiManager;

	image* _attackEffect;//플레이어가 적을 공격할때 적과 충돌시 이펙트 이미지

	float _enemyEffectPosX;//플레이어의 공격이 에너미랑 충돌시 충돌한 에너미의 위치에 뿌려줄 이펙트 위치
	float _enemyEffectPosY;//플레이어의 공격이 에너미랑 충돌시 충돌한 에너미의 위치에 뿌려줄 이펙트 위치
	bool _attackEffectFrame;//플레이어가 적을 공격했을때 생기는 이펙트

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
	void playerAttackHitEffect();//플레이어가 에너미를 공격해서 충돌시 나올 이펙트 이미지

	void setPlayerMemoryAddressLink(player* player) { _player = player; }
	void setEnemyManagerMemoryAddressLink(enemyManager* enemyManager) { _enemyManager = enemyManager; }
	void setStageManagerMemoryAddressLink(stageManager* stageManager) { _stageManager = stageManager; }
	void setItemManagerMemoryAddressLink(itemManager* itemManager) { _itemManager = itemManager; }
	void setUiManagerMemoryAddressLink(UiManager* uiManager) { _uiManager = uiManager; }
};

