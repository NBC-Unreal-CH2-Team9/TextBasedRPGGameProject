#pragma once

#include "Item.h"

class AttackBoost : public Item {
public:
	AttackBoost(int attackincrease)
		: Item("Attack Boost", 100), attackincrease(attackincrease) {
	};

	void Use(Character& user);

protected:
	int attackincrease;
};


