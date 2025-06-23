#pragma once

#include "../Monster/Monster.h"

class Orc : public Monster
{
public:
	Orc(std::string name, int health, int attack) : Monster(name, health, attack) {}
};