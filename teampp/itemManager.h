#pragma once
#include "gameNode.h"
#include "item.h"
#include "money.h"


class itemManager : public gameNode
{
private:
	
	item* _Item;
	money* _Money;

public:

	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();

	item* getVItem() { return _Item; }

	

};