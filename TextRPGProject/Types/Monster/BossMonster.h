#pragma once
#include "../Monster/Monster.h"


class BossMonster : public Monster
{
public:
	BossMonster(std::string name, int health, int attack, int gold, int experience) : Monster(name, health, attack, gold, experience) {}
};