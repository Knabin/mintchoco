#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(const char * imageName, POINT position)
{
	_currentFrameX = _currentFrameY = 0;
	_count = _fireCount = 0;

	//에너미 이미지는 키값으로 넣어주자
	_imageName = IMAGEMANAGER->findImage(imageName);

	_rndFireCount = RND->getFromIntTo(1, 700);

	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getFrameWidth(),
		_imageName->getFrameHeight());

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	_count++;

	if (_count % 2 == 0)
	{
		if (_currentFrameX >= _imageName->getMaxFrameX()) _currentFrameX = 0;
		_imageName->setFrameX(_currentFrameX);
		_currentFrameX++;
		_count = 0;
	}

}

void enemy::render()
{
	draw();
}

void enemy::move()
{
	switch (_direction)
	{
	case SIDE:
		break;
	case UPDOWN:
		break;
	case FREE:
		break;
	
	}
}

void enemy::draw()
{
	//이미지는 1장인데 렉트 위치가 서로 다르게 위치해있으면
	//렉트를 기반으로 그리기 때문에 1장가지고 충분히 사용가능하다

	_imageName->frameRender(getMemDC(), _rc.left, _rc.top,
		_currentFrameX, _currentFrameY);
}

bool enemy::bulletCountFire()
{
	_fireCount++;

	if (_fireCount % _rndFireCount == 0)
	{
		_rndFireCount = RND->getFromIntTo(1, 700);
		_fireCount = 0;

		return true;
	}


	return false;
}
