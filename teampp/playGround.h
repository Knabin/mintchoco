#pragma once
#include "gameNode.h"
#include "player.h"
#include "jump.h"

class playGround : public gameNode
{
private:
	player* _player;//플레이어 상속할당
	jump* _jump;//점프 상속할당
	image* _backGround1;//처음시작시 나올 배경화면 이미지
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

