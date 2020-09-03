#include "stdafx.h"
#include "UiManager.h"
#include "stageManager.h"
#include "player.h"

UiManager::UiManager()
{
}

UiManager::~UiManager()
{
}

HRESULT UiManager::init()
{

	//ui 현재 소지금 선언

	for (int i = 0; i < 5; i++)
	{
		_CurrentCoin[i]._UIimage = IMAGEMANAGER->addImage("0", "images/ui/0.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("1", "images/ui/1.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("2", "images/ui/2.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("3", "images/ui/3.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("4", "images/ui/4.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("5", "images/ui/5.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("6", "images/ui/6.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("7", "images/ui/7.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("8", "images/ui/8.bmp", 18, 25, true, RGB(255, 0, 255));
		IMAGEMANAGER->addImage("9", "images/ui/9.bmp", 18, 25, true, RGB(255, 0, 255));

		_CurrentCoin[i]._x = WINSIZEX / 2 - 372;
		_CurrentCoin[i]._y = WINSIZEX / 2 - 547;
		_CurrentCoin[i]._rc = RectMakeCenter(_CurrentCoin[i]._x + 23 * i, _CurrentCoin[i]._y, 18, 25);
	}


	//ui 돈 선언

	_UiCoin._UIimage = IMAGEMANAGER->addImage("UICoin", "images/ui/coin.bmp", 32, 32, true, RGB(255, 0, 255));
	_UiCoin._x = WINSIZEX / 2 - 392;
	_UiCoin._y = WINSIZEY / 2 - 249;
	_UiCoin._rc = RectMakeCenter(_UiCoin._x, _UiCoin._y, _UiCoin._UIimage->getWidth(), _UiCoin._UIimage->getHeight());

	//=============================================================================================================================//

	//MiniMap 선언

	_MiniMap._UIimage = IMAGEMANAGER->addImage("MiniMap1", "images/ui/miniMap_01.bmp", 350, 609, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("MiniMap2", "images/ui/miniMap_02.bmp", 350, 609, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("MiniMap3", "images/ui/miniMap_03.bmp", 350, 609, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("MiniMap4", "images/ui/miniMap_04.bmp", 350, 609, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("MiniMap5", "images/ui/miniMap_05.bmp", 350, 609, true, RGB(255, 0, 255));
	_MiniMap._x = WINSIZEX / 2;
	_MiniMap._y = WINSIZEY + 500;
	_MiniMap._rc = RectMakeCenter(_MiniMap._x, _MiniMap._y, _MiniMap._UIimage->getWidth(), _MiniMap._UIimage->getHeight());

	_MiniMap._MiniMapState = CLOSESTOP;

	//=============================================================================================================================//

	//Player Image 선언

	_PlayerImage._UIimage = IMAGEMANAGER->addImage("PlayerImage", "images/ui/UI_Kyoko_Portrait.bmp", 120, 135, true, RGB(255, 0, 255));
	_PlayerImage._x = WINSIZEX / 2 - 465;
	_PlayerImage._y = WINSIZEY / 2 - 280;
	_PlayerImage._rc = RectMakeCenter(_PlayerImage._x, _PlayerImage._y,
		_PlayerImage._UIimage->getWidth(),
		_PlayerImage._UIimage->getHeight());

	//=============================================================================================================================//


	//Player HpbarPoint 선언

	for (int i = 0; i < 26; i++)
	{
		_PlayerHpPoint[i]._UIimage = IMAGEMANAGER->addImage("HPpoint", "images/ui/HP_Point.bmp", 20, 18, true, RGB(255, 0, 255));
		_PlayerHpPoint[i]._x = 238;
		_PlayerHpPoint[i]._y = WINSIZEY / 2 - 320;
		_PlayerHpPoint[i]._rc = RectMakeCenter(_PlayerHpPoint[i]._x - 11 * i, _PlayerHpPoint[i]._y,
			_PlayerHpPoint[i]._UIimage->getWidth(),
			_PlayerHpPoint[i]._UIimage->getHeight());
	}

	//=============================================================================================================================//

	//Player_Hpbar 선언

	_PlayerHpBar._UIimage = IMAGEMANAGER->addImage("HPbar", "images/ui/UI_Player_bar_Empty.bmp", 322, 92, true, RGB(255, 0, 255));
	_PlayerHpBar._x = WINSIZEX / 2 - 255;
	_PlayerHpBar._y = WINSIZEY / 2 - 280;
	_PlayerHpBar._rc = RectMakeCenter(_PlayerHpBar._x, _PlayerHpBar._y,
		_PlayerHpBar._UIimage->getWidth(),
		_PlayerHpBar._UIimage->getHeight());

	//=============================================================================================================================//

	//Boss_HpbarPoint 선언

	_BossHpPoint._UIimage = IMAGEMANAGER->addImage("BossHPpoint", "images/ui/Boss_HP_Bar.bmp", 437, 35, true, RGB(255, 0, 255));
	_BossHpPoint._x = WINSIZEX / 2 - 46;
	_BossHpPoint._y = WINSIZEY / 2 + 306;
	_BossHpPoint._Mrc.setCenterPos(_BossHpPoint._x, _BossHpPoint._y);

	//=============================================================================================================================//

	//Boss_Hpbar 선언

	_BossHpbar._UIimage = IMAGEMANAGER->addImage("BossHPbar", "images/ui/Boss_Hp.bmp", 560, 84, true, RGB(255, 0, 255));
	_BossHpbar._x = WINSIZEX / 2;
	_BossHpbar._y = WINSIZEY / 2 + 300;
	_BossHpbar._rc = RectMakeCenter(_BossHpbar._x, _BossHpbar._y,
		_BossHpbar._UIimage->getWidth(),
		_BossHpbar._UIimage->getHeight());

	//=============================================================================================================================//

	//Boss_Name 선언

	_BossName._UIimage = IMAGEMANAGER->addImage("BossName", "images/ui/Boss_Name.bmp", 130, 35, true, RGB(255, 0, 255));
	_BossName._x = WINSIZEX / 2 - 27;
	_BossName._y = WINSIZEY / 2 + 287;
	_BossName._rc = RectMakeCenter(_BossName._x, _BossName._y,
		_BossName._UIimage->getWidth(),
		_BossName._UIimage->getHeight());

	//=============================================================================================================================//

	_BossHpbarHide._UIimage = IMAGEMANAGER->addImage("BossHpbarHide", "images/ui/Boss_Hpbar_Hide3.bmp", 437, 35, true, RGB(255, 0, 255));
	_BossHpbarHide._x = WINSIZEX / 2 - 46;
	_BossHpbarHide._y = WINSIZEY / 2 + 307;
	_BossHpbarHide._rc = RectMakeCenter(_BossHpbarHide._x, _BossHpbarHide._y,
		_BossHpbarHide._UIimage->getWidth(),
		_BossHpbarHide._UIimage->getHeight());

	IMAGEMANAGER->addImage("UiFooter", "images/ui/UI_footer.bmp", 1341, 96, false, RGB(255, 0, 255));

	//=============================================================================================================================//

	SOUNDMANAGER->addSound("menu cursor", "sounds/menu/menu_cursor.wav", false, false);
	SOUNDMANAGER->addSound("menu confirm", "sounds/menu/menu_confirm.wav", false, false);
	SOUNDMANAGER->addSound("menu phone", "sounds/menu/menu_phone_slider_tick.wav", false, false);
	SOUNDMANAGER->addSound("menu select", "sounds/menu/menu_player_select_last.wav", false, false);
	SOUNDMANAGER->addSound("end song", "sounds/bgm/RCG_End_Credits.wav", true, false);

	IMAGEMANAGER->addImage("kyoko1", "images/ui/kyoko_1.bmp", 386, 460, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("kyoko2", "images/ui/kyoko_2.bmp", 386, 460, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("kyoko3", "images/ui/kyoko_3.bmp", 386, 460, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("misuzu1", "images/ui/misuzu_1.bmp", 386, 460, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("misuzu2", "images/ui/misuzu_2.bmp", 386, 460, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("misuzu3", "images/ui/misuzu_3.bmp", 386, 460, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("script k", "images/ui/script_kyoko.bmp", 200, 76, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("script m", "images/ui/script_misuzu.bmp", 200, 76, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("misuzu vs", "images/ui/battle_misuzu.bmp", 1280, 720, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("gameover 1", "images/ui/gameover1.bmp", 679, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gameover 2", "images/ui/gameover2.bmp", 679, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("game end", "images/ui/endLog.bmp", 1280, 4815, false, RGB(255, 0, 255));

	_saveRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 150, 220, 70);
	_scriptIndex = _txtIndex = _endCount = _isGameOver = _restartDirect = _endY = _isGameEnd = _creditCount = 0;

	_playerHP = 26;

	if (TXTDATA->canLoadFile("data/script.data", ';'))
	{
		_vScript = TXTDATA->txtLoad("data/script.data", ";");
	}

	AddFontResource("CookieRun Bold.otf");

	return S_OK;
}

void UiManager::release()
{
	RemoveFontResource("CookieRun Bold.otf");
}

void UiManager::update()
{
	if (_isGameEnd)
	{
		if (_endY > -4815 + WINSIZEY)
		{
			_endY -= 3;
		}
		else
		{
			_creditCount++;
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN) || _creditCount >= 1500)
			{
				_isGameEnd = false;
				_restart = true;
			}
		}
	}
	else if (_isGameOver)
	{
		gameOver();
	}
	else
	{
		BossDeath();
		MiniMapMove(); //미니맵 이동,상태 함수
		if (_scriptStart && !_scriptEnd) printScript();
		else if (_scriptStart && _scriptEnd)
		{
			_endCount++;
			if (_endCount % 200 == 0)
			{
				_endCount = 0;
				_scriptStart = false;
			}
		}
	}
}

void UiManager::render(HDC hdc)
{
	if (_isGameEnd)
	{
		IMAGEMANAGER->findImage("game end")->render(hdc, 0, _endY);
	}
	else if (_isGameOver)
	{
		switch (_gameOverState)
		{
		case GAMEOVERSTATE::RESTART:
			IMAGEMANAGER->findImage("gameover 1")->render(hdc, WINSIZEX / 2 - IMAGEMANAGER->findImage("gameover 1")->getWidth() / 2, WINSIZEY / 2 - IMAGEMANAGER->findImage("gameover 1")->getHeight() / 2);
			break;
		case GAMEOVERSTATE::QUIT:
			IMAGEMANAGER->findImage("gameover 2")->render(hdc, WINSIZEX / 2 - IMAGEMANAGER->findImage("gameover 2")->getWidth() / 2, WINSIZEY / 2 - IMAGEMANAGER->findImage("gameover 2")->getHeight() / 2);
			break;
		}
	}
	else if (!_scriptStart)
	{
		if (_scriptEnd)
		{
			if (_stageManager->getNowbossStage() == true)
			{

				IMAGEMANAGER->findImage("BossHPpoint")->render(hdc, _BossHpPoint._x - 218, _BossHpPoint._y - 17);

				IMAGEMANAGER->findImage("BossHpbarHide")->render(hdc, _BossHpbarHide._x - 648, _BossHpbarHide._y - 7);

				IMAGEMANAGER->findImage("UiFooter")->render(hdc, -975, 650);

				IMAGEMANAGER->findImage("BossHPbar")->render(hdc, _BossHpbar._x - 280, _BossHpbar._y - 42);

				IMAGEMANAGER->findImage("BossName")->render(hdc, _BossName._x - 75, _BossName._y - 17);

			}
		}

		IMAGEMANAGER->findImage("HPbar")->render(hdc, _PlayerHpBar._x - 165, _PlayerHpBar._y - 45);

		IMAGEMANAGER->findImage("PlayerImage")->render(hdc, _PlayerImage._x - 60, _PlayerImage._y - 78);

		for (int i = 0; i < _playerHP; i++)
		{
			IMAGEMANAGER->findImage("HPpoint")->render(hdc, _PlayerHpPoint[i]._x + 11 * i, _PlayerHpPoint[i]._y);
		}

		IMAGEMANAGER->findImage("UICoin")->render(hdc, _UiCoin._x - 18, _UiCoin._y - 18);



		//플레이어 돈 300까지 구현

		for (int i = 0; i < 5; i++)
		{
			IMAGEMANAGER->findImage("0")->render(hdc, _CurrentCoin[i]._x + 23 * i, _CurrentCoin[i]._y);


			if (_player->getCoin() % 9 == 1)
			{
				IMAGEMANAGER->findImage("1")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() % 9 == 2)
			{
				IMAGEMANAGER->findImage("2")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() % 9 == 3)
			{
				IMAGEMANAGER->findImage("3")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() % 9 == 4)
			{
				IMAGEMANAGER->findImage("4")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() % 9 == 5)
			{
				IMAGEMANAGER->findImage("5")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() % 9 == 6)
			{
				IMAGEMANAGER->findImage("6")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() % 9 == 7)
			{
				IMAGEMANAGER->findImage("7")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() % 9 == 8)
			{
				IMAGEMANAGER->findImage("8")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() == 90)
			{
				IMAGEMANAGER->findImage("9")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}
			if (_player->getCoin() == 100)
			{
				IMAGEMANAGER->findImage("1")->render(hdc, _CurrentCoin[2]._x + 46, _CurrentCoin[2]._y);
				IMAGEMANAGER->findImage("0")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
			}

			if (_player->getCoin() >= 101)
			{
				IMAGEMANAGER->findImage("1")->render(hdc, _CurrentCoin[2]._x + 46, _CurrentCoin[2]._y);

				if (_player->getCoin() % 9 == 2)
				{
					IMAGEMANAGER->findImage("1")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 3)
				{
					IMAGEMANAGER->findImage("2")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 4)
				{
					IMAGEMANAGER->findImage("3")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 5)
				{
					IMAGEMANAGER->findImage("4")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 6)
				{
					IMAGEMANAGER->findImage("5")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 7)
				{
					IMAGEMANAGER->findImage("6")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 8)
				{
					IMAGEMANAGER->findImage("7")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() == 180)
				{
					IMAGEMANAGER->findImage("8")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 1)
				{
					IMAGEMANAGER->findImage("9")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() == 200)
				{
					IMAGEMANAGER->findImage("2")->render(hdc, _CurrentCoin[2]._x + 46, _CurrentCoin[2]._y);
					IMAGEMANAGER->findImage("0")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}

			}

			if (_player->getCoin() >= 201)
			{
				IMAGEMANAGER->findImage("2")->render(hdc, _CurrentCoin[2]._x + 46, _CurrentCoin[2]._y);

				if (_player->getCoin() % 9 == 3)
				{
					IMAGEMANAGER->findImage("1")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 4)
				{
					IMAGEMANAGER->findImage("2")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 5)
				{
					IMAGEMANAGER->findImage("3")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 6)
				{
					IMAGEMANAGER->findImage("4")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 7)
				{
					IMAGEMANAGER->findImage("5")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 8)
				{
					IMAGEMANAGER->findImage("6")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() == 270)
				{
					IMAGEMANAGER->findImage("7")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 1)
				{
					IMAGEMANAGER->findImage("8")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() % 9 == 2)
				{
					IMAGEMANAGER->findImage("9")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
				if (_player->getCoin() == 300)
				{
					IMAGEMANAGER->findImage("3")->render(hdc, _CurrentCoin[2]._x + 46, _CurrentCoin[2]._y);
					IMAGEMANAGER->findImage("0")->render(hdc, _CurrentCoin[3]._x + 69, _CurrentCoin[3]._y);
				}
			}

		}					
	}
	else
	{
	// ============== 나빈 추가 ================
		if (_scriptEnd)
		{
			IMAGEMANAGER->findImage("misuzu vs")->render(hdc);
		}
		else
		{
			if (_isKyoko)
			{
				IMAGEMANAGER->findImage("script k")->render(hdc, 0, WINSIZEY - 76);
				switch (_scriptIndex)
				{
				case 1: case 3: case 11:
					IMAGEMANAGER->findImage("kyoko1")->render(hdc, 0, 180);
					break;
				case 7: case 19: case 21:
					IMAGEMANAGER->findImage("kyoko3")->render(hdc, 0, 180);
					break;
				case 15:
					IMAGEMANAGER->findImage("kyoko2")->render(hdc, 0, 180);
					break;
				}

			}
			else
			{
				IMAGEMANAGER->findImage("script m")->render(hdc, 0, WINSIZEY - 76);
				switch (_scriptIndex)
				{
				case 5: case 17:
					IMAGEMANAGER->findImage("misuzu3")->render(hdc, WINSIZEX - IMAGEMANAGER->findImage("misuzu1")->getWidth() - 80, 180);
					break;
				case 9:
					IMAGEMANAGER->findImage("misuzu1")->render(hdc, WINSIZEX - IMAGEMANAGER->findImage("misuzu1")->getWidth() - 80, 180);
					break;
				case 13: case 23:
					IMAGEMANAGER->findImage("misuzu2")->render(hdc, WINSIZEX - IMAGEMANAGER->findImage("misuzu1")->getWidth() - 80, 180);
					break;
				}
			}

			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(255, 255, 255));
			char str[1024];
			HFONT font, oldFont;
			RECT rcText = RectMake(200, WINSIZEY - 56, WINSIZEX - 350, 76);
			font = CreateFont(35, 0, 0, 0, 400, false, false, false,
				DEFAULT_CHARSET,
				OUT_STRING_PRECIS,
				CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY,
				DEFAULT_PITCH | FF_SWISS,
				TEXT("CookieRunOTF Bold"));

			if (_txtIndex > 90)
			{
				rcText = RectMake(200, WINSIZEY - 76, WINSIZEX - 350, 76);
			}

			oldFont = (HFONT)SelectObject(hdc, font);
			DrawText(hdc, TEXT(_txt.c_str()), _txtIndex, &rcText,
				DT_LEFT | DT_WORDBREAK | DT_VCENTER);

			DeleteObject(font);
		}
	}


	// 스테이지 이동 시 미니맵 렌더링 변경
	if (_stageManager->getNowstage1() == true)
	{
		IMAGEMANAGER->findImage("MiniMap1")->render(hdc, _MiniMap._x - 175, _MiniMap._y - 305);
	}
	if (_stageManager->getNowstage2() == true)
	{
		IMAGEMANAGER->findImage("MiniMap2")->render(hdc, _MiniMap._x - 175, _MiniMap._y - 305);
	}
	if (_stageManager->getNowstage3() == true)
	{
		IMAGEMANAGER->findImage("MiniMap3")->render(hdc, _MiniMap._x - 175, _MiniMap._y - 305);
	}
	if (_stageManager->getNowstage4() == true)
	{
		IMAGEMANAGER->findImage("MiniMap4")->render(hdc, _MiniMap._x - 175, _MiniMap._y - 305);
	}
	if (_stageManager->getNowbossStage() == true)
	{
		IMAGEMANAGER->findImage("MiniMap5")->render(hdc, _MiniMap._x - 175, _MiniMap._y - 305);
	}
}


void UiManager::MiniMapMove()
{
	//미니맵 렉트메이커
	_MiniMap._rc = RectMakeCenter(_MiniMap._x, _MiniMap._y, _MiniMap._UIimage->getWidth(), _MiniMap._UIimage->getHeight());


	//키 입력시 미니맵 이동 (키 중복 주의)
	if (KEYMANAGER->isOnceKeyDown('M'))
	{
		SOUNDMANAGER->play("menu phone");
		if (_MiniMap._MiniMapState == CLOSESTOP)
			_MiniMap._MiniMapState = OPEN;
		else if (_MiniMap._MiniMapState == OPENSTOP)
			_MiniMap._MiniMapState = CLOSE;
	}

	if (_MiniMap._y <= WINSIZEY / 2 && _MiniMap._MiniMapState == OPEN)
	{
		_MiniMap._MiniMapState = OPENSTOP;
	}
	if (_MiniMap._y >= WINSIZEY / 2 + 700 && _MiniMap._MiniMapState == CLOSE)
	{
		_MiniMap._MiniMapState = CLOSESTOP;
	}

	if (_MiniMap._MiniMapState == OPENSTOP && KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_saveRc, _ptMouse))
	{
		SOUNDMANAGER->stopAll("");
		SOUNDMANAGER->play("menu confirm");
		dataManager::getInstance()->saveData(_player->getPlayerHP(), _player->getCoin(), _stageManager->getNowStage());
		_restart = true;
	}

	//미니맵 현재 상태
	switch (_MiniMap._MiniMapState)
	{
	case OPEN:
	{
		_MiniMap._y -= 20;
	}
	break;

	case CLOSE:
	{
		_MiniMap._y += 20;
	}
	break;
	}
}


//player Hp 감소
void UiManager::PlayerHpMinus()
{
	_playerHP -= 1;
}

void UiManager::PlayerHpPlus()
{
	

	if (_playerHP < 22)
	{
		_playerHP += 5;
	}
	if (_playerHP == 25)
	{
		_playerHP += 1;
	}
	if (_playerHP == 24)
	{
		_playerHP += 2;
	}
	if (_playerHP == 23)
	{
		_playerHP += 3;
	}
	if (_playerHP == 22)
	{
		_playerHP += 4;
	}
	if (_playerHP >= 26)
	{
		_playerHP += 0;
	}

}

void UiManager::BossHpMinus()
{
	_BossHpPoint._x -= 0.70f;
	_BossHpPoint._y += 0.02f;
}

void UiManager::BossDeath()
{
	if (_BossHpPoint._x < 163)
	{
		_BossHpPoint._x = WINSIZEX / 2 - 46;
		_BossHpPoint._y = WINSIZEY / 2 + 306;
		_isGameEnd = true;
		SOUNDMANAGER->stopAll("");
		SOUNDMANAGER->playBGM("end song");
	}
}

void UiManager::gameOver()
{	
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _gameOverState == GAMEOVERSTATE::RESTART)
	{
		_gameOverState = GAMEOVERSTATE::QUIT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _gameOverState == GAMEOVERSTATE::QUIT)
	{
		_gameOverState = GAMEOVERSTATE::RESTART;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_gameOverState == GAMEOVERSTATE::RESTART)
		{
			SOUNDMANAGER->stopAll("");
			SOUNDMANAGER->play("menu confirm");
			_restartDirect = true;
		}
		else
		{
			SOUNDMANAGER->stopAll("");
			SOUNDMANAGER->play("menu confirm");
			_restart = true;
			_isGameOver = false;
		}
	}	
}

void UiManager::printScript()
{
	_txt = _vScript[_scriptIndex];

	if (_scriptIndex % 2 == 0)
	{
		if (_txt == "K")
			_isKyoko = true;
		else _isKyoko = false;
		_txt = _vScript[++_scriptIndex];
	}

	if (_txtIndex <= _txt.length())
	{
		_txtIndex++;
	}
	else if (_txtIndex >= _txt.length() && KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_scriptIndex++;
		_txtIndex = 0;
	}

	if (_txtIndex < _txt.length() && KEYMANAGER->isOnceKeyDown(VK_SPACE))
		_txtIndex = _txt.length();

	if (_scriptIndex >= _vScript.size())
	{
		if (!SOUNDMANAGER->isPlaySound("bgm boss")) SOUNDMANAGER->play("bgm boss");
		SOUNDMANAGER->stopAll("bgm boss");
		_scriptEnd = true;
	}
}
