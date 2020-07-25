#pragma once
#include "gameNode.h"
#define PLAYERHPPOINT 26


class stageManager;

enum MiniMapState // �̴ϸ� ����
{
	OPEN = 0,
	CLOSE,
	OPENSTOP,
	CLOSESTOP
};

enum class GAMEOVERSTATE
{
	RESTART,
	QUIT
};

struct tagUIbar	  //UI ����ü
{
	image* _UIimage;
	RECT _rc;
	MYRECT _Mrc;
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
	tagUIbar _BossHpbarHide;				  
	tagUIbar _UiCoin;						  //uiâ ��

	tagUIbar _MiniMap;						  //�̴ϸ�

	stageManager* _stageManager;			//stageManager ���漱��

	// ======= ���� �߰� =======
	RECT _saveRc;							// ���̺� ��ư RECT
	bool _restart;							// ���� �� �����
	bool _restartDirect;					// �����

	vector<string> _vScript;
	bool _scriptStart;
	bool _scriptEnd;
	int _scriptIndex;
	int _txtIndex;
	int _endCount;
	string _txt;

	bool _isKyoko;

	image* _imgGameOver;
	bool _isGameOver;
	GAMEOVERSTATE _gameOverState;
	// ========================

public:

	UiManager();
	~UiManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void MiniMapMove();						//�̴ϸ� �̵� �Լ�
	
	void PlayerHpMinus();					//PlayerHpPoint ���� �Լ�
	void BossHpMinus();						//boss hp ���� �Լ�
	void BossDeath();						//boss hp�� ������ �����ϸ�?
	
	void gameOver();

	void printScript();

	void setStageManagerMemoryAddressLink(stageManager* stageManager) { _stageManager = stageManager; }

	bool isMiniMapOpen() {
		if (_MiniMap._MiniMapState == OPENSTOP || _MiniMap._MiniMapState == OPEN || _scriptStart)
		{
			return true;
		}
		return false;
	}
	bool getRestart() { return _restart; }
	void setRestart(bool res) { _restart = res; }

	bool getRestartDirect() { return _restartDirect; }
	void setRestartDirect(bool res) { _restartDirect = res; }

	bool getScriptStart() { return _scriptStart; }
	void setScriptStart(bool b) { _scriptStart = b; }

	bool getIsGameOver() { return _isGameOver; }
	void setIsGameOver(bool gameover) { _isGameOver = gameover; }
};
