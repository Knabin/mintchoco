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

	_player = new player;
	_player->init();

	_enemyManager = new enemyManager;
	_enemyManager->init();

	_collisionManager = new collisionManager;
	_collisionManager->init();

	_uiManager = new UiManager;
	_uiManager->init();

	_stageManager = new stageManager;
	_stageManager->setEnemyManagerMemoryAddressLink(_enemyManager);
	_stageManager->init();

	_itemManager = new itemManager;
	_itemManager->init();

	_scene = new scene;
	_scene->init();


	_collisionManager->setPlayerMemoryAddressLink(_player);
	_collisionManager->setEnemyManagerMemoryAddressLink(_enemyManager);
	_collisionManager->setStageManagerMemoryAddressLink(_stageManager);
	_collisionManager->setItemManagerMemoryAddressLink(_itemManager);
	_collisionManager->setUiManagerMemoryAddressLink(_uiManager);

	_enemyManager->setStageManagerMemoryAddressLink(_stageManager);
	_uiManager->setStageManagerMemoryAddressLink(_stageManager);

	//_enemyManager->setBossMove();

	{
		IMAGEMANAGER->addImage("stage2 pillar", "images/stage/stage02_pillar.bmp", 195, 843, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("stage3 pillar", "images/stage/stage03_pillar.bmp", 195, 843, true, RGB(255, 0, 255));
	}

	// ==========================================
	// ## 카메라 중점 초기화 ##
	// ==========================================
	// 플레이어 센터나 테스트용 렉트(MYRECT) 만들어서 사용하세요
	CAMERA->setPosition(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());
	CAMERA->setBackWidth(_stageManager->getPixelImage()->getWidth());
	CAMERA->setBackHeight(_stageManager->getPixelImage()->getHeight());

	return S_OK;
}

void playGround::release()
{
	_stageManager->release();
	_player->release();
	_enemyManager->release();
	_scene->release();
}

void playGround::update()
{
	gameNode::update();

	if (_scene->getGameStart() == false && _scene->getSaveLoading() == false && _scene->getLoading() == false)
	{
		_scene->PointerMove();
	}

	if (_scene->getGameStart() == false && _scene->getSaveLoading() == true && _scene->getLoading() == false)
	{
		_scene->SaveLoadMove();
	}

	if (_scene->getGameStart() == false && _scene->getSaveLoading() == false && _scene->getLoading() == true)
	{
		_scene->LoadingCountPlus();
		_scene->GameStart();
	}


	if (_scene->getGameStart() == true && _scene->getSaveLoading() == false && _scene->getLoading() == false)
	{
		//==========================================================================================================================//

		_enemyManager->update();
		_player->update();
		_collisionManager->update();
		_stageManager->update();
		_uiManager->update();

		_enemyManager->setPlayerPos(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());

		if (KEYMANAGER->isOnceKeyDown('1'))
		{
			CAMERA->cameraFixed();
		}
		if (KEYMANAGER->isOnceKeyDown('2'))
		{
			CAMERA->cameraFixed(200, 200);
		}
		if (KEYMANAGER->isOnceKeyDown('3'))
		{
			CAMERA->setIsFixed(false);
		}
		if (KEYMANAGER->isOnceKeyDown('4'))
		{
			vector<string> temp;
			temp.push_back(to_string(100));
			temp.push_back(to_string(10));
			temp.push_back(to_string(_stageManager->getNowStage()));
			TXTDATA->txtSave("data/player.data", temp);
		}
		if (KEYMANAGER->isOnceKeyDown(VK_F1))
		{
			_stageManager->Stage1Move();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_F2))
		{
			_stageManager->Stage2Move();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_F3))
		{
			_stageManager->Stage3Move();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_F4))
		{
			_stageManager->Stage4Move();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_F5))
		{
			_stageManager->BossStageMove();
		}

		// ==========================================
		// ## 카메라 중점 초기화 ##
		// ==========================================
		CAMERA->shakeStart();
		// 플레이어 센터나 테스트용 렉트(MYRECT) 만들어서 사용하세요
		//CAMERA->setPosition(WINSIZEX/2, WINSIZEY/2);
		// 따라오는 카메라
		CAMERA->changePosition(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());
	}
}

void playGround::render()
{
	if (_scene->getGameStart() == false && _scene->getSaveLoading() == false && _scene->getLoading() == false)
	{
		_scene->TitleBackGroundDraw(getHDC());
	}
	if (_scene->getGameStart() == false && _scene->getSaveLoading() == true && _scene->getLoading() == false)
	{
		_scene->SaveLoadingBackGroundDraw(getMemDC());
		_backBuffer->render(getHDC());
	}

	if (_scene->getGameStart() == false && _scene->getSaveLoading() == false && _scene->getLoading() == true)
	{
		_scene->LoadingBackGroundDraw(getHDC());
	}

	if (_scene->getGameStart() == true && _scene->getSaveLoading() == false && _scene->getLoading() == false)
	{
		//==========================================================================================================================//

		PatBlt(CAMERA->getMemDC(), 0, 0, getMemDCWidth(), getMemDCHeight(), BLACKNESS);
		PatBlt(getMemDC(), 0, 0, getMemDCWidth(), getMemDCHeight(), BLACKNESS);
		//=================================================

		_stageManager->render();
		_player->render();
		_collisionManager->render();
		_enemyManager->render();
		_itemManager->render();
		_scene->render();

		ZORDER->render();

		// 기둥 render
		if (_stageManager->getNowStage() == 1)
		{
			IMAGEMANAGER->findImage("stage2 pillar")->alphaRender(getMemDC(), 1707, 0, 170);
		}
		else if (_stageManager->getNowStage() == 2)
		{
			IMAGEMANAGER->findImage("stage3 pillar")->alphaRender(getMemDC(), 498, 0, 170);
		}

		//=============================================
		_backBuffer->render(CAMERA->getMemDC(), 0, CAMERA->getBlackSize() * 0.5,
			CAMERA->getLeft(), CAMERA->getTop() + CAMERA->getShakeNumber(),
			CAMERA->getViewWidth(), CAMERA->getViewHeight());
		_uiManager->render(CAMERA->getMemDC());
		CAMERA->render(getHDC());

	}
}