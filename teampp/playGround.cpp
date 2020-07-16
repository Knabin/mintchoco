#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}
//tset

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);

	_backGround1 = IMAGEMANAGER->addImage("backGround1", "image/01_backGround.bmp", 2016, 672, true, RGB(255, 0, 255));//인게임 처음 시작시 배경화면

	_player = new player;
	_player->init();
	//플레이어 상속할당

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

	_player->update();//플레이어 업데이트


}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================
	
	_backGround1->render(getMemDC(), 0, 20);//인게임 처음 시작시 배경화면
	_player->render();//플레이어 렌더

	ZORDER->render();
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}
