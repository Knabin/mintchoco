//#include "..\..\..\..\..\Desktop\teampp (1)\enemyManager.h"
#include "stdafx.h"
#include "enemyManager.h"
#include "stageManager.h"

enemyManager::enemyManager()
{
}

enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{

	// �������� 1 spawn ����Ʈ �ʱ�ȭ
	{
		vector<MYPOINT> vP;

		MYPOINT p1(1375, 300);
		MYPOINT p2(1500, 300);

		vP.push_back(p1);
		vP.push_back(p2);

		_mPoint.insert(make_pair(0, vP));
	}

	// �������� 2 spawn ����Ʈ �ʱ�ȭ
	{
		vector<MYPOINT> vP;

		MYPOINT p1(300, 600);
		MYPOINT p2(400, 520);
		MYPOINT p3(950, 400);
		MYPOINT p4(1100, 400);

		vP.push_back(p1);
		vP.push_back(p2);
		vP.push_back(p3);
		vP.push_back(p4);

		_mPoint.insert(make_pair(1, vP));
	}

	// �������� 3 spawn ����Ʈ �ʱ�ȭ
	{
		vector<MYPOINT> vP;

		MYPOINT p1(2100, 600);
		MYPOINT p2(2000, 520);
		MYPOINT p3(1250, 400);
		MYPOINT p4(1400, 400);

		vP.push_back(p1);
		vP.push_back(p2);
		vP.push_back(p3);
		vP.push_back(p4);

		_mPoint.insert(make_pair(2, vP));
	}

	// �������� 4 spawn ����Ʈ �ʱ�ȭ
	{
		vector<MYPOINT> vP;

		MYPOINT p1(300, 600);
		MYPOINT p2(400, 520);
		MYPOINT p3(1750, 500);
		MYPOINT p4(1850, 600);

		vP.push_back(p1);
		vP.push_back(p2);
		vP.push_back(p3);
		vP.push_back(p4);

		_mPoint.insert(make_pair(3, vP));
	}

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (int i = 0; i < _vEnemies.size(); ++i)
	{
		//_vEnemies[i]->update();		//collisionManager�� itemDrop �Լ��� �Ű���ϴ�.
		if (_vEnemies[i]->getHP() <= 0 && _vEnemies[i]->getEnemyDead())
		{
			_sm->plusEnemyCount();
			_vEnemies[i]->setEnemyDead(false);
			_vEnemies.erase(_vEnemies.begin() + i);
		}
	}
	
	//_boss->update();  // ���� ������Ʈ
}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemies.size(); ++i)
		_vEnemies[i]->render();

	//_boss->render();	// ���� �̹��� ����
}


void enemyManager::setBossMove()	//���� ���� �߰�
{
	_boss = new boss;
	_boss->init("BOSSIDLE", WINSIZEX / 2, WINSIZEY / 2, 0.0f);
}

void enemyManager::setEnemiesVector(int stageNum)
{
	if (_vEnemies.size() != 0)
	{
		for (int i = 0; i < _vEnemies.size(); ++i)
		{
			_vEnemies[i]->release();
			SAFE_DELETE(_vEnemies[i]);
		}
		_vEnemies.clear();
	}

	switch (stageNum)
	{
	case 0:
		// �������� 1
	{
		float x[] = { 800, 1010, 1500, 1750 };
		float y[] = { 480, 300, 350, 500 };
		for (int i = 0; i < 4; i++)
		{
			if (i < 2) _vEnemies.push_back(createEnemy(1, x[i], y[i]));
			else		_vEnemies.push_back(createEnemy(2, x[i], y[i]));
		}
	}
	break;
	case 1:
		// �������� 2
	{
		float x[] = { 800, 1300, 1050, 1750, 550 };
		float y[] = { 400, 520, 710, 700, 650 };
		for (int i = 0; i < 5; i++)
		{
			if (i < 2)		_vEnemies.push_back(createEnemy(1, x[i], y[i]));
			else if (i >= 4) _vEnemies.push_back(createEnemy(0, x[i], y[i]));
			else			_vEnemies.push_back(createEnemy(2, x[i], y[i]));
		}
	}
	break;
	case 2:
		// �������� 3
	{
		float x[] = { 1800, 1400, 550, 1700 };
		float y[] = { 450, 700, 650, 750 };

		for (int i = 0; i < 4; i++)
		{
			enemy* _tempSchoolGirl = new schoolgirl;
			_tempSchoolGirl->init("schoolgirl_move", x[i], y[i], 2.3f);
			_vEnemies.push_back(_tempSchoolGirl);
		}
	}
	break;
	case 3:
		// �������� 4
	{
		float x[] = { 800, 1300, 1050, 1750, 550 };
		float y[] = { 400, 520, 710, 700, 650 };
		for (int i = 0; i < 5; i++)
		{
			if (i < 2)		_vEnemies.push_back(createEnemy(1, x[i], y[i]));
			else if (i >= 4) _vEnemies.push_back(createEnemy(0, x[i], y[i]));
			else			_vEnemies.push_back(createEnemy(2, x[i], y[i]));
		}
	}
		break;
	case 4:
		// ���� ��������
		_vEnemies.push_back(createEnemy(3, WINSIZEX + 300, WINSIZEY - 120));
		break;
	}

	for (int i = 0; i < _vEnemies.size(); ++i)
		_vEnemies[i]->setStageNum(stageNum);
}

enemy* enemyManager::createEnemy(int enemyType, float x, float y)
{
	switch (enemyType)
	{
	case 0:			// cheerleader
	{
		enemy* em = new cheerleader;
		em->init("cheer_move", x, y, 2.3f);
		return em;
	}
	break;
	case 1:
	default:		// school boy
	{
		enemy* em = new schoolboy;
		em->init("schoolboy_move", x, y, 2.3f);
		return em;
	}
		break;
	case 2: 		// school girl
	{
		enemy* em = new schoolgirl;
		em->init("schoolgirl_move", x, y, 2.3f);
		return em;
	}
		break;
	case 3:			// ����
	{
		enemy* em = new boss;
		em->init("BOSSIDLE", x, y, 0.0f);
		return em;
	}
		break;
	}
}

enemy * enemyManager::createEnemy(int enemyType, float x, float y, int stageNum)
{
	switch (enemyType)
	{
	case 0:			// cheerleader
	{
		enemy* em = new cheerleader;
		em->init("cheer_move", x, y, 2.3f);
		em->setStageNum(stageNum);
		return em;
	}
	break;
	case 1:
	default:		// school boy
	{
		enemy* em = new schoolboy;
		em->init("schoolboy_move", x, y, 2.3f);
		em->setStageNum(stageNum);
		return em;
	}
	break;
	case 2: 		// school girl
	{
		enemy* em = new schoolgirl;
		em->init("schoolgirl_move", x, y, 2.3f);
		em->setStageNum(stageNum);
		return em;
	}
	break;
	case 3:			// ����
	{
		enemy* em = new boss;
		em->init("BOSSIDLE", WINSIZEX / 2, WINSIZEY / 2, 0.0f);
		em->setStageNum(stageNum);
		return em;
	}
	break;
	}
}

void enemyManager::spawnEnemy(int stageNum)
{
	if (stageNum > 3) return;
	vPoint temp = _mPoint.at(stageNum);

	// spawn�� ����Ʈ�� �������� ������
	int r = RND->getInt(temp.size());
	
	// spawn�� enemy Ÿ���� �������� ������
	int r2 = RND->getInt(3);
	// ġ����� �������� 1���� �������� �ʴ´ٰ� �Ͽ� ���ǹ� �ɾ���! �����Ӱ� ������ �ּ���
	if (stageNum == 0) r2 = RND->getFromIntTo(1, 3);

	_vEnemies.push_back(createEnemy(r2, temp[r].x, temp[r].y, stageNum));
}


void enemyManager::removeEnemy(int index)
{
	_vEnemies[index]->release();
	SAFE_DELETE(_vEnemies[index]);
	_vEnemies.erase(_vEnemies.begin() + index);
}

void enemyManager::removeEnemies()
{
	for (int i = 0; i < _vEnemies.size(); ++i)
	{
		_vEnemies[i]->release();
		SAFE_DELETE(_vEnemies[i]);
	}
	_vEnemies.clear();
}

void enemyManager::setPlayerPos(float x, float y)
{
	for (int i = 0; i < _vEnemies.size(); ++i)
		_vEnemies[i]->setPlayerPos(x, y);

	//_boss->setPlayerPos(x, y);
}
