#pragma once
#include "gameNode.h"

enum class NPCTYPE
{
	TYPE1, END,
};

enum class NPCSTATE
{
	// �⺻ ����
	LEFT_IDLE,
	RIGHT_IDLE,

	// ���� ����
	LEFT_REACT,
	RIGHT_REACT,
};

class npc : public gameNode
{
private:
	image* _image;
	image* _imageReact;
	
	float _x, _y;
	MYRECT _rc;

	NPCTYPE _type;
	NPCSTATE _state;

	animation* _ani_idle;
	animation* _ani_react;

public:
	npc();
	~npc();
	// typeNum : 0
	HRESULT init(float x, float y, int typeNum, bool isLeft = true);

	void release();
	void update();
	void render();

	void doReact();

	bool isLeft()
	{
		if (static_cast<int>(_state) % 2 == 0) return true;
		return false;
	}
	
	float getX() { return _x; }
	float getY() { return _y; }

	MYRECT& getRect() { return _rc; }
};

