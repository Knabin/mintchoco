#pragma once
#include "gameNode.h"
class player;
class enemyManager;
class stageManager;
class itemManager;
class UiManager;
class boss;


class collisionManager : public gameNode
{
private:
	player* _player;
	enemyManager* _enemyManager;
	stageManager* _stageManager;
	itemManager* _itemManager;
	UiManager* _uiManager;
	boss* _boss;

	image* _attackEffect;//�÷��̾ ���� �����Ҷ� ���� �浹�� ����Ʈ �̹���

	float _enemyEffectPosX;//�÷��̾��� ������ ���ʹ̶� �浹�� �浹�� ���ʹ��� ��ġ�� �ѷ��� ����Ʈ ��ġ
	float _enemyEffectPosY;//�÷��̾��� ������ ���ʹ̶� �浹�� �浹�� ���ʹ��� ��ġ�� �ѷ��� ����Ʈ ��ġ
	bool _attackEffectFrame;//�÷��̾ ���� ���������� ����� ����Ʈ

	int _count;
	int _enemyCollisionCount;
	int _enemyCollisionCount1;
	int _enemyCollisionCount2;
	int _enemyCollisionCount3;

	int _bossCollisionCount;
	int _bossCollisionCount1;
	int _bossCollisionCount2;
	int _bossCollisionCount3;

public:
	collisionManager() {}
	~collisionManager() {}

	HRESULT init();
	void render();
	void update();
	void release();

	void stagedoor_collision(); //�������� �̵�
	void stagedoor_collision_image(); //�������� �̵� �̹��� ����
	void enemy_collisionNoBlock();//���̶� �÷��̾� �����̶� �浹��
	void enemy_collisionLeftBlock();
	void enemy_collisionRightBlock();
	void npcCollision();
	void player_collision();//�÷��̾�� �� �����̶� �浹��
	void item_drop();		//���ʹ� ��� �� ������ ���
	void item_collision();	//������ ���� ��� (ü�� 5�� ȸ��)
	void money_collision(); // �� ���� ���	  (10���� ȹ��)

	void boss_collisionNoBlock();
	void boss_collisionLeftBlock();
	void boss_collisionRightBlock();
	void player_bossCollision();

	void playGetHitSound();
	void playPlayerGetHitSound();
	void playerAttackHitEffect();


	void setPlayerMemoryAddressLink(player* player) { _player = player; }
	void setEnemyManagerMemoryAddressLink(enemyManager* enemyManager) { _enemyManager = enemyManager; }
	void setStageManagerMemoryAddressLink(stageManager* stageManager) { _stageManager = stageManager; }
	void setItemManagerMemoryAddressLink(itemManager* itemManager) { _itemManager = itemManager; }
	void setUiManagerMemoryAddressLink(UiManager* uiManager) { _uiManager = uiManager; }
};

