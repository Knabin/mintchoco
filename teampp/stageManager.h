#pragma once
#include "gameNode.h"
#include "stage01.h"
#include "stage02.h"
#include "stage03.h"
#include "stage04.h"
#include "bossStage.h"



enum NowStage  //현재 스테이지 상태 정의
{
	S1 = 0,		//스테이지1
	S2,			//스테이지2
	S3,			//스테이지3
	S4,			//스테이지4
	BS			//보스 스테이지
};

enum ChainLockState		// 쇠사슬 좌물쇠 현재 상태 정의
{
	LOCK = 0,
	CLEAR,
	LOCKING,
	CLEARING
};

struct tagLockChain		//스테이지 쇠사슬 자물쇠 구조체
{
	image* _ChainLockImage;
	MYRECT _Mrc;					//쇠사슬 마이렉트
	RECT _rc;						//자물쇠 일반렉트
	float _x, _y;
	int _currentFrameX, _currentFrameY;
};


struct tagBattleStart	//배틀 스타트 구조체
{
	image* _BattleStartImage;
	int _currentFrameX, _currentFrameY;  //배틀 스타트 재생프레임
	int _FrameCount;					 //배틀 스타트 프레임 카운트
};

class stageManager : public gameNode
{
private:

	float _x, _y;
	RECT _rc;

	stage01* _Stage1;
	stage02* _Stage2;
	stage03* _Stage3;
	stage04* _Stage4;
	bossStage* _BossStage;

	image* _currentPixelCollision;  //픽셀이미지

	tagLockChain _ChainLeft;          //왼쪽   쇠사슬
	tagLockChain _ChainRight;         //오른쪽 쇠사슬
	tagLockChain _ChainTop;           //윗쪽   쇠사슬
	tagLockChain _ChainBottom;        //아랫쪽 쇠사슬

	tagLockChain _Lock;				  //자물쇠

	bool _LeftChainShake;
	bool _RightChainShake;
	bool _TopChainShake;
	bool _BottomChainShake;
	
	bool _LockDamage1;				//자물쇠 조금 깨진 상태
	bool _LockDamage2;				//자물쇠 많이 깨진 상태
	bool _LockClear;				//자물쇠 완전 해제 상태
	
	int _LockChainCount;		    //프레임이미지인 자물쇠,쇠사슬 프레임카운트 선언

	int _LockCount;					//일정 카운트마다 자물쇠를 잠궈주는 과정을 보여줌
	int _ClearCount;				//일정 카운트마다 자물쇠를 해제해주는 과정을 보여줌

	ChainLockState _ChainLockState; // 쇠사슬 좌물쇠 현재 상태 정의

	tagBattleStart _BattleStart;	//배틀스타트 구조체
	bool _PlayBattleStart;			//배틀스타트가 재생중인가?


	//플레이어가 각 스테이지 마다 어느 좌표에 접근해 체인락이 걸리는가?
	bool _PlayerStage1ChainLock;	
	bool _PlayerStage2ChainLock;	
	bool _PlayerStage3ChainLock;	
	bool _PlayerStage4ChainLock;	

	bool _PlayerStage1ChainLockAlready;
	bool _PlayerStage2ChainLockAlready;
	bool _PlayerStage3ChainLockAlready;
	bool _PlayerStage4ChainLockAlready;

	//테스트용 체인락 타임
	int _ChainLockTime;

	//현재 스테이지 상태 정의
	NowStage _NowStage;

	//다른 클래스에서 참조하기 위한 스테이지 상태 bool값
	bool _NowStage1;
	bool _NowStage2;
	bool _NowStage3;
	bool _NowStage4;
	bool _NowBossStage;

	//현재 스테이지의 npc를 가지고 있을 vector
	vector<class npc*> _vNpcs;

	// 스테이지에 일정 시간마다 enemy를 spawn하기 위한 int 값
	int _spawnCount;
	float _bossIntroX;

	// 보스 스테이지에서 동영상 재생을 위한 bool값
	bool _canPlayVideo;

	// 체인 락 상태를 풀기 위해 처치한 enemy를 저장하는 int 값
	int _enemyCount;

	class enemyManager* _em;
	class player*		_player;

public:

	stageManager();
	~stageManager();

	HRESULT init();
	void release();
	void update();
	void render();


	//현재 스테이지는 어디인가? swtich문
	void NowStage();
	int getNowStage() { return _NowStage; }


	//현재 스테이지는 여기입니다.
	void Stage1Move();
	void Stage2Move();
	void Stage3Move();
	void Stage4Move();
	void BossStageMove();

	//stagedoor 충돌 시 이미지가 바뀝니다.
	void Stage1_Stage2_Ok();
	void Stage2_Stage3_Ok();
	void Stage2_Stage1_Ok();
	void Stage3_Stage4_Ok();
	void Stage3_Stage2_Ok();
	void Stage4_BossStage_Ok();
	void Stage4_Stage3_Ok();
	void BossStage_Stage4_Ok();
	
	//체인락을 실질적으로 움직이게 하고 그립니다.
	void ChainLockMove();					 
	void ChainLockFrameDraw();				 

	// ===== 나빈 추가 =====
	void plusEnemyCount() { _enemyCount += 1; }

	//각 스테이지 마다 어느 지점에 접근 시 위의 체인락 함수를 실행시킵니다.

	void Stage1ChainLock();					
	void Stage1DoorLockDraw();				

	void Stage2ChainLock();		
	void Stage2DoorLockDraw();				

	void Stage3ChainLock();				
	void Stage3DoorLockDraw();		

	void Stage4ChainLock();			
	void Stage4DoorLockDraw();				

	//배틀 스타트 프레임을 재생시키고 그립니다.
	void PlayBattleStartFrame();		    
	void PlayBattleStartBackGroundDraw(HDC hdc);    

	bool getPlayBattleStart() { return _PlayBattleStart; }
	void setPlayBattleStart(bool playBattleStart) { _PlayBattleStart = playBattleStart; }

	//스테이지 상태 bool값 접근자
	bool getNowstage1() { return _NowStage1; }
	bool getNowstage2() { return _NowStage2; }
	bool getNowstage3() { return _NowStage3; }
	bool getNowstage4() { return _NowStage4; }
	bool getNowbossStage() { return _NowBossStage; }

	//스테이지 이동 문 접근자
	stage01* getVStage1() { return _Stage1; }
	stage02* getVStage2() { return _Stage2; }
	stage03* getVStage3() { return _Stage3; }
	stage04* getVStage4() { return _Stage4; }
	bossStage* getVBossStage() { return _BossStage; }

	image* getPixelImage() { return _currentPixelCollision; } //픽셀이미지 겟

	vector<class npc*>& getNpcVector() { return _vNpcs; }

	void setEnemyManagerMemoryAddressLink(class enemyManager* em) { _em = em; }
	void setPlayerMemoryAddressLink(class player* player) { _player = player; }


	bool getCanPlayVideo() { return _canPlayVideo; }
	void setCanPlayVideo(bool b) { _canPlayVideo = b; if (!b) _BossStage->setIsBroken(b); }

	bool checkBossStageX (float x) 
	{
		if (_canPlayVideo == true) return false;
		if (_NowBossStage && x >= _bossIntroX) 
		{
			setCanPlayVideo(true);
			_BossStage->setIsBroken(true);
			return true;
		}
		return false;
	}
};

