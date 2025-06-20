#pragma once

#include "../Actor.h"
#include "Inventory.h"

class Character : public Actor {
public:
	virtual void Attack(Actor& other);
	virtual void TakeDamage(int damage);

	Inventory* GetInventory() {
		return &inventory;
	}

protected:
	Inventory inventory;
};