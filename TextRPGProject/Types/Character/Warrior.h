#pragma once

#include "../Character/Character.h"

class Warrior : public Character
{
public:
	Warrior(int level, std::string name, int health, int attack, int exp) : Character(level, name, health, attack, exp) {}

	void OnLevelChangedHealth() override;

	void OnLevelChangedAttack() override;
};