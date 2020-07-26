#include "stdafx.h"
#include "money.h"

money::money()
{
}

money::~money()
{
}

HRESULT money::init(const char * imageName, float x, float y)
{
	IMAGEMANAGER->addImage("µ¿Àü", "images/item/coin.bmp", 36, 36, true, RGB(255, 0, 255));

	_moneyImage = IMAGEMANAGER->findImage(imageName);

	_x = x;
	_y = y;

	_rc.setCenterPos(_x, _y);

	return S_OK;
}

void money::release()
{
}

void money::update()
{
}

void money::render()
{
	_moneyImage->render(getMemDC(), _rc.left, _rc.top);
}
