#pragma once

#include <string>
#include "../Character/Character.h"
//#include "../Actor.h"

// 인터페이스 [2]
// 전투 시스템, 전투 결과, 상점 시스템을 위한 아이템 인터페이스
// 이 인터페이스가 있기 때문에, 아이템의 종류와 관계없이 다른 사람이 구현을 할 수 있음

class Item {
public:
	Item(std::string name) : name(name) {};

	virtual void Use(Character& user) = 0;

	// 아래 함수를 쓰면, 몬스터도 아이템을 사용할 수 있다.
	// virtual void Use(Actor& user) = 0;

	std::string GetName();

protected:
	std::string name;
};