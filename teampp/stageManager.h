#pragma once
#include "gameNode.h"
#include "stage01.h"
#include "stage02.h"
#include "stage03.h"
#include "stage04.h"
#include "bossStage.h"



enum NowStage  //���� �������� ���� ����
{
	S1 = 0,		//��������1
	S2,			//��������2
	S3,			//��������3
	S4,			//��������4
	BS			//���� ��������
};

enum ChainLockState		// ��罽 �¹��� ���� ���� ����
{
	LOCK = 0,
	CLEAR,
	LOCKING,
	CLEARING
};

struct tagLockChain		//�������� ��罽 �ڹ��� ����ü
{
	image* _ChainLockImage;
	MYRECT _Mrc;					//��罽 ���̷�Ʈ
	RECT _rc;						//�ڹ��� �Ϲݷ�Ʈ
	float _x, _y;
	int _currentFrameX, _currentFrameY;
};


struct tagBattleStart	//��Ʋ ��ŸƮ ����ü
{
	image* _BattleStartImage;
	int _currentFrameX, _currentFrameY;  //��Ʋ ��ŸƮ ���������
	int _FrameCount;					 //��Ʋ ��ŸƮ ������ ī��Ʈ
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

	image* _currentPixelCollision;  //�ȼ��̹���

	tagLockChain _ChainLeft;          //����   ��罽
	tagLockChain _ChainRight;         //������ ��罽
	tagLockChain _ChainTop;           //����   ��罽
	tagLockChain _ChainBottom;        //�Ʒ��� ��罽

	tagLockChain _Lock;				  //�ڹ���

	bool _LeftChainShake;
	bool _RightChainShake;
	bool _TopChainShake;
	bool _BottomChainShake;
	
	bool _LockDamage1;				//�ڹ��� ���� ���� ����
	bool _LockDamage2;				//�ڹ��� ���� ���� ����
	bool _LockClear;				//�ڹ��� ���� ���� ����
	
	int _LockChainCount;		    //�������̹����� �ڹ���,��罽 ������ī��Ʈ ����

	int _LockCount;					//���� ī��Ʈ���� �ڹ��踦 ����ִ� ������ ������
	int _ClearCount;				//���� ī��Ʈ���� �ڹ��踦 �������ִ� ������ ������

	ChainLockState _ChainLockState; // ��罽 �¹��� ���� ���� ����

	tagBattleStart _BattleStart;	//��Ʋ��ŸƮ ����ü
	bool _PlayBattleStart;			//��Ʋ��ŸƮ�� ������ΰ�?


	//�÷��̾ �� �������� ���� ��� ��ǥ�� ������ ü�ζ��� �ɸ��°�?
	bool _PlayerStage1ChainLock;	
	bool _PlayerStage2ChainLock;	
	bool _PlayerStage3ChainLock;	
	bool _PlayerStage4ChainLock;	

	bool _PlayerStage1ChainLockAlready;
	bool _PlayerStage2ChainLockAlready;
	bool _PlayerStage3ChainLockAlready;
	bool _PlayerStage4ChainLockAlready;

	//�׽�Ʈ�� ü�ζ� Ÿ��
	int _ChainLockTime;

	//���� �������� ���� ����
	NowStage _NowStage;

	//�ٸ� Ŭ�������� �����ϱ� ���� �������� ���� bool��
	bool _NowStage1;
	bool _NowStage2;
	bool _NowStage3;
	bool _NowStage4;
	bool _NowBossStage;

	//���� ���������� npc�� ������ ���� vector
	vector<class npc*> _vNpcs;

	// ���������� ���� �ð����� enemy�� spawn�ϱ� ���� int ��
	int _spawnCount;
	float _bossIntroX;

	// ���� ������������ ������ ����� ���� bool��
	bool _canPlayVideo;

	// ü�� �� ���¸� Ǯ�� ���� óġ�� enemy�� �����ϴ� int ��
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


	//���� ���������� ����ΰ�? swtich��
	void NowStage();
	int getNowStage() { return _NowStage; }


	//���� ���������� �����Դϴ�.
	void Stage1Move();
	void Stage2Move();
	void Stage3Move();
	void Stage4Move();
	void BossStageMove();

	//stagedoor �浹 �� �̹����� �ٲ�ϴ�.
	void Stage1_Stage2_Ok();
	void Stage2_Stage3_Ok();
	void Stage2_Stage1_Ok();
	void Stage3_Stage4_Ok();
	void Stage3_Stage2_Ok();
	void Stage4_BossStage_Ok();
	void Stage4_Stage3_Ok();
	void BossStage_Stage4_Ok();
	
	//ü�ζ��� ���������� �����̰� �ϰ� �׸��ϴ�.
	void ChainLockMove();					 
	void ChainLockFrameDraw();				 

	// ===== ���� �߰� =====
	void plusEnemyCount() { _enemyCount += 1; }

	//�� �������� ���� ��� ������ ���� �� ���� ü�ζ� �Լ��� �����ŵ�ϴ�.

	void Stage1ChainLock();					
	void Stage1DoorLockDraw();				

	void Stage2ChainLock();		
	void Stage2DoorLockDraw();				

	void Stage3ChainLock();				
	void Stage3DoorLockDraw();		

	void Stage4ChainLock();			
	void Stage4DoorLockDraw();				

	//��Ʋ ��ŸƮ �������� �����Ű�� �׸��ϴ�.
	void PlayBattleStartFrame();		    
	void PlayBattleStartBackGroundDraw(HDC hdc);    

	bool getPlayBattleStart() { return _PlayBattleStart; }
	void setPlayBattleStart(bool playBattleStart) { _PlayBattleStart = playBattleStart; }

	//�������� ���� bool�� ������
	bool getNowstage1() { return _NowStage1; }
	bool getNowstage2() { return _NowStage2; }
	bool getNowstage3() { return _NowStage3; }
	bool getNowstage4() { return _NowStage4; }
	bool getNowbossStage() { return _NowBossStage; }

	//�������� �̵� �� ������
	stage01* getVStage1() { return _Stage1; }
	stage02* getVStage2() { return _Stage2; }
	stage03* getVStage3() { return _Stage3; }
	stage04* getVStage4() { return _Stage4; }
	bossStage* getVBossStage() { return _BossStage; }

	image* getPixelImage() { return _currentPixelCollision; } //�ȼ��̹��� ��

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

