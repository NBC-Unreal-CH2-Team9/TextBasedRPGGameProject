#pragma once
#include "../Monster/Monster.h"


class BossMonster : public Monster
{
public:
	BossMonster(std::string name, int health, int attack, int gold, int experience) : Monster(name, health, attack, gold, experience) {}

	void Attack(Actor& other) override;

private:
	void UseSkill(Actor& other, std::string name);
	void HealSkill();
	void AttackSkill(Actor& other);
	void PassiveSkill();

	bool passiveSkill = true;

};