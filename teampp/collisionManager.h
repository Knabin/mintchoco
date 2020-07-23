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

public:
	collisionManager() {}
	~collisionManager() {}
	
	HRESULT init();
	void render();
	void update();
	void release();

	void stagedoor_collision(); //�������� �̵�
	void stagedoor_collision_image(); //�������� �̵� �̹��� ����
	void enemy_collision();//���̶� �÷��̾� �����̶� �浹��
	void npcCollision();
	void player_collision();//�÷��̾�� �� �����̶� �浹��

	void playerHpMinus();	//�浹 �� player hp ����

	void setPlayerMemoryAddressLink(player* player) { _player = player; }
	void setEnemyManagerMemoryAddressLink(enemyManager* enemyManager) { _enemyManager = enemyManager; }
	void setStageManagerMemoryAddressLink(stageManager* stageManager) { _stageManager = stageManager; }
	void setItemManagerMemoryAddressLink(itemManager* itemManager) { _itemManager = itemManager; }
	void setUiManagerMemoryAddressLink(UiManager* uiManager) { _uiManager = uiManager; }
};

