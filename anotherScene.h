#pragma once
#include "gameNode.h"
#include "button.h"
#include "fun.h"

class anotherScene : public gameNode
{
private:
	button* _btnSceneChange;

	fun* _funTest;
	image* _funImage;
public:
	anotherScene();
	~anotherScene();

	virtual HRESULT init();
	virtual void update();
	virtual void render();

	static void cbSceneChange();

};

