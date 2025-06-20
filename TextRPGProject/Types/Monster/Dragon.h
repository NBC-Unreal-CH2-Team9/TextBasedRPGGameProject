#pragma once

#include "../Monster/Monster.h"


class Dragon : public Monster
{
public:
	Dragon(std::string name, int health, int attack) : Monster(name, health, attack) {}
	void Attack(Actor& other) override;
};