#include "Tanker.h"

#include <iostream>  

void Tanker::OnLevelChangedHealth() {
	int newHealth = (maxHealth + level * 35);
	health = newHealth;
	maxHealth = newHealth;
}

void Tanker::OnLevelChangedAttack() {
	attack += (level * 3);
}