#pragma once
#include "gameNode.h"
class jump : public gameNode
{
private:
	float _jumpPower;
	float _gravity;

	float* _x;
	float* _y;

	float _startX, _startY;

	float _speed, _angle;

	bool _isJumping;
	bool _isWalkJumping;
	bool _isRunJumping;
	bool _leftOrRight;

public:
	jump();
	~jump();

	HRESULT init();
	void render();
	void update();
	void release();

	void jumping(float* x, float* y, float jumpPower, float gravity);
	void jumpingUpdate();
	void walkJumping(float* x, float* y, float jumpPower, float gravity, float angle, float speed, bool leftOrRight);
	void walkJumpingUpdate();//왼쪽이면 0 오른쪽이면 1
	void runJumping(float* x, float* y, float jumpPower, float gravity, float angle, float speed, bool leftOrRight);
	void runJumpingUpdate();//왼쪽이면 0 오른쪽이면 1
	float getJumpPower() { return _jumpPower; }
};

