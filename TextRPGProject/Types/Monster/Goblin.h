#pragma once
#include "../Monster/Monster.h"


class Goblin : public Monster
{
public:
	Goblin(std::string name, int health, int attack) : Monster(name, health, attack) {}
};