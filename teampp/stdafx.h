#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

using namespace std;

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "utils.h"
#include "collision.h"
#include "imageManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "soundManager.h"
#include "sceneManager.h"
#include "keyAniManager.h"
#include "txtData.h"
#include "iniDataManager.h"
#include "zOrder.h"
#include "camera.h"
#include "dataManager.h"

using namespace TTYONE_UTIL;

//MS VS버전이 올라가면서 기존의 문자열 함수의 안정성을 올리기위해
//_s를 붙인 함수를 사용하게끔 경고하는 메시지를 무시해준다


// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
#define WINNAME (LPCTSTR)(TEXT("River City Girls"))
#define WINSTARTX	50
#define WINSTARTY	50
#define WINSIZEX	1280	
#define WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define RND randomFunction::getInstance()
#define KEYMANAGER keyManager::getInstance()
#define IMAGEMANAGER imageManager::getInstance()
#define TIMEMANAGER timeManager::getInstance()
#define EFFECTMANAGER effectManager::getInstance()
#define SOUNDMANAGER soundManager::getInstance()
#define SCENEMANAGER sceneManager::getInstance()
#define KEYANIMANAGER keyAniManager::getInstance()
#define ZORDER zOrder::getInstance()
#define TXTDATA txtData::getInstance()
#define INIDATA iniDataManager::getInstance()
#define CAMERA camera::getInstance()

#define SAFE_DELETE(p)		{if(p) {delete(p); (p) = NULL;}}
#define SAFE_RELEASE(p)		{if(p) {(p)->release(); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[](p); (p) = NULL;}}

//====================================
// ## 20.05.29 ## Extern ##
//====================================

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;