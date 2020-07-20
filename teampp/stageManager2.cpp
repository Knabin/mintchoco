#include "stdafx.h"
#include "stageManager2.h"

stageManager2::stageManager2()
{
}

stageManager2::~stageManager2()
{
}

HRESULT stageManager2::init()
{
	_Stage1 = new stage01;
	_Stage1->init();

	_Stage2 = new stage02;
	_Stage2->init();

	_Stage3 = new stage03;
	_Stage3->init();

	_NowStage = S1;
	_NowStage1 = true;
	_NowStage2 = false;
	_NowStage3 = false;

	return S_OK;
}

void stageManager2::release()
{
}

void stageManager2::update()
{
}

void stageManager2::render()
{
	NowStage();
}

void stageManager2::NowStage()
{
	switch (_NowStage)
	{
	case S1:
	{
		_Stage1->render();
	}
	break;
	case S2:
	{
		_Stage2->render();
	}
	break;
	case S3:
	{
		_Stage3->render();
	}
	break;
	}
}

void stageManager2::Stage1Move()
{
	_NowStage = S1;
	_NowStage1 = true;
	_NowStage2 = false;
	_NowStage3 = false;
}

void stageManager2::Stage2Move()
{
	_NowStage = S2;
	_NowStage1 = false;
	_NowStage2 = true;
	_NowStage3 = false;
}

void stageManager2::Stage3Move()
{
	_NowStage = S3;
	_NowStage1 = false;
	_NowStage2 = false;
	_NowStage3 = true;
}
