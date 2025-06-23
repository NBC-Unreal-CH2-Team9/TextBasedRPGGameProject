#pragma once
#include "../Monster/Monster.h"

class Troll : public Monster
{
public:
	Troll(std::string name, int health, int attack) : Monster(name, health, attack) {}
};