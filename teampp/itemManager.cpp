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
		Hamburger->init("�ܹ���", x, y);

		_vItems.push_back(Hamburger);
	}
	
	if (randomDrop == 1)
	{
		item* Icecream;
		Icecream = new item;
		Icecream->init("���̽�ũ��", x, y);

		_vItems.push_back(Icecream);
	}
	
	if (randomDrop >= 3)
	{
		money* Money;
		Money = new money;
		Money->init("����", x, y);

		_vMoney.push_back(Money);
	}

}

void itemManager::removeItem()
{
	for (int i = 0; i < _vItems.size(); i++)
	{
		_vItems.erase(_vItems.begin() + i);
	}
}

void itemManager::removeMoney()
{
	for (int i = 0; i < _vMoney.size(); i++)
	{
		_vMoney.erase(_vMoney.begin() + i);
	}
}

