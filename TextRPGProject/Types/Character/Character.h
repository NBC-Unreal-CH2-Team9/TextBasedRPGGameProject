#pragma once

#include "../Actor.h"

class Character : public Actor {
	// ±¸Çö

public:
	virtual void Attack(Actor& other);
	virtual void TakeDamage(int damage);
};