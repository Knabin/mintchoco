#pragma once
#include "gameNode.h"
#define PLAYERHPPOINT 29

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
	tagUIbar _MiniMap;						  //�̴ϸ�
	tagUIbar _BossHpPoint;					  //����Hp����Ʈ
	tagUIbar _BossHpbar;					  //���� Hp��
	tagUIbar _BossName;						  //���� Name

public:

	UiManager();
	~UiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void MiniMapMove();						//�̴ϸ� �̵� �Լ�
	void PlayerHpMinus();					//PlayerHpPoint ���� �Լ�

};
