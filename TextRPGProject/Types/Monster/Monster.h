#pragma once

#include <iostream>
#include "../Actor.h"

class Monster : public Actor {
	// ����
public:

	Monster (std::string name, int health, int attack) : Actor(name, health, attack) {}

	void Attack(Actor& other) override;
	void TakeDamage(int damage) override;
};