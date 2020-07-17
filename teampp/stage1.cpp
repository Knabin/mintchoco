#include "stdafx.h"
#include "stage1.h"

HRESULT stage1::init()
{
	IMAGEMANAGER->addImage("background1", "images/background/stage1.bmp", 2016, 672, false, NULL);
	_pixelCollision = IMAGEMANAGER->addImage("background1_pixel", "images/background/stage1_pixel.bmp", 2016, 672, false, NULL);


	return S_OK;
}

void stage1::release()
{
}

void stage1::update()
{


}

void stage1::render()
{
	IMAGEMANAGER->findImage("background1")->render(getMemDC());
}
