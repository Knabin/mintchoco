#pragma once
#include "gameNode.h"

class saveLoadTest : public gameNode
{
public:
	saveLoadTest();
	~saveLoadTest();

	void update();

	void save();
	void load();
};

