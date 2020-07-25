#pragma once
#include "gameNode.h"
class jump : public gameNode
{
private:
	float _jumpPower;
	float _gravity;

	float* _x;
	float* _z;

	float _startX, _startZ;

	bool _isJumping;

public:
	jump();
	~jump();

	HRESULT init();
	void render();
	void update();
	void release();

	void jumping(float* x, float* z, float jumpPower, float gravity);
	void setStartZmin(float startY) { _startZ -= startY; }
	void setStartZpls(float startY) { _startZ += startY; }
	void setJumpPower(float jumpPower) { _jumpPower = jumpPower; }
	void setGravity(float gravity) { _gravity = gravity; }
	float getJumpPower() { return _jumpPower; }
	float getGravity() { return _gravity; }
	float getStartZ() { return _startZ; }
};

