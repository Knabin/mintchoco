#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//珥덇린???⑥닔
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

	_enemyManager->setBossMove();

	//_enemyManager->setEnemyCheerMove();
	//_enemyManager->setEnemySchoolBoyMove();
	//_enemyManager->setEnemySchoolGirlMove();

	// ==========================================
	// ## 移대찓??以묒젏 珥덇린??##
	// ==========================================
	// ?뚮젅?댁뼱 ?쇳꽣???뚯뒪?몄슜 ?됲듃(MYRECT) 留뚮뱾?댁꽌 ?ъ슜?섏꽭??
	CAMERA->setPosition(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());
	CAMERA->setBackWidth(_stageManager->getPixelImage()->getWidth());
	CAMERA->setBackHeight(_stageManager->getPixelImage()->getHeight());

	return S_OK;
}

//硫붾え由??댁젣
void playGround::release()
{
	_stageManager->release();
	_player->release();
	_enemyManager->release();
}

//?곗궛
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
		//INIDATA->addData("?뚮젅?댁뼱", "HP", to_string(_player->getPlayerHP()).c_str());
		//INIDATA->addData("?뚮젅?댁뼱", "肄붿씤", to_string(_player->getCoin()).c_str());
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
	// ## 移대찓??以묒젏 珥덇린??##
	// ==========================================
	CAMERA->shakeStart();
	// ?뚮젅?댁뼱 ?쇳꽣???뚯뒪?몄슜 ?됲듃(MYRECT) 留뚮뱾?댁꽌 ?ъ슜?섏꽭??
	//CAMERA->setPosition(WINSIZEX/2, WINSIZEY/2);
	// ?곕씪?ㅻ뒗 移대찓??
	CAMERA->changePosition(_player->getPlayerRect().getCenterX(), _player->getPlayerRect().getCenterY());
	
}

//끄억
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

	//SetBkMode(getMemDC(), TRANSPARENT);
	//char str[1024];
	//HFONT font, oldFont;
	//RECT rcText = RectMake(WINSIZEX / 2, WINSIZEY / 2, 800, 800);
	//font = CreateFont(40, 0, 100, 0, 400, false, false, false,
	//	DEFAULT_CHARSET,
	//	OUT_STRING_PRECIS,
	//	CLIP_DEFAULT_PRECIS,
	//	PROOF_QUALITY,
	//	DEFAULT_PITCH | FF_SWISS,
	//	TEXT("굴림체"));

	//oldFont = (HFONT)SelectObject(getMemDC(), font);
	//DrawText(getMemDC(), TEXT("으아아아아"), strlen("으아아아아"), &rcText,
	//	DT_LEFT | DT_NOCLIP | DT_WORDBREAK);

	//=============================================
	_backBuffer->render(CAMERA->getMemDC(), 0, CAMERA->getBlackSize() * 0.5,
		CAMERA->getLeft(), CAMERA->getTop() + CAMERA->getShakeNumber(),
		CAMERA->getViewWidth(), CAMERA->getViewHeight());
	_uiManager->render(CAMERA->getMemDC());
	CAMERA->render(getHDC());
}