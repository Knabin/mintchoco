#pragma once
#include "gameNode.h"

struct tagStage3
{
	image* _StageImage;
	RECT _rc;
	float _x, _y;

};
class stage03 : public gameNode
{
private:

	tagStage3 _Stage3BackGround;		//3�������� ��� ȭ��
	tagStage3 _Stage3LeftDoor;			//3�������� LeftDoor

public:

	stage03();
	~stage03();


	HRESULT init();
	void release();
	void update();
	void render();

	inline RECT getRect() { return _Stage3LeftDoor._rc; }

};
