#pragma once

#include "../Monster/Monster.h"


class Dragon : public Monster
{
public:
	Dragon(std::string name, int health, int attack, int gold, int experience) : Monster(name, health, attack, gold, experience) {}
};