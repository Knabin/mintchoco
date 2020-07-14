#include "stdafx.h"
#include "saveLoadTest.h"


saveLoadTest::saveLoadTest()
{
}


saveLoadTest::~saveLoadTest()
{
}

void saveLoadTest::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) save();
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) load();
}

void saveLoadTest::save()
{
	//파일 입출력은 다양한 방식이 존재한다
	//C - FILE* (기능이 없고, 그래서 인지 빨라요)
	//C++ - ifstream, ofstream(기능이 많음, 상대적으로 느림)
	//Win32 CreateFile() 이란 함수가 있다

	HANDLE file;
	DWORD write;

	char str[128] = "여러분 지한이는 xx지가 아닙니다";

	file = CreateFile("찬영이가지한이괴롭힌다.txt", GENERIC_WRITE,
		FALSE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);
}

void saveLoadTest::load()
{
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("찬영이가지한이괴롭힌다.txt", GENERIC_READ,
		FALSE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	CloseHandle(file);

	MessageBox(_hWnd, str, "준포폴화이팅", MB_OK);

}
