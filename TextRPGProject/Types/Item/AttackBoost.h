#pragma once

#include "Item.h"

class AttackBoost : public Item {
public:
	AttackBoost(int attackincrease)
		: Item("Attack Boost", 100), attackincrease(attackincrease) {
	};

	void Use(Character& user);

	int GetStat() {
		return attackincrease;
	}

protected:
	int attackincrease;
};


