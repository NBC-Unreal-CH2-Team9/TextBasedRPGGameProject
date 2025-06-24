#pragma once
#include "../Monster/Monster.h"

class Slime : public Monster
{
public:
	Slime(std::string name, int health, int attack, int gold, int experience) : Monster(name, health, attack, gold, experience) {}
};