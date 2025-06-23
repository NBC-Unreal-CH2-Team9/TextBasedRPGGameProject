#pragma once

#include <iostream>
#include "../Actor.h"

class Monster : public Actor {
	// ±¸Çö
public:
	Monster(std::string name, int health, int attack, int gold, int experience) : Actor(name, health, attack), gold(gold), experience(experience) {}
	void Attack(Actor& other) override;
	void TakeDamage(int damage) override;

	int GetGold();
	int GetExperience();

protected:
	int gold;
	int experience;
};

class MonsterManager {
public:
	static Monster* CreateDragon(int characterLevel);
	static Monster* CreateOrc(int characterLevel);
	static Monster* CreateSlime(int characterLevel);
	static Monster* CreateGoblin(int characterLevel);
	static Monster* CreateTroll(int characterLevel);

		

private:
	static int CalculateHealth(int characterLevel, int minHealth, int maxHealth);
	static int CalculateAttack(int characterLevel, int minAttack, int maxAttack);
	static int CalculateGold(int minGold);

};