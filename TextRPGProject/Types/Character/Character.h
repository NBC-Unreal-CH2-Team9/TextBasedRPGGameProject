#pragma once

#include "../Actor.h"
#include "../Item/Item.h"

class Character : public Actor {

public:
	Character(std::string name, int level = 1, int maxHealth = 200, int experience = 0, int gold = 0)
		: Actor(name, maxHealth, 30)
		, level(level)
		, maxHealth(maxHealth)
		, experience(experience)
		, gold(gold)
		, item(nullptr)
	{

	};

	~Character();

	void DisplayStatus();

protected:	
	// TODO : ���� �Ŵ��� Ŭ�������� ĳ���͸� �����ͷ� ��� �ְ�
	int level;
	int maxHealth;
	int experience;
	int gold;
	Item* item;
};