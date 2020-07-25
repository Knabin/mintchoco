#include "stdafx.h"
#include "UiManager.h"
#include "stageManager.h"

UiManager::UiManager()
{
}

UiManager::~UiManager()
{
}

HRESULT UiManager::init()
{

	//ui 돈 선언

	_UiCoin._UIimage = IMAGEMANAGER->addImage("UICoin", "images/ui/coin.bmp", 32, 32, true, RGB(255, 0, 255));
	_UiCoin._x = WINSIZEX / 2 - 392;
	_UiCoin._y = WINSIZEY / 2 - 251;
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
		_PlayerHpPoint[i]._x = WINSIZEX / 2 - 127;
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
	_BossHpPoint._rc = RectMakeCenter(_BossHpPoint._x, _BossHpPoint._y,
		_BossHpPoint._UIimage->getWidth(),
		_BossHpPoint._UIimage->getHeight());

	//=============================================================================================================================//

	//Boss_Hpbar 선언

	_BossHpbar._UIimage = IMAGEMANAGER->addImage("BossHPbar", "images/ui/Boss_Hp2.bmp", 560, 84, true, RGB(255, 0, 255));
	_BossHpbar._x = WINSIZEX / 2;
	_BossHpbar._y = WINSIZEY / 2 + 300;
	_BossHpbar._rc = RectMakeCenter(_BossHpbar._x, _BossHpbar._y,
		_BossHpbar._UIimage->getWidth(),
		_BossHpbar._UIimage->getHeight());

	//=============================================================================================================================//

	//Boss_Name 선언

	_BossName._UIimage = IMAGEMANAGER->addImage("BossName", "images/ui/Boss_Name2.bmp", 130, 35, true, RGB(255, 0, 255));
	_BossName._x = WINSIZEX / 2 - 28;
	_BossName._y = WINSIZEY / 2 + 290;
	_BossName._rc = RectMakeCenter(_BossName._x, _BossName._y,
		_BossName._UIimage->getWidth(),
		_BossName._UIimage->getHeight());

	//=============================================================================================================================//
	_BossHpPointHide._UIimage = IMAGEMANAGER->addImage("BossHpBarHide", "images/ui/Boss_Hpbar_Hide.bmp", 437, 35, true, RGB(255, 0, 255));
	_BossHpPointHide._x = WINSIZEX / 2 - 46;
	_BossHpPointHide._y = WINSIZEY / 2 + 306;
	_BossHpPointHide._rc = RectMakeCenter(_BossHpPointHide._x, _BossHpPointHide._y,
		_BossHpPointHide._UIimage->getWidth(),
		_BossHpPointHide._UIimage->getHeight());

	IMAGEMANAGER->addImage("kyoko1", "images/ui/ui_kyoko1.bmp", 684, 816, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("kyoko2", "images/ui/ui_kyoko2.bmp", 684, 816, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("kyoko3", "images/ui/ui_kyoko3.bmp", 684, 816, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("misuzu1", "images/ui/ui_misuzu1.bmp", 684, 816, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("misuzu2", "images/ui/ui_misuzu2.bmp", 684, 816, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("misuzu3", "images/ui/ui_misuzu3.bmp", 684, 816, true, RGB(255, 0, 255));

	_saveRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + 150, 220, 70);
	_scriptIndex = _txtIndex = _endCount = 0;

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
	MiniMapMove(); //미니맵 이동,상태 함수
}

void UiManager::render(HDC hdc)
{
											     	 //Player//
	//=============================================================================================================================//
	if (!_scriptStart)
	{
		IMAGEMANAGER->findImage("HPbar")->render(hdc, _PlayerHpBar._x - 165, _PlayerHpBar._y - 45);

		IMAGEMANAGER->findImage("PlayerImage")->render(hdc, _PlayerImage._x - 60, _PlayerImage._y - 78);

		for (int i = 0; i < 26; i++)
		{
			IMAGEMANAGER->findImage("HPpoint")->render(hdc, _PlayerHpPoint[i]._x - 11 * i, _PlayerHpPoint[i]._y);
		}

		//=============================================================================================================================//

		IMAGEMANAGER->findImage("UICoin")->render(hdc, _UiCoin._x - 18, _UiCoin._y - 18);
	}
	else
	{
		IMAGEMANAGER->findImage("kyoko1")->render(hdc, 0, 0);
	}

														//Boss//
	//=============================================================================================================================//

	if (_stageManager->getNowbossStage() == true)		
	{
		IMAGEMANAGER->findImage("BossHPpoint")->render(hdc, _BossHpPoint._x - 218, _BossHpPoint._y - 17);

		IMAGEMANAGER->findImage("BossHpBarHide")->render(hdc, _BossHpPointHide._x - 648, _BossHpPointHide._y - 6);

		IMAGEMANAGER->findImage("BossHPbar")->render(hdc, _BossHpbar._x - 280, _BossHpbar._y - 42);

		IMAGEMANAGER->findImage("BossName")->render(hdc, _BossName._x - 75, _BossName._y - 17);

		IMAGEMANAGER->findImage("UiHide")->render(hdc, -975, 640);
	}

	else
	{
		IMAGEMANAGER->findImage("kyoko1")->render(hdc, 0, 0);
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

	//cout << _saveRc.left << ", " << _ptMouse.x << "    " << _saveRc.top << ", " << _ptMouse.y << endl;
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_saveRc, _ptMouse))
	{
		dataManager::getInstance()->saveData(26, 10, _stageManager->getNowStage());
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

	case OPENSTOP:
	{

	}
	break;

	case CLOSESTOP:
	{

	}
	break;
	}
}


//player Hp 감소
void UiManager::PlayerHpMinus()
{
	for (int i = 0; i < 26; i++)
	{
		if (_PlayerHpPoint[i]._y < CAMERA->getTop() - 200) continue;  // if문의 정수 변경시 감소 속도 조절
		{
			_PlayerHpPoint[i]._y -= 500;
			break;
		}
	}
}

void UiManager::PlayerDeath()
{

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
