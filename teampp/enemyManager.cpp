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
	for (int i = 0; i < _vSchoolBoy.size(); i++)
	{
		_vSchoolBoy[i]->update();
	}
	for (int i = 0; i < _vSchoolGirl.size(); i++)
	{
		_vSchoolGirl[i]->update();
	}
	
}

void enemyManager::render()
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->render();
	}
	for (int i = 0; i < _vSchoolBoy.size(); i++)
	{
		_vSchoolBoy[i]->render();
	}
	for (int i = 0; i < _vSchoolGirl.size(); i++)
	{
		_vSchoolGirl[i]->render();
	}
}

void enemyManager::setEnemyCheerMove()
{
	float x[] = {500};
	float y[] = {350};

	for (int i = 0; i < 4; i++)
	{
		enemy* _tempCheer = new cheerleader;
		_tempCheer->init("cheer_move", x[i], y[i], 2.3f);
		_vCheerLeader.push_back(_tempCheer);
	}
}

void enemyManager::setEnemySchoolBoyMove()
{
	float x[] = { 1300 };
	float y[] = { 550 };

	for (int i = 0; i < 1; i++)
	{
		enemy* _tempSchoolBoy = new schoolboy;
		_tempSchoolBoy->init("schoolboy_move", x[i], y[i], 2.3f);
		_vSchoolBoy.push_back(_tempSchoolBoy);
	}
}

void enemyManager::setEnemySchoolGirlMove()
{
	float x[] = { 1000 };
	float y[] = { 450 };

	for (int i = 0; i < 1; i++)
	{
		enemy* _tempSchoolGirl = new schoolgirl;
		_tempSchoolGirl->init("schoolgirl_move", x[i], y[i], 2.3f);
		_vSchoolGirl.push_back(_tempSchoolGirl);
	}
}


void enemyManager::setPlayerPos(float x, float y)
{
	for (int i = 0; i < _vCheerLeader.size(); i++)
	{
		_vCheerLeader[i]->setPlayerPos(x, y);
	}
	for (int i = 0; i < _vSchoolBoy.size(); i++)
	{
		_vSchoolBoy[i]->setPlayerPos(x, y);
	}
	for (int i = 0; i < _vSchoolGirl.size(); i++)
	{
		_vSchoolGirl[i]->setPlayerPos(x, y);
	}
}
