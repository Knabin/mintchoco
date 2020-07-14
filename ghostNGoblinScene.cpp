#include "stdafx.h"
#include "ghostNGoblinScene.h"


ghostNGoblinScene::ghostNGoblinScene()
{
}


ghostNGoblinScene::~ghostNGoblinScene()
{
}

HRESULT ghostNGoblinScene::init()
{
	_knight = new knight;
	_knight->init();

	return S_OK;
}

void ghostNGoblinScene::release()
{
}

void ghostNGoblinScene::update()
{
	_knight->update();
}

void ghostNGoblinScene::render()
{
	_knight->render();
}
