#pragma once

#include <string>

class Character;
// class Actor;

class Item {
public:
	Item(std::string name, int pirce) : name(name), price(pirce) {};

	virtual void Use(Character& user) = 0;

	// 아래 함수를 쓰면, 몬스터도 아이템을 사용할 수 있다.
	// virtual void Use(Actor& user) = 0;

	int GetPrice() {
		return price;
	}
	std::string GetName() {
		return name;
	}

	virtual int GetStat() = 0;

protected:
	std::string name;
	int price;
};

