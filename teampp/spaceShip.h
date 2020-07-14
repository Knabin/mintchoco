#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

#pragma warning(disable:4996)

//헤더파일 꼬임방지를 위한 클래스 전방선언
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	jumo* _jumo;

	enemyManager* _em;

	progressBar* _hpBar;
	float _currentHP, _maxHP;

	int _alphaValue;

public:
	spaceShip();
	~spaceShip();

	//알트 + 엔터 -> C -> C -> 엔터
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//충돌용 함수
	void collision();

	//외부에서 데미지주는 함수
	void hitDamage(float damage);

	//전방선언 시 빈껍데기에 실제를 찾아주기위한 메모리 링크 설정자
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	image* getShipImage() { return _ship; }

	//주모 미사일 접근자
	jumo* getJumo() { return _jumo; }
};

