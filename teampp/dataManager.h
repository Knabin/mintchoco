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
	// �����ϴ� �Լ�(���� ����(0~2), �÷��̾� HP, �÷��̾� ����, �������� ��ȣ(0~4)
	void saveData(int hp, int coin, int stageNum);
	// �ҷ����� �Լ�
	vector<string>& loadDataString();
	vector<int>& loadDataInteger();

	inline void setSlot(int slot) { _slot = slot; }
	inline int getSlot() { return _slot; }

};

