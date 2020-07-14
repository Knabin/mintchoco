#include "stdafx.h"
#include "spaceScene.h"
#include "battle.h"


spaceScene::spaceScene()
{
}


spaceScene::~spaceScene()
{
}

HRESULT spaceScene::init()
{
	_battle = new battle;
	_battle->init("battle", WINSIZEX / 2, WINSIZEY / 2);

	return S_OK;
}

void spaceScene::release()
{
}

void spaceScene::update()
{
	_battle->update();
}

void spaceScene::render()
{
	_battle->render();
}
