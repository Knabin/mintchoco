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
	
	stageSelect _stageSelect;  //스테이지 선택

	image* _currentPixelCollision;  //픽셀이미지

public:

	stageManager() {}  
	~stageManager() {}

	HRESULT init();
	void release();
	void update();
	void render();

	void stageClear();  //스테이지 클리어

	image* getPixelImage() { return _currentPixelCollision; } //픽셀이미지 겟
};

