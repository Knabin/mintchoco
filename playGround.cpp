#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//ÃÊ±âÈ­ ÇÔ¼ö
HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("¹è°æ", "¿ìÁÖ.bmp", WINSIZEX, WINSIZEY, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("¹öÆ°", "button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÃÑ¾Ë", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	//ÁÖ¼® Å×½ºÆ®
<<<<<<< HEAD
	//2¹øÂ° Å×½ºÆ®
=======

>>>>>>> 61d00a9... í…ŒìŠ¤íŠ¸

	SCENEMANAGER->addScene("°í½ºÆ®¾À", new ghostNGoblinScene);

	SCENEMANAGER->changeScene("°í½ºÆ®¾À");


	return S_OK;
}

//¸Þ¸ð¸® ÇØÁ¦
void playGround::release()
{
	
}

//¿¬»ê
void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();
}

//±×¸®±â Àü¿ë
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	IMAGEMANAGER->findImage("¹è°æ")->render(getMemDC());
	
	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());
	
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}
