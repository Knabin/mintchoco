#include "stdafx.h"
#include "dataManager.h"

dataManager::dataManager()
{
	string stage1 = "data/save1.data";
	string stage2 = "data/save2.data";
	string stage3 = "data/save3.data";

	_vFileName.push_back(stage1);
	_vFileName.push_back(stage2);
	_vFileName.push_back(stage3);
}

dataManager::~dataManager()
{
}

void dataManager::saveData(int hp, int coin, int stageNum)
{
	vector<string> temp;
	temp.push_back(to_string(hp));
	temp.push_back(to_string(coin));
	temp.push_back(to_string(stageNum));
	TXTDATA->txtSave(_vFileName[_slot].c_str(), temp);
}

vector<string>& dataManager::loadDataString()
{
	_vString.clear();

	if (TXTDATA->canLoadFile(_vFileName[_slot].c_str()))
	{
		_vString = TXTDATA->txtLoad(_vFileName[_slot].c_str());
	}

	return _vString;
}

vector<int>& dataManager::loadDataInteger()
{
	_vInt.clear();

	if (TXTDATA->canLoadFile(_vFileName[_slot].c_str()))
	{
		vector<string> str;
		str = TXTDATA->txtLoad(_vFileName[_slot].c_str());

		for (int i = 0; i < 3; ++i)
			_vInt.push_back(stoi(str[i]));
	}

	return _vInt;
}
