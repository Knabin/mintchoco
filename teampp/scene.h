#pragma once
#include "gameNode.h"

enum SaveLoadWindowState // ���̺� �ε� â �� ��ġ
{
	W1 = 0,
	W2,
	W3

};

enum PointerState //������ ��Ʈ ����ġ
{
	START = 0,
	QUIT
};

struct tagScene
{
	image* SceneImage;
	RECT _rc;							 //������ ��Ʈ
	float _x, _y;

	PointerState _PointerState;			 //������ ��Ʈ ����ġ

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

	tagScene _MainTitle;		//Ÿ��Ʋ ���
	tagScene _StartQuit;		//Ÿ��Ʋ ��ư
	tagScene _Pointer;			//Ÿ��Ʋ ������
	tagScene _SaveLoadWindow1;  //���̺�ε� ù����â
	tagScene _SaveLoadWindow2;  //���̺�ε� �ι�°â

	tagScene _SaveLoadWindow3;  //���̺�ε� ����°â

	SaveLoadWindowState _SaveLoadWindowState;

	// ===== ���� �߰� =====
	vector<saveData> _vData;

	string _mapNoName;
	string _stageNoName;
	// ====================


	bool _GameStart;			//���� �������ΰ�?
	bool _Loading;				//�ε� â�ΰ�?
	bool _SaveLoading;			//���̺�ε� â�ΰ�?	

	int _LoadingCount;			//�ε� ī��Ʈ

public:

	scene();
	~scene();

	HRESULT init();
	void release();
	void update();
	void render();

	void PointerMove();					         //������ �̵� �Լ�
	void SaveLoadMove();				         //���̺� �ε� â �̵� �Լ�
	void LoadingCountPlus();			//�ε� ȭ���� ���� �ٸ��� ������� count update �Լ�
	void GameStart();					//�ε� ȭ���� ������ ������ �����ض�


	void TitleBackGroundDraw(HDC hdc);		     //Ÿ��Ʋȭ���� �׷���
	void SaveLoadingBackGroundDraw(HDC hdc);     //���̺�ε�â �� �׷���
	void LoadingBackGroundDraw(HDC hdc);	     //�ε�ȭ���� �׷���


	bool getGameStart() { return _GameStart; }
	bool getLoading() { return _Loading; }
	bool getSaveLoading() { return _SaveLoading; }



	// ===== ���� �߰� =====
	int getSaveLoadWindowState() { return _SaveLoadWindowState; }
	void setSaveLoadWindowState(int sl) { _SaveLoadWindowState = (SaveLoadWindowState)sl; }

	void getPlayerSaveData();
	void getPlayerSaveData(int slot);

	void setLoading(bool loading) { _Loading = loading; }
	// ====================

};

