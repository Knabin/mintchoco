#pragma once
#include "gameNode.h"
#include "item.h"
#include "money.h"
#include <vector>



class itemManager : public gameNode
{
private:
	
	typedef vector<item*>						vItem;
	typedef vector<item*>::iterator				viItem;

	typedef vector<money*>						vMoney;
	typedef vector<money*>::iterator			viMoney;

private:

	vItem  _vItems;
	viItem _viItems;

	vMoney _vMoney;
	viMoney _viMoney;


public:

	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();

	vector<item*>& getItemsVector() { return _vItems; }
	vector<money*>& getMoneyVector() { return _vMoney; }

	void setVItemsDrop(float x, float y);    //아이템 루트

	void removeItem(int Num);		//아이템 삭제
	void removeMoney(int Num2);		// 돈 삭제

	void removeAllItem();
	void removeAllMoney();


};