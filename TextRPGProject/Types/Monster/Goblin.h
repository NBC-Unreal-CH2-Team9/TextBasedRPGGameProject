#pragma once
#include "../Monster/Monster.h"


class Goblin : public Monster
{
public:
	Goblin(std::string name, int health, int attack, int gold, int experience) : Monster(name, health, attack, gold, experience) {}
};