#pragma once

#include "../Monster/Monster.h"

class Orc : public Monster
{
public:
	Orc(std::string name, int health, int attack, int gold, int experience) : Monster(name, health, attack, gold, experience) {}
};