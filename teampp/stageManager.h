#pragma once
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"

#include "gameNode.h" 

enum stageSelect 
{
	STAGE1,
	STAGE2,
	STAGE3
};

class stageManager : public gameNode
{
private:
	stage1* _stage1;   
	stage2* _stage2;
	stage3* _stage3;
	
	stageSelect _stageSelect;  //�������� ����

	image* _currentPixelCollision;  //�ȼ��̹���

public:

	stageManager() {}  
	~stageManager() {}

	HRESULT init();
	void release();
	void update();
	void render();

	void stageClear();  //�������� Ŭ����

	image* getPixelImage() { return _currentPixelCollision; } //�ȼ��̹��� ��
};

