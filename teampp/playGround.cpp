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


	_collisionManager->setPlayerMemoryAddressLink(_player);
	_collisionManager->setEnemyManagerMemoryAddressLink(_enemyManager);
	_collisionManager->setStageManagerMemoryAddressLink(_stageManager);
	_collisionManager->setItemManagerMemoryAddressLink(_itemManager);
	_collisionManager->setUiManagerMemoryAddressLink(_uiManager);

	_enemyManager->setStageManagerMemoryAddressLink(_stageManager);
	_uiManager->setStageManagerMemoryAddressLink(_stageManager);


	//_enemyManager->setEnemyCheerMove();
	//_enemyManager->setEnemySchoolBoyMove();
	//_enemyManager->setEnemySchoolGirlMove();

	// ==========================================
	// ## 카메라 중점 초기화 ##
	// ==========================================
	// 플레이어 센터나 테스트용 렉트(MYRECT) 만들어서 사용하세요
	CAMERA->setPosition(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());
	CAMERA->setBackWidth(_stageManager->getPixelImage()->getWidth());
	CAMERA->setBackHeight(_stageManager->getPixelImage()->getHeight());

	return S_OK;
}

//메모리 해제
void playGround::release()
{
	_stageManager->release();
	_player->release();
	_enemyManager->release();
}

//연산
void playGround::update()
{
	gameNode::update();
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
		//INIDATA->addData("플레이어", "HP", to_string(_player->getPlayerHP()).c_str());
		//INIDATA->addData("플레이어", "코인", to_string(_player->getCoin()).c_str());
		vector<string> temp;
		temp.push_back(to_string(100));
		temp.push_back(to_string(10));
		temp.push_back(to_string(_stageManager->getNowStage()));
		TXTDATA->txtSave("data/player.data", temp);
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		cout << TXTDATA->txtLoad("data/player.data")[0] << endl;
		cout << TXTDATA->txtLoad("data/player.data")[1] << endl;
		cout << TXTDATA->txtLoad("data/player.data")[2] << endl;
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

//그리기 전용
void playGround::render()
{
	PatBlt(CAMERA->getMemDC(), 0, 0, getMemDCWidth(), getMemDCHeight(), BLACKNESS);
	PatBlt(getMemDC(), 0, 0, getMemDCWidth(), getMemDCHeight(), BLACKNESS);
	//=================================================
	_stageManager->render();
	_player->render();
	_collisionManager->render();
	_enemyManager->render();
	_itemManager->render();

	ZORDER->render();

	//=============================================
	_backBuffer->render(CAMERA->getMemDC(), 0, CAMERA->getBlackSize() * 0.5,
		CAMERA->getLeft(), CAMERA->getTop() + CAMERA->getShakeNumber(),
		CAMERA->getViewWidth(), CAMERA->getViewHeight());
	_uiManager->render(CAMERA->getMemDC());
	CAMERA->render(getHDC());
}