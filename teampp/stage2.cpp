#include "stdafx.h"
#include "stage2.h"

HRESULT stage2::init()
{
	IMAGEMANAGER->addImage("background2", "images/background/stage2.bmp", 2112, 864, false, NULL);
	_pixelCollision = IMAGEMANAGER->addImage("background2_pixel", "images/background/stage2_pixel.bmp", 2112, 864, false, NULL);

	return S_OK;
}

void stage2::release()
{
}

void stage2::update()
{
}

void stage2::render()
{
	IMAGEMANAGER->findImage("background2")->render(getMemDC());
}
