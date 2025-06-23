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

protected:
	std::string name;
	int price;
};

// Temporal class, Equipment
// 장비 구현이 끝나면, 제거해야 함
class Equipment {
public:
	Equipment(std::string name, int pirce) : name(name), price(pirce) {};
	int GetPrice() {
		return price;
	}
	std::string GetName() {
		return name;
	}

protected:
	std::string name;
	int price;
};