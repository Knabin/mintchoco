#include "stdafx.h"
#include "enemyManager.h"

enemyManager::enemyManager()
{
}

enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_enemy = new enemy;
	_enemy->init();

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	_enemy->update();
}

void enemyManager::render()
{
	_enemy->render();
}
