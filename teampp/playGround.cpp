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

	_stageManager->setPlayerMemoryAddressLink(_player);
	_collisionManager->setPlayerMemoryAddressLink(_player);
	_collisionManager->setEnemyManagerMemoryAddressLink(_enemyManager);
	_collisionManager->setStageManagerMemoryAddressLink(_stageManager);
	_collisionManager->setItemManagerMemoryAddressLink(_itemManager);
	_collisionManager->setUiManagerMemoryAddressLink(_uiManager);

	_enemyManager->setStageManagerMemoryAddressLink(_stageManager);
	_player->setStageManagerMemoryAddressLink(_stageManager);

	_uiManager->setStageManagerMemoryAddressLink(_stageManager);


	{
		IMAGEMANAGER->addImage("stage2 pillar", "images/stage/stage02_pillar.bmp", 195, 864, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("stage3 pillar", "images/stage/stage03_pillar.bmp", 195, 864, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("ui back", "images/ui/black.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	}

	{
		SOUNDMANAGER->addSound("bgm title", "sounds/bgm/RCG_Intro_Song.wav", true, true);
		SOUNDMANAGER->addSound("bgm menu", "sounds/bgm/RCG_menu01.wav", true, true);
		SOUNDMANAGER->addSound("bgm classroom", "sounds/bgm/RCG_Detention.wav", true, true);
		SOUNDMANAGER->addSound("bgm hall", "sounds/bgm/RCG_Knock_Out.wav", true, true);
		SOUNDMANAGER->addSound("bgm chemi", "sounds/bgm/RCG_Lunch_Money.wav", true, true);
		SOUNDMANAGER->addSound("bgm boss", "sounds/bgm/RCG_boss_misuzu.wav", true, true);
	}

	_playVideo = _playIntroVideo = _endIntroVideo = 0;

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
	_collisionManager->release();
	_uiManager->release();
	_itemManager->release();
}

void playGround::update()
{
	gameNode::update();

	if (!_playIntroVideo && !_endIntroVideo)
	{
		IntroVideo = MCIWndCreate(_hWnd, _hInstance, MCIWNDF_NOTIFYANSI | MCIWNDF_NOMENU | MCIWNDF_NOTIFYALL | MCIWNDF_NOPLAYBAR, intro); // 초기화
		MoveWindow(IntroVideo, 0, 0, WINSIZEX, WINSIZEY, NULL);
		MCIWndPlay(IntroVideo);
		_playIntroVideo = true;
		SOUNDMANAGER->playBGM("bgm title");
	}
	
	if (_playIntroVideo && !_endIntroVideo)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) //강제로 스킵
		{
			stopIntro();
		}
	}
	else if(_playVideo)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) //강제로 스킵
		{
			stopVideo();
		}
	}
	else
	{
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

			if (_scene->getGameStart())
			{
				dataManager::getInstance()->setSlot(_scene->getSaveLoadWindowState());

				vector<int> temp = dataManager::getInstance()->loadDataInteger();
				if (temp.size() != 0)
				{
					switch (temp[2])
					{
					case 0:
						_stageManager->Stage1Move();
						_player->playerPosition_1();
						break;
					case 1:
						_stageManager->Stage2Move();
						_player->playerPosition_2at1();
						break;
					case 2:
						_stageManager->Stage3Move();
						_player->playerPosition_3at2();
						break;
					case 3:
						_stageManager->Stage4Move();
						_player->playerPosition_4at3();
						break;
					case 4:
						_stageManager->BossStageMove();
						_player->playerPosition_Bossat4();
						break;
					}

					_stageManager->setPlayBattleStart(true);
				}
			}
		}

		if (_scene->getGameStart() == true && _scene->getSaveLoading() == false && _scene->getLoading() == false)
		{
			//==========================================================================================================================//
			if (!_uiManager->isMiniMapOpen())
			{
				_enemyManager->update();
				_player->update();
				_collisionManager->update();
				_stageManager->update();
				if (_stageManager->checkBossStageX(_player->getPlayerX()))
				{
					SOUNDMANAGER->stopAll("");
					LogoVideo = MCIWndCreate(_hWnd, _hInstance, MCIWNDF_NOTIFYANSI | MCIWNDF_NOMENU | MCIWNDF_NOTIFYALL | MCIWNDF_NOPLAYBAR, movie); // 초기화
					MoveWindow(LogoVideo, 0, 0, WINSIZEX, WINSIZEY, NULL);
					MCIWndPlay(LogoVideo);
					_playVideo = true;
				}
			}
			
			_uiManager->update();

			if (_uiManager->getRestart())
			{
				this->release();
				this->init();
				_playIntroVideo = true;
				_endIntroVideo = true;
				SOUNDMANAGER->playBGM("bgm title");
			}

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
				dataManager::getInstance()->saveData(100, 10, _stageManager->getNowStage());
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
			if (!_uiManager->isMiniMapOpen())
				CAMERA->changePosition(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());
		}
	}
}

void playGround::render()
{
	if (_playIntroVideo && !_endIntroVideo)
	{
		char lp[10];
		long mode;
		mode = MCIWndGetMode(IntroVideo, lp, sizeof(lp));
		if (mode == 525) //영상 멈춤
		{
			stopIntro();
		}
	}
	else if (_playVideo)
	{
		char lp[10];
		long mode;
		mode = MCIWndGetMode(LogoVideo, lp, sizeof(lp));
		if (mode == 525) //영상 멈춤
		{
			stopVideo();
		}
	}
	else {
		if (_scene->getGameStart() == false && _scene->getSaveLoading() == false && _scene->getLoading() == false)
		{
			_scene->TitleBackGroundDraw(getMemDC());
			_backBuffer->render(getHDC());
		}

		if (_scene->getGameStart() == false && _scene->getSaveLoading() == true && _scene->getLoading() == false)
		{
			_scene->SaveLoadingBackGroundDraw(getMemDC());
			_backBuffer->render(getHDC());
		}

		if (_scene->getGameStart() == false && _scene->getSaveLoading() == false && _scene->getLoading() == true)
		{
			_scene->LoadingBackGroundDraw(getMemDC());
			_backBuffer->render(getHDC());
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
			//_itemManager->render();
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

			if (_uiManager->isMiniMapOpen())
				IMAGEMANAGER->findImage("ui back")->alphaRender(getMemDC(), CAMERA->getLeft(), CAMERA->getTop(), 150);

			//=============================================
			_backBuffer->render(CAMERA->getMemDC(), 0, CAMERA->getBlackSize() * 0.5,
				CAMERA->getLeft(), CAMERA->getTop() + CAMERA->getShakeNumber(),
				CAMERA->getViewWidth(), CAMERA->getViewHeight());

			_uiManager->render(CAMERA->getMemDC());
			if (_stageManager->getPlayBattleStart() == true) _stageManager->PlayBattleStartBackGroundDraw(CAMERA->getMemDC());

			CAMERA->render(getHDC());
		}
	}
}

void playGround::stopVideo()
{
	if (!SOUNDMANAGER->isPlaySound("bgm chemi")) SOUNDMANAGER->playBGM("bgm chemi");
	SOUNDMANAGER->stopAll("bgm chemi");

	_player->playerPosition_BossStart();

	RECT _temp;
	GetWindowRect(_hWnd, &_temp);

	MCIWndClose(LogoVideo);
	MoveWindow(_hWnd, _temp.left, _temp.top, _temp.right - _temp.left, _temp.bottom - _temp.top, true);

	_playVideo = false;
	_uiManager->setScriptStart(true);
	_enemyManager->setEnemiesVector(4);
}

void playGround::stopIntro()
{
	RECT _temp;
	GetWindowRect(_hWnd, &_temp);

	MCIWndDestroy(IntroVideo);
	MoveWindow(_hWnd, _temp.left, _temp.top, _temp.right - _temp.left, _temp.bottom - _temp.top, true);

	_endIntroVideo = true;
}
