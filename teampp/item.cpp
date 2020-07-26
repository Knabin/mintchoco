#include "stdafx.h"
#include "item.h"

item::item()
{
}

item::~item()
{
}

HRESULT item::init(const char * imageName, float x, float y)
{
	IMAGEMANAGER->addImage("���̽�ũ��", "images/item/icecream.bmp", 55, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ܹ���", "images/item/hamburger.bmp", 64, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�˷ο�", "images/item/aloe.bmp", 50, 76, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ƣ��", "images/item/tempura.bmp", 58, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "images/item/tonkatsu.bmp", 60, 51, true, RGB(255, 0, 255));

	_itemImage = IMAGEMANAGER->findImage(imageName);

	_x = x;
	_y = y;

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
	_itemImage->render(getMemDC(), _rc.left, _rc.top);
}


