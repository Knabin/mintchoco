#pragma once
class dataManager
{
public:
	static dataManager* getInstance()
	{
		static dataManager instance;
		return &instance;
	}

private:
	dataManager();
	~dataManager();

	vector<string> _vFileName;
	vector<string> _vString;
	vector<int> _vInt;

	int _slot;

public:
	// 저장하는 함수(현재 슬롯(0~2), 플레이어 HP, 플레이어 코인, 스테이지 번호(0~4)
	void saveData(int hp, int coin, int stageNum);
	// 불러오는 함수
	vector<string>& loadDataString();
	vector<int>& loadDataInteger();

	inline void setSlot(int slot) { _slot = slot; }
	inline int getSlot() { return _slot; }

};

