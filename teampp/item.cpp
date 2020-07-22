#include "stdafx.h"
#include "item.h"

item::item()
{
}

item::~item()
{
}

HRESULT item::init()
{
	ItemImage = IMAGEMANAGER->addImage("사과", "images/item/apple.bmp", 32, 33, true, RGB(255, 0, 255));
	_x = WINSIZEX / 2 - 300;
	_y = WINSIZEY / 2 + 100;
	_rc.setCenterPos(_x, _y);

	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render()
{
	IMAGEMANAGER->findImage("사과")->render(getMemDC(), _x - 16, _y - 16);
}
