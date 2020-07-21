#include "stdafx.h"
#include "npc.h"

npc::npc()
{
	IMAGEMANAGER->addFrameImage("npc1", "images/npc/npc_boy1.bmp", 396, 480, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("npc1 react", "images/npc/npc_boy1_react.bmp", 306, 480, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("npc2", "images/npc/npc_girl1.bmp", 312, 396, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("npc2 react", "images/npc/npc_girl1_react.bmp", 297, 384, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("npc3", "images/npc/npc_girl2.bmp", 324, 522, 4, 2, true, RGB(255,0,255));
	IMAGEMANAGER->addFrameImage("npc3 react", "images/npc/npc_girl2_react.bmp", 360, 504, 3, 2, true, RGB(255, 0, 255));
}

npc::~npc()
{
}

HRESULT npc::init(float x, float y, int typeNum, bool isLeft)
{
	_x = x;
	_y = y;

	switch (typeNum)
	{
	case 0:
		_image = IMAGEMANAGER->findImage("npc1");
		_imageReact = IMAGEMANAGER->findImage("npc1 react");
		break;
	case 1:
		_image = IMAGEMANAGER->findImage("npc2");
		_imageReact = IMAGEMANAGER->findImage("npc2 react");
		break;
	case 2:
		_image = IMAGEMANAGER->findImage("npc3");
		_imageReact = IMAGEMANAGER->findImage("npc3 react");
		break;
	}

	_rc.set(0, 0, _image->getFrameWidth(), _image->getFrameHeight());
	_rc.setCenterPos(x, y);
	
	_ani_idle = new animation;
	_ani_idle->init(_image->getWidth(), _image->getHeight(),
		_image->getFrameWidth(), _image->getFrameHeight());
	_ani_idle->setFPS(1);
	_ani_idle->setDefPlayFrame(false, true);

	_ani_react = new animation;
	_ani_react->init(_imageReact->getWidth(), _imageReact->getHeight(),
		_imageReact->getFrameWidth(), _imageReact->getFrameHeight());
	_ani_react->setFPS(1);
	_ani_react->setDefPlayFrame(false, false);

	if (isLeft)
	{
		_state = NPCSTATE::LEFT_IDLE;
		_ani_idle->setPlayFrame(0, 3, false, true);
	}
	else
	{
		_state = NPCSTATE::RIGHT_IDLE;
		_ani_idle->setPlayFrame(4, 7, false, true);
	}

	_ani_idle->start();

	return S_OK;
}

void npc::release()
{
}

void npc::update()
{
	switch (_state)
	{
	case NPCSTATE::LEFT_IDLE:
	case NPCSTATE::RIGHT_IDLE:
		_ani_idle->frameUpdate(TIMEMANAGER->getElapsedTime() * 3);
		break;
	case NPCSTATE::LEFT_REACT:
	case NPCSTATE::RIGHT_REACT:
		_ani_react->frameUpdate(TIMEMANAGER->getElapsedTime() * 3);
		if (!_ani_react->isPlay())
		{
			_state = isLeft() ? NPCSTATE::LEFT_IDLE : NPCSTATE::RIGHT_IDLE;
			isLeft() ? _ani_idle->setPlayFrame(0, 3, false, true) : _ani_idle->setPlayFrame(4, 7, false, true);
			_ani_idle->start();
		}
		break;
	}
}

void npc::render()
{
	//_rc.render(getMemDC());
	switch (_state)
	{
	case NPCSTATE::LEFT_IDLE:
	case NPCSTATE::RIGHT_IDLE:
		ZORDER->pushObject(getMemDC(), _image, _ani_idle, 1, _x, 0, _rc.bottom);
		break;
	case NPCSTATE::LEFT_REACT:
	case NPCSTATE::RIGHT_REACT:
		ZORDER->pushObject(getMemDC(), _imageReact, _ani_react, 1, _x, 0, _rc.bottom);
		break;
	}
}

void npc::doReact()
{
	_image = IMAGEMANAGER->findImage("npc1 react");
	if (isLeft())
	{
		_state = NPCSTATE::LEFT_REACT;
		_ani_react->setPlayFrame(0, 2, false, false);
	}
	else
	{
		_state = NPCSTATE::RIGHT_REACT;
		_ani_react->setPlayFrame(3, 5, false, false);
	}
	_ani_react->start();
}
