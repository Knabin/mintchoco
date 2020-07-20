#include "stdafx.h"
#include "zOrder.h"

HRESULT zOrder::init()
{

	return S_OK;
}

void zOrder::release()
{
	_vObject.clear();
}

void zOrder::update()
{
}

void zOrder::render()
{
	sortVector(0, _vObject.size()-1);


	//for (int i = 0; i < _vObject.size(); ++i)
	//{
	//	for (int j = 0; j < _vObject.size(); ++j)
	//	{
	//		if (_vObject[i].z == _vObject[j].z)
	//		{
	//			if (_vObject[i].type == 0 && i < j)
	//			{
	//				swap(_vObject[i], _vObject[j]);
	//			}
	//		}
	//	}
	//}

	int index = -1;
	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (_vObject[i].type == PLAYER)
		{
			index = i;
			break;
		}
	}
	if (index >= 0)
	{
		for (int i = 0; i < _vObject.size(); ++i)
		{
			if (_vObject[i].z == _vObject[index].z && index < i)
			{
				swap(_vObject[i], _vObject[index]);
				index = i;
			}
		}
	}




	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (_vObject[i].ani != nullptr)
		{
			// 애니 렌더
			_vObject[i].image->aniRender(_vObject[i].hdc, _vObject[i].x -_vObject[i].image->getFrameWidth()/2, _vObject[i].z -_vObject[i].image->getFrameHeight() - _vObject[i].jumpPower, _vObject[i].ani);
		}
		else if (_vObject[i].frameX > -1 && _vObject[i].frameY > -1)
		{
			// 프레임 렌더
			_vObject[i].image->frameRender(_vObject[i].hdc, _vObject[i].x - _vObject[i].image->getFrameWidth() / 2, _vObject[i].z - _vObject[i].image->getFrameHeight() - _vObject[i].jumpPower, _vObject[i].frameX, _vObject[i].frameY);
		}
		else
		{
			// 일반 렌더
			_vObject[i].image->render(_vObject[i].hdc, _vObject[i].x - _vObject[i].image->getWidth() / 2, _vObject[i].z - _vObject[i].image->getHeight() - _vObject[i].jumpPower);
		}
	}




	_vObject.clear();

	
}

void zOrder::pushObject(HDC hdc, image * img, int type, float x, float jumpPower, float z)
{
	tagObject obj;
	obj.image = img;
	obj.ani = nullptr;
	obj.hdc = hdc;
	obj.type = type;
	obj.x = x;
	obj.jumpPower = jumpPower;
	obj.z = z;
	obj.frameX = -1;
	obj.frameY = -1;

	_vObject.push_back(obj);
}

void zOrder::pushObject(HDC hdc, const char * imageName, int type, float x, float jumpPower, float z)
{
	tagObject obj;
	obj.image = IMAGEMANAGER->findImage(imageName);
	obj.ani = nullptr;
	obj.hdc = hdc;
	obj.type = type;
	obj.x = x;
	obj.jumpPower = jumpPower;
	obj.z = z;
	obj.frameX = -1;
	obj.frameY = -1;

	_vObject.push_back(obj);
}

void zOrder::pushObject(HDC hdc, image * img, float frameX, float frameY, int type, float x, float jumpPower, float z)
{
	tagObject obj;
	obj.image = img;
	obj.ani = nullptr;
	obj.hdc = hdc;
	obj.type = type;
	obj.x = x;
	obj.jumpPower = jumpPower;
	obj.z = z;
	obj.frameX = frameX;
	obj.frameY = frameY;

	_vObject.push_back(obj);
}

void zOrder::pushObject(HDC hdc, const char * imageName, float frameX, float frameY, int type, float x, float jumpPower, float z)
{
	tagObject obj;
	obj.image = IMAGEMANAGER->findImage(imageName);
	obj.ani = nullptr;
	obj.hdc = hdc;
	obj.type = type;
	obj.x = x;
	obj.jumpPower = jumpPower;
	obj.z = z;
	obj.frameX = frameX;
	obj.frameY = frameY;

	_vObject.push_back(obj);
}

void zOrder::pushObject(HDC hdc, image * img, animation * ani, int type, float x, float jumpPower, float z)
{
	tagObject obj;
	obj.image = img;
	obj.ani = ani;
	obj.hdc = hdc;
	obj.type = type;
	obj.x = x;
	obj.jumpPower = jumpPower;
	obj.z = z;
	obj.frameX = -1;
	obj.frameY = -1;

	_vObject.push_back(obj);
}

void zOrder::pushObject(HDC hdc, const char * imageName, animation * ani, int type, float x, float jumpPower, float z)
{
	tagObject obj;
	obj.image = IMAGEMANAGER->findImage(imageName);
	obj.ani = ani;
	obj.hdc = hdc;
	obj.type = type;
	obj.x = x;
	obj.jumpPower = jumpPower;
	obj.z = z;
	obj.frameX = -1;
	obj.frameY = -1;

	_vObject.push_back(obj);
}

void zOrder::sortVector(int start, int end)
{
	//cout << start << ", " << end << endl;
	if (start >= end) return;
	int pivot = _vObject[(start+end) / 2].z;
	int left = start;
	int right = end;

	while (left <= right)
	{
		// left랑 pivot 비교해서 left가 작으면 ++
		while (_vObject[left].z < pivot) ++left;
		// right랑 pivot 비교해서 right가 크면 --
		while (_vObject[right].z > pivot) --right;

		// 두 개 스왑
		if (left <= right)
		{
			swap(_vObject[left], _vObject[right]);
			++left;
			--right;
		}
	}
	sortVector(start, right);
	sortVector(left, end);
}

