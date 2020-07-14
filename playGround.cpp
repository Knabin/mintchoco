#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("���", "����.bmp", WINSIZEX, WINSIZEY, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ư", "button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ѿ�", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));



	SCENEMANAGER->addScene("��Ʈ��", new ghostNGoblinScene);

	SCENEMANAGER->changeScene("��Ʈ��");


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

	SCENEMANAGER->update();
}

//�׸��� ����
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	IMAGEMANAGER->findImage("���")->render(getMemDC());
	
	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());
	
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}
