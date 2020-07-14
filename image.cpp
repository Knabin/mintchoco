#include "stdafx.h"
#include "image.h"

//#pragma <- �����Ϸ� ���ñ�
#pragma comment(lib, "msimg32.lib")

//��� �̴ϼȶ�����
image::image()
	: _imageInfo(NULL),
	_fileName(NULL),
	_trans(false),
	_transColor(RGB(0,0,0))
{
}


image::~image()
{
}

HRESULT image::init(int width, int height)
{
	//����ó��
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���� ������ �����ؼ� ����۰� NULL�̸�
	if (_imageInfo == NULL)
	{
		//�޸� ���� ��
		release();

		//�����ߴ� �޼����� ȣ���ض�
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);


	return S_OK;
}

HRESULT image::init(const char * fileName, int width, int height, BOOL trans, COLORREF transColor)
{
	//�̹��� ������ Ȥ�ó� �����ִٸ� �����ض�
	if (_imageInfo != NULL) release();

	//DC������ ������ ����ϰ� ������
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);	//�� DC���� �ϳ� ����
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//��Ʈ�� ������ ������ ���� �ʾҴٸ�
	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;


	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char * fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	//�̹��� ������ Ȥ�ó� �����ִٸ� �����ض�
	if (_imageInfo != NULL) release();

	//DC������ ������ ����ϰ� ������
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);	//�� DC���� �ϳ� ����
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x - (width / 2);
	_imageInfo->y = y - (height / 2);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//��Ʈ�� ������ ������ ���� �ʾҴٸ�
	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char * fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	//�̹��� ������ Ȥ�ó� �����ִٸ� �����ض�
	if (_imageInfo != NULL) release();

	//DC������ ������ ����ϰ� ������
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);	//�� DC���� �ϳ� ����
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//��Ʈ�� ������ ������ ���� �ʾҴٸ�
	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

void image::release()
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
		DeleteObject(_blendImage->hBit);
		DeleteDC(_blendImage->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);
		SAFE_DELETE(_blendImage);

		_trans = false;
		_transColor = RGB(0, 0, 0);
	}
}

void image::setTransColor(BOOL trans, COLORREF transColor)
{
	_trans = trans;
	_transColor = transColor;
}

void image::render(HDC hdc)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//����� ���� DC
			_imageInfo->x,					//����� ��ǥ X
			_imageInfo->y,					//����� ��ǥ Y
			_imageInfo->width,		//����� ũ�� (����)
			_imageInfo->height,		//����� ũ�� (����)
			_imageInfo->hMemDC,		//�����ؿ� DC
			0, 0,					//�����ؿ� ��ǥ X,Y
			_imageInfo->width,		//������ ����ũ��
			_imageInfo->height,		//������ ����ũ��
			_transColor);			//�����Ҷ� ������ �ȼ���
	}
	else
	{
		//DC���� ���� ��Ӻ��縦 ���ִ� �Լ� BitBlt
		BitBlt(hdc,					//������ DC
			_imageInfo->x,			//������ X��ǥ(left)
			_imageInfo->y,			//������ Y��ǥ(top)
			_imageInfo->width,		//������ ũ��
			_imageInfo->height,		//������ ũ��
			_imageInfo->hMemDC,		//����� DC
			0, 0,					//����� X,Y(left, top)
			SRCCOPY);				//�������� �����ϰڴ�
	}
}

void image::render(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//����� ���� DC
			destX,					//����� ��ǥ X
			destY,					//����� ��ǥ Y
			_imageInfo->width,		//����� ũ�� (����)
			_imageInfo->height,		//����� ũ�� (����)
			_imageInfo->hMemDC,		//�����ؿ� DC
			0, 0,					//�����ؿ� ��ǥ X,Y
			_imageInfo->width,		//������ ����ũ��
			_imageInfo->height,		//������ ����ũ��
			_transColor);			//�����Ҷ� ������ �ȼ���
	}
	else
	{
		//DC���� ���� ��Ӻ��縦 ���ִ� �Լ� BitBlt
		BitBlt(hdc,					//������ DC
			destX,					//������ X��ǥ(left)
			destY,					//������ Y��ǥ(top)
			_imageInfo->width,		//������ ũ��
			_imageInfo->height,	//������ ũ��
			_imageInfo->hMemDC,	//����� DC
			0, 0,					//����� X,Y(left, top)
			SRCCOPY);				//�������� �����ϰڴ�
	}
	

}

void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//����� ���� DC
			destX,					//����� ��ǥ X
			destY,					//����� ��ǥ Y
			sourWidth,				//����� ũ�� (����)
			sourHeight,				//����� ũ�� (����)
			_imageInfo->hMemDC,		//�����ؿ� DC
			sourX, sourY,			//�����ؿ� ��ǥ X,Y
			sourWidth,				//������ ����ũ��
			sourHeight,				//������ ����ũ��
			_transColor);			//�����Ҷ� ������ �ȼ���
	}
	else
	{
		//DC���� ���� ��Ӻ��縦 ���ִ� �Լ� BitBlt
		BitBlt(hdc,					//������ DC
			destX,					//������ X��ǥ(left)
			destY,					//������ Y��ǥ(top)
			sourWidth,				//������ ũ��
			sourHeight,				//������ ũ��
			_imageInfo->hMemDC,		//����� DC
			sourX, sourY,			//����� X,Y(left, top)
			SRCCOPY);				//�������� �����ϰڴ�
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//����� ���� DC
			destX,					//����� ��ǥ X
			destY,					//����� ��ǥ Y
			_imageInfo->frameWidth,	//����� ũ�� (����)
			_imageInfo->frameHeight,//����� ũ�� (����)
			_imageInfo->hMemDC,		//�����ؿ� DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,			//�����ؿ� ��ǥ X,Y
			_imageInfo->frameWidth,								//������ ����ũ��
			_imageInfo->frameHeight,							//������ ����ũ��
			_transColor);			//�����Ҷ� ������ �ȼ���
	}
	else
	{
		//DC���� ���� ��Ӻ��縦 ���ִ� �Լ� BitBlt
		BitBlt(hdc,							//������ DC
			destX,							//������ X��ǥ(left)
			destY,							//������ Y��ǥ(top)
			_imageInfo->frameWidth,			//������ ũ��
			_imageInfo->frameHeight,		//������ ũ��
			_imageInfo->hMemDC,				//����� DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,			//����� X,Y(left, top)
			SRCCOPY);				//�������� �����ϰڴ�
	}
}

void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//����� ���� DC
			destX,					//����� ��ǥ X
			destY,					//����� ��ǥ Y
			_imageInfo->frameWidth,	//����� ũ�� (����)
			_imageInfo->frameHeight,//����� ũ�� (����)
			_imageInfo->hMemDC,		//�����ؿ� DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,			//�����ؿ� ��ǥ X,Y
			_imageInfo->frameWidth,								//������ ����ũ��
			_imageInfo->frameHeight,							//������ ����ũ��
			_transColor);			//�����Ҷ� ������ �ȼ���
	}
	else
	{
		//DC���� ���� ��Ӻ��縦 ���ִ� �Լ� BitBlt
		BitBlt(hdc,							//������ DC
			destX,							//������ X��ǥ(left)
			destY,							//������ Y��ǥ(top)
			_imageInfo->frameWidth,			//������ ũ��
			_imageInfo->frameHeight,		//������ ũ��
			_imageInfo->hMemDC,				//����� DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,			//����� X,Y(left, top)
			SRCCOPY);				//�������� �����ϰڴ�
	}
}

void image::loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	//������ ����ó���� �Ҷ� ������ �����ڸ� �� �̿��սô�
	if (offSetX < 0) offSetX = _imageInfo->width + (offSetX % _imageInfo->width);
	if (offSetY < 0) offSetY = _imageInfo->height + (offSetY % _imageInfo->height);

	int sourWidth;
	int sourHeight;

	RECT rcDest;
	RECT rcSour;

	int drawAreaX = drawArea->left;					//�׷��� ���� left
	int drawAreaY = drawArea->top;					//�׷��� ���� top
	int drawAreaW = drawArea->right - drawAreaX;	//�׷��� ���� width
	int drawAreaH = drawArea->bottom - drawAreaY;	//�׷��� ���� height

	//���κ���
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		rcSour.top = (y + offSetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;

		//ȭ�� �� ���� ���� Ȯ��
		if (y + sourHeight > drawAreaH)
		{
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}


		//ȭ������� ����������ŭ�� �����Ѵ�
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			rcSour.left = (x + offSetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;

			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			render(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top);
		}


	}


}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, 0, 0, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_transColor);

		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y,
			_imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width,
			_imageInfo->height, _blendFunc);

	}
	else
	{
		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width,
			_imageInfo->height, _blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_transColor);

		AlphaBlend(hdc, destX, destY,
			_imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width,
			_imageInfo->height, _blendFunc);

	}
	else
	{
		AlphaBlend(hdc, destX, destY,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width,
			_imageInfo->height, _blendFunc);
	}
}

void image::aniRender(HDC hdc, int destX, int destY, animation* ani)
{
	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}
