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
	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (_vObject[i].ani != nullptr)
		{
			// �ִ� ����
			_vObject[i].image->aniRender(_vObject[i].hdc, _vObject[i].x, _vObject[i].z - _vObject[i].jumpPower, _vObject[i].ani);
		}
		else if (_vObject[i].frameX > -1 && _vObject[i].frameY > -1)
		{
			// ������ ����
			_vObject[i].image->frameRender(_vObject[i].hdc, _vObject[i].x, _vObject[i].z - _vObject[i].jumpPower, _vObject[i].frameX, _vObject[i].frameY);
		}
		else
		{
			// �Ϲ� ����
			_vObject[i].image->render(_vObject[i].hdc, _vObject[i].x, _vObject[i].z - _vObject[i].jumpPower);
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
	cout << start << ", " << end << endl;
	if (start >= end) return;
	int pivot = _vObject[(start+end) / 2].z;
	int left = start;
	int right = end;

	while (left <= right)
	{
		// left�� pivot ���ؼ� left�� ������ ++
		while (_vObject[left].z < pivot) ++left;
		// right�� pivot ���ؼ� right�� ũ�� --
		while (_vObject[right].z > pivot) --right;

		// �� �� ����
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
