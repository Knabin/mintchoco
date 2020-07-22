#pragma once
#include "gameNode.h"
#include "stage01.h"
#include "stage02.h"
#include "stage03.h"


enum NowStage  //현재 스테이지 상태 정의
{
	S1 = 0,		//스테이지1
	S2,			//스테이지2
	S3			//스테이지3
};

struct tagMiniMap
{
	image* _MiniMapImage;
	RECT _rc;
	float _x, _y;
};

class stageManager : public gameNode
{
private:

	stage01* _Stage1;
	stage02* _Stage2;
	stage03* _Stage3;

	image* _currentPixelCollision;  //픽셀이미지

	//현재 스테이지 상태 정의
	NowStage _NowStage;

	//playground에서 참조하기 위한 스테이지 상태 bool값
	bool _NowStage1;
	bool _NowStage2;
	bool _NowStage3;

	//현재 스테이지의 npc를 가지고 있을 vector
	vector<class npc*> _vNpcs;

	// 스테이지에 일정 시간마다 enemy를 spawn하기 위한 int 값
	int _spawnCount;

	class enemyManager* _em;

public:

	stageManager();
	~stageManager();

	HRESULT init();
	void release();
	void update();
	void render();


	//현재 스테이지는 어디인가? swtich문
	void NowStage();


	//현재 스테이지는 여기입니다.
	void Stage1Move();
	void Stage2Move();
	void Stage3Move();

	//stagedoor 충돌 시 이미지가 바뀝니다.
	void Stage1_Stage2_Ok();
	void Stage2_Stage3_Ok();
	void Stage2_Stage1_Ok();
	void Stage3_Stage2_Ok();


	//스테이지 상태 bool값 접근자
	bool getNowstage1() { return _NowStage1; }
	bool getNowstage2() { return _NowStage2; }
	bool getNowstage3() { return _NowStage3; }

	//스테이지 상태 enum(int) 접근자
	int getNowStage() { return _NowStage; }


	//스테이지 이동 문 접근자
	stage01* getVStage1() { return _Stage1; }
	stage02* getVStage2() { return _Stage2; }
	stage03* getVStage3() { return _Stage3; }

	image* getPixelImage() { return _currentPixelCollision; } //픽셀이미지 겟

	vector<class npc*>& getNpcVector() { return _vNpcs; }

	void setEnemyManagerMemoryAddressLink(class enemyManager* em) { _em = em; }

};

