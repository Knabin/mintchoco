#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(float x, float y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp", width, height, true, RGB(255, 0, 255));

	//�ڿ� �򸮴� �������� ����ũ�⸦ �������� ��´�
	_width = _progressBarBottom->getWidth();

	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	_rcProgress = RectMakeCenter(_x, _y,
		_progressBarTop->getWidth(),
		_progressBarBottom->getHeight());
}

void progressBar::render()
{
	IMAGEMANAGER->render("backBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2,
		0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render("frontBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2,
		0, 0,
		_width, _progressBarBottom->getHeight());

}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	//����� ���ϴ� �����̿���!
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}
