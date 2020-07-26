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
	int randomDrop = RND->getFromFloatTo(1, 13);

	if (randomDrop == 1)
	{
		item* Hamburger;
		Hamburger = new item;
		Hamburger->init("ÇÜ¹ö°Å", x, y);

		_vItems.push_back(Hamburger);
	}
	
	if (randomDrop == 2)
	{
		item* Icecream;
		Icecream = new item;
		Icecream->init("¾ÆÀÌ½ºÅ©¸²", x, y);

		_vItems.push_back(Icecream);
	}

	if (randomDrop == 3)
	{
		item* Aloe;
		Aloe = new item;
		Aloe->init("¾Ë·Î¿¡", x, y);

		_vItems.push_back(Aloe);
	}

	if (randomDrop == 4)
	{
		item* tempura;
		tempura = new item;
		tempura->init("Æ¢±è", x, y);

		_vItems.push_back(tempura);
	}

	if (randomDrop >= 5)
	{
		item* Tonkatsu;
		Tonkatsu = new item;
		Tonkatsu->init("µ·°¡½º", x, y);

		_vItems.push_back(Tonkatsu);
	}
	
	if (randomDrop >= 13)
	{
		money* Money;
		Money = new money;
		Money->init("µ¿Àü", x, y);

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

