#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}
//tset
//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);

	//jiSub test

	return S_OK;
}

//�޸� ����
void playGround::release()
{
	
}

//����
void playGround::update()
{
	gameNode::update();

}

//�׸��� ����
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}
