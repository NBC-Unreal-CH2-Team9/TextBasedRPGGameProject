#pragma once

#include <vector>
#include "../Actor.h"
#include "Inventory.h"

class Character : public Actor {
public:
	virtual void Attack(Actor& other);
	virtual void TakeDamage(int damage);

protected:
	Inventory inventory;
};