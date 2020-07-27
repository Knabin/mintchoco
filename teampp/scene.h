#pragma once
#include "gameNode.h"

enum SaveLoadWindowState // 세이브 로드 창 현 위치
{
	W1 = 0,
	W2,
	W3

};

enum PointerState //포인터 렉트 현위치
{
	START = 0,
	QUIT
};

struct tagScene
{
	image* SceneImage;
	RECT _rc;							 //포인터 렉트
	float _x, _y;

	PointerState _PointerState;			 //포인터 렉트 현위치

};
typedef struct tagSaveData
{
	image* saveStage;
	image* saveStageOff;
	int stageNum;
	string mapName;
	string stageName;
	
	tagSaveData()
	{
		saveStage = nullptr;
		saveStageOff = nullptr;
		stageNum = -1;
		mapName = "";
		stageName = "";
	}
} saveData;

class scene : public gameNode
{

private:

	tagScene _MainTitle;		//타이틀 배경
	tagScene _StartQuit;		//타이틀 버튼
	tagScene _Pointer;			//타이틀 포인터
	tagScene _SaveLoadWindow1;  //세이브로드 첫번쨰창
	tagScene _SaveLoadWindow2;  //세이브로드 두번째창

	tagScene _SaveLoadWindow3;  //세이브로드 세번째창

	SaveLoadWindowState _SaveLoadWindowState;

	// ===== 나빈 추가 =====
	vector<saveData> _vData;

	string _mapNoName;
	string _stageNoName;
	// ====================


	bool _GameStart;			//게임 시작중인가?
	bool _Loading;				//로딩 창인가?
	bool _SaveLoading;			//세이브로딩 창인가?	

	int _LoadingCount;			//로딩 카운트

public:

	scene();
	~scene();

	HRESULT init();
	void release();
	void update();
	void render();

	void PointerMove();					         //포인터 이동 함수
	void SaveLoadMove();				         //세이브 로드 창 이동 함수
	void LoadingCountPlus();			//로딩 화면을 각기 다르게 출력해줄 count update 함수
	void GameStart();					//로딩 화면이 끝나면 게임을 시작해라


	void TitleBackGroundDraw(HDC hdc);		     //타이틀화면을 그려라
	void SaveLoadingBackGroundDraw(HDC hdc);     //세이브로딩창 을 그려라
	void LoadingBackGroundDraw(HDC hdc);	     //로딩화면을 그려라


	bool getGameStart() { return _GameStart; }
	bool getLoading() { return _Loading; }
	bool getSaveLoading() { return _SaveLoading; }



	// ===== 나빈 추가 =====
	int getSaveLoadWindowState() { return _SaveLoadWindowState; }
	void setSaveLoadWindowState(int sl) { _SaveLoadWindowState = (SaveLoadWindowState)sl; }

	void getPlayerSaveData();
	void getPlayerSaveData(int slot);

	void setLoading(bool loading) { _Loading = loading; }
	// ====================

};

