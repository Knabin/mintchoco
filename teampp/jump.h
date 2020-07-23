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

	bool _isJumping;

public:
	jump();
	~jump();

	HRESULT init();
	void render();
	void update();
	void release();

	void jumping(float* x, float* y, float jumpPower, float gravity);
	void setStartYmin(float startY) { _startY -= startY; }
	void setStartYpls(float startY) { _startY += startY; }
	void setJumpPower(float jumpPower) { _jumpPower = jumpPower; }
	void setGravity(float gravity) { _gravity = gravity; }
	float getJumpPower() { return _jumpPower; }
	float getGravity() { return _gravity; }
	float getStartY() { return _startY; }
};

