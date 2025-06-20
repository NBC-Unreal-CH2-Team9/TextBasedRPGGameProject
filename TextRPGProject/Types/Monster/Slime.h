#pragma once
#include "../Monster/Monster.h"

class Slime : public Monster
{
public:
	Slime(std::string name, int health, int attack) : Monster(name, health, attack) {}
};