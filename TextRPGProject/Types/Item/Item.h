#pragma once

#include <string>

class Character;
// class Actor;

// �������̽� [2]
// ���� �ý���, ���� ���, ���� �ý����� ���� ������ �������̽�
// �� �������̽��� �ֱ� ������, �������� ������ ������� �ٸ� ����� ������ �� �� ����

class Item {
public:
	Item(std::string name, int pirce) : name(name), price(price) {};

	virtual void Use(Character& user) = 0;

	// �Ʒ� �Լ��� ����, ���͵� �������� ����� �� �ִ�.
	// virtual void Use(Actor& user) = 0;

	std::string GetName();
	int GetPrice();
	std::string GetName() {
		return name;
	}

protected:
	std::string name;
	int price;
};