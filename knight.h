#pragma once
#include "gameNode.h"

#define KNIGHTSPEED 2.5f

enum KNIGHTDIRECTION
{
	KNIGHTDIRECTION_RIGHT_STOP,
	KNIGHTDIRECTION_LEFT_STOP,
	KNIGHTDIRECTION_RIGHT_MOVE,
	KNIGHTDIRECTION_LEFT_MOVE,
	KNIGHTDIRECTION_RIGHT_SIT,
	KNIGHTDIRECTION_LEFT_SIT,
	KNIGHTDIRECTION_RIGHT_ATTACK,
	KNIGHTDIRECTION_LEFT_ATTACK,
	KNIGHTDIRECTION_RIGHT_SIT_ATTACK,
	KNIGHTDIRECTION_LEFT_SIT_ATTACK,
	KNIGHTDIRECTION_RIGHT_JUMP,
	KNIGHTDIRECTION_LEFT_JUMP,
	KNIGHTDIRECTION_RIGHT_MOVE_JUMP,
	KNIGHTDIRECTION_LEFT_MOVE_JUMP
};

class knight : public gameNode
{
private:
	KNIGHTDIRECTION _knightDirection;

	image* _image;
	float _x, _y;
	RECT _rc;
	animation* _knightMotion;


public:
	knight();
	~knight();

	HRESULT init();
	void release();
	void update();
	void render();

	static void rightFire(void* obj);
	static void leftFire(void* obj);

	KNIGHTDIRECTION getKnightDirection() { return _knightDirection; }
	void setKnightDirection(KNIGHTDIRECTION direction) { _knightDirection = direction; }

	animation* getKnightMotion() { return _knightMotion; }
	void setKnightMotion(animation* ani) { _knightMotion = ani; }

};

