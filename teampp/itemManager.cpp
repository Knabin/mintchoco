#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
{
}

itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{

		
	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{

	
}

void itemManager::render()
{
	for (_viItems = _vItems.begin(); _viItems != _vItems.end(); ++_viItems)
	{
		(*_viItems)->render();
	}
	for (_viMoney = _vMoney.begin(); _viMoney != _vMoney.end(); ++_viMoney)
	{
		(*_viMoney)->render();
	}
}

void itemManager::setVItemsDrop(float x, float y)
{	
	int randomDrop = RND->getFromFloatTo(1, 6);

	if (randomDrop == 2)
	{
		item* Hamburger;
		Hamburger = new item;
		Hamburger->init("햄버거", x, y);

		_vItems.push_back(Hamburger);
	}
	
	if (randomDrop == 1)
	{
		item* Icecream;
		Icecream = new item;
		Icecream->init("아이스크림", x, y);

		_vItems.push_back(Icecream);
	}
	
	if (randomDrop >= 3)
	{
		money* Money;
		Money = new money;
		Money->init("동전", x, y);

		_vMoney.push_back(Money);
	}

}

void itemManager::removeItem(int Num)
{
	_vItems[Num]->release();
	SAFE_DELETE(_vItems[Num]);
	_vItems.erase(_vItems.begin() + Num);
}

void itemManager::removeMoney(int Num2)
{
	_vMoney[Num2]->release();
	SAFE_DELETE(_vMoney[Num2]);
	_vMoney.erase(_vMoney.begin() + Num2);

}

void itemManager::removeAllItem()
{
	for (int i = 0; i < _vItems.size(); ++i)
	{
		_vItems[i]->release();
		SAFE_DELETE(_vItems[i]);
	}
	_vItems.clear();
}

void itemManager::removeAllMoney()
{
	for (int i = 0; i < _vMoney.size(); ++i)
	{
		_vMoney[i]->release();
		SAFE_DELETE(_vMoney[i]);
	}
	_vMoney.clear();
}

