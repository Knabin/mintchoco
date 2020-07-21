#pragma once
#include "gameNode.h"
#define PLAYERHPPOINT 25


class stageManager2;

enum MiniMapState // �̴ϸ� ����
{
	OPEN = 0,
	CLOSE,
	OPENSTOP,
	CLOSESTOP
};
struct tagUIbar	  //UI ����ü
{
	image* _UIimage;
	RECT _rc;
	float _x, _y;

	MiniMapState _MiniMapState; //�̴ϸ� ���� 
};

class UiManager : public gameNode
{
private:
	tagUIbar _PlayerHpPoint[PLAYERHPPOINT];   //Hp����Ʈ
	tagUIbar _PlayerHpBar;					  //Hp��
	tagUIbar _PlayerImage;					  //�÷��̾� �̹���
	tagUIbar _BossHpPoint;					  //����Hp����Ʈ
	tagUIbar _BossHpbar;					  //���� Hp��
	tagUIbar _BossName;						  //���� Name
	tagUIbar _UiCoin;						  //uiâ ��

	tagUIbar _MiniMap;						  //�̴ϸ�

	stageManager2* _stageManager2;			//stageManager ���漱��


public:

	UiManager();
	~UiManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void MiniMapMove();						//�̴ϸ� �̵� �Լ�
	void PlayerHpMinus();					//PlayerHpPoint ���� �Լ�


	void setStageManager2MemoryAddressLink(stageManager2* stageManager) { _stageManager2 = stageManager; }

};
