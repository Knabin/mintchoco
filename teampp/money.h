#pragma once
#include "gameNode.h"

class money : public gameNode
{

private:

	image* _moneyImage;		//돈 이미지
	MYRECT _rc;				//아이템 충돌용 렉트
	float _x, _y;

public:

	money();
	~money();

	HRESULT init(const char * imageName, float x, float y);
	void release();
	void update();
	void render();

	inline MYRECT getRect() { return _rc; }

};