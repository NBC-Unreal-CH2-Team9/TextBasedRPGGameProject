#pragma once

#include <iostream>
#include "../Actor.h"

class Monster : public Actor {
	// ±¸Çö
public:
	Monster (std::string name, int health, int attack) : Actor(name, health, attack) {}

	void Attack(Actor& other) override;
	void TakeDamage(int damage) override;
};

class MonsterManager {
public:
	static Monster* CreateDragon(int characterLevel);
	static Monster* CreateOrc(int characterLevel);
	static Monster* CreateSlime(int characterLevel);
	static Monster* CreateGoblin(int characterLevel);

private:
	static int CalculateHealth(int characterLevel);
	static int CalculateAttack(int characterLevel);
};