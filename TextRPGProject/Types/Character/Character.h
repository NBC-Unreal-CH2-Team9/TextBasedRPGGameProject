#pragma once

#include "../Actor.h"

class Character : public Actor {
	// ����

public:
	virtual void Attack(Actor& other);
	virtual void TakeDamage(int damage);
};