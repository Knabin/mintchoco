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

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->update();
	}
	
	
}

void enemyManager::render()
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->render();
	}
}

void enemyManager::setEnemyCheerMove()
{
	float x[] = {300,500,700};
	float y[] = {350,450,550};

	for (int i = 0; i < 3; i++)
	{
		enemy* _tempCheer = new enemy;
		_tempCheer->init("move", x[i], y[i], 3);
		_vCheerLeader.push_back(_tempCheer);
	}
}

void enemyManager::setPlayerPos(float x, float y)
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->setPlayerPos(x, y);
	}
}
