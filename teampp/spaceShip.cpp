#include "stdafx.h"
#include "spaceShip.h"
#include "enemyManager.h"

spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{
}

HRESULT spaceShip::init()
{
	_ship = IMAGEMANAGER->addImage("플레이어", "rocket.bmp",
							52, 64, true, RGB(255, 0, 255));

	_ship->setX(WINSIZEX / 2);
	_ship->setY(WINSIZEY / 2 + 200);

	//주모 미싸일 인스턴스 생성
	_jumo = new jumo;
	_jumo->init(30, WINSIZEY);

	//체력바 할당
	_hpBar = new progressBar;
	_hpBar->init(_ship->getX(), _ship->getY() - 10, _ship->getWidth(), 10);
	_currentHP = _maxHP = 100;
	
	_alphaValue = 255;

	return S_OK;
}

void spaceShip::release()
{
}

void spaceShip::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _ship->getX() > 0)
	{
		_ship->setX(_ship->getX() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) &&
		_ship->getX() + _ship->getWidth() < WINSIZEX)
	{
		_ship->setX(_ship->getX() + 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && _ship->getY() > 0)
	{
		_ship->setY(_ship->getY() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) &&
		_ship->getY() + _ship->getHeight() < WINSIZEY)
	{
		_ship->setY(_ship->getY() + 5);
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_jumo->fire(_ship->getCenterX(), _ship->getY() - 20);
	}

	_jumo->update();

	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 20);
	//체력게이지 갱신
	_hpBar->update();
	_hpBar->setGauge(_currentHP, _maxHP);

	collision();

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		char temp[128];
		vector<string> vStr;

		vStr.push_back(itoa(_ship->getX(), temp, 10));
		vStr.push_back(itoa(_ship->getY(), temp, 10));
		vStr.push_back(itoa(_currentHP, temp, 10));
		vStr.push_back(itoa(_maxHP, temp, 10));

		TXTDATA->txtSave("세이브테스트.txt", vStr);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		vector<string> vStr;

		vStr = TXTDATA->txtLoad("세이브테스트.txt");

		_ship->setX(atoi(vStr[0].c_str()));
		_ship->setY(atoi(vStr[1].c_str()));
		_currentHP = (atoi(vStr[2].c_str()));

	}

	_alphaValue--;
	if (_alphaValue <= 0) _alphaValue = 255;


}

void spaceShip::render()
{
	//_ship->render(getMemDC(), _ship->getX(), _ship->getY());
	_ship->alphaRender(getMemDC(), _ship->getX(), _ship->getY(), _alphaValue);
	_jumo->render();
	//체력바 그려준다
	_hpBar->render();
}

void spaceShip::collision()
{
	for (int i = 0; i < _em->getVMinion().size(); ++i)
	{
		for (int j = 0; j < _jumo->getVJumo().size(); ++j)
		{
			RECT temp;
			if (IntersectRect(&temp, &_jumo->getVJumo()[j].rc, &_em->getVMinion()[i]->getRect()))
			{
				_em->removeMinion(i);
				_jumo->removeJumo(j);
				break;
			}
		}
	}
}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}
