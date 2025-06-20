#pragma once

#include <string>
#include "../Character/Character.h"
//#include "../Actor.h"

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

protected:
	std::string name;
	int price;
};