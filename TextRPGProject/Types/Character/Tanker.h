#pragma once

#include "../Character/Character.h"

class Tanker : public Character
{
public:
	Tanker(int level, std::string name, int health, int attack, int exp) : Character(level, name, health, attack, exp) {}

	void OnLevelChangedHealth() override;

	void OnLevelChangedAttack() override;
};