#pragma once
#include "gameNode.h"

struct tagBossStage
{
	image* _STageImage;
	MYRECT _rc;
	float _x, _y;

	image* _pixelCollision;

};
class bossStage : public gameNode
{
private:

	tagBossStage _BossStagePixelBackGround;
	tagBossStage _BossStageBackGround;

public:

	bossStage();
	~bossStage();

	HRESULT init();
	void release();
	void update();
	void render();

	image* getPixel() { return _BossStagePixelBackGround._pixelCollision; }

};

