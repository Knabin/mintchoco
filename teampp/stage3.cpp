#include "stdafx.h"
#include "stage3.h"

HRESULT stage3::init()
{
	IMAGEMANAGER->addImage("background3", "images/background/stage3.bmp", 2769, 1280, false, NULL);
	_pixelCollision = IMAGEMANAGER->addImage("background3_pixel", "images/background/stage3_pixel.bmp", 2769, 1280, false, NULL);

	return S_OK;
}

void stage3::release()
{
}

void stage3::update()
{
}

void stage3::render()
{
	IMAGEMANAGER->findImage("background3")->render(getMemDC());
}
