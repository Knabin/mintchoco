#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_bullet = new bullet;
	_bullet->init("bullet", 30, WINSIZEY);

	
	
	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}
	minionBulletFire();
	_bullet->update();

	collision();

}

void enemyManager::render()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
	_bullet->render();
}

void enemyManager::setMinion()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("enemy", PointMake(80 + j * 80, 80 + i * 100));
			

			_vMinion.push_back(ufo);
		}
	}
}

void enemyManager::minionBulletFire()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{

		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();

			/*
			_bullet->fire((rc.left + rc.right) / 2,
				rc.bottom + 5, -(PI / 2), 7.0f);
				*/

			_bullet->fire((rc.left + rc.right) / 2,
				rc.bottom + 5,
				getAngle((rc.left + rc.right) / 2,
						 (rc.top + rc.bottom) / 2,
					_ship->getShipImage()->getCenterX(),
					_ship->getShipImage()->getCenterY()),
				7.0f);
		}

	}

}

void enemyManager::removeMinion(int arrNum)
{
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void enemyManager::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		RECT temp;

		RECT rc = RectMake(_ship->getShipImage()->getX(),
			_ship->getShipImage()->getY(),
			_ship->getShipImage()->getWidth(),
			_ship->getShipImage()->getHeight());

		if (IntersectRect(&temp, &rc, &_bullet->getVBullet()[i].rc))
		{
			_ship->hitDamage(10);
			_bullet->removeBullet(i);
			break;
		}


	}


	//스페이스 쉽이랑 충돌용
}
