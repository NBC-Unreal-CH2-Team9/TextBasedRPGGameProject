#pragma once

#include <string>

class Character;
// class Actor;

class Item {
public:
	Item(std::string name, int pirce) : name(name), price(pirce) {};

	virtual void Use(Character& user) = 0;

	// �Ʒ� �Լ��� ����, ���͵� �������� ����� �� �ִ�.
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
// ��� ������ ������, �����ؾ� ��
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