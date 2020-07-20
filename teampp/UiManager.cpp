#include "stdafx.h"
#include "UiManager.h"

UiManager::UiManager()
{
}

UiManager::~UiManager()
{
}

HRESULT UiManager::init()
{
	//MiniMap 선언

	_MiniMap._UIimage = IMAGEMANAGER->addImage("MiniMap1", "images/ui/miniMap_0.bmp", 350, 609, true, RGB(255, 0, 255));
	_MiniMap._x = WINSIZEX / 2;
	_MiniMap._y = WINSIZEY + 500;
	_MiniMap._rc = RectMakeCenter(_MiniMap._x, _MiniMap._y, _MiniMap._UIimage->getWidth(), _MiniMap._UIimage->getHeight());

	_MiniMap._MiniMapState = CLOSESTOP;

	//=============================================================================================================================//

	//Player Image 선언


	_PlayerImage._UIimage = IMAGEMANAGER->addImage("PlayerImage", "images/ui/UI_Kyoko_Portrait.bmp", 100, 113, true, RGB(255, 0, 255));
	_PlayerImage._x = WINSIZEX / 2 - 485;
	_PlayerImage._y = WINSIZEY / 2 - 298;
	_PlayerImage._rc = RectMakeCenter(_PlayerImage._x, _PlayerImage._y,
		_PlayerImage._UIimage->getWidth(),
		_PlayerImage._UIimage->getHeight());

	//=============================================================================================================================//


	//Player HpbarPoint 선언

	for (int i = 0; i < 29; i++)
	{
		_PlayerHpPoint[i]._UIimage = IMAGEMANAGER->addImage("HPpoint", "images/ui/HP_Point.bmp", 20, 18, true, RGB(255, 0, 255));
		_PlayerHpPoint[i]._x = WINSIZEX / 2 - 127;
		_PlayerHpPoint[i]._y = WINSIZEY / 2 - 325;
		_PlayerHpPoint[i]._rc = RectMakeCenter(_PlayerHpPoint[i]._x - 11 * i, _PlayerHpPoint[i]._y,
			_PlayerHpPoint[i]._UIimage->getWidth(),
			_PlayerHpPoint[i]._UIimage->getHeight());
	}

	//=============================================================================================================================//

	//Player_Hpbar 선언

	_PlayerHpBar._UIimage = IMAGEMANAGER->addImage("HPbar", "images/ui/UI_Player_bar_Empty.bmp", 350, 79, true, RGB(255, 0, 255));
	_PlayerHpBar._x = WINSIZEX / 2 - 275;
	_PlayerHpBar._y = WINSIZEY / 2 - 290;
	_PlayerHpBar._rc = RectMakeCenter(_PlayerHpBar._x, _PlayerHpBar._y,
		_PlayerHpBar._UIimage->getWidth(),
		_PlayerHpBar._UIimage->getHeight());

	//=============================================================================================================================//

	//Boss_HpbarPoint 선언

	_BossHpPoint._UIimage = IMAGEMANAGER->addImage("BossHPpoint", "images/ui/Boss_HP_Bar.bmp", 436, 33, true, RGB(255, 0, 255));
	_BossHpPoint._x = WINSIZEX / 2 - 46;
	_BossHpPoint._y = WINSIZEY / 2 + 307;
	_BossHpPoint._rc = RectMakeCenter(_BossHpPoint._x, _BossHpPoint._y,
		_BossHpPoint._UIimage->getWidth(),
		_BossHpPoint._UIimage->getHeight());

	//=============================================================================================================================//

	//Boss_Hpbar 선언

	_BossHpbar._UIimage = IMAGEMANAGER->addImage("BossHPbar", "images/ui/boss_hp.bmp", 560, 84, true, RGB(255, 0, 255));
	_BossHpbar._x = WINSIZEX / 2;
	_BossHpbar._y = WINSIZEY / 2 + 300;
	_BossHpbar._rc = RectMakeCenter(_BossHpbar._x, _BossHpbar._y,
		_BossHpbar._UIimage->getWidth(),
		_BossHpbar._UIimage->getHeight());

	//=============================================================================================================================//

	//Boss_Name 선언

	_BossName._UIimage = IMAGEMANAGER->addImage("BossName", "images/ui/Boss_Name.bmp", 188, 50, true, RGB(255, 0, 255));
	_BossName._x = WINSIZEX / 2 - 100;
	_BossName._y = WINSIZEY / 2 - 100;
	_BossName._rc = RectMakeCenter(_BossName._x, _BossName._y,
		_BossName._UIimage->getWidth(),
		_BossName._UIimage->getHeight());

	//=============================================================================================================================//

	return S_OK;
}

void UiManager::release()
{
}

void UiManager::update()
{
	MiniMapMove(); //미니맵 이동,상태 함수
}

void UiManager::render()
{
	IMAGEMANAGER->findImage("HPbar")->render(getMemDC(), _PlayerHpBar._x - 175, _PlayerHpBar._y - 40);

	IMAGEMANAGER->findImage("PlayerImage")->render(getMemDC(), _PlayerImage._x - 50, _PlayerImage._y - 62);

	for (int i = 0; i < 29; i++)
	{
		IMAGEMANAGER->findImage("HPpoint")->render(getMemDC(), _PlayerHpPoint[i]._x - 11 * i, _PlayerHpPoint[i]._y);
	}

	//IMAGEMANAGER->findImage("BossHPbar")->render(getMemDC(), _BossHpbar._x - 280, _BossHpbar._y - 42);

	//IMAGEMANAGER->findImage("BossHPpoint")->render(getMemDC(), _BossHpPoint._x - 218, _BossHpPoint._y - 17);

	//IMAGEMANAGER->findImage("BossName")->render(getMemDC(), _BossName._x, _BossName._y);

	IMAGEMANAGER->findImage("MiniMap1")->render(getMemDC(), _MiniMap._x - 175, _MiniMap._y - 305);

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

void UiManager::PlayerHpMinus()
{
	for (int i = 0; i < 29; i++)
	{
		if (_PlayerHpPoint[i]._y < -400) continue;  // if문의 정수 변경시 감소 속도 조절
		{
			_PlayerHpPoint[i]._y -= 50;
			break;
		}
	}
}
