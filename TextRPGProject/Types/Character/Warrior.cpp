#include "Warrior.h"
#include <iostream>

void Warrior::OnLevelChangedHealth() {
	int newHealth = (maxHealth + level * 20);
	health = newHealth;
	maxHealth = newHealth;
}

void Warrior::OnLevelChangedAttack() {
	attack += (level * 4);
}