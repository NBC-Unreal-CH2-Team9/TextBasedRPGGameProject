#pragma once

#include "../Actor.h"
#include "Inventory.h"

class Character : public Actor {
public:
	Character(std::string name, int health, int attack) : Actor(name, health, attack) {
	}
	virtual void Attack(Actor& other);
	virtual void TakeDamage(int damage);

	Inventory* GetInventory() {
		return &inventory;
	}

	int GetGold() {
		return gold;
	}
	void SetGold(int value) {
		gold = value;
	}

protected:
	Inventory inventory;
	int gold;
};