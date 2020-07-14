#include "stdafx.h"
#include "anotherScene.h"


anotherScene::anotherScene()
{
}


anotherScene::~anotherScene()
{
}

HRESULT anotherScene::init()
{
	_btnSceneChange = new button;
	_btnSceneChange->init("¹öÆ°", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	_funTest = new fun;
	_funTest->init();

	IMAGEMANAGER->findImage("ÃÑ¾Ë")->setX(WINSIZEX / 2);
	IMAGEMANAGER->findImage("ÃÑ¾Ë")->setY(WINSIZEY / 2);

	_funTest->moveTo(IMAGEMANAGER->findImage("ÃÑ¾Ë"), 100, 100, 10.0f);



	return S_OK;
}

void anotherScene::update()
{
	_btnSceneChange->update();
	_funTest->update();
}

void anotherScene::render()
{
	_btnSceneChange->render();
	IMAGEMANAGER->findImage("ÃÑ¾Ë")->render(getMemDC());

	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2 + 150, "´Ù¸¥ ¾À", strlen("´Ù¸¥ ¾À"));
}

void anotherScene::cbSceneChange()
{
	SCENEMANAGER->changeScene("½ºÅ¸¾À");
}
