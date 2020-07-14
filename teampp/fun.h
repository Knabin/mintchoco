#pragma once
#include "gameNode.h"

class fun : public gameNode
{
private:
	image* _image;
	float _startX, _startY;
	float _endX, _endY;

	float _angle;
	float _travelRange;
	float _worldTimeCount;
	float _time;

	bool _isMoving;




public:
	fun();
	~fun();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void moveTo(image* image, float endX, float endY, float time);

	void moving();

	bool getIsMoving() { return _isMoving; }
};

