#pragma once
#include "gameNode.h"

//�ݹ��Լ� == �Լ� ������
typedef void(*CALLBACK_FUNCTION)(void);

//�ݹ��Լ��� ��������Ʈ(delegate) �����غ��� �����ϴ�

//<Functional> ���̺귯���� ����ϸ� ������ ������ �ݹ��Լ�
//�Ű������� �������� ��� ������ ���ϴ�
//std::bind, std::move, std::Function

//Lambda�İ� ����ؼ� �ݹ��Լ��� �Ẹ�� �����ϸ� �� ������

//�����ƴմϴ� ��������

enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;

	const char* _imageName;
	image* _image;
	RECT _rc;

	float _x, _y;
	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	CALLBACK_FUNCTION _callbackFunction;	//�ݹ��Լ� ����

public:
	button();
	~button();

	HRESULT init(const char* imageName, float x, float y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION cbFunction);

	void release();
	void update();
	void render();
};

