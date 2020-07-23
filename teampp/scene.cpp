#include "stdafx.h"
#include "scene.h"

scene::scene()
{
}

scene::~scene()
{
}

HRESULT scene::init()
{


	//-----------------------------------------------------------------------------------------------------------------------------/
	//세이브로드 백그라운드 선언

	IMAGEMANAGER->addImage("SaveLoadBackGround", "images/ui/save_load.bmp", 1280, 720, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("SaveLoadOpen", "images/ui/save_load_open.bmp", 487, 200, true, RGB(255, 0, 255));

	_SaveLoadWindowState = W1;

	//-----------------------------------------------------------------------------------------------------------------------------//

	//세이브로드 첫번째 창 선언

	_SaveLoadWindow1.SceneImage = IMAGEMANAGER->addImage("SaveLoadClose1", "images/ui/save_load_close.bmp", 487, 200, true, RGB(255, 0, 255));

	_SaveLoadWindow1._x = WINSIZEX / 2 + 280;
	_SaveLoadWindow1._y = WINSIZEY / 2 - 200;

	_SaveLoadWindow1._rc = RectMakeCenter(_SaveLoadWindow1._x, _SaveLoadWindow1._y, _SaveLoadWindow1.SceneImage->getWidth(), _SaveLoadWindow1.SceneImage->getHeight());

	//-----------------------------------------------------------------------------------------------------------------------------//

	//세이브로드 두번째 창 선언

	_SaveLoadWindow2.SceneImage = IMAGEMANAGER->addImage("SaveLoadClose2", "images/ui/save_load_close.bmp", 487, 200, true, RGB(255, 0, 255));

	_SaveLoadWindow2._x = WINSIZEX / 2 + 280;
	_SaveLoadWindow2._y = WINSIZEY / 2 - 10;

	_SaveLoadWindow2._rc = RectMakeCenter(_SaveLoadWindow2._x, _SaveLoadWindow2._y, _SaveLoadWindow2.SceneImage->getWidth(), _SaveLoadWindow2.SceneImage->getHeight());

	//-----------------------------------------------------------------------------------------------------------------------------//

	//세이브로드 세번째 창 선언

	_SaveLoadWindow3.SceneImage = IMAGEMANAGER->addImage("SaveLoadClose3", "images/ui/save_load_close.bmp", 487, 200, true, RGB(255, 0, 255));

	_SaveLoadWindow3._x = WINSIZEX / 2 + 280;
	_SaveLoadWindow3._y = WINSIZEY / 2 + 180;

	_SaveLoadWindow3._rc = RectMakeCenter(_SaveLoadWindow3._x, _SaveLoadWindow3._y, _SaveLoadWindow3.SceneImage->getWidth(), _SaveLoadWindow3.SceneImage->getHeight());

	//-----------------------------------------------------------------------------------------------------------------------------//


	//타이틀 배경 화면 선언

	IMAGEMANAGER->addImage("타이틀", "images/ui/menu_start.bmp", 1280, 720, false, RGB(0, 0, 0));

	//-----------------------------------------------------------------------------------------------------------------------------//

	//StartQuit 버튼 선언

	_StartQuit.SceneImage = IMAGEMANAGER->addImage("StartQuit", "images/ui/StartScene_Menu.bmp", 150, 114, true, RGB(255, 0, 255));
	_StartQuit._x = WINSIZEX / 2 - 350;
	_StartQuit._y = WINSIZEY / 2 + 125;

	_StartQuit._rc = RectMakeCenter(_StartQuit._x, _StartQuit._y, _StartQuit.SceneImage->getWidth(), _StartQuit.SceneImage->getHeight());

	//-----------------------------------------------------------------------------------------------------------------------------//

	//포인터화살표 버튼 선언
	
	IMAGEMANAGER->addImage("포인터", "images/ui/StartScene_Pointer.bmp", 55, 61, true, RGB(255, 0, 255));

	_Pointer._x = _StartQuit._x - 75;
	_Pointer._y = _StartQuit._y + 15;

	_Pointer._rc = RectMakeCenter(_Pointer._x, _Pointer._y, 50, 50);

	_Pointer._PointerState = START;

	//-----------------------------------------------------------------------------------------------------------------------------//

	//로딩 Scene 배경 선언

	IMAGEMANAGER->addImage("로딩1", "images/ui/Loading01.bmp", 1280, 720, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("로딩2", "images/ui/Loading02.bmp", 1280, 720, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("로딩3", "images/ui/Loading03.bmp", 1280, 720, false, RGB(0, 0, 0));


	//게임 시작이니? 로딩중이니? 아님 세이브 로딩중이니? 그것도 아니면 베틀스타트씬이 재생중이니?
	_SaveLoading = false;
	_Loading = false;
	_GameStart = false;

	_LoadingCount = 0;

	//-----------------------------------------------------------------------------------------------------------------------------//

	// 나빈 추가) 로드 씬 스테이지 이미지 추가

	IMAGEMANAGER->addImage("ui_stage_image1", "images/ui/stage_ui_01.bmp", 114, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stage_image2", "images/ui/stage_ui_02.bmp", 114, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stage_image3", "images/ui/stage_ui_03.bmp", 114, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stage_image4", "images/ui/stage_ui_04.bmp", 114, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stage_image5", "images/ui/stage_ui_05.bmp", 114, 136, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ui_stage_image1 off", "images/ui/stage_ui_01_off.bmp", 114, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stage_image2 off", "images/ui/stage_ui_02_off.bmp", 114, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stage_image3 off", "images/ui/stage_ui_03_off.bmp", 114, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stage_image4 off", "images/ui/stage_ui_04_off.bmp", 114, 136, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stage_image5 off", "images/ui/stage_ui_05_off.bmp", 114, 136, true, RGB(255, 0, 255));
	return S_OK;
}

void scene::release()
{
	ReleaseDC(_hWnd, getHDC());
}

void scene::update()
{

}

void scene::render()
{

}

void scene::PointerMove()
{
	_Pointer._rc = RectMakeCenter(_Pointer._x, _Pointer._y, 50, 50);

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _Pointer._PointerState == START)
	{
		_Pointer._y += 55;
		_Pointer._PointerState = QUIT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _Pointer._PointerState == QUIT)
	{
		_Pointer._y -= 55;
		_Pointer._PointerState = START;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _Pointer._PointerState == START)
	{
		_SaveLoading = true;
		_Loading = false;
		_GameStart = false;
		getPlayerSaveData();
	}

	switch (_Pointer._PointerState)		//포인터가 현재 어디를 가르키고 있나?
	{
		case START:
		{

		}
		break;

		case QUIT:
		{

		}
		break;
		}
}

void scene::SaveLoadMove()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_SaveLoadWindowState == W1)
		{
			_SaveLoadWindowState = W2;
		}

		else if (_SaveLoadWindowState == W2)
		{
			_SaveLoadWindowState = W3;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_SaveLoadWindowState == W3)
		{
			_SaveLoadWindowState = W2;
		}

		else if (_SaveLoadWindowState == W2)
		{
			_SaveLoadWindowState = W1;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _SaveLoadWindowState == W1)
	{
		_SaveLoading = false;
		_Loading = true;
		_GameStart = false;
	}
}


void scene::LoadingCountPlus()
{
	_LoadingCount++;
}

void scene::GameStart()
{
	if (_LoadingCount > 150)
	{
		_SaveLoading = false;
		_Loading = false;
		_GameStart = true;
	}
}


void scene::TitleBackGroundDraw(HDC hdc)
{
	
	IMAGEMANAGER->findImage("타이틀")->render(hdc, 0, 0);

	IMAGEMANAGER->findImage("StartQuit")->render(hdc, _StartQuit._x, _StartQuit._y);

	IMAGEMANAGER->findImage("포인터")->render(hdc, _Pointer._x, _Pointer._y);
	
}

void scene::SaveLoadingBackGroundDraw(HDC hdc)
{
	IMAGEMANAGER->findImage("SaveLoadBackGround")->render(hdc, 0, 0);

	IMAGEMANAGER->findImage("SaveLoadClose1")->render(hdc, _SaveLoadWindow1._x - 244, _SaveLoadWindow1._y - 100);
	IMAGEMANAGER->findImage("SaveLoadClose2")->render(hdc, _SaveLoadWindow2._x - 244, _SaveLoadWindow2._y - 100);
	IMAGEMANAGER->findImage("SaveLoadClose3")->render(hdc, _SaveLoadWindow3._x - 244, _SaveLoadWindow3._y - 100);


	switch (_SaveLoadWindowState)
	{
	case W1:
	{
		IMAGEMANAGER->findImage("SaveLoadOpen")->render(hdc, _SaveLoadWindow1._x - 244, _SaveLoadWindow1._y - 100);
		_saveStage->render(hdc, _SaveLoadWindow1._x - 236, _SaveLoadWindow1._y - 54);
	}
	break;

	case W2:
	{
		IMAGEMANAGER->findImage("SaveLoadOpen")->render(hdc, _SaveLoadWindow2._x - 244, _SaveLoadWindow2._y - 100);
		_saveStageOff->render(hdc, _SaveLoadWindow1._x - 236, _SaveLoadWindow1._y - 54);
	}
	break;

	case W3:
	{
		IMAGEMANAGER->findImage("SaveLoadOpen")->render(hdc, _SaveLoadWindow3._x - 244, _SaveLoadWindow3._y - 100);
		_saveStageOff->render(hdc, _SaveLoadWindow1._x - 236, _SaveLoadWindow1._y - 54);
	}
	break;
	}

	SetBkMode(hdc, TRANSPARENT);
	char str[1024];
	HFONT font, oldFont;
	RECT rcText = RectMake(_SaveLoadWindow1._x, _SaveLoadWindow1._y, 800, 800);
	font = CreateFont(40, 0, 80, 0, 400, false, false, false,
		DEFAULT_CHARSET,
		OUT_STRING_PRECIS,
		CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		TEXT("굴림체"));

	oldFont = (HFONT)SelectObject(getMemDC(), font);
	DrawText(getMemDC(), _stageName.c_str(), _stageName.size(), &rcText,
		DT_LEFT | DT_NOCLIP | DT_WORDBREAK);

}

void scene::LoadingBackGroundDraw(HDC hdc)
{
	if (_LoadingCount <= 30)
	{
		IMAGEMANAGER->findImage("로딩1")->render(hdc, 0, 0);
	}
	if (_LoadingCount > 30)
	{
		IMAGEMANAGER->findImage("로딩2")->render(hdc, 0, 0);
	}
	if (_LoadingCount > 60)
	{
		IMAGEMANAGER->findImage("로딩3")->render(hdc, 0, 0);
	}
	if (_LoadingCount > 90)
	{
		IMAGEMANAGER->findImage("로딩2")->render(hdc, 0, 0);
	}
	if (_LoadingCount > 120)
	{
		IMAGEMANAGER->findImage("로딩1")->render(hdc, 0, 0);
	}	
}


void scene::getPlayerSaveData()
{
	cout << TXTDATA->txtLoad("data/player.data")[0] << endl;
	cout << TXTDATA->txtLoad("data/player.data")[1] << endl;
	cout << TXTDATA->txtLoad("data/player.data")[2] << endl;
	_stageNum = atoi(TXTDATA->txtLoad("data/player.data")[2].c_str());

	switch (_stageNum)
	{
	case 0:
		_saveStage = IMAGEMANAGER->findImage("ui_stage_image1");
		_saveStageOff = IMAGEMANAGER->findImage("ui_stage_image1 off");
		_stageName = "반성실";
		break;
	case 1:
		_saveStage = IMAGEMANAGER->findImage("ui_stage_image2");
		_saveStageOff = IMAGEMANAGER->findImage("ui_stage_image2 off");
		_stageName = "1층 복도";
		break;
	case 2:
		_saveStage = IMAGEMANAGER->findImage("ui_stage_image3");
		_saveStageOff = IMAGEMANAGER->findImage("ui_stage_image3 off");
		_stageName = "2층 복도";
		break;
	case 3:
		_saveStage = IMAGEMANAGER->findImage("ui_stage_image4");
		_saveStageOff = IMAGEMANAGER->findImage("ui_stage_image4 off");
		_stageName = "화학실";
		break;
	case 4:
		_saveStage = IMAGEMANAGER->findImage("ui_stage_image5");
		_saveStageOff = IMAGEMANAGER->findImage("ui_stage_image5 off");
		_stageName = "학교 로비";
		break;
	default:
		break;
	}
}