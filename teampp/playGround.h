#pragma once
#include "gameNode.h"
#include "player.h"
#include "jump.h"

class playGround : public gameNode
{
private:
	player* _player;//�÷��̾� ����Ҵ�
	jump* _jump;//���� ����Ҵ�
	image* _backGround1;//ó�����۽� ���� ���ȭ�� �̹���
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

