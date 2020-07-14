#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("배경", "우주.bmp", WINSIZEX, WINSIZEY, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("버튼", "button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("총알", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));



	SCENEMANAGER->addScene("고스트씬", new ghostNGoblinScene);

	SCENEMANAGER->changeScene("고스트씬");


	return S_OK;
}

//메모리 해제
void playGround::release()
{
	
}

//연산
void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();
}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	IMAGEMANAGER->findImage("배경")->render(getMemDC());
	
	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());
	
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}
