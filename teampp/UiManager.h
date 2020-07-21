#pragma once
#include "gameNode.h"
#define PLAYERHPPOINT 25


class stageManager2;

enum MiniMapState // 미니맵 상태
{
	OPEN = 0,
	CLOSE,
	OPENSTOP,
	CLOSESTOP
};
struct tagUIbar	  //UI 구조체
{
	image* _UIimage;
	RECT _rc;
	float _x, _y;

	MiniMapState _MiniMapState; //미니맵 상태 
};

class UiManager : public gameNode
{
private:
	tagUIbar _PlayerHpPoint[PLAYERHPPOINT];   //Hp포인트
	tagUIbar _PlayerHpBar;					  //Hp바
	tagUIbar _PlayerImage;					  //플레이어 이미지
	tagUIbar _BossHpPoint;					  //보스Hp포인트
	tagUIbar _BossHpbar;					  //보스 Hp바
	tagUIbar _BossName;						  //보스 Name
	tagUIbar _UiCoin;						  //ui창 돈

	tagUIbar _MiniMap;						  //미니맵

	stageManager2* _stageManager2;			//stageManager 전방선언


public:

	UiManager();
	~UiManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void MiniMapMove();						//미니맵 이동 함수
	void PlayerHpMinus();					//PlayerHpPoint 감소 함수


	void setStageManager2MemoryAddressLink(stageManager2* stageManager) { _stageManager2 = stageManager; }

};
