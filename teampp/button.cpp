#include "stdafx.h"
#include "button.h"


button::button()
{
}


button::~button()
{
}

HRESULT button::init(const char * imageName, float x, float y, POINT btnDownFramePoint, POINT btnUpFramePoint, CALLBACK_FUNCTION cbFunction)
{
	//�ݹ��Լ� �ʱ�ȭ
	_callbackFunction = static_cast<CALLBACK_FUNCTION>(cbFunction);

	//ó���� ��ư ���´� �ʱ�ȭ �� ����
	_direction = BUTTONDIRECTION_NULL;

	//��ư�� ��ǥ
	_x = x;
	_y = y;

	//��ư �̹����� ������ ��ȣ
	_btnUpFramePoint = btnUpFramePoint;
	_btnDownFramePoint = btnDownFramePoint;

	//��ư �̹���
	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(x, y, _image->getFrameWidth(), _image->getFrameHeight());


	return S_OK;
}

void button::release()
{
}

void button::update()
{
	if (PtInRect(&_rc, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_direction = BUTTONDIRECTION_DOWN;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && _direction == BUTTONDIRECTION_DOWN)
		{
			_direction = BUTTONDIRECTION_UP;
			_callbackFunction();
		}

	}
	else _direction = BUTTONDIRECTION_NULL;

}

void button::render()
{
	switch (_direction)
	{
		case BUTTONDIRECTION_NULL:	case BUTTONDIRECTION_UP:
			_image->frameRender(getMemDC(), _rc.left, _rc.top,
				_btnUpFramePoint.x, _btnUpFramePoint.y);
		break;
		case BUTTONDIRECTION_DOWN:
			_image->frameRender(getMemDC(), _rc.left, _rc.top,
				_btnDownFramePoint.x, _btnDownFramePoint.y);
		break;
	
	}
}
