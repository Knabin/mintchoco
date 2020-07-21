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

	_stageManager2 = new stageManager2;
	_stageManager2->init();

	//_itemManager = new itemManager;
	//_itemManager->init();


	_collisionManager->setPlayerMemoryAddressLink(_player);
	_collisionManager->setEnemyManagerMemoryAddressLink(_enemyManager);
	_collisionManager->setStageManager2MemoryAddressLink(_stageManager2);


	_enemyManager->setEnemyCheerMove();
	_enemyManager->setEnemySchoolBoyMove();
	_enemyManager->setEnemySchoolGirlMove();

	// ==========================================
	// ## 카메라 중점 초기화 ##
	// ==========================================
	// 플레이어 센터나 테스트용 렉트(MYRECT) 만들어서 사용하세요
	CAMERA->setPosition(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());
	CAMERA->setBackWidth(_stageManager2->getPixelImage()->getWidth());
	CAMERA->setBackHeight(_stageManager2->getPixelImage()->getHeight());

	return S_OK;
}

//메모리 해제
void playGround::release()
{
	_stageManager2->release();
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
	_stageManager2->update();
	_uiManager->update();

	_enemyManager->setPlayerPos(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());
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
	PatBlt(getMemDC(), 0, 0, getMemDCWidth(), getMemDCHeight(), BLACKNESS);
	//=================================================
	_stageManager2->render();
	_player->render();
	_collisionManager->render();
	_enemyManager->render();
	//_itemManager->render();
	
	ZORDER->render();

	//=============================================
	_backBuffer->render(getHDC(), 0, CAMERA->getBlackSize() * 0.5,
		CAMERA->getLeft(), CAMERA->getTop() + CAMERA->getShakeNumber(),
		CAMERA->getWidth(), CAMERA->getHeight());
	_uiManager->render(getHDC());
}
