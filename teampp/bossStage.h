#pragma once
#include "gameNode.h"

struct tagBossStage
{
	image* _StageImage;
	MYRECT _rc;
	float _x, _y;

	image* _pixelCollision;

};
class bossStage : public gameNode
{
private:

	tagBossStage _BossStagePixelBackGround;
	tagBossStage _BossStageBackGround;
	tagBossStage _BossStageLeftDoor;
	tagBossStage _BossStageLeftDoorOpen;

	bool _isBroken;

public:

	bossStage();
	~bossStage();

	HRESULT init();
	void release();
	void update();
	void render();

	void BossStageLeftDoorOpenDraw();

	image* getPixel() { return _BossStagePixelBackGround._pixelCollision; }

	inline MYRECT getRect() { return _BossStageLeftDoor._rc; }
	inline void setIsBroken(bool br) { _isBroken = br; }

};

