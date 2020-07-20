#pragma once
#include "gameNode.h"


enum PointerState //������ ��Ʈ ����ġ
{
	START = 0,
	QUIT
};
struct tagScene
{
	image* SceneImage;
	RECT _rc;			//������ ��Ʈ
	float _x, _y;
	PointerState _PointerState;
};

class scene : public gameNode
{

private:

	tagScene _MainTitle;		//Ÿ��Ʋ ���
	tagScene _StartQuit;		//Ÿ��Ʋ ��ư
	tagScene _Pointer;			//Ÿ��Ʋ ������

	bool _GameStart;			//���� �����Ұ��ΰ�?
	bool _Loading;				//�ε� �����Ұ� �ΰ�?

	int _LoadingCount;			//�ε� ī��Ʈ

public:

	scene();
	~scene();

	HRESULT init();
	void release();
	void update();
	void render();

	void PointerMove();		//������ �̵� �Լ�
	void Draw();			//����, �ε��� �׸���

};

